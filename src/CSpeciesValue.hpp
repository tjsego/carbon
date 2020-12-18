/*
 * CSpeciesValue.hpp
 *
 *  Created on: Dec 16, 2020
 *      Author: andy
 */

#ifndef EXTERN_CARBON_SRC_CSPECIESVALUE_HPP_
#define EXTERN_CARBON_SRC_CSPECIESVALUE_HPP_

#include <c_port.h>
#include <CSpecies.hpp>

struct CSpeciesValue : PyFloatObject
{
    struct CStateVector *state_vector;
    uint32_t index;
};

CAPI_FUNC(CSpeciesValue*) CSpeciesValue_New(double value, struct CStateVector *sv, uint32_t index);

CAPI_DATA(PyTypeObject) CSpeciesValue_Type;

HRESULT _CSpeciesValue_Init(PyObject *m);

#endif /* EXTERN_CARBON_SRC_CSPECIESVALUE_HPP_ */
