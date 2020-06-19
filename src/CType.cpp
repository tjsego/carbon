/*
 * CType.cpp
 *
 *  Created on: Feb 1, 2017
 *      Author: andy
 */

#include <carbon.h>



static_assert(sizeof(CType) == sizeof(PyTypeObject), "CType must be same as PyTypeObject");
static_assert(offsetof(CType, tp_finalize) == offsetof(PyTypeObject, tp_finalize), "CType offset different");


PyTypeObject CType_Type = {
  CVarObject_HEAD_INIT(NULL, 0)
  "Type",                     // .tp_name
  sizeof(CType),              // .tp_basicsize
  0                         , // .tp_itemsize
  0                         , // .tp_dealloc
  0                         , // .tp_print
  0                         , // .tp_getattr
  0                         , // .tp_setattr
  0                         , // .tp_as_async
  0                         , // .tp_repr
  0                         , // .tp_as_number
  0                         , // .tp_as_sequence
  0                         , // .tp_as_mapping
  0                         , // .tp_hash
  0                         , // .tp_call
  0                         , // .tp_str
  0                         , // .tp_getattro
  0                         , // .tp_setattro
  0                         , // .tp_as_buffer
  Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE                         , // .tp_flag
  "metatype for base of Carbon Objects"                         , // .tp_doc
  0                         , // .tp_traverse
  0                         , // .tp_clear
  0                         , // .tp_richcompare
  0                         , // .tp_weaklistoffset
  0                         , // .tp_iter
  0                         , // .tp_iternext
  0                         , // .tp_methods
  0                         , // .tp_members
  0                         , // .tp_getset
  0                         , // .tp_base
  0                         , // .tp_dict
  0                         , // .tp_descr_get
  0                         , // .tp_descr_set
  0                         , // .tp_dictoffset
  0                         , // .tp_init
  0                         , // .tp_alloc
  PyType_Type.tp_new                         , // .tp_new
  0                         , // .tp_free
  0                         , // .tp_is_gc
  0                         , // .tp_bases
  0                         , // .tp_mro
  0                         , // .tp_cache
  0                         , // .tp_subclasses
  0                         , // .tp_weaklist
  0                         , // .tp_del
  0                         , // .tp_version_tag
  0                         , // .tp_finalize
};
PyTypeObject *CType_TypePtr = &CType_Type;



HRESULT CType_init(PyObject *m) {


    CType_Type.tp_base = (CType*)&PyType_Type;

    if (PyType_Ready((PyTypeObject*)&CType_Type) < 0) {
        return E_FAIL;
    }

    Py_INCREF(CObject_TypePtr);
    if (PyModule_AddObject(m, "Type", (PyObject *)&CType_Type) < 0) {
        Py_DECREF(&CType_Type);
        return E_FAIL;
    }

    return S_OK;
}

//CType::CType(const char* name, CType* base) : CObject{CType_Type}
//{
//    tp_name = name;
 //   tp_base = base;
//}

/**
 * T1 : CObject
 * T2 : T1
 * T3 : T2
 * T4 : T1
 *
 *
 
 */

CAPI_FUNC(int) CType_IsSubtype(CType *a, CType *b) {
    do {
        if (a == b)
            return 1;
        a = (CType*)a->tp_base;
    } while (a != NULL && a != CObject_TypePtr);
    return b == CObject_TypePtr;
}
