/*
 * ca_object.cpp
 *
 *  Created on: Jul 2, 2015
 *      Author: andy
 */


#include <stdarg.h>
#include <iostream>

#include <carbon.h>
#include <CObject.hpp>


CType CObject_Type = {
    {0, NULL},
    .tp_name = "custom.Custom",
    .tp_doc = "Custom objects",
    .tp_basicsize = sizeof(CObject),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew
};

CType* CObject_TypePtr = &CObject_Type;





static_assert(sizeof(CObject) == sizeof(PyObject), "CObject must be same as PyObject");




//CObject_Type->tp_base = CObject_Type;






extern "C" {

void Ca_Dealloc(CObject*)
{
}

CObject* CObject_GetAttrString(CObject *o,
		const char *attr_name)
{
	return NULL;
}



CObject * CObject_CallMethod(CObject* o, const char* method, const char* format, ...)
{
	return NULL;
}

CObject * CObject_CallMethodObjArgs(CObject* o, CObject* method, ...)
{
	return NULL;
}


CAPI_FUNC(uint32_t) Ca_IncRef(CObject* o)
{
	return 0;
}

CAPI_FUNC(uint32_t) Ca_DecRef(CObject* o)
{
	return 0;
}


CObject* CObject_Repr(CObject* o)
{
	return 0;
}

CObject* CObject_Str(CObject* o)
{
	return 0;
}


long CObject_HashNotImplemented(CObject *self)
{
	/*
    PyErr_Format(PyExc_TypeError, "unhashable type: '%.200s'",
                 self->ob_type->tp_name);
                 */
    return -1;
}

}

HRESULT CObject_init(PyObject *m) {

    if (PyType_Ready((PyTypeObject*)CObject_TypePtr) < 0)
        return E_FAIL;

    Py_INCREF(CObject_TypePtr);
    if (PyModule_AddObject(m, "Object", (PyObject *)CObject_TypePtr) < 0) {
        Py_DECREF(&CObject_Type);
        return E_FAIL;
    }

    return S_OK;
}

HRESULT CObject_ChangeType(CObject* obj, const CType* type)
{
    obj->ob_type = const_cast<CType*>(type);
    return S_OK;
}
