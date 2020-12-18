/*
 * CSpeciesList.hpp
 *
 *  Created on: Dec 16, 2020
 *      Author: andy
 */

#ifndef EXTERN_CARBON_SRC_CSpeciesList_HPP_
#define EXTERN_CARBON_SRC_CSpeciesList_HPP_

#include <c_port.h>
#include <vector>

struct CSpecies;

struct CSpeciesList : PyObject
{
    std::vector<CSpecies*> species;
};

CAPI_FUNC(CSpeciesList*) CSpeciesList_NewFromPyArgs(PyObject *args);

CAPI_DATA(PyTypeObject) CSpeciesList_Type;

HRESULT _CSpeciesList_Init(PyObject *m);

#endif /* EXTERN_CARBON_SRC_CSpeciesList_HPP_ */
