/*
 * c_speciesreference.h
 *
 *  Created on: Jun 4, 2020
 *      Author: andy
 *
 * copy of the libSBML API, originally written by Ben Bornstein
 */

#ifndef EXTERN_CARBON_INCLUDE_C_SPECIESREFERENCE_H_
#define EXTERN_CARBON_INCLUDE_C_SPECIESREFERENCE_H_

#include <c_port.h>

CAPI_STRUCT(CSpeciesReference_t);
CAPI_STRUCT(StoichiometryMath_t);
CAPI_STRUCT(ListOf_t);

/**
 * Creates a new CSpeciesReference_t structure using the given SBML @p level
 * and @p version values.
 *
 * @param level an unsigned int, the SBML Level to assign to this
 * CSpeciesReference_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * CSpeciesReference_t.
 *
 * @return a pointer to the newly created CSpeciesReference_t structure.
 *
 * @copydetails doc_note_setting_lv
 *
 * @memberof CSpeciesReference_t
 */
CAPI_FUNC(CSpeciesReference_t *) CSpeciesReference_create (unsigned int level, unsigned int version);


/**
 * Creates a new CSpeciesReference_t structure using the given
 * SBMLNamespaces_t structure.
 *
 * @param sbmlns SBMLNamespaces_t, a pointer to an SBMLNamespaces_t structure
 * to assign to this CSpeciesReference_t.
 *
 * @return a pointer to the newly created CSpeciesReference_t structure.
 *
 * @copydetails doc_note_setting_lv
 *
 * @memberof CSpeciesReference_t
 */
//CAPI_FUNC(CSpeciesReference_t *) CSpeciesReference_createWithNS (SBMLNamespaces_t *sbmlns);


/**
 * Creates a new ModifierSpeciesReference (CSpeciesReference_t) structure
 * using the given SBMLNamespaces_t structure.
 *
 * @param level an unsigned int, the SBML Level to assign to this
 * CSpeciesReference_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * CSpeciesReference_t.
 *
 * @return a pointer to the newly created CSpeciesReference_t structure.
 *
 * @copydetails doc_note_setting_lv
 *
 * @memberof CSpeciesReference_t
 */
CAPI_FUNC(CSpeciesReference_t *) CSpeciesReference_createModifier (unsigned int level, unsigned int version);


/**
 * Creates a new ModifierSpeciesReference (CSpeciesReference_t) structure
 * using the given SBMLNamespaces_t structure.
 *
 * @param sbmlns SBMLNamespaces_t, a pointer to an SBMLNamespaces_t structure
 * to assign to this modifier CSpeciesReference_t.
 *
 * @return a pointer to the newly created CSpeciesReference_t structure.
 *
 * @copydetails doc_note_setting_lv
 *
 * @memberof CSpeciesReference_t
 */
//CAPI_FUNC(CSpeciesReference_t *) CSpeciesReference_createModifierWithNS (SBMLNamespaces_t *sbmlns);


/**
 * Frees the given CSpeciesReference_t structure.
 *
 * @param sr the CSpeciesReference_t structure.
 *
 * @memberof CSpeciesReference_t
 */
CAPI_FUNC(void) CSpeciesReference_free (CSpeciesReference_t *sr);


/**
 * Creates and returns a deep copy of the given CSpeciesReference_t
 * structure.
 *
 * @param sr the CSpeciesReference_t structure to use.
 *
 * @return a (deep) copy of this CSpeciesReference_t.
 *
 * @memberof CSpeciesReference_t
 */
CAPI_FUNC(CSpeciesReference_t *) CSpeciesReference_clone (const CSpeciesReference_t *sr);


/**
 * Initializes the attributes of the given CSpeciesReference_t structure to
 * their defaults:
 *
 * @li stoichiometry is set to @c 1
 * @li denominator is set to @c 1
 *
 * This function has no effect if the CSpeciesReference_t structure is a
 * modifer (see CSpeciesReference_isModifier()).
 *
 * @param sr the CSpeciesReference_t structure to use.
 *
 * @memberof CSpeciesReference_t
 */
CAPI_FUNC(void) CSpeciesReference_initDefaults (CSpeciesReference_t *sr);


/**
 * Returns a list of XMLNamespaces_t associated with this CSpeciesReference_t
 * structure.
 *
 * @param sr the CSpeciesReference_t structure.
 *
 * @return pointer to the XMLNamespaces_t structure associated with
 * this structure.
 *
 * @memberof CSpeciesReference_t
 */
//CAPI_FUNC(const XMLNamespaces_t *) CSpeciesReference_getNamespaces(CSpeciesReference_t *sr);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given CSpeciesReference_t structure is a modifier.
 *
 * @param sr the CSpeciesReference_t structure to use.
 *
 * @return @c 1 (true) if this CSpeciesReference_t represents a modifier
 * species, @c 0 (false)if it is a plain CSpeciesReference_t.
 *
 * @memberof CSpeciesReference_t
 */
CAPI_FUNC(int) CSpeciesReference_isModifier (const CSpeciesReference_t *sr);


/**
 * Get the value of the "id" attribute of the given CSpeciesReference_t
 * structure.
 *
 * @param sr the CSpeciesReference_t structure to use.
 *
 * @return the identifier of the CSpeciesReference_t instance.
 *
 * @memberof CSpeciesReference_t
 */
CAPI_FUNC(const char *) CSpeciesReference_getId (const CSpeciesReference_t *sr);


/**
 * Get the value of the "name" attribute of the given CSpeciesReference_t
 * structure.
 *
 * @param sr the CSpeciesReference_t structure to use.
 *
 * @return the name of the CSpeciesReference_t instance.
 *
 * @memberof CSpeciesReference_t
 */
CAPI_FUNC(const char *) CSpeciesReference_getName (const CSpeciesReference_t *sr);


/**
 * Get the value of the "species" attribute of the given CSpeciesReference_t
 * structure.
 *
 * @param sr the CSpeciesReference_t structure to use.
 *
 * @return the "species" attribute value.
 *
 * @memberof CSpeciesReference_t
 */
CAPI_FUNC(const char *) CSpeciesReference_getSpecies (const CSpeciesReference_t *sr);


/**
 * Get the value of the "stoichiometry" attribute of the given
 * CSpeciesReference_t structure.
 *
 * This function returns @c 0 if the CSpeciesReference_t structure is a
 * Modifer (see CSpeciesReference_isModifier()).
 *
 * @param sr the CSpeciesReference_t structure to use.
 *
 * @return the "stoichiometry" attribute value.
 *
 * @memberof CSpeciesReference_t
 */
CAPI_FUNC(double) CSpeciesReference_getStoichiometry (const CSpeciesReference_t *sr);


/**
 * Get the content of the "stoichiometryMath" subelement of the given
 * CSpeciesReference_t structure.
 *
 * This function returns NULL if the CSpeciesReference_t structure is a
 * Modifer (see CSpeciesReference_isModifier()).
 *
 * @param sr the CSpeciesReference_t structure to use.
 *
 * @return the stoichiometryMath of this CSpeciesReference_t.
 *
 * @note This function has no effect on SBML Level 1 or Level 3
 * CSpeciesReference_t objects, neither of which have
 * StoichiometryMath_t children.
 *
 * @memberof CSpeciesReference_t
 */
CAPI_FUNC(StoichiometryMath_t *) CSpeciesReference_getStoichiometryMath (CSpeciesReference_t *sr);


/**
 * Get the value of the "denominator" attribute, for the case of a
 * rational-numbered stoichiometry or a model in SBML Level 1.
 *
 * The "denominator" attribute is only actually written out in the case of
 * an SBML Level 1 model.  In SBML Level 2, rational-number stoichiometries
 * are written as MathML elements in the "stoichiometryMath" subelement.
 * However, as a convenience to users, libSBML allows the creation and
 * manipulation of rational-number stoichiometries by supplying the
 * numerator and denominator directly rather than having to manually create
 * an ASTNode_t structure.  LibSBML will write out the appropriate constructs
 * (either a combination of "stoichiometry" and "denominator" in the case
 * of SBML Level 1, or a "stoichiometryMath" subelement in the case of SBML
 * Level 2).
 * However, as the "stoichiometryMath" subelement was removed in SBML
 * Level&nbsp;3, automatic translation of the "denominator"
 * attribute is no longer supported for that level.
 *
 * This function returns 0 if the CSpeciesReference_t structure is a Modifer (see
 * CSpeciesReference_isModifier()).
 *
 * @param sr the CSpeciesReference_t structure to use.
 *
 * @return the denominator of this CSpeciesReference_t.
 *
 * @memberof CSpeciesReference_t
 */
CAPI_FUNC(int) CSpeciesReference_getDenominator (const CSpeciesReference_t *sr);


/**
 * Get the value of the "constant" attribute.
 *
 * @param sr the CSpeciesReference_t structure to use.
 *
 * @return the constant attribute of this CSpeciesReference_t.
 *
 * @memberof CSpeciesReference_t
 */
CAPI_FUNC(int) CSpeciesReference_getConstant (const CSpeciesReference_t *sr);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on
 * whether the "id" attribute of the given CSpeciesReference_t structure is
 * set.
 *
 * @param sr the CSpeciesReference_t structure to use.
 *
 * @return @c 1 (true) if the "id" attribute of given CSpeciesReference_t
 * structure is set, @c 0 (false) otherwise.
 *
 * @memberof CSpeciesReference_t
 */
CAPI_FUNC(int) CSpeciesReference_isSetId (const CSpeciesReference_t *sr);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on
 * whether the "name" attribute of the given CSpeciesReference_t
 * structure is set.
 *
 * @param sr the CSpeciesReference_t structure to use.
 *
 * @return @c 1 (true) if the "name" attribute of given CSpeciesReference_t
 * structure is set, @c 0 (false) otherwise.
 *
 * @memberof CSpeciesReference_t
 */
CAPI_FUNC(int) CSpeciesReference_isSetName (const CSpeciesReference_t *sr);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on
 * whether the "species" attribute of the given CSpeciesReference_t
 * structure is set.
 *
 * @param sr the CSpeciesReference_t structure to use.
 *
 * @return @c 1 (true) if the "species" attribute of given CSpeciesReference_t
 * structure is set, @c 0 (false) otherwise.
 *
 * @memberof CSpeciesReference_t
 */
CAPI_FUNC(int) CSpeciesReference_isSetSpecies (const CSpeciesReference_t *sr);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on
 * whether the "stoichiometryMath" subelement of the given
 * CSpeciesReference_t structure is non-empty.
 *
 * This function returns false if the CSpeciesReference_t structure is a
 * Modifer (see CSpeciesReference_isModifier()).
 *
 * @param sr the CSpeciesReference_t structure to use.
 *
 * @return @c 1 (true) if the "stoichiometryMath" subelement has content,
 * @c 0 (false) otherwise.
 *
 * @memberof CSpeciesReference_t
 */
CAPI_FUNC(int) CSpeciesReference_isSetStoichiometryMath (const CSpeciesReference_t *sr);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on
 * whether the "stoichiometry" attribute of the given CSpeciesReference_t structure is
 * set.
 *
 * @param sr the CSpeciesReference_t structure to use.
 *
 * @return @c 1 (true) if the "stoichiometry" attribute of given CSpeciesReference_t
 * structure is set, @c 0 (false) otherwise.
 *
 * @memberof CSpeciesReference_t
 */
CAPI_FUNC(int) CSpeciesReference_isSetStoichiometry (const CSpeciesReference_t *sr);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on
 * whether the "constant" attribute of the given CSpeciesReference_t structure is
 * set.
 *
 * @param sr the CSpeciesReference_t structure to use.
 *
 * @return @c 1 (true) if the "constant" attribute of given CSpeciesReference_t
 * structure is set, @c 0 (false) otherwise.
 *
 * @memberof CSpeciesReference_t
 */
CAPI_FUNC(int) CSpeciesReference_isSetConstant (const CSpeciesReference_t *sr);


/**
 * Sets the value of the "id" attribute of the given CSpeciesReference_t
 * structure.
 *
 * The string in @p sid will be copied.
 *
 * @param sr the CSpeciesReference_t structure to use.
 *
 * @param sid the identifier string that will be copied and assigned as the
 * "id" attribute value.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_UNEXPECTED_ATTRIBUTE, OperationReturnValues_t}
 *
 * @note Using this function with an @p sid of NULL is equivalent to
 * unsetting the "id" attribute.
 *
 * @memberof CSpeciesReference_t
 */
CAPI_FUNC(int) CSpeciesReference_setId (CSpeciesReference_t *sr, const char *sid);


/**
 * Sets the value of the "name" attribute of the given CSpeciesReference_t
 * structure.
 *
 * The string in @p sid will be copied.
 *
 * @param sr the CSpeciesReference_t structure to use.
 *
 * @param name the identifier string that will be copied and assigned as the
 * "name" attribute value.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_UNEXPECTED_ATTRIBUTE, OperationReturnValues_t}
 *
 * @note Using this function with the name set to NULL is equivalent to
 * unsetting the "name" attribute.
 *
 * @memberof CSpeciesReference_t
 */
CAPI_FUNC(int) CSpeciesReference_setName (CSpeciesReference_t *sr, const char *name);


/**
 * Sets the value of the "species" attribute of the given CSpeciesReference_t
 * structure.
 *
 * The string in @p sid will be copied.
 *
 * @param sr the CSpeciesReference_t structure to use.
 *
 * @param sid the identifier string that will be copied and assigned as the
 * "species" attribute value.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @note Using this function with an @p sid of NULL is equivalent to
 * unsetting the "species" attribute.
 *
 * @memberof CSpeciesReference_t
 */
CAPI_FUNC(int) CSpeciesReference_setSpecies (CSpeciesReference_t *sr, const char *sid);


/**
 * Sets the value of the "stoichiometry" attribute of the given
 * CSpeciesReference_t structure.
 *
 * This function has no effect if the CSpeciesReference_t structure is a
 * Modifer (see CSpeciesReference_isModifier()).
 *
 * @param sr the CSpeciesReference_t structure to use.
 *
 * @param value the value to assign to the "stoichiometry" attribute.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof CSpeciesReference_t
 */
CAPI_FUNC(int) CSpeciesReference_setStoichiometry (CSpeciesReference_t *sr, double value);


/**
 * Creates a new, empty StoichiometryMath_t structure, adds it to the
 * @p sr CSpeciesReference_t, and returns it.
 *
 * @return the newly created StoichiometryMath_t structure instance.
 *
 * @see Reaction_addReactant()
 * @see Reaction_addProduct()
 *
 * @note This function has no effect on SBML Level 1 or Level 3
 * CSpeciesReference_t elements, neither of which have
 * StoichiometryMath_t children.
 *
 * @memberof CSpeciesReference_t
 */
CAPI_FUNC(StoichiometryMath_t *) CSpeciesReference_createStoichiometryMath (CSpeciesReference_t *sr);


/**
 * Sets the content of the "stoichiometryMath" subelement of the given
 * CSpeciesReference_t structure.
 *
 * This function has no effect if the CSpeciesReference_t structure is a
 * Modifer (see CSpeciesReference_isModifier()).
 *
 * @param sr the CSpeciesReference_t structure to use.
 *
 * @param math the StoichiometryMath_t structure to use in the given CSpeciesReference_t.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_UNEXPECTED_ATTRIBUTE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_LEVEL_MISMATCH, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_VERSION_MISMATCH, OperationReturnValues_t}
 *
 * @note This function has no effect on SBML Level 1 or Level 3
 * CSpeciesReference_t elements, neither of which have
 * StoichiometryMath_t children.
 *
 * @memberof CSpeciesReference_t
 */
CAPI_FUNC(int) CSpeciesReference_setStoichiometryMath (  CSpeciesReference_t *sr
                                       , const StoichiometryMath_t    *math );


/**
 * Sets the value of the "denominator" attribute of the given
 * CSpeciesReference_t structure.
 *
 * The "denominator" attribute is only actually written out in the case of
 * an SBML Level 1 model.  In SBML Level 2, rational-number stoichiometries
 * are written as MathML elements in the "stoichiometryMath" subelement.
 * However, as a convenience to users, libSBML allows the creation and
 * manipulation of rational-number stoichiometries by supplying the
 * numerator and denominator directly rather than having to manually create
 * an ASTNode_t structure.  LibSBML will write out the appropriate constructs
 * (either a combination of "stoichiometry" and "denominator" in the case
 * of SBML Level 1, or a "stoichiometryMath" subelement in the case of SBML
 * Level 2).
 * However, as the "stoichiometryMath" subelement was removed in SBML
 * Level&nbsp;3, automatic translation of the "denominator"
 * attribute is no longer supported for that level.
 *
 * This function has no effect if the CSpeciesReference_t structure is a
 * Modifer (see CSpeciesReference_isModifier()).
 *
 * @param sr the CSpeciesReference_t structure to use.
 *
 * @param value the value to assign to the "denominator" attribute.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_UNEXPECTED_ATTRIBUTE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof CSpeciesReference_t
 */
CAPI_FUNC(int) CSpeciesReference_setDenominator (CSpeciesReference_t *sr, int value);


/**
 * Assign the "constant" attribute of a CSpeciesReference_t structure.
 *
 * @param sr the CSpeciesReference_t structure to set.
 * @param value the value to assign as the "constant" attribute
 * of the CSpeciesReference_t, either @c zero for false or @c nonzero for true.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_UNEXPECTED_ATTRIBUTE, OperationReturnValues_t}
 *
 * @memberof CSpeciesReference_t
 */
CAPI_FUNC(int) CSpeciesReference_setConstant (CSpeciesReference_t *sr, int value);


/**
 * Unsets the value of the "id" attribute of the given CSpeciesReference_t
 * structure.
 *
 * @param sr the CSpeciesReference_t structure to use.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof CSpeciesReference_t
 */
CAPI_FUNC(int) CSpeciesReference_unsetId (CSpeciesReference_t *sr);


/**
 * Unsets the value of the "name" attribute of the given CSpeciesReference_t
 * structure.
 *
 * @param sr the CSpeciesReference_t structure to use.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof CSpeciesReference_t
 */
CAPI_FUNC(int) CSpeciesReference_unsetName (CSpeciesReference_t *sr);


/**
 * Unsets the value of the "species" attribute of the given CSpeciesReference_t
 * structure.
 *
 * @param sr the CSpeciesReference_t structure to use.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof CSpeciesReference_t
 */
CAPI_FUNC(int) CSpeciesReference_unsetSpecies (CSpeciesReference_t *sr);


/**
 * Unsets the value of the "constant" attribute of the given CSpeciesReference_t
 * structure.
 *
 * @param sr the CSpeciesReference_t structure to use.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof CSpeciesReference_t
 */
CAPI_FUNC(int) CSpeciesReference_unsetConstant (CSpeciesReference_t *sr);


/**
 * Unsets the content of the "stoichiometryMath" subelement of the given
 * CSpeciesReference_t structure.
 *
 * This function has no effect if the CSpeciesReference_t structure is a
 * Modifer (see CSpeciesReference_isModifier()).
 *
 * @param sr the CSpeciesReference_t structure to use.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @note This function has no effect on SBML Level 1 or Level 3
 * CSpeciesReference_t elements, neither of which have
 * StoichiometryMath_t children.
 *
 * @memberof CSpeciesReference_t
 */
CAPI_FUNC(int) CSpeciesReference_unsetStoichiometryMath (CSpeciesReference_t *sr);


/**
 * Unsets the content of the "stoichiometry" attribute of the given
 * CSpeciesReference_t structure.
 *
 * This function has no effect if the CSpeciesReference_t structure is a
 * Modifer (see CSpeciesReference_isModifier()).
 *
 * @param sr the CSpeciesReference_t structure to use.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof CSpeciesReference_t
 */
CAPI_FUNC(int) CSpeciesReference_unsetStoichiometry (CSpeciesReference_t *sr);


/**
  * Predicate returning @c 1 (true) or @c 0 (false) depending on whether
  * all the required attributes for this CSpeciesReference_t structure
  * have been set.
  *
  * The required attributes for a CSpeciesReference_t structure are:
  * @li species
  * @li constant (in L3 only)
  *
  * @param sr the CSpeciesReference_t structure to check.
  *
  * @return @c 1 (true) if all the required
  * attributes for this object have been defined, @c 0 (false) otherwise.
  *
 * @memberof CSpeciesReference_t
 */
CAPI_FUNC(int) CSpeciesReference_hasRequiredAttributes (CSpeciesReference_t *sr);


/**
 * Returns the CSpeciesReference_t structure having a given identifier.
 *
 * @param lo the ListOfSpeciesReferences_t structure to search.
 * @param sid the "id" attribute value being sought.
 *
 * @return item in the @p lo ListOfSpeciesReferences with the given @p sid or a
 * null pointer if no such item exists.
 *
 * @see ListOf_t
 *
 * @memberof ListOfSpeciesReferences_t
 */
CAPI_FUNC(CSpeciesReference_t *) ListOfSpeciesReferences_getById (ListOf_t *lo, const char *sid);


/**
 * Removes a CSpeciesReference_t structure based on its identifier.
 *
 * The caller owns the returned item and is responsible for deleting it.
 *
 * @param lo the list of CSpeciesReference_t structures to search.
 * @param sid the "id" attribute value of the structure to remove.
 *
 * @return The CSpeciesReference_t structure removed, or a null pointer if no such
 * item exists in @p lo.
 *
 * @see ListOf_t
 *
 * @memberof ListOfSpeciesReferences_t
 */
CAPI_FUNC(CSpeciesReference_t *) ListOfSpeciesReferences_removeById (ListOf_t *lo, const char *sid);




#endif /* EXTERN_CARBON_INCLUDE_C_SPECIESREFERENCE_H_ */
