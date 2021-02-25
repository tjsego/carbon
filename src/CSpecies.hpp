/*
 * c_species.hpp
 *
 *  Created on: Jun 18, 2020
 *      Author: andy
 */

#ifndef EXTERN_CARBON_SRC_C_SPECIES_HPP_
#define EXTERN_CARBON_SRC_C_SPECIES_HPP_

#include <c_species.h>
#include <string>

namespace libsbml{
    class Species;
    class SBMLNamespaces;
};



struct CSpecies : PyObject {
    libsbml::Species *species;
    int32_t flags() const;
    const std::string& getId () const;
};


CAPI_FUNC(libsbml::SBMLNamespaces*) C_GetSBMLNamespaces();


CAPI_FUNC(CSpecies*) CSpecies_NewFromPyArgs(PyObject *args, PyObject *kwargs);


PyObject* PySpecies_getId (const CSpecies *s);

PyObject* PySpecies_getName (const CSpecies *s);

PyObject* PySpecies_getInitialAmount (const CSpecies *s);

PyObject* PySpecies_getInitialConcentration (const CSpecies *s);

PyObject* PySpecies_getBoundaryCondition (const CSpecies *s);

PyObject* PySpecies_getConstant (const CSpecies *s);

PyObject* PySpecies_getHasOnlySubstanceUnits (const CSpecies *s);

int PySpecies_setId (CSpecies *s, PyObject *str);

int PySpecies_setName (CSpecies *s, PyObject *str);

int PySpecies_setInitialAmount (CSpecies *s, PyObject *value);

int PySpecies_setInitialConcentration (CSpecies *s, PyObject *value);

int PySpecies_setBoundaryCondition (CSpecies *s, PyObject *value);

int PySpecies_setConstant (CSpecies *s, PyObject *value);

int PySpecies_setHasOnlySubstanceUnits (const CSpecies *s, PyObject *value);



CAPI_DATA(PyTypeObject) CSpecies_Type;

HRESULT _CSpecies_Init(PyObject *m);

#endif /* EXTERN_CARBON_SRC_C_SPECIES_HPP_ */
