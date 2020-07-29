/*
 * c_util.h
 *
 *  Created on: Jun 30, 2020
 *      Author: andy
 */

#ifndef EXTERN_CARBON_INCLUDE_C_UTIL_H_
#define EXTERN_CARBON_INCLUDE_C_UTIL_H_

#include <c_port.h>
#include <stdint.h>
#include <stdlib.h>

/**
 * Determine if dictionary p contains key. If an item in p is matches key,
 * return 1, otherwise return 0. On error, return -1. This is equivalent to the
 * Python expression key in p.
 *
 * char* wrapper for PyDict_Contains
 */
CAPI_FUNC(int) CDict_ContainsItemString(PyObject *p, const char *key);


CAPI_FUNC(HRESULT) CMath_FindPrimes(uint64_t start_prime, int n, uint64_t *result);

CAPI_FUNC(uint64_t) CMath_NextPrime(uint64_t start_prime);


#ifdef _WIN32
#define CAligned_Malloc(size,  alignment) _aligned_malloc(size,  alignment)
#define CAligned_Free(mem) _aligned_free(mem)
#else
#define CAligned_Malloc(size,  alignment) aligned_alloc(alignment,  size)
#define CAligned_Free(mem) free(mem)
#endif


#ifdef __cplusplus

#include <random>


typedef std::mt19937 CRandomType;

CAPI_DATA(CRandomType) CRandom;

#endif




#endif /* EXTERN_CARBON_INCLUDE_C_UTIL_H_ */