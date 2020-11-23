/*
 * mx_error.cpp
 *
 *  Created on: Oct 3, 2017
 *      Author: andy
 */

#include <cstdio>
#include <carbon.h>
#include <ctype.h>

#ifdef CType
#error CType is macro
#endif



#include <c_error.h>

#ifdef CType
#error CType is macro
#endif



#include <iostream>

#include <sstream>

static CError Error;
static CError *ErrorPtr = NULL;
static uint32_t CError_Opt = CERROR_SET_PYTHON_ERROR;

CAPI_FUNC(HRESULT) CErr_Set(HRESULT code, const char* msg, int line,
		const char* file, const char* func) {
	std::cerr << "error: " << code << ", " << msg << ", " << line << ", " << func << std::endl;

	Error.err = code;
	Error.fname = file;
	Error.func = func;
	Error.msg = msg;

	ErrorPtr = &Error;

	if(CError_Opt & CERROR_SET_PYTHON_ERROR) {
	    std::stringstream ss;
	    ss << "error: " << code << ", " << msg << ", " << line << ", " << func;
	    PyErr_SetString(PyExc_RuntimeError, ss.str().c_str());
	}

	return code;
}
    
CAPI_FUNC(HRESULT) CExp_Set(const std::exception& e, const char* msg, int line, const char* file, const char* func) {
    std::cerr << "error: " << e.what() << ", " << msg << ", " << line << ", " << func << std::endl;
    
    Error.err = E_FAIL;
    Error.fname = file;
    Error.func = func;
    Error.msg = msg;
    
    ErrorPtr = &Error;
    
    if(CError_Opt & CERROR_SET_PYTHON_ERROR) {
        std::stringstream ss;
        ss << "error: " << e.what() << ", " << msg << ", " << line << ", " << func;
        PyErr_SetString(PyExc_RuntimeError, ss.str().c_str());
    }
    
    return E_FAIL;
}






CAPI_FUNC(CError*) CErr_Occurred() {
    return ErrorPtr;
}

CAPI_FUNC(void) CErr_Clear() {
    ErrorPtr = NULL;
}

CAPI_FUNC(void) CErr_SetOptions(uint32_t options) {
    CError_Opt = options;
}
