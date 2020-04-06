/*
 * c_descrobject.h
 *
 *  Created on: Mar 17, 2020
 *      Author: andy
 */

#ifndef EXTERN_CARBON_INCLUDE_C_DESCROBJECT_H_
#define EXTERN_CARBON_INCLUDE_C_DESCROBJECT_H_

#include "Python.h"
#include "structmember.h"
#include <c_port.h>




//typedef struct CMemberDef {
//    const char *name;
//    int type;
//    Py_ssize_t offset;
//    int flags;
//    const char *doc;
//} CMemberDef;

/* Flags */
#define CDESCR_INSTANCE           8
#define CDESCR_TYPE               16

/* Various kinds of descriptor objects */

typedef struct {
    PyObject_HEAD
    PyTypeObject *d_type;
    PyObject *d_name;
    PyObject *d_qualname;
} CDescrObject;

#define CDescr_COMMON CDescrObject d_common


typedef struct {
    CDescr_COMMON;
    struct PyMemberDef d_member;
} CMemberDescrObject;



//
#define CDescr_TYPE(x) (((CDescrObject *)(x))->d_type)
#define CDescr_NAME(x) (((CDescrObject *)(x))->d_name)
//
//typedef struct {
//    PyDescr_COMMON;
//    PyMethodDef *d_method;
//} PyMethodDescrObject;
//
//typedef struct {
//    PyDescr_COMMON;
//    struct PyMemberDef *d_member;
//} PyMemberDescrObject;
//
//typedef struct {
//    PyDescr_COMMON;
//    PyGetSetDef *d_getset;
//} PyGetSetDescrObject;
//
//typedef struct {
//    PyDescr_COMMON;
//    struct wrapperbase *d_base;
//    void *d_wrapped; /* This can be any function pointer */
//} PyWrapperDescrObject;
//#endif /* Py_LIMITED_API */
//
//PyAPI_DATA(PyTypeObject) PyClassMethodDescr_Type;
//PyAPI_DATA(PyTypeObject) PyGetSetDescr_Type;
CAPI_DATA(PyTypeObject) CMemberDescr_Type;
//PyAPI_DATA(PyTypeObject) PyMethodDescr_Type;
//PyAPI_DATA(PyTypeObject) PyWrapperDescr_Type;
//PyAPI_DATA(PyTypeObject) PyDictProxy_Type;
//#ifndef Py_LIMITED_API
//PyAPI_DATA(PyTypeObject) _PyMethodWrapper_Type;
//#endif /* Py_LIMITED_API */
//
//PyAPI_FUNC(PyObject *) PyDescr_NewMethod(PyTypeObject *, PyMethodDef *);
//PyAPI_FUNC(PyObject *) PyDescr_NewClassMethod(PyTypeObject *, PyMethodDef *);
//
//


/**
 *
 */
CAPI_FUNC(PyObject *) CDescr_NewMember(PyTypeObject *,  const PyMemberDef *);


//PyAPI_FUNC(PyObject *) PyDescr_NewGetSet(PyTypeObject *,
//                                               struct PyGetSetDef *);
//#ifndef Py_LIMITED_API
//
//PyAPI_FUNC(PyObject *) _PyMethodDescr_FastCallKeywords(
//        PyObject *descrobj, PyObject *const *stack, Py_ssize_t nargs, PyObject *kwnames);
//PyAPI_FUNC(PyObject *) PyDescr_NewWrapper(PyTypeObject *,
//                                                struct wrapperbase *, void *);
//#define PyDescr_IsData(d) (Py_TYPE(d)->tp_descr_set != NULL)
//#endif
//
//PyAPI_FUNC(PyObject *) PyDictProxy_New(PyObject *);
//PyAPI_FUNC(PyObject *) PyWrapper_New(PyObject *, PyObject *);
//
//
//PyAPI_DATA(PyTypeObject) PyProperty_Type;






#endif /* EXTERN_CARBON_INCLUDE_C_DESCROBJECT_H_ */
