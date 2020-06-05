/*
 * c_reaction.h
 *
 *  Created on: Jun 4, 2020
 *      Author: andy
 *
 * copy of the libSBML API, originally written by Ben Bornstein
 */

#ifndef EXTERN_CARBON_INCLUDE_C_REACTION_H_
#define EXTERN_CARBON_INCLUDE_C_REACTION_H_

#include <c_port.h>

CAPI_STRUCT(Species_t);
CAPI_STRUCT(CReaction_t);
CAPI_STRUCT(KineticLaw_t);
CAPI_STRUCT(SpeciesReference_t);
CAPI_STRUCT(ListOf_t);

/**
 * Creates a new CReaction_t structure using the given SBML @p level
 * and @p version values.
 *
 * @param level an unsigned int, the SBML Level to assign to this
 * CReaction_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * CReaction_t.
 *
 * @return a pointer to the newly created CReaction_t structure.
 *
 * @copydetails doc_note_setting_lv
 *
 * @memberof CReaction_t
 */
CAPI_FUNC(CReaction_t *) CReaction_create (unsigned int level, unsigned int version);


/**
 * Creates a new CReaction_t structure using the given
 * SBMLNamespaces_t structure.
 *
 * @param sbmlns SBMLNamespaces_t, a pointer to an SBMLNamespaces_t structure
 * to assign to this CReaction_t.
 *
 * @return a pointer to the newly created CReaction_t structure.
 *
 * @copydetails doc_note_setting_lv
 *
 * @memberof CReaction_t
 */
//CAPI_FUNC(CReaction_t *) CReaction_createWithNS (SBMLNamespaces_t *sbmlns);


/**
 * Frees the given CReaction_t.
 *
 * @memberof CReaction_t
 */
CAPI_FUNC(void) CReaction_free (CReaction_t *r);


/**
 * @return a (deep) copy of this CReaction_t.
 *
 * @memberof CReaction_t
 */
CAPI_FUNC(CReaction_t *) CReaction_clone (const CReaction_t *r);


/**
 * Initializes the fields of this CReaction_t to their defaults:
 *
 * The SBML Reaction component has slightly different aspects and
 * default attribute values in different SBML Levels and Versions.
 * This method sets the values to certain common defaults, based
 * mostly on what they are in SBML Level&nbsp;2.  Specifically:
 *
 * @li Sets the "reversible" attribute to @c true
 * @li Sets the "fast" attribute to @c false
 * @li Marks the "fast" attribute as @em not having been set for
 *     SBML Level&nbsp;2, but @em as having been set for
 *     SBML Level&nbsp;1 and SBML Level&nbsp;3.
 *
 * @copydetails doc_warning_reaction_cant_ignore_fast
 *
 * @memberof CReaction_t
 */
CAPI_FUNC(void) CReaction_initDefaults (CReaction_t *r);


/**
 * Returns a list of XMLNamespaces_t associated with this CReaction_t
 * structure.
 *
 * @param r the CReaction_t structure.
 *
 * @return pointer to the XMLNamespaces_t structure associated with
 * this structure
 *
 * @memberof CReaction_t
 */
//CAPI_FUNC(const XMLNamespaces_t *) CReaction_getNamespaces(CReaction_t *r);


/**
 * @return the id of this CReaction_t.
 *
 * @memberof CReaction_t
 */
CAPI_FUNC(const char *) CReaction_getId (const CReaction_t *r);


/**
 * @return the name of this CReaction_t.
 *
 * @memberof CReaction_t
 */
CAPI_FUNC(const char *) CReaction_getName (const CReaction_t *r);


/**
 * @return the KineticLaw_t of this CReaction_t.
 *
 * @memberof CReaction_t
 */
CAPI_FUNC(KineticLaw_t *) CReaction_getKineticLaw (CReaction_t *r);


/**
 * @return the reversible status of this CReaction_t.
 *
 * @memberof CReaction_t
 */
CAPI_FUNC(int) CReaction_getReversible (const CReaction_t *r);


/**
 * @return the fast status of this CReaction_t.
 *
 * @copydetails doc_fast_attribute_removed
 *
 * @memberof CReaction_t
 */
CAPI_FUNC(int) CReaction_getFast (const CReaction_t *r);


/**
 * @return the compartment of this CReaction_t.
 *
 * @memberof CReaction_t
 */
CAPI_FUNC(const char *) CReaction_getCompartment (const CReaction_t *r);


/**
 * @return @c 1 (true) if the id of this CReaction_t is set,
 * @c 0 (false) otherwise.
 *
 * @memberof CReaction_t
 */
CAPI_FUNC(int) CReaction_isSetId (const CReaction_t *r);


/**
 * @return @c 1 (true) if the name of this CReaction_t is set,
 * @c 0 (false) otherwise.
 *
 * @memberof CReaction_t
 */
CAPI_FUNC(int) CReaction_isSetName (const CReaction_t *r);


/**
 * @return @c 1 (true) if the KineticLaw_t of this CReaction_t is set,
 * @c 0 (false) otherwise.
 *
 * @memberof CReaction_t
 */
CAPI_FUNC(int) CReaction_isSetKineticLaw (const CReaction_t *r);


/**
 * @return @c 1 (true) if the fast status of this CReaction_t is set,
 * @c 0 (false) otherwise.
 *
 * In L1, fast is optional with a default of false, which means it is
 * effectively always set.  In L2, however, fast is optional with no
 * default value, so it may or may not be set to a specific value.
 *
 * @copydetails doc_fast_attribute_removed
 *
 * @memberof CReaction_t
 */
CAPI_FUNC(int) CReaction_isSetFast (const CReaction_t *r);


/**
 * @return @c 1 (true) if the KineticLaw_t of this CReaction_t is set,
 * @c 0 (false) otherwise.
 *
 * @memberof CReaction_t
 */
CAPI_FUNC(int) CReaction_isSetCompartment (const CReaction_t *r);


/**
 * @return @c 1 (true) if the reversible attribute of this CReaction_t is set,
 * @c 0 (false) otherwise.
 *
 * @memberof CReaction_t
 */
CAPI_FUNC(int) CReaction_isSetReversible (const CReaction_t *r);


/**
 * Sets the id of this CReaction_t to a copy of @p sid.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @note Using this function with an @p sid of NULL is equivalent to
 * unsetting the "id" attribute.
 *
 * @memberof CReaction_t
 */
CAPI_FUNC(int) CReaction_setId (CReaction_t *r, const char *sid);


/**
 * Sets the name of this CReaction_t to a copy of name.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @note Using this function with the name set to NULL is equivalent to
 * unsetting the "name" attribute.
 *
 * @memberof CReaction_t
 */
CAPI_FUNC(int) CReaction_setName (CReaction_t *r, const char *name);


/**
 * Sets the KineticLaw_t of this CReaction_t to a copy of the given KineticLaw_t.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_LEVEL_MISMATCH, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_VERSION_MISMATCH, OperationReturnValues_t}
 *
 * @memberof CReaction_t
 */
CAPI_FUNC(int) CReaction_setKineticLaw (CReaction_t *r, const KineticLaw_t *kl);


/**
 * Sets the reversible status of this CReaction_t to value (boolean).
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof CReaction_t
 */
CAPI_FUNC(int) CReaction_setReversible (CReaction_t *r, int value);


/**
 * Sets the fast status of this CReaction_t to value (boolean).
 *
 * @copydetails doc_fast_attribute_removed
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_UNEXPECTED_ATTRIBUTE, OperationReturnValues_t}
 *
 * @memberof CReaction_t
 */
CAPI_FUNC(int) CReaction_setFast (CReaction_t *r, int value);


/**
 * Sets the compartment of this CReaction_t to a copy of compartment.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_UNEXPECTED_ATTRIBUTE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @note Using this function with the compartment set to NULL is equivalent to
 * unsetting the "compartment" attribute.
 *
 * @memberof CReaction_t
 */
CAPI_FUNC(int) CReaction_setCompartment (CReaction_t *r, const char *compartment);


/**
 * Unsets the name of this CReaction_t.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof CReaction_t
 */
CAPI_FUNC(int) CReaction_unsetName (CReaction_t *r);


/**
 * Unsets the compartment of this CReaction_t.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_UNEXPECTED_ATTRIBUTE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof CReaction_t
 */
CAPI_FUNC(int) CReaction_unsetCompartment (CReaction_t *r);


/**
 * Unsets the KineticLaw_t of this CReaction_t.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof CReaction_t
 */
CAPI_FUNC(int) CReaction_unsetKineticLaw (CReaction_t *r);


/**
 * Unsets the fast status of this Reation_t.
 *
 * @copydetails doc_fast_attribute_removed
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_UNEXPECTED_ATTRIBUTE, OperationReturnValues_t}
 *
 * In L1, fast is optional with a default of false, which means it is
 * effectively always set.  In L2, however, fast is optional with no
 * default value, so it may or may not be set to a specific value.
 *
 * @memberof CReaction_t
 */
CAPI_FUNC(int) CReaction_unsetFast (CReaction_t *r);


/**
 * Unsets the reversible status of this CReaction_t.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_UNEXPECTED_ATTRIBUTE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof CReaction_t
 */
CAPI_FUNC(int) CReaction_unsetReversible (CReaction_t *r);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether
 * all the required attributes for this CReaction_t structure
 * have been set.
 *
 * The required attributes for a CReaction_t structure are:
 * @li "id" (or "name" in SBML Level&nbsp;1)
 * @li "fast" (in Level&nbsp;3 Version&nbsp;1 only, where it is defined as a required attribute)
 * @li "reversible" (in Level&nbsp;3 only, where it is defined as a required attribute)
 *
 * @param r the CReaction_t structure to check.
 *
 * @return @c 1 (true) if all the required
 * attributes for this structure have been defined, @c 0 (false) otherwise.
 *
 * @memberof CReaction_t
 */
CAPI_FUNC(int) CReaction_hasRequiredAttributes (CReaction_t *r);


/**
 * Adds a copy of the given reactant (SpeciesReference_t) to this CReaction_t.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_LEVEL_MISMATCH, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_VERSION_MISMATCH, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof CReaction_t
 */
CAPI_FUNC(int) CReaction_addReactant (CReaction_t *r, const SpeciesReference_t *sr);


/**
 * Adds a copy of the given product (SpeciesReference_t) to this CReaction_t.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_LEVEL_MISMATCH, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_VERSION_MISMATCH, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof CReaction_t
 */
CAPI_FUNC(int) CReaction_addProduct (CReaction_t *r, const SpeciesReference_t *sr);


/**
 * Adds a copy of the given modifier (modifier SpeciesReference_t) to this
 * CReaction_t.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_UNEXPECTED_ATTRIBUTE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_LEVEL_MISMATCH, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_VERSION_MISMATCH, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof CReaction_t
 */
CAPI_FUNC(int) CReaction_addModifier (CReaction_t *r, const SpeciesReference_t *msr);

/**
 * Adds a copy of the given Species_t object as a reactant to this CReaction_t.
 *
 * @param r the CReaction_t structure to which the reactant is added.
 * @param s the Species_t structure to be added as reactant.
 * @param stoichiometry the stoichiometry of the added reactant.
 * @param id the string to be used as the id of the SpeciesReference_t that will
 *        be created.
 * @param constant an attribute specifying whether the created SpeciesReference_t is
 *        constant or not.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_LEVEL_MISMATCH, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_VERSION_MISMATCH, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @note the Species_t structure itself is NOT added to the model
 *
 * @memberof CReaction_t
 */
CAPI_FUNC(int) CReaction_addReactantBySpecies (CReaction_t *r, const Species_t *s,
                               double stoichiometry, const char *id,
                               int constant);


/**
 * Adds a copy of the given Species_t object as a product to this CReaction_t.
 *
 * @param r the CReaction_t structure to which the product is added.
 * @param s the Species_t structure to be added as product.
 * @param stoichiometry the stoichiometry of the added product.
 * @param id the string to be used as the id of the SpeciesReference_t that will
 *        be created.
 * @param constant an attribute specifying whether the SpeciesReference_t is
 *        constant or not.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_LEVEL_MISMATCH, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_VERSION_MISMATCH, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @note the Species_t structure itself is NOT added to the model
 *
 * @memberof CReaction_t
 */
CAPI_FUNC(int) CReaction_addProductBySpecies (CReaction_t *r, const Species_t *s,
                               double stoichiometry, const char *id,
                               int constant);


/**
 * Adds a copy of the given Species_t object as a modifier to this CReaction_t.
 *
 * @param r the CReaction_t structure to which the modifier is added.
 * @param s the Species_t structure to be added as modifier.
 * @param id the string to be used as the id of the SpeciesReference_t that will
 *        be created.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_LEVEL_MISMATCH, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_VERSION_MISMATCH, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @note the Species_t structure itself is NOT added to the model
 *
 * @memberof CReaction_t
 */
CAPI_FUNC(int) CReaction_addModifierBySpecies (CReaction_t *r, const Species_t *s,
                               const char *id);


/**
 * Creates a new SpeciesReference, adds it to this CReaction_t's list of
 * reactants and returns it.
 *
 * @memberof CReaction_t
 */
CAPI_FUNC(SpeciesReference_t *) CReaction_createReactant (CReaction_t *r);


/**
 * Creates a new SpeciesReference, adds it to this CReaction_t's list of
 * products and returns it.
 *
 * @memberof CReaction_t
 */
CAPI_FUNC(SpeciesReference_t *) CReaction_createProduct (CReaction_t *r);


/**
 * Creates a new SpeciesReference, adds it to this CReaction_t's list of
 * modifiers and returns it.
 *
 * @memberof CReaction_t
 */
CAPI_FUNC(SpeciesReference_t *) CReaction_createModifier (CReaction_t *r);


/**
 * Creates a new KineticLaw_t for this CReaction_t and returns it.  If this
 * CReaction_t had a previous KineticLaw_t, it will be destroyed.
 *
 * @memberof CReaction_t
 */
CAPI_FUNC(KineticLaw_t *) CReaction_createKineticLaw (CReaction_t *r);


/**
 * @return the list of Reactants for this CReaction_t.
 *
 * @memberof CReaction_t
 */
CAPI_FUNC(ListOf_t *) CReaction_getListOfReactants (CReaction_t *r);


/**
 * @return the list of Products for this CReaction_t.
 *
 * @memberof CReaction_t
 */
CAPI_FUNC(ListOf_t *) CReaction_getListOfProducts (CReaction_t *r);


/**
 * @return the list of Modifiers for this CReaction_t.
 *
 * @memberof CReaction_t
 */
CAPI_FUNC(ListOf_t *) CReaction_getListOfModifiers (CReaction_t *r);


/**
 * @return the nth reactant (SpeciesReference_t) of this CReaction_t.
 * If the index @p n is invalid, @c NULL is returned.
 *
 * @memberof CReaction_t
 */
CAPI_FUNC(SpeciesReference_t *) CReaction_getReactant (CReaction_t *r, unsigned int n);


/**
 * @return the reactant (SpeciesReference_t) in this CReaction_t with the given
 * species or @c NULL if no such reactant exists.
 *
 * @memberof CReaction_t
 */
CAPI_FUNC(SpeciesReference_t *) CReaction_getReactantBySpecies (CReaction_t *r, const char *species);


/**
 * @return the nth product (SpeciesReference_t) of this CReaction_t.
 * If the index @p n is invalid, @c NULL is returned.
 *
 * @memberof CReaction_t
 */
CAPI_FUNC(SpeciesReference_t *) CReaction_getProduct (CReaction_t *r, unsigned int n);


/**
 * @return the product (SpeciesReference_t) in this CReaction_t with the given
 * species or @c NULL if no such product exists.
 *
 * @memberof CReaction_t
 */
CAPI_FUNC(SpeciesReference_t *) CReaction_getProductBySpecies (CReaction_t *r, const char *species);


/**
 * @return the nth modifier (modifier SpeciesReference_t) of this CReaction_t.
 * If the index @p n is invalid, @c NULL is returned.
 *
 * @memberof CReaction_t
 */
CAPI_FUNC(SpeciesReference_t *) CReaction_getModifier (CReaction_t *r, unsigned int n);


/**
 * @return the modifier (modifier SpeciesReference_t) in this CReaction_t with
 * the given species or @c NULL if no such modifier exists.
 *
 * @memberof CReaction_t
 */
CAPI_FUNC(SpeciesReference_t *) CReaction_getModifierBySpecies (CReaction_t *r, const char *species);


/**
 * @return the number of reactants (SpeciesReference_t's) in this CReaction_t.
 *
 * @memberof CReaction_t
 */
CAPI_FUNC(unsigned int) CReaction_getNumReactants (const CReaction_t *r);


/**
 * @return the number of products (SpeciesReference_t's) in this CReaction_t.
 *
 * @memberof CReaction_t
 */
CAPI_FUNC(unsigned int) CReaction_getNumProducts (const CReaction_t *r);


/**
 * @return the number of modifiers (modifier SpeciesReference_t's) in this
 * CReaction_t.
 *
 * @memberof CReaction_t
 */
CAPI_FUNC(unsigned int) CReaction_getNumModifiers (const CReaction_t *r);


/**
 * Removes the nth reactant SpeciesReference_t structure from this
 * CReaction_t structure and returns a pointer to it.
 *
 * The caller owns the returned structure and is responsible for deleting it.
 *
 * @param r the CReaction_t structure.
 * @param n the integer index of the reactant SpeciesReference_t to remove.
 *
 * @return the reactant SpeciesReference_t structure removed.  As mentioned
 * above, the caller owns the returned structure. @c NULL is returned if the
 * given index is out of range.
 *
 * @memberof CReaction_t
 */
CAPI_FUNC(SpeciesReference_t *) CReaction_removeReactant (CReaction_t *r, unsigned int n);


/**
 * Removes the reactant SpeciesReference_t structure with the given
 * "species" attribute from this CReaction_t structure and returns a pointer
 * to it.
 *
 * The caller owns the returned structure and is responsible for deleting it.
 *
 * @param r the CReaction_t structure.
 * @param species the "species" attribute of the reactant SpeciesReference_t
 * to remove.
 *
 * @return the reactant SpeciesReference_t structure removed.  As mentioned
 * above, the caller owns the returned structure. @c NULL is returned if no
 * reactant SpeciesReference_t structure with the "species" attribute exists
 * in this CReaction_t.
 *
 * @memberof CReaction_t
 */
CAPI_FUNC(SpeciesReference_t *) CReaction_removeReactantBySpecies (CReaction_t *r, const char *species);


/**
 * Removes the nth product SpeciesReference_t structure from this
 * CReaction_t structure and returns a pointer to it.
 *
 * The caller owns the returned structure and is responsible for deleting it.
 *
 * @param r the CReaction_t structure.
 * @param n the integer index of the product SpeciesReference_t to remove.
 *
 * @return the product SpeciesReference_t structure removed.  As mentioned
 * above, the caller owns the returned structure. @c NULL is returned if the
 * given index is out of range.
 *
 * @memberof CReaction_t
 */
CAPI_FUNC(SpeciesReference_t *) CReaction_removeProduct (CReaction_t *r, unsigned int n);


/**
 * Removes the product SpeciesReference_t structure with the given
 * "species" attribute from this CReaction_t structure and returns a pointer
 * to it.
 *
 * The caller owns the returned structure and is responsible for deleting it.
 *
 * @param r the CReaction_t structure.
 * @param species the "species" attribute of the product SpeciesReference_t
 * to remove.
 *
 * @return the product SpeciesReference_t structure removed.  As mentioned
 * above, the caller owns the returned structure. @c NULL is returned if no
 * product SpeciesReference_t structure with the "species" attribute exists
 * in this CReaction_t.
 *
 * @memberof CReaction_t
 */
CAPI_FUNC(SpeciesReference_t *) CReaction_removeProductBySpecies (CReaction_t *r, const char *species);


/**
 * Removes the nth modifier SpeciesReference_t structure from this
 * CReaction_t structure and returns a pointer to it.
 *
 * The caller owns the returned structure and is responsible for deleting it.
 *
 * @param r the CReaction_t structure.
 * @param n the integer index of the modifier SpeciesReference_t to remove.
 *
 * @return the modifier SpeciesReference_t structure removed.  As mentioned
 * above, the caller owns the returned structure. @c NULL is returned if the
 * given index is out of range.
 *
 * @memberof CReaction_t
 */
CAPI_FUNC(SpeciesReference_t *) CReaction_removeModifier (CReaction_t *r, unsigned int n);


/**
 * Removes the modifier SpeciesReference_t structure with the given
 * "species" attribute from this CReaction_t structure and returns a pointer
 * to it.
 *
 * The caller owns the returned structure and is responsible for deleting it.
 *
 * @param r the CReaction_t structure.
 * @param species the "species" attribute of the modifier SpeciesReference_t
 * to remove.
 *
 * @return the modifier SpeciesReference_t structure removed.  As mentioned
 * above, the caller owns the returned structure. @c NULL is returned if no
 * modifier SpeciesReference_t structure with the "species" attribute exists
 * in this CReaction_t.
 *
 * @memberof CReaction_t
 */
CAPI_FUNC(SpeciesReference_t *) CReaction_removeModifierBySpecies (CReaction_t *r, const char *species);


/**
 * Returns the CReaction_t structure having a given identifier.
 *
 * @param lo the ListOfReactions_t structure to search.
 * @param sid the "id" attribute value being sought.
 *
 * @return item in the @p lo ListOfReactions with the given @p sid or a
 * null pointer if no such item exists.
 *
 * @see ListOf_t
 *
 * @memberof ListOfReactions_t
 */
CAPI_FUNC(CReaction_t *) ListOfReactions_getById (ListOf_t *lo, const char *sid);


/**
 * Removes a CReaction_t structure based on its identifier.
 *
 * The caller owns the returned item and is responsible for deleting it.
 *
 * @param lo the list of CReaction_t structures to search.
 * @param sid the "id" attribute value of the structure to remove.
 *
 * @return The CReaction_t structure removed, or a null pointer if no such
 * item exists in @p lo.
 *
 * @see ListOf_t
 *
 * @memberof ListOfReactions_t
 */
CAPI_FUNC(CReaction_t *) ListOfReactions_removeById (ListOf_t *lo, const char *sid);


#endif /* EXTERN_CARBON_INCLUDE_C_REACTION_H_ */
