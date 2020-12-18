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


CStateVector* CStateVector_New(struct CSpeciesList *species,
                               uint32_t flags, uint32_t size, void* data) {
    CStateVector* obj = (CStateVector*)PyType_GenericNew((PyTypeObject *)
        &CStateVector_Type, NULL, NULL);
    obj->species = species;
    Py_INCREF(species);
    obj->size = species->species.size();
    obj->fvec = (float*)malloc(obj->size *sizeof(float));
    bzero(obj->fvec, obj->size *sizeof(float));
    return obj;
}

static PyObject* statevector_str(CStateVector *self) {
    std::stringstream  ss;
    
    ss << "StateVector([";
    for(int i = 0; i < self->size; ++i) {
        CSpecies *s = self->species->species[i];
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
    std::cout << MX_FUNCTION << std::endl;

    self->ob_type->tp_free(self);
}

static PyMethodDef statevector_methods[] = {
        { NULL, NULL, 0, NULL }
};

// sq_length
static Py_ssize_t statevector_length(PyObject *_self) {
    std::cout << MX_FUNCTION << std::endl;
    CStateVector *self = (CStateVector*)_self;
    return self->size;
}

// sq_concat
static PyObject *statevector_concat(PyObject *, PyObject *) {
    std::cout << MX_FUNCTION << std::endl;
    return 0;
}

// sq_repeat
static PyObject *statevector_repeat(PyObject *, Py_ssize_t) {
    std::cout << MX_FUNCTION << std::endl;
    return 0;
}

// sq_item
static PyObject *statevector_item(PyObject *_self, Py_ssize_t i) {

    CStateVector *self = (CStateVector*)_self;
    
    if(i < self->size) {
        return (PyObject*)CSpeciesValue_New(self->fvec[i], self, i);
    }
    else {
        PyErr_SetString(PyExc_IndexError, "cluster index out of range");
    }
    return NULL;
}

// sq_ass_item
static int statevector_ass_item(PyObject *_self, Py_ssize_t i, PyObject *o) {
    CStateVector *self = (CStateVector*)_self;
    
    if(i < self->size) {
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
        PyErr_SetString(PyExc_IndexError, "cluster index out of range");
    }
    return -1;
}

// sq_contains
static int statevector_contains(PyObject *, PyObject *) {
    std::cout << MX_FUNCTION << std::endl;
    return 0;
}

// sq_inplace_concat
static PyObject *statevector_inplace_concat(PyObject *, PyObject *) {
    std::cout << MX_FUNCTION << std::endl;
    return 0;
}

// sq_inplace_repeat
static PyObject *statevector_inplace_repeat(PyObject *, Py_ssize_t) {
    std::cout << MX_FUNCTION << std::endl;
    return 0;
}

static PySequenceMethods statevector_sequence_methods =  {
    statevector_length, // lenfunc sq_length;
    statevector_concat, // binaryfunc sq_concat;
    statevector_repeat, // ssizeargfunc sq_repeat;
    statevector_item, // ssizeargfunc sq_item;
    0, // void *was_sq_slice;
    statevector_ass_item, // ssizeobjargproc sq_ass_item;
    0, // void *was_sq_ass_slice;
    statevector_contains, // objobjproc sq_contains;
    statevector_inplace_concat, // binaryfunc sq_inplace_concat;
    statevector_inplace_repeat  // ssizeargfunc sq_inplace_repeat;
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
  &statevector_sequence_methods         , // .tp_as_sequence
  0                                     , // .tp_as_mapping
  0                                     , // .tp_hash
  0                                     , // .tp_call
  (reprfunc)statevector_str             , // .tp_str
  0                                     , // .tp_getattro
  0                                     , // .tp_setattro
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
  0                                     , // .tp_getset
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
