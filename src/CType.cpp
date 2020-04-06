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
    {0, NULL},
    .tp_name = "Type",
    .tp_basicsize = sizeof(CType),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
    .tp_new = PyType_GenericNew,
    .tp_doc = "metatype for base of Carbon Objects",
    .tp_new = PyType_Type.tp_new
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
