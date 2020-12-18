/*
 * c_species.hpp
 *
 *  Created on: Jun 18, 2020
 *      Author: andy
 */

#ifndef EXTERN_CARBON_SRC_C_SPECIES_HPP_
#define EXTERN_CARBON_SRC_C_SPECIES_HPP_

#include <c_species.h>

namespace libsbml{
    class Species;
    class SBMLNamespaces;
};

struct CSpecies : PyObject {
    libsbml::Species *species;
};


CAPI_FUNC(libsbml::SBMLNamespaces*) C_GetSBMLNamespaces();


CAPI_FUNC(CSpecies*) CSpecies_NewFromPyArgs(PyObject *args, PyObject *kwargs);


PyObject* PySpecies_getId (const libsbml::Species *s);

PyObject* PySpecies_getName (const libsbml::Species *s);

PyObject* PySpecies_getInitialAmount (const libsbml::Species *s);

PyObject* PySpecies_getInitialConcentration (const libsbml::Species *s);

PyObject* PySpecies_getBoundaryCondition (const libsbml::Species *s);

PyObject* PySpecies_getConstant (const libsbml::Species *s);

int PySpecies_setId (libsbml::Species *s, PyObject *str);

int PySpecies_setName (libsbml::Species *s, PyObject *str);

int PySpecies_setInitialAmount (libsbml::Species *s, PyObject *value);

int PySpecies_setInitialConcentration (libsbml::Species *s, PyObject *value);

int PySpecies_setBoundaryCondition (libsbml::Species *s, PyObject *value);

int PySpecies_setConstant (libsbml::Species *s, PyObject *value);



CAPI_DATA(PyTypeObject) CSpecies_Type;

HRESULT _CSpecies_Init(PyObject *m);

#endif /* EXTERN_CARBON_SRC_C_SPECIES_HPP_ */
