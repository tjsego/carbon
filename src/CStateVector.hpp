//
//  CStateVector.hpp
//  CorradeInterconnect
//
//  Created by Andy Somogyi on 12/16/20.
//

#ifndef CStateVector_hpp
#define CStateVector_hpp

#include <c_port.h>
#include <stdio.h>

struct CStateVector : PyObject {
    uint32_t flags;
    uint32_t size;
    struct CSpeciesList *species;
    
    // vector of values
    union {
        float *fvec;
        double *dvec;
    };
    
    // vector of fluxes
    float *q;
};


CAPI_FUNC(CStateVector*) CStateVector_New(struct CSpeciesList *species, uint32_t flags, uint32_t size, void* data);

CAPI_DATA(PyTypeObject) CStateVector_Type;

HRESULT _CStateVector_Init(PyObject *m);

#endif /* CStateVector_hpp */
