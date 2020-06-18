/*
 * c_kineticlaw.cpp
 *
 *  Created on: Jun 4, 2020
 *      Author: andy
 */

#include <c_kineticlaw.hpp>

CKineticLaw_t * CKineticLaw_create(unsigned int level,
        unsigned int version)
{
    return 0;
}

void CKineticLaw_free(CKineticLaw_t *kl)
{
}

CKineticLaw_t * CKineticLaw_clone(const CKineticLaw_t *kl)
{
    return 0;
}

const char* CKineticLaw_getFormula(const CKineticLaw_t *kl)
{
    return 0;
}

const ASTNode_t * CKineticLaw_getMath(const CKineticLaw_t* kl)
{
    return 0;
}

const char* CKineticLaw_getTimeUnits(const CKineticLaw_t *kl)
{
    return 0;
}

const char* CKineticLaw_getSubstanceUnits(const CKineticLaw_t *kl)
{
    return 0;
}

int CKineticLaw_isSetFormula(const CKineticLaw_t *kl)
{
    return 0;
}

int CKineticLaw_isSetMath(const CKineticLaw_t *kl)
{
    return 0;
}

int CKineticLaw_isSetTimeUnits(const CKineticLaw_t *kl)
{
    return 0;
}

int CKineticLaw_isSetSubstanceUnits(const CKineticLaw_t *kl)
{
    return 0;
}

int CKineticLaw_setFormula(CKineticLaw_t *kl, const char *formula)
{
    return 0;
}

int CKineticLaw_setMath(CKineticLaw_t *kl, const ASTNode_t *math)
{
    return 0;
}

int CKineticLaw_setTimeUnits(CKineticLaw_t *kl, const char *sid)
{
    return 0;
}

int CKineticLaw_setSubstanceUnits(CKineticLaw_t *kl, const char *sid)
{
    return 0;
}

int CKineticLaw_unsetTimeUnits(CKineticLaw_t *kl)
{
    return 0;
}

int CKineticLaw_unsetSubstanceUnits(CKineticLaw_t *kl)
{
    return 0;
}

int CKineticLaw_addParameter(CKineticLaw_t *kl, const Parameter_t *p)
{
    return 0;
}

int CKineticLaw_addLocalParameter(CKineticLaw_t *kl, const LocalParameter_t *p)
{
    return 0;
}

Parameter_t * CKineticLaw_createParameter(CKineticLaw_t *kl)
{
    return 0;
}

LocalParameter_t * CKineticLaw_createLocalParameter(
        CKineticLaw_t *kl)
{
    return 0;
}

ListOf_t * CKineticLaw_getListOfParameters(CKineticLaw_t *kl)
{
    return 0;
}

ListOf_t * CKineticLaw_getListOfLocalParameters(CKineticLaw_t *kl)
{
    return 0;
}

Parameter_t * CKineticLaw_getParameter(CKineticLaw_t *kl,
        unsigned int n)
{
    return 0;
}

LocalParameter_t * CKineticLaw_getLocalParameter(CKineticLaw_t *kl,
        unsigned int n)
{
    return 0;
}

Parameter_t * CKineticLaw_getParameterById(CKineticLaw_t *kl,
        const char *sid)
{
    return 0;
}

LocalParameter_t * CKineticLaw_getLocalParameterById(
        CKineticLaw_t *kl, const char *sid)
{
    return 0;
}

unsigned int CKineticLaw_getNumParameters(const CKineticLaw_t *kl)
{
    return 0;
}

unsigned int CKineticLaw_getNumLocalParameters(const CKineticLaw_t *kl)
{
    return 0;
}

UnitDefinition_t * CKineticLaw_getDerivedUnitDefinition(
        CKineticLaw_t *kl)
{
    return 0;
}

int CKineticLaw_containsUndeclaredUnits(CKineticLaw_t *kl)
{
    return 0;
}

Parameter_t * CKineticLaw_removeParameter(CKineticLaw_t *kl,
        unsigned int n)
{
    return 0;
}

LocalParameter_t * CKineticLaw_removeLocalParameter(
        CKineticLaw_t *kl, unsigned int n)
{
    return 0;
}

Parameter_t * CKineticLaw_removeParameterById(CKineticLaw_t *kl,
        const char *sid)
{
    return 0;
}

LocalParameter_t * CKineticLaw_removeLocalParameterById(
        CKineticLaw_t *kl, const char *sid)
{
    return 0;
}
