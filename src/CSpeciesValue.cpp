/*
 * CSpeciesValue.cpp
 *
 *  Created on: Dec 16, 2020
 *      Author: andy
 */

#include <CSpeciesValue.hpp>
#include <CStateVector.hpp>
#include <CSpeciesList.hpp>
#include <sbml/Species.h>
#include <CObject.hpp>
#include <CConvert.hpp>
#include <iostream>

// get the libsbml species from a CSpeciesValue object
static CSpecies *speciesvalue_species(PyObject *obj) {
    CSpeciesValue *cv = (CSpeciesValue*)obj;
    CStateVector *sv = cv->state_vector;
    CSpeciesList *sl = sv->species;
    return sl->item(cv->index);
}

/* Number implementations must check *both*
   arguments for proper type and implement the necessary conversions
   in the slot functions themselves. */

static int cspeciesvalue_init(CSpeciesValue *self, PyObject *args, PyObject *kwargs) {
    std::cout << MX_FUNCTION << std::endl;
    self->ob_fval = 123456790;
    return 0;
}

static void cspeciesvalue_dealloc(CSpeciesValue *self) {
    std::cout << MX_FUNCTION << std::endl;
    Py_DECREF(self->state_vector);
    ((PyObject*)self)->ob_type->tp_free(self);
}

CSpeciesValue* CSpeciesValue_New(double value, struct CStateVector *sv, uint32_t index) {
    CSpeciesValue *obj = (CSpeciesValue*)PyType_GenericNew(&CSpeciesValue_Type, NULL, NULL);
    if(!obj) {
        PyErr_SetString(PyExc_Exception, "could not allocate CSpeciesValue");
        return NULL;
    }
    
    obj->ob_fval = value;
    obj->state_vector = sv;
    obj->index = index;
    Py_INCREF(sv);
    
    return obj;
}

PyGetSetDef cspeciesvalue_getsets[] = {
    {
        .name = "boundary",
        .get = [](PyObject *obj, void *p) -> PyObject* {
            CSpecies *species = speciesvalue_species(obj);
            return PySpecies_getBoundaryCondition(species);
        },
        .set = [](PyObject *obj, PyObject *val, void *p) -> int {
            PyErr_SetString(PyExc_Exception, "boundary is read-only");
            return -1;
        },
        .doc = "test doc",
        .closure = NULL
    },
    {
        .name = "initial_amount",
        .get = [](PyObject *obj, void *p) -> PyObject* {
            CSpecies *species = speciesvalue_species(obj);
            return PySpecies_getInitialAmount(species);
        },
        .set = [](PyObject *obj, PyObject *val, void *p) -> int {
            PyErr_SetString(PyExc_Exception, "initial_amount is read-only");
            return -1;
        },
        .doc = "test doc",
        .closure = NULL
    },
    {
        .name = "initial_concentration",
        .get = [](PyObject *obj, void *p) -> PyObject* {
            CSpecies *species = speciesvalue_species(obj);
            return PySpecies_getInitialConcentration(species);
        },
        .set = [](PyObject *obj, PyObject *val, void *p) -> int {
            PyErr_SetString(PyExc_Exception, "initial_concentration is read-only");
            return -1;
        },
        .doc = "test doc",
        .closure = NULL
    },
    {
        .name = "constant",
        .get = [](PyObject *obj, void *p) -> PyObject* {
            CSpecies *species = speciesvalue_species(obj);
            return PySpecies_getConstant(species);
        },
        .set = [](PyObject *obj, PyObject *val, void *p) -> int {
            PyErr_SetString(PyExc_Exception, "constant is read-only");
            return -1;
        },
        .doc = "test doc",
        .closure = NULL
    },
    {NULL}
};


PyTypeObject CSpeciesValue_Type = {
  CVarObject_HEAD_INIT(NULL, 0)
  "SpeciesValue"                        , // .tp_name
  sizeof(CSpeciesValue)                 , // .tp_basicsize
  0                                     , // .tp_itemsize
  (destructor )cspeciesvalue_dealloc    , // .tp_dealloc
  0                                     , // .tp_print
  0                                     , // .tp_getattr
  0                                     , // .tp_setattr
  0                                     , // .tp_as_async
  0                                     , // .tp_repr
  0                                     , // .tp_as_number
  0                                     , // .tp_as_sequence
  0                                     , // .tp_as_mapping
  0                                     , // .tp_hash
  0                                     , // .tp_call
  0                                     , // .tp_str
  0                                     , // .tp_getattro
  0                                     , // .tp_setattro
  0                                     , // .tp_as_buffer
  Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_TYPE_SUBCLASS, // .tp_flags
  0                                     , // .tp_doc
  0                                     , // .tp_traverse
  0                                     , // .tp_clear
  0                                     , // .tp_richcompare
  0                                     , // .tp_weaklistoffset
  0                                     , // .tp_iter
  0                                     , // .tp_iternext
  0                                     , // .tp_methods
  0                                     , // .tp_members
  cspeciesvalue_getsets                 , // .tp_getset
  0                                     , // .tp_base
  0                                     , // .tp_dict
  0                                     , // .tp_descr_get
  0                                     , // .tp_descr_set
  0                                     , // .tp_dictoffset
  (initproc)cspeciesvalue_init          , // .tp_init
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
  0                                     , // .tp_next
#endif
};

HRESULT _CSpeciesValue_Init(PyObject* m) {
    
    // TODO: should we increment PyFloat_Type???
    CSpeciesValue_Type.tp_base = &PyFloat_Type;
    
    if (PyType_Ready((PyTypeObject*)&CSpeciesValue_Type) < 0) {
        return E_FAIL;
    }
    
    Py_INCREF(&CSpeciesValue_Type);
    if (PyModule_AddObject(m, "SpeciesValue", (PyObject *)&CSpeciesValue_Type) < 0) {
        Py_DECREF(&CSpeciesValue_Type);
        return E_FAIL;
    }
    
    return S_OK;
}

