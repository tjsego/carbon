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


enum StateVectorFlags {
    STATEVECTOR_NONE            = 0,
    STATEVECTOR_OWNMEMORY       = 1 << 0,
};


struct CStateVector : PyObject {
    uint32_t flags;
    uint32_t size;
    struct CSpeciesList *species;
    
    /**
     * owner of this state vector, usually a
     * MxParticle, but we leave the door open for other
     * kinds of things.
     */
    PyObject *owner;
    
    void* data;
    
    // vector of values
    union {
        float *fvec;
        double *dvec;
    };
    
    // vector of fluxes
    float *q;
    
    // vector of species flags
    uint32_t *species_flags;
};


/**
 * make a new state vector,
 * owner can be null, if given, we borrow a reference.
 *
 * If we are given an existing state vector, we find any mathcing species
 * and copy thier *values* over. 
 */
CAPI_FUNC(CStateVector*) CStateVector_New(struct CSpeciesList *species,
                                          PyObject *owner,
                                          CStateVector *existingStateVector,
                                          uint32_t flags,
                                          uint32_t size,
                                          void* data);

CAPI_DATA(PyTypeObject) CStateVector_Type;

HRESULT _CStateVector_Init(PyObject *m);

#endif /* CStateVector_hpp */
