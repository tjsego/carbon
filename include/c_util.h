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
// windows
#define CAligned_Malloc(size,  alignment) _aligned_malloc(size,  alignment)
#define CAligned_Free(mem) _aligned_free(mem)
#elif __APPLE__
// mac
inline void* CAligned_Malloc(size_t size, size_t alignment)
{
    enum {
        void_size = sizeof(void*)
    };
    if (!size) {
        return 0;
    }
    if (alignment < void_size) {
        alignment = void_size;
    }
    void* p;
    if (::posix_memalign(&p, alignment, size) != 0) {
        p = 0;
    }
    return p;
}
#define CAligned_Free(mem) free(mem)
#else
// linux
#define CAligned_Malloc(size,  alignment) aligned_alloc(alignment,  size)
#define CAligned_Free(mem) free(mem)
#endif


#ifdef __cplusplus

#include <random>


typedef std::mt19937 CRandomType;

CAPI_DATA(CRandomType) CRandom;


/**
 * Grab the IPython object, NULL if does not exist
 */
CAPI_FUNC(PyObject*) CIPython_Get();


CAPI_FUNC(PyObject*) C_CmdLineArgsForPid(PyObject *pid);



#endif




#endif /* EXTERN_CARBON_INCLUDE_C_UTIL_H_ */
