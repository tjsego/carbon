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

PyTypeObject Test_Type = {
  CVarObject_HEAD_INIT(NULL, 0)
  .tp_name =           0, 
  .tp_basicsize =      0,
  .tp_itemsize =       0, 
  .tp_dealloc =        0, 
  .tp_print =          0, 
  .tp_getattr =        0, 
  .tp_setattr =        0, 
  .tp_as_async =       0, 
  .tp_repr =           0, 
  .tp_as_number =      0, 
  .tp_as_sequence =    0, 
  .tp_as_mapping =     0, 
  .tp_hash =           0, 
  .tp_call =           0, 
  .tp_str =            0, 
  .tp_getattro =       0, 
  .tp_setattro =       0, 
  .tp_as_buffer =      0, 
  .tp_flags =          0, 
  .tp_doc =            0, 
  .tp_traverse =       0, 
  .tp_clear =          0, 
  .tp_richcompare =    0, 
  .tp_weaklistoffset = 0, 
  .tp_iter =           0, 
  .tp_iternext =       0, 
  .tp_methods =        0, 
  .tp_members =        0, 
  .tp_getset =         0, 
  .tp_base =           0, 
  .tp_dict =           0, 
  .tp_descr_get =      0, 
  .tp_descr_set =      0, 
  .tp_dictoffset =     0, 
  .tp_init =           0, 
  .tp_alloc =          0, 
  .tp_new =            0, 
  .tp_free =           0, 
  .tp_is_gc =          0, 
  .tp_bases =          0, 
  .tp_mro =            0, 
  .tp_cache =          0, 
  .tp_subclasses =     0, 
  .tp_weaklist =       0, 
  .tp_del =            0, 
  .tp_version_tag =    0, 
  .tp_finalize =       0, 
#ifdef COUNT_ALLOCS
  .tp_allocs =         0, 
  .tp_frees =          0, 
  .tp_maxalloc =       0, 
  .tp_prev =           0, 
  .tp_next =           0 
#endif
}; 



PyTypeObject CObject_Type = {
  CVarObject_HEAD_INIT(NULL, 0)
  .tp_name =           "Object", 
  .tp_basicsize =      sizeof(CObject),
  .tp_itemsize =       0, 
  .tp_dealloc =        0, 
  .tp_print =          0, 
  .tp_getattr =        0, 
  .tp_setattr =        0, 
  .tp_as_async =       0, 
  .tp_repr =           0, 
  .tp_as_number =      0, 
  .tp_as_sequence =    0, 
  .tp_as_mapping =     0, 
  .tp_hash =           0, 
  .tp_call =           0, 
  .tp_str =            0, 
  .tp_getattro =       0, 
  .tp_setattro =       0, 
  .tp_as_buffer =      0, 
  .tp_flags =          Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
  .tp_doc =            "carbon base object",
  .tp_traverse =       0, 
  .tp_clear =          0, 
  .tp_richcompare =    0, 
  .tp_weaklistoffset = 0, 
  .tp_iter =           0, 
  .tp_iternext =       0, 
  .tp_methods =        0, 
  .tp_members =        0, 
  .tp_getset =         0, 
  .tp_base =           0, 
  .tp_dict =           0, 
  .tp_descr_get =      0, 
  .tp_descr_set =      0, 
  .tp_dictoffset =     0, 
  .tp_init =           0, 
  .tp_alloc =          0, 
  .tp_new =            PyType_GenericNew,
  .tp_free =           0, 
  .tp_is_gc =          0, 
  .tp_bases =          0, 
  .tp_mro =            0, 
  .tp_cache =          0, 
  .tp_subclasses =     0, 
  .tp_weaklist =       0, 
  .tp_del =            0, 
  .tp_version_tag =    0, 
  .tp_finalize =       0, 
};

PyTypeObject* CObject_TypePtr = &CObject_Type;





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

    CType_Type.tp_base = (CType*)&CType_Type;

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
