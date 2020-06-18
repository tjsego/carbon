/*
 * c_speciesreference.cpp
 *
 *  Created on: Jun 4, 2020
 *      Author: andy
 */

#include <c_speciesreference.hpp>

CSpeciesReference_t * CSpeciesReference_create(unsigned int level,
        unsigned int version)
{
    return 0;
}

CSpeciesReference_t * CSpeciesReference_createModifier(
        unsigned int level, unsigned int version)
{
    return 0;
}

void CSpeciesReference_free(CSpeciesReference_t *sr)
{
}

CSpeciesReference_t * CSpeciesReference_clone(
        const CSpeciesReference_t *sr)
{
    return 0;
}

void CSpeciesReference_initDefaults(CSpeciesReference_t *sr)
{
}

int CSpeciesReference_isModifier(const CSpeciesReference_t *sr)
{
    return 0;
}

const char* CSpeciesReference_getId(const CSpeciesReference_t *sr)
{
    return 0;
}

const char* CSpeciesReference_getName(const CSpeciesReference_t *sr)
{
    return 0;
}

const char* CSpeciesReference_getSpecies(const CSpeciesReference_t *sr)
{
    return 0;
}

double CSpeciesReference_getStoichiometry(const CSpeciesReference_t *sr)
{
    return 0;
}

StoichiometryMath_t * CSpeciesReference_getStoichiometryMath(
        CSpeciesReference_t *sr)
{
    return 0;
}

int CSpeciesReference_getDenominator(const CSpeciesReference_t *sr)
{
    return 0;
}

int CSpeciesReference_getConstant(const CSpeciesReference_t *sr)
{
    return 0;
}

int CSpeciesReference_isSetId(const CSpeciesReference_t *sr)
{
    return 0;
}

int CSpeciesReference_isSetName(const CSpeciesReference_t *sr)
{
    return 0;
}

int CSpeciesReference_isSetSpecies(const CSpeciesReference_t *sr)
{
    return 0;
}

int CSpeciesReference_isSetStoichiometryMath(const CSpeciesReference_t *sr)
{
    return 0;
}

int CSpeciesReference_isSetStoichiometry(const CSpeciesReference_t *sr)
{
    return 0;
}

int CSpeciesReference_isSetConstant(const CSpeciesReference_t *sr)
{
    return 0;
}

int CSpeciesReference_setId(CSpeciesReference_t *sr, const char *sid)
{
    return 0;
}

int CSpeciesReference_setName(CSpeciesReference_t *sr, const char *name)
{
    return 0;
}

int CSpeciesReference_setSpecies(CSpeciesReference_t *sr, const char *sid)
{
    return 0;
}

int CSpeciesReference_setStoichiometry(CSpeciesReference_t *sr, double value)
{
    return 0;
}

StoichiometryMath_t * CSpeciesReference_createStoichiometryMath(
        CSpeciesReference_t *sr)
{
    return 0;
}

int CSpeciesReference_setStoichiometryMath(CSpeciesReference_t *sr,
        const StoichiometryMath_t *math)
{
    return 0;
}

int CSpeciesReference_setDenominator(CSpeciesReference_t *sr, int value)
{
    return 0;
}

int CSpeciesReference_setConstant(CSpeciesReference_t *sr, int value)
{
    return 0;
}

int CSpeciesReference_unsetId(CSpeciesReference_t *sr)
{
    return 0;
}

int CSpeciesReference_unsetName(CSpeciesReference_t *sr)
{
    return 0;
}

int CSpeciesReference_unsetSpecies(CSpeciesReference_t *sr)
{
    return 0;
}

int CSpeciesReference_unsetConstant(CSpeciesReference_t *sr)
{
    return 0;
}

int CSpeciesReference_unsetStoichiometryMath(CSpeciesReference_t *sr)
{
    return 0;
}

int CSpeciesReference_unsetStoichiometry(CSpeciesReference_t *sr)
{
    return 0;
}

int CSpeciesReference_hasRequiredAttributes(CSpeciesReference_t *sr)
{
    return 0;
}

CSpeciesReference_t * ListOfSpeciesReferences_getById(ListOf_t *lo,
        const char *sid)
{
    return 0;
}

CSpeciesReference_t * ListOfSpeciesReferences_removeById(
        ListOf_t *lo, const char *sid)
{
    return 0;
}
