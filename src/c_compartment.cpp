/*
 * c_compartment.cpp
 *
 *  Created on: Jun 5, 2020
 *      Author: andy
 */

#include <c_compartment.hpp>
#include <sbml/Compartment.h>

CCompartment_t * CCompartment_create()
{
    libsbml::Compartment *c = new libsbml::Compartment(2, 1);
    CCompartment_t *result = new CCompartment_t();
    result->sbml_obj = c;
    return result;
}

void CCompartment_free(CCompartment_t *c)
{
}

CCompartment_t * CCompartment_clone(const CCompartment_t *c)
{
    return 0;
}

void CCompartment_initDefaults(CCompartment_t *c)
{
}

const char* CCompartment_getId(const CCompartment_t *c)
{
    return 0;
}

const char* CCompartment_getName(const CCompartment_t *c)
{
    return 0;
}

const char* CCompartment_getCompartmentType(const CCompartment_t *c)
{
    return 0;
}

unsigned int CCompartment_getSpatialDimensions(const CCompartment_t *c)
{
    return 0;
}

double CCompartment_getSpatialDimensionsAsDouble(const CCompartment_t *c)
{
    return 0;
}

double CCompartment_getSize(const CCompartment_t *c)
{
    return 0;
}

double CCompartment_getVolume(const CCompartment_t *c)
{
    return 0;
}

const char* CCompartment_getUnits(const CCompartment_t *c)
{
    return 0;
}

const char* CCompartment_getOutside(const CCompartment_t *c)
{
    return 0;
}

int CCompartment_getConstant(const CCompartment_t *c)
{
    return 0;
}

int CCompartment_isSetId(const CCompartment_t *c)
{
    return 0;
}

int CCompartment_isSetName(const CCompartment_t *c)
{
    return 0;
}

int CCompartment_isSetCompartmentType(const CCompartment_t *c)
{
    return 0;
}

int CCompartment_isSetSize(const CCompartment_t *c)
{
    return 0;
}

int CCompartment_isSetVolume(const CCompartment_t *c)
{
    return 0;
}

int CCompartment_isSetUnits(const CCompartment_t *c)
{
    return 0;
}

int CCompartment_isSetOutside(const CCompartment_t *c)
{
    return 0;
}

int CCompartment_isSetSpatialDimensions(const CCompartment_t *c)
{
    return 0;
}

int CCompartment_isSetConstant(const CCompartment_t *c)
{
    return 0;
}

int CCompartment_setId(CCompartment_t *c, const char *sid)
{
    return 0;
}

int CCompartment_setName(CCompartment_t *c, const char *name)
{
    return 0;
}

int CCompartment_setCompartmentType(CCompartment_t *c, const char *sid)
{
    return 0;
}

int CCompartment_setSpatialDimensions(CCompartment_t *c, unsigned int value)
{
    return 0;
}

int CCompartment_setSpatialDimensionsAsDouble(CCompartment_t *c, double value)
{
    return 0;
}

int CCompartment_setSize(CCompartment_t *c, double value)
{
    return 0;
}

int CCompartment_setVolume(CCompartment_t *c, double value)
{
    return 0;
}

int CCompartment_setUnits(CCompartment_t *c, const char *sid)
{
    return 0;
}

int CCompartment_setOutside(CCompartment_t *c, const char *sid)
{
    return 0;
}

int CCompartment_setConstant(CCompartment_t *c, int value)
{
    return 0;
}

int CCompartment_unsetName(CCompartment_t *c)
{
    return 0;
}

int CCompartment_unsetCompartmentType(CCompartment_t *c)
{
    return 0;
}

int CCompartment_unsetConstant(CCompartment_t *c)
{
    return 0;
}

int CCompartment_unsetSize(CCompartment_t *c)
{
    return 0;
}

int CCompartment_unsetVolume(CCompartment_t *c)
{
    return 0;
}

int CCompartment_unsetUnits(CCompartment_t *c)
{
    return 0;
}

int CCompartment_unsetOutside(CCompartment_t *c)
{
    return 0;
}

int CCompartment_unsetSpatialDimensions(CCompartment_t *c)
{
    return 0;
}

CUnitDefinition_t * CCompartment_getDerivedUnitDefinition(
        CCompartment_t *c)
{
    return 0;
}

int CCompartment_hasRequiredAttributes(CCompartment_t *c)
{
    return 0;
}
