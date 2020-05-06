/*
 * c_event.h
 *
 *  Created on: Mar 30, 2020
 *      Author: andy
 */

#ifndef EXTERN_CARBON_INCLUDE_C_EVENT_H_
#define EXTERN_CARBON_INCLUDE_C_EVENT_H_

#include <c_port.h>
#include <Python.h>

/**
 * Basic opaque Event object type (it's actually a PyObject)
 */
CAPI_STRUCT(CEvent);


CEvent *CEvent_New();

HRESULT CEvent_Invoke(PyObject *args, PyObject *kw_args);

HRESULT CEvent_AddDelegate(PyObject *delegate);

HRESULT CEvent_RemoveDelegate(PyObject *delegate);





#endif /* EXTERN_CARBON_INCLUDE_C_EVENT_H_ */
