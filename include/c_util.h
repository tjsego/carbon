/*
 * c_util.h
 *
 *  Created on: Jun 30, 2020
 *      Author: andy
 */

#ifndef EXTERN_CARBON_INCLUDE_C_UTIL_H_
#define EXTERN_CARBON_INCLUDE_C_UTIL_H_

#include <c_port.h>

/**
 * Determine if dictionary p contains key. If an item in p is matches key,
 * return 1, otherwise return 0. On error, return -1. This is equivalent to the
 * Python expression key in p.
 *
 * char* wrapper for PyDict_Contains
 */
CAPI_FUNC(int) CDict_ContainsItemString(PyObject *p, const char *key);


#ifdef __cplusplus

#include <random>


typedef std::mt19937 CRandomType;

CAPI_DATA(CRandomType) CRandom;

#endif




#endif /* EXTERN_CARBON_INCLUDE_C_UTIL_H_ */
