/*
 * CSpeciesList.cpp
 *
 *  Created on: Dec 16, 2020
 *      Author: andy
 */

#include <CSpeciesList.hpp>
#include <CSpecies.hpp>
#include <CObject.hpp>
#include <CConvert.hpp>
#include <sbml/Species.h>
#include <sstream>
#include <iostream>

static int specieslist_init(CSpeciesList *self, PyObject *args, PyObject *kwargs) {
    std::cout << MX_FUNCTION << std::endl;

}

static void specieslist_dealloc(CSpeciesList *self) {
    std::cout << MX_FUNCTION << std::endl;

    self->ob_type->tp_free(self);
}

static PyMethodDef specieslist_methods[] = {
        { NULL, NULL, 0, NULL }
};

static PyObject* specieslist_str(CSpeciesList *self) {
    std::stringstream  ss;
    
    ss << "SpeciesList([";
    for(int i = 0; i < self->species.size(); ++i) {
        CSpecies *s = self->species[i];
        ss << "'" << s->species->getId() << "'";

        if(i+1 < self->species.size()) {
            ss << ", ";
        }
    }
    ss << "])";
    return carbon::cast(ss.str());
}


// sq_length
static Py_ssize_t specieslist_length(PyObject *_self) {
    std::cout << MX_FUNCTION << std::endl;
    CSpeciesList *self = (CSpeciesList*)_self;
    return self->species.size();
}

// sq_concat
static PyObject *specieslist_concat(PyObject *, PyObject *) {
    std::cout << MX_FUNCTION << std::endl;
    return 0;
}

// sq_repeat
static PyObject *specieslist_repeat(PyObject *, Py_ssize_t) {
    std::cout << MX_FUNCTION << std::endl;
    return 0;
}

// sq_item
static PyObject *specieslist_item(PyObject *_self, Py_ssize_t i) {

    CSpeciesList *self = (CSpeciesList*)_self;
    
    if(i < self->species.size()) {
        CSpecies *s = self->species[i];
        Py_INCREF(s);
        return s;
    }
    else {
        PyErr_SetString(PyExc_IndexError, "index out of range");
    }
    return NULL;
}

// sq_ass_item
static int specieslist_ass_item(PyObject *_self, Py_ssize_t i, PyObject *o) {
    PyErr_SetString(PyExc_IndexError, "SpeciesList does not support assignment");
    return -1;
}

// sq_contains
static int specieslist_contains(PyObject *, PyObject *) {
    std::cout << MX_FUNCTION << std::endl;
    return 0;
}

// sq_inplace_concat
static PyObject *specieslist_inplace_concat(PyObject *, PyObject *) {
    std::cout << MX_FUNCTION << std::endl;
    return 0;
}

// sq_inplace_repeat
static PyObject *specieslist_inplace_repeat(PyObject *, Py_ssize_t) {
    std::cout << MX_FUNCTION << std::endl;
    return 0;
}

static PySequenceMethods specieslist_sequence_methods =  {
    specieslist_length, // lenfunc sq_length;
    specieslist_concat, // binaryfunc sq_concat;
    specieslist_repeat, // ssizeargfunc sq_repeat;
    specieslist_item, // ssizeargfunc sq_item;
    0, // void *was_sq_slice;
    specieslist_ass_item, // ssizeobjargproc sq_ass_item;
    0, // void *was_sq_ass_slice;
    specieslist_contains, // objobjproc sq_contains;
    specieslist_inplace_concat, // binaryfunc sq_inplace_concat;
    specieslist_inplace_repeat  // ssizeargfunc sq_inplace_repeat;
};


PyTypeObject CSpeciesList_Type = {
  CVarObject_HEAD_INIT(NULL, 0)
  "SpeciesList"                         , // .tp_name
  sizeof(CSpeciesList)                  , // .tp_basicsize
  0                                     , // .tp_itemsize
  (destructor)specieslist_dealloc       , // .tp_dealloc
  0                                     , // .tp_print
  0                                     , // .tp_getattr
  0                                     , // .tp_setattr
  0                                     , // .tp_as_async
  (reprfunc)specieslist_str             , // .tp_repr
  0                                     , // .tp_as_number
  &specieslist_sequence_methods         , // .tp_as_sequence
  0                                     , // .tp_as_mapping
  0                                     , // .tp_hash
  0                                     , // .tp_call
  (reprfunc)specieslist_str             , // .tp_str
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
  specieslist_methods                   , // .tp_methods
  0                                     , // .tp_members
  0                                     , // .tp_getset
  0                                     , // .tp_base
  0                                     , // .tp_dict
  0                                     , // .tp_descr_get
  0                                     , // .tp_descr_set
  0                                     , // .tp_dictoffset
  (initproc)specieslist_init            , // .tp_init
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

CSpeciesList* CSpeciesList_NewFromPyArgs(PyObject *args) {
    if(args == NULL || !PySequence_Check(args)) {
        PyErr_SetString(PyExc_ValueError, "args must be a sequence");
        return NULL;
    }
    
    CSpeciesList *obj = (CSpeciesList*)PyType_GenericNew(&CSpeciesList_Type, NULL, NULL);
    if(!obj) {
        PyErr_SetString(PyExc_ValueError, "could not allocate new SpeciesList");
        return NULL;
    }
    
    int size = PySequence_Size(args);
    for(int i = 0; i < size; ++i) {
        CSpecies *species = CSpecies_NewFromPyArgs(PySequence_GetItem(args, i), NULL);
        if(species) {
            obj->species.push_back(species);
        }
        else {
            // CSpecies_NewFromPyArgs sets python error if it fails
            Py_DECREF(obj);
            return NULL;
        }
    }
    return obj;
}

C_BASIC_PYTHON_TYPE_INIT(SpeciesList)
