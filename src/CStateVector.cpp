//
//  CStateVector.cpp
//  CorradeInterconnect
//
//  Created by Andy Somogyi on 12/16/20.
//

#include "CStateVector.hpp"
#include <CSpeciesList.hpp>
#include <CSpeciesValue.hpp>
#include <CObject.hpp>
#include <CConvert.hpp>
#include <sbml/Species.h>

#include <iostream>
#include <sstream>

// reset the species values based on the values specified in the species.
void CStateVector::reset() {
    for(int i = 0; i < species->size(); ++i) {
        CSpecies *s = species->item(i);
        float value = 0.f;
        if(s->species->isSetInitialConcentration()) {
            value = s->species->getInitialConcentration();
        }
        fvec[i] = value;
    }
}


// get named attribute
static PyObject *statevector_getattro(CStateVector *self, PyObject *attr) {
    
    int index = self->species->index_of(attr);
    if(index >= 0) {
        double value = self->fvec[index];
        return (PyObject*)CSpeciesValue_New(value, self, index);
    }
    PyTypeObject *type = self->ob_type;
    PyTypeObject *base = type->tp_base;
    return base->tp_getattro((PyObject*)self, attr);
}

//Set the value of the named attribute for the object.
// The value argument is set to NULL to delete the attribute.
static int statevector_setattro(CStateVector *self, PyObject *attr, PyObject *value) {
    if(PyNumber_Check(value) < 0) {
        PyErr_SetString(PyExc_TypeError, "StateVector assignment must be a number");
        return -1;
    }
    
    int index = self->species->index_of(attr);
    
    if(index < 0) {
        PyErr_SetString(PyExc_KeyError, "invalid species id");
        return -1;
    }
    
    double dbl = PyFloat_AsDouble(value);
    
    self->fvec[index] = dbl;
    
    return 0;
}

static void statevector_copy_values(CStateVector *newVec, CStateVector* oldVec) {
    for(int i = 0; i < oldVec->species->size(); ++i) {
        CSpecies *species = oldVec->species->item(i);
        
        int j = newVec->species->index_of(species->getId());
        if(j >= 0) {
            newVec->fvec[j] = oldVec->fvec[i];
        }
    }
}


// Initial version, locally allocate block of memory for each state vec,
// single block per vec, and q is offset at the end of the values block.

CStateVector* CStateVector_New(struct CSpeciesList *species,
                               PyObject *owner,
                               CStateVector *existingStateVector,
                               uint32_t flags,
                               uint32_t size,
                               void* data) {
    
    CStateVector* obj = (CStateVector*)PyType_GenericNew((PyTypeObject *)
        &CStateVector_Type, NULL, NULL);
    
    obj->species = species;
    Py_INCREF(species);
    
    if(owner) {
        obj->owner = owner;
        Py_INCREF(owner);
    }
    
    obj->size = species->size();
    
    const int fvec_offset = 0;
    const int fvec_size = obj->size * sizeof(float);
    const int q_offset = fvec_offset + fvec_size;
    const int q_size = obj->size * sizeof(float);
    const int flags_offset = q_offset + q_size;
    const int flags_size = obj->size * sizeof(int32_t);
    
    if(!data) {
        obj->flags |= STATEVECTOR_OWNMEMORY;
        obj->data = malloc(fvec_size + q_size + flags_size);
        bzero(obj->data, fvec_size + q_size + flags_size);
        obj->fvec =          (float*)   ((uint8_t*)obj->data + fvec_offset);
        obj->q =             (float*)   ((uint8_t*)obj->data + q_offset);
        obj->species_flags = (uint32_t*)((uint8_t*)obj->data + flags_offset);
    }
    
    if(existingStateVector) {
        statevector_copy_values(obj, existingStateVector);
    }
    
    for(int i = 0; i < species->size(); ++i) {
        obj->species_flags[i] = species->item(i)->flags();
    }
    
    return obj;
}

static PyObject* statevector_str(CStateVector *self) {
    std::stringstream  ss;
    
    ss << "StateVector([";
    for(int i = 0; i < self->size; ++i) {
        CSpecies *s = self->species->item(i);
        ss << s->species->getId();
        ss << ":";
        ss << self->fvec[i];
        if(i+1 < self->size) {
            ss << ", ";
        }
    }
    ss << "])";
    return carbon::cast(ss.str());
}

static void statevector_dealloc(CStateVector *self) {
    if(self->flags & STATEVECTOR_OWNMEMORY) {
        free(self->fvec);
    }
    
    if(self->owner) {
        Py_DECREF(self->owner);
    }
    
    self->ob_type->tp_free(self);
}

// sq_length
static Py_ssize_t statevector_length(PyObject *_self) {
    CStateVector *self = (CStateVector*)_self;
    return self->size;
}

// sq_item
static PyObject *statevector_subscript(PyObject *_self, PyObject *pindex) {

    CStateVector *self = (CStateVector*)_self;
    
    int i = self->species->index_of(pindex);
    
    if(i >= 0 && i < self->size) {
        return (PyObject*)CSpeciesValue_New(self->fvec[i], self, i);
    }
    else {
        PyErr_SetString(PyExc_IndexError, "state vector index out of range");
    }
    return NULL;
}

// sq_ass_item
static int statevector_ass_item(PyObject *_self, PyObject *pindex, PyObject *o) {
    CStateVector *self = (CStateVector*)_self;
    int i = self->species->index_of(pindex);
    
    if(i >= 0 && i < self->size) {
        if(PyNumber_Check(o)) {
            double d = PyFloat_AsDouble(o);
            self->fvec[i] = d;
            return 0;
        }
        else {
            PyErr_SetString(PyExc_IndexError, "assignment value is not a number");
        }
    }
    else {
        PyErr_SetString(PyExc_IndexError, "statevector index out of range");
    }
    return -1;
}

static PyMappingMethods statevector_mapping = {
    statevector_length,      //mp_length
    statevector_subscript,   //mp_subscript
    statevector_ass_item,    //mp_ass_subscript
};


PyGetSetDef statevector_getset[] = {
    {
        .name = "owner",
        .get = [](PyObject *_self, void *p) -> PyObject* {
            CStateVector *self = (CStateVector*)_self;
            if(self->owner) {
                Py_INCREF(self->owner);
                return self->owner;
            }
            else {
                Py_RETURN_NONE;
            }
        },
        .set = [](PyObject *_self, PyObject *val, void *p) -> int {
            CStateVector *self = (CStateVector*)_self;
            if(self->owner) {
                Py_DECREF(self->owner);
                self->owner = NULL;
            }
            if (val != Py_None) {
                self->owner = val;
                Py_INCREF(self->owner);
            }
            return 0;
        },
        .doc = "test doc",
        .closure = NULL
    },
    {NULL}
};

static PyObject *statevector_reset(CStateVector *self) {
    self->reset();
    Py_RETURN_NONE;
}

static PyMethodDef statevector_methods[] = {
    { "reset", (PyCFunction)statevector_reset, METH_NOARGS, NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject CStateVector_Type = {
  CVarObject_HEAD_INIT(NULL, 0)
  "StateVector"                         , // .tp_name
  sizeof(CStateVector)                  , // .tp_basicsize
  0                                     , // .tp_itemsize
  (destructor)statevector_dealloc       , // .tp_dealloc
  0                                     , // .tp_print
  0                                     , // .tp_getattr
  0                                     , // .tp_setattr
  0                                     , // .tp_as_async
  (reprfunc)statevector_str             , // .tp_repr
  0                                     , // .tp_as_number
  0                                     , // .tp_as_sequence
  &statevector_mapping                  , // .tp_as_mapping
  0                                     , // .tp_hash
  0                                     , // .tp_call
  (reprfunc)statevector_str             , // .tp_str
  (getattrofunc)statevector_getattro    , // .tp_getattro
  (setattrofunc)statevector_setattro    , // .tp_setattro
  0                                     , // .tp_as_buffer
  Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE , // .tp_flags
  0                                     , // .tp_doc
  0                                     , // .tp_traverse
  0                                     , // .tp_clear
  0                                     , // .tp_richcompare
  0                                     , // .tp_weaklistoffset
  0                                     , // .tp_iter
  0                                     , // .tp_iternext
  0                                     , // .tp_methods
  0                                     , // .tp_members
  statevector_getset                    , // .tp_getset
  0                                     , // .tp_base
  0                                     , // .tp_dict
  0                                     , // .tp_descr_get
  0                                     , // .tp_descr_set
  0                                     , // .tp_dictoffset
  0                                     , // .tp_init
  0                                     , // .tp_alloc
  PyType_GenericNew                     , // .tp_new
  0                                     , // .tp_free
  0                                     , // .tp_is_gc
  0                                     , // .tp_bases
  0                                     , // .tp_mro
  0                                     , // .tp_cache
  0                                     , // .tp_subclasses
  0                                     , // .tp_weaklist
  0                                     , // .tp_del
  0                                     , // .tp_version_tag
  0                                     , // .tp_finalize
#ifdef COUNT_ALLOCS
  0                                     , // .tp_allocs
  0                                     , // .tp_frees
  0                                     , // .tp_maxalloc
  0                                     , // .tp_prev
  0                                     , // .tp_next =
#endif
};


C_BASIC_PYTHON_TYPE_INIT(StateVector)
