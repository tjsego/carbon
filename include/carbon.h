/*
 * carbon.h
 *
 *  Created on: Jun 30, 2015
 *      Author: andy
 */

#ifndef _INCLUDED_CARBON_H_
#define _INCLUDED_CARBON_H_


#include <Python.h>
#include <c_port.h>
#include <c_object.h>
#include <c_type.h>

#ifdef __cplusplus
#include <c_object.hpp>
#endif

/**
 * Initialize the entire runtime.
 *
 * Callers of the Carbon lib need to initialize it, this creates the Python
 * module and also initializes Python if not already initialized.
 */
CAPI_FUNC(HRESULT) C_Initialize(int);


/**
 * Shutdown and cleanup.
 */
CAPI_FUNC(HRESULT) C_Finalize();

#endif /* _INCLUDED_CARBON_H_ */
