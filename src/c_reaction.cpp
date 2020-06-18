/*
 * c_reaction.cpp
 *
 *  Created on: Jun 4, 2020
 *      Author: andy
 */

#include <c_reaction.hpp>

CReaction_t * CReaction_create(unsigned int level,
        unsigned int version)
{
    return 0;
}

void CReaction_free(CReaction_t *r)
{
}

CReaction_t * CReaction_clone(const CReaction_t *r)
{
    return 0;
}

void CReaction_initDefaults(CReaction_t *r)
{
}

const char* CReaction_getId(const CReaction_t *r)
{
    return 0;
}

const char* CReaction_getName(const CReaction_t *r)
{
    return 0;
}

KineticLaw_t * CReaction_getKineticLaw(CReaction_t *r)
{
    return 0;
}

int CReaction_getReversible(const CReaction_t *r)
{
    return 0;
}

int CReaction_getFast(const CReaction_t *r)
{
    return 0;
}

const char* CReaction_getCompartment(const CReaction_t *r)
{
    return 0;
}

int CReaction_isSetId(const CReaction_t *r)
{
    return 0;
}

int CReaction_isSetName(const CReaction_t *r)
{
    return 0;
}

int CReaction_isSetKineticLaw(const CReaction_t *r)
{
    return 0;
}

int CReaction_isSetFast(const CReaction_t *r)
{
    return 0;
}

int CReaction_isSetCompartment(const CReaction_t *r)
{
    return 0;
}

int CReaction_isSetReversible(const CReaction_t *r)
{
    return 0;
}

int CReaction_setId(CReaction_t *r, const char *sid)
{
    return 0;
}

int CReaction_setName(CReaction_t *r, const char *name)
{
    return 0;
}

int CReaction_setKineticLaw(CReaction_t *r, const KineticLaw_t *kl)
{
    return 0;
}

int CReaction_setReversible(CReaction_t *r, int value)
{
    return 0;
}

int CReaction_setFast(CReaction_t *r, int value)
{
    return 0;
}

int CReaction_setCompartment(CReaction_t *r, const char *compartment)
{
    return 0;
}

int CReaction_unsetName(CReaction_t *r)
{
    return 0;
}

int CReaction_unsetCompartment(CReaction_t *r)
{
    return 0;
}

int CReaction_unsetKineticLaw(CReaction_t *r)
{
    return 0;
}

int CReaction_unsetFast(CReaction_t *r)
{
    return 0;
}

int CReaction_unsetReversible(CReaction_t *r)
{
    return 0;
}

int CReaction_hasRequiredAttributes(CReaction_t *r)
{
    return 0;
}

int CReaction_addReactant(CReaction_t *r, const SpeciesReference_t *sr)
{
    return 0;
}

int CReaction_addProduct(CReaction_t *r, const SpeciesReference_t *sr)
{
    return 0;
}

int CReaction_addModifier(CReaction_t *r, const SpeciesReference_t *msr)
{
    return 0;
}

int CReaction_addReactantBySpecies(CReaction_t *r, const Species_t *s,
        double stoichiometry, const char *id, int constant)
{
    return 0;
}

int CReaction_addProductBySpecies(CReaction_t *r, const Species_t *s,
        double stoichiometry, const char *id, int constant)
{
    return 0;
}

int CReaction_addModifierBySpecies(CReaction_t *r, const Species_t *s,
        const char *id)
{
    return 0;
}

SpeciesReference_t * CReaction_createReactant(CReaction_t *r)
{
    return 0;
}

SpeciesReference_t * CReaction_createProduct(CReaction_t *r)
{
    return 0;
}

SpeciesReference_t * CReaction_createModifier(CReaction_t *r)
{
    return 0;
}

KineticLaw_t * CReaction_createKineticLaw(CReaction_t *r)
{
    return 0;
}

ListOf_t * CReaction_getListOfReactants(CReaction_t *r)
{
    return 0;
}

ListOf_t * CReaction_getListOfProducts(CReaction_t *r)
{
    return 0;
}

ListOf_t * CReaction_getListOfModifiers(CReaction_t *r)
{
    return 0;
}

SpeciesReference_t * CReaction_getReactant(CReaction_t *r,
        unsigned int n)
{
    return 0;
}

SpeciesReference_t * CReaction_getReactantBySpecies(CReaction_t *r,
        const char *species)
{
    return 0;
}

SpeciesReference_t * CReaction_getProduct(CReaction_t *r,
        unsigned int n)
{
    return 0;
}

SpeciesReference_t * CReaction_getProductBySpecies(CReaction_t *r,
        const char *species)
{
    return 0;
}

SpeciesReference_t * CReaction_getModifier(CReaction_t *r,
        unsigned int n)
{
    return 0;
}

SpeciesReference_t * CReaction_getModifierBySpecies(CReaction_t *r,
        const char *species)
{
    return 0;
}

unsigned int CReaction_getNumReactants(const CReaction_t *r)
{
    return 0;
}

unsigned int CReaction_getNumProducts(const CReaction_t *r)
{
    return 0;
}

unsigned int CReaction_getNumModifiers(const CReaction_t *r)
{
    return 0;
}

SpeciesReference_t * CReaction_removeReactant(CReaction_t *r,
        unsigned int n)
{
    return 0;
}

SpeciesReference_t * CReaction_removeReactantBySpecies(
        CReaction_t *r, const char *species)
{
    return 0;
}

SpeciesReference_t * CReaction_removeProduct(CReaction_t *r,
        unsigned int n)
{
    return 0;
}

SpeciesReference_t * CReaction_removeProductBySpecies(
        CReaction_t *r, const char *species)
{
    return 0;
}

SpeciesReference_t * CReaction_removeModifier(CReaction_t *r,
        unsigned int n)
{
    return 0;
}

SpeciesReference_t * CReaction_removeModifierBySpecies(
        CReaction_t *r, const char *species)
{
    return 0;
}

CReaction_t * ListOfReactions_getById(ListOf_t *lo, const char *sid)
{
    return 0;
}

CReaction_t * ListOfReactions_removeById(ListOf_t *lo,
        const char *sid)
{
    return 0;
}
