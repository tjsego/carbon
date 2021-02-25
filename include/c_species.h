/*
 * cspecies.h
 *
 *  Created on: Jun 4, 2020
 *      Author: andy
 *
 * copy of the libSBML API, originally written by Ben Bornstein
 */

#ifndef EXTERN_CARBON_INCLUDE_C_SPECIES_H_
#define EXTERN_CARBON_INCLUDE_C_SPECIES_H_

#include <c_port.h>

CAPI_STRUCT(CSpecies_t);


enum CSpeciesFlags {

    SPECIES_BOUNDARY           = 1 << 0,
    SPECIES_SUBSTANCE          = 1 << 2,
    SPECIES_CONSTANT           = 1 << 3,
    SPECIES_KONSTANT           = SPECIES_BOUNDARY | SPECIES_CONSTANT
};


/**
 * Creates a new CSpecies_t structure using the given SBML @p level
 * and @p version values.
 *
 * @param level an unsigned int, the SBML Level to assign to this
 * CSpecies_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * CSpecies_t.
 *
 * @return a pointer to the newly created CSpecies_t structure.
 *
 * @copydetails doc_note_setting_lv
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(CSpecies_t *) CSpecies_create (unsigned int level, unsigned int version);


/**
 * Creates a new CSpecies_t structure using the given
 * SBMLNamespaces_t structure.
 *
 * @param sbmlns SBMLNamespaces_t, a pointer to an SBMLNamespaces_t structure
 * to assign to this CSpecies_t.
 *
 * @return a pointer to the newly created CSpecies_t structure.
 *
 * @copydetails doc_note_setting_lv
 *
 * @memberof CSpecies_t
 */
// CAPI_FUNC(CSpecies_t *) CSpecies_createWithNS (SBMLNamespaces_t *sbmlns);


/**
 * Frees the given CSpecies_t structure.
 *
 * @param s the CSpecies_t structure to be freed.
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(void) CSpecies_free (CSpecies_t *s);


/**
 * Creates a deep copy of the given CSpecies_t structure
 *
 * @param s the CSpecies_t structure to be copied.
 *
 * @return a (deep) copy of the given CSpecies_t structure.
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(CSpecies_t *) CSpecies_clone (const CSpecies_t *s);


/**
 * Initializes the attributes of the given CSpecies_t structure to the
 * defaults defined in the specification of the relevant Level/Version of
 * SBML.
 *
 * @li sets "boundaryCondition" to @c true
 * @li (Level 2 only) sets "constant" to @c false
 * @li (Level 2 only) sets "hasOnlySubstanceUnits" to @c false
 *
 * @param s the CSpecies_t structure.
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(void) CSpecies_initDefaults (CSpecies_t *s);


/**
 * Returns a list of XMLNamespaces_t associated with this CSpecies_t
 * structure.
 *
 * @param s the CSpecies_t structure.
 *
 * @return pointer to the XMLNamespaces_t structure associated with
 * this structure
 *
 * @memberof CSpecies_t
 */
//CAPI_FUNC(const XMLNamespaces_t *) CSpecies_getNamespaces(CSpecies_t *s);


/**
 * Takes a CSpecies_t structure and returns its identifier.
 *
 * @param s the CSpecies_t structure whose identifier is sought.
 *
 * @return the identifier of the CSpecies_t structure @p s, as a pointer
 * to a string.
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(PyObject*) CSpecies_getId (const CSpecies_t *s);


/**
 * Takes a CSpecies_t structure and returns its name.
 *
 * @param s the CSpecies_t structure whose name is sought.
 *
 * @return the name of the CSpecies_t structure @p s, as a pointer to a
 * string.
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(PyObject*) CSpecies_getName (const CSpecies_t *s);


/**
 * Get the species type of this CSpecies_t structure, as indicated by the
 * CSpecies_t structure's "speciesType" attribute value.
 *
 * @param s the CSpecies_t structure.
 *
 * @return the value of the "speciesType" attribute of the
 * CSpecies_t structure @p s as a string.
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(const char *) CSpecies_getSpeciesType (const CSpecies_t *s);


/**
 * Get the compartment in which this species is located.
 *
 * @param s the CSpecies_t structure.
 *
 * @return the value of the "compartment" attribute of the given CSpecies_t
 * structure, as a string.
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(const char *) CSpecies_getCompartment (const CSpecies_t *s);


/**
 * Get the value of the "initialAmount" attribute.
 *
 * @param s the CSpecies_t structure.
 *
 * @return the "initialAmount" attribute of the given CSpecies_t structure,
 * as a floating point number.
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(double) CSpecies_getInitialAmount (const CSpecies_t *s);


/**
 * Get the value of the "initialConcentration" attribute.
 *
 * @param s the CSpecies_t structure.
 *
 * @return the "initialConcentration" of the given CSpecies_t structure, as
 * a floating point number.
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(double) CSpecies_getInitialConcentration (const CSpecies_t *s);


/**
 * Get the value of the "substanceUnit" attribute.
 *
 * @param s the CSpecies_t structure.
 *
 * @return the "substanceUnits" attribute of the given CSpecies_t structure,
 * as a string.
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(const char *) CSpecies_getSubstanceUnits (const CSpecies_t *s);


/**
 * Get the value of the "spatialSizeUnits" attribute.
 *
 * @param s the CSpecies_t structure.
 *
 * @return the spatialSizeUnits of the given CSpecies_t.
 *
 * @copydetails doc_warning_species_spatialSizeUnits
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(const char *) CSpecies_getSpatialSizeUnits (const CSpecies_t *s);


/**
 * (SBML Level 1 only) Get the value of the "units" attribute.
 *
 * @param s the CSpecies_t structure.
 *
 * @return the units of the given CSpecies_t structure.
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(const char *) CSpecies_getUnits (const CSpecies_t *s);


/**
 * Get the value of the "hasOnlySubstanceUnits" attribute.
 *
 * @param s the CSpecies_t structure.
 *
 * @return @c 1 (true) or @c 0 (false) depending on the value
 * of the given CSpecies_t structure's "hasOnlySubstanceUnits" attribute
 * value.
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(int) CSpecies_getHasOnlySubstanceUnits (const CSpecies_t *s);


/**
 * Get the value of the "boundaryCondition" attribute.
 *
 * @param s the CSpecies_t structure.
 *
 * @return @c 1 (true) or @c 0 (false) depending on the value
 * of the given CSpecies_t structure's "boundaryCondition" attribute
 * value.
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(int) CSpecies_getBoundaryCondition (const CSpecies_t *s);


/**
 * Get the value of the "charge" attribute.
 *
 * @param s the CSpecies_t structure.
 *
 * @return the charge of the given CSpecies_t structure.
 *
 * @note Beginning in SBML Level 2 Version&nbsp;2, the "charge" attribute on
 * CSpecies_t is deprecated and its use strongly discouraged.  Its presence
 * is considered a misfeature in earlier definitions of SBML because its
 * implications for the mathematics of a model were never defined, and in
 * any case, no known modeling system ever used it.  Instead, models take
 * account of charge values directly in their definitions of species by
 * (for example) having separate species identities for the charged and
 * uncharged versions of the same species.  This allows the condition to
 * affect model mathematics directly.  LibSBML retains this method for
 * easier compatibility with SBML Level 1.
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(int) CSpecies_getCharge (const CSpecies_t *s);


/**
 * Get the value of the "constant" attribute.
 *
 * @param s the CSpecies_t structure.
 *
 * @return @c 1 (true) or @c 0 (false) depending on the value
 * of the given CSpecies_t structure's "constant" attribute
 * value.
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(int) CSpecies_getConstant (const CSpecies_t *s);


/**
 * Get the value of the "conversionFactor" attribute.
 *
 * @param s the CSpecies_t structure.
 *
 * @return the "conversionFactor" attribute of the given CSpecies_t structure,
 * as a string.
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(const char *) CSpecies_getConversionFactor (const CSpecies_t *s);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the attribute
 * "id" of the given CSpecies_t structure is set.
 *
 * @param s the CSpecies_t structure.
 *
 * @return @c 1 (true) if the "id" attribute of the given CSpecies_t
 * structure is set, @c 0 (false) otherwise.
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(int) CSpecies_isSetId (const CSpecies_t *s);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the attribute
 * "name" of the given CSpecies_t structure is set.
 *
 * @param s the CSpecies_t structure.
 *
 * @return @c 1 (true) if the "name" attribute of the given CSpecies_t
 * structure is set, @c 0 (false) otherwise.
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(int) CSpecies_isSetName (const CSpecies_t *s);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the attribute
 * "speciesType" of the given CSpecies_t structure is set.
 *
 * @param s the CSpecies_t structure.
 *
 * @return @c 1 (true) if the "speciesType" attribute of the given
 * CSpecies_t structure is set, @c 0 (false) otherwise.
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(int) CSpecies_isSetSpeciesType (const CSpecies_t *s);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the attribute
 * "compartment" of the given CSpecies_t structure is set.
 *
 * @param s the CSpecies_t structure.
 *
 * @return @c 1 (true) if the "compartment" attribute of the given
 * CSpecies_t structure is set, @c 0 (false) otherwise.
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(int) CSpecies_isSetCompartment (const CSpecies_t *s);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the attribute
 * "initialAmount" of the given CSpecies_t structure is set.
 *
 * @param s the CSpecies_t structure.
 *
 * @return @c 1 (true) if the "initialAmount" attribute of the given
 * CSpecies_t structure is set, @c 0 (false) otherwise.
 *
 * @note In SBML Level 1, CSpecies_t' "initialAmount" is required and
 * therefore <em>should always be set</em>.  (However, in Level 1, the
 * attribute has no default value either, so this method will not return
 * nonzero until a value has been assigned.)  In SBML Level 2,
 * "initialAmount" is optional and as such may or may not be set.
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(int) CSpecies_isSetInitialAmount (const CSpecies_t *s);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the attribute
 * "compartment" of the given CSpecies_t structure is set.
 *
 * @param s the CSpecies_t structure.
 *
 * @return @c 1 (true) if the "compartment" attribute of the given
 * CSpecies_t structure is set, @c 0 (false) otherwise.
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(int) CSpecies_isSetInitialConcentration (const CSpecies_t *s);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the attribute
 * "substanceUnits" of the given CSpecies_t structure is set.
 *
 * @param s the CSpecies_t structure.
 *
 * @return @c 1 (true) if the "substanceUnits" attribute of the given
 * CSpecies_t structure is set, @c 0 (false) otherwise.
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(int) CSpecies_isSetSubstanceUnits (const CSpecies_t *s);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the attribute
 * "spatialSizeUnits" of the given CSpecies_t structure is set.
 *
 * @param s the CSpecies_t structure.
 *
 * @return @c 1 (true) if the "spatialSizeUnits" attribute of the given
 * CSpecies_t structure is set, @c 0 (false) otherwise.
 *
 * @copydetails doc_warning_species_spatialSizeUnits
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(int) CSpecies_isSetSpatialSizeUnits (const CSpecies_t *s);


/**
 * (SBML Level 1 only) Predicate returning @c 1 (true) or @c 0 (false) depending on
 * whether the attribute "units" of the given CSpecies_t structure is
 * set.
 *
 * @param s the CSpecies_t structure.
 *
 * @return @c 1 (true) if the "units" attribute of the given
 * CSpecies_t structure is set, @c 0 (false) otherwise.
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(int) CSpecies_isSetUnits (const CSpecies_t *s);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the attribute
 * "charge" of the given CSpecies_t structure is set.
 *
 * @param s the CSpecies_t structure.
 *
 * @return @c 1 (true) if the "charge" attribute of the given
 * CSpecies_t structure is set, @c 0 (false) otherwise.
 *
 * @note Beginning in SBML Level 2 Version&nbsp;2, the "charge" attribute on
 * CSpecies_t in SBML is deprecated and its use strongly discouraged.  Its
 * presence is considered a misfeature in earlier definitions of SBML
 * because its implications for the mathematics of a model were never
 * defined, and in any case, no known modeling system ever used it.
 * Instead, models take account of charge values directly in their
 * definitions of species by (for example) having separate species
 * identities for the charged and uncharged versions of the same species.
 * This allows the condition to affect model mathematics directly.
 * LibSBML retains this method for easier compatibility with SBML Level 1.
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(int) CSpecies_isSetCharge (const CSpecies_t *s);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the attribute
 * "conversionFactor" of the given CSpecies_t structure is set.
 *
 * @param s the CSpecies_t structure.
 *
 * @return @c 1 (true) if the "conversionFactor" attribute of the given CSpecies_t
 * structure is set, @c 0 (false) otherwise.
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(int) CSpecies_isSetConversionFactor (const CSpecies_t *s);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the attribute
 * "constant" of the given CSpecies_t structure is set.
 *
 * @param s the CSpecies_t structure.
 *
 * @return @c 1 (true) if the "constant" attribute of the given CSpecies_t
 * structure is set, @c 0 (false) otherwise.
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(int) CSpecies_isSetConstant (const CSpecies_t *s);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the attribute
 * "boundaryCondition" of the given CSpecies_t structure is set.
 *
 * @param s the CSpecies_t structure.
 *
 * @return @c 1 (true) if the "boundaryCondition" attribute of the given CSpecies_t
 * structure is set, @c 0 (false) otherwise.
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(int) CSpecies_isSetBoundaryCondition (const CSpecies_t *s);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the attribute
 * "hasOnlySubstanceUnits" of the given CSpecies_t structure is set.
 *
 * @param s the CSpecies_t structure.
 *
 * @return @c 1 (true) if the "hasOnlySubstanceUnits" attribute of the given CSpecies_t
 * structure is set, @c 0 (false) otherwise.
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(int) CSpecies_isSetHasOnlySubstanceUnits (const CSpecies_t *s);


/**
 * Sets the "id" attribute of the given CSpecies_t structure.
 *
 * This function copies the string given in @p sid.  If the string is
 * @c NULL, this function is equivalent to calling CSpecies_unsetId().
 *
 * @param s the CSpecies_t structure.
 *
 * @param sid the identifier string to which the "id" attribute should be
 * set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @note Using this function with an @p sid of NULL is equivalent to
 * unsetting the "id" attribute.
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(int) CSpecies_setId (CSpecies_t *s, PyObject *str);


/**
 * Sets the "name" attribute of the given CSpecies_t structure.
 *
 * This function copies the string given in @p name.  If the string is
 * @c NULL, this function is equivalent to calling CSpecies_unsetName().
 *
 * @param s the CSpecies_t structure.
 *
 * @param name the name string to which the "name" attribute should be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @note Using this function with the name set to NULL is equivalent to
 * unsetting the "name" attribute.
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(int) CSpecies_setName (CSpecies_t *s, PyObject *str);


/**
 * Sets the "speciesType" attribute of the given CSpecies_t structure.
 *
 * This function copies the string given in @p sid.  If the string
 * is @c NULL, this function is equivalent to calling CSpecies_unsetSpeciesType().
 *
 * @param s the CSpecies_t structure.
 *
 * @param sid the identifer to which the "speciesType" attribute
 * should be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_UNEXPECTED_ATTRIBUTE, OperationReturnValues_t}
 *
 * @note Using this function with an @p sid of NULL is equivalent to
 * unsetting the "speciesType" attribute.
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(int) CSpecies_setSpeciesType (CSpecies_t *s, const char *sid);


/**
 * Sets the "compartment" attribute of the given CSpecies_t structure.
 *
 * This function copies the string given in @p compartment.  If the string
 * is @c NULL, this function is equivalent to calling CSpecies_unsetCompartment().
 *
 * @param s the CSpecies_t structure.
 *
 * @param sid the identifer to which the "compartment" attribute
 * should be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @note Using this function with an @p sid of NULL is equivalent to
 * unsetting the "compartment" attribute.
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(int) CSpecies_setCompartment (CSpecies_t *s, const char *sid);


/**
 * Sets the "initialAmount" attribute value of the given CSpecies_t
 * structure.
 *
 * As a side-effect, calling this function also unsets the
 * "initialConcentration" attribute.
 *
 * @param s the CSpecies_t structure.
 *
 * @param value the numerical value for the "initialAmount" attribute.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(int) CSpecies_setInitialAmount (CSpecies_t *s, double value);


/**
 * Sets the "initialConcentration" attribute value of the given CSpecies_t
 * structure.
 *
 * As a side-effect, calling this function also unsets the "initialAmount"
 * attribute.
 *
 * @param s the CSpecies_t structure.
 *
 * @param value the numerical value for the "initialConcentration"
 * attribute.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_UNEXPECTED_ATTRIBUTE, OperationReturnValues_t}
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(int) CSpecies_setInitialConcentration (CSpecies_t *s, double value);


/**
 * Sets the "substanceUnits" attribute of the given CSpecies_t structure.
 *
 * This function copies the string given in @p sid.  If the string
 * is @c NULL, this function is equivalent to calling
 * CSpecies_unsetSubstanceUnits().
 *
 * @param s the CSpecies_t structure.
 *
 * @param sid the identifer to which the "substanceUnits"
 * attribute should be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @note Using this function with an @p sid of NULL is equivalent to
 * unsetting the "substanceUnits" attribute.
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(int) CSpecies_setSubstanceUnits (CSpecies_t *s, const char *sid);


/**
 * Sets the "spatialSizeUnits" attribute of the given CSpecies_t structure.
 *
 * This function copies the string given in @p sid.  If the string is @c NULL,
 * this function is equivalent to calling CSpecies_unsetSpatialSizeUnits().
 *
 * @param s the CSpecies_t structure.
 *
 * @param sid the identifer to which the "spatialSizeUnits"
 * attribute should be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_UNEXPECTED_ATTRIBUTE, OperationReturnValues_t}
 *
 * @note Using this function with an @p sid of NULL is equivalent to
 * unsetting the "spatialSizeUnits" attribute.
 *
 * @copydetails doc_warning_species_spatialSizeUnits
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(int) CSpecies_setSpatialSizeUnits (CSpecies_t *s, const char *sid);


/**
 * (SBML Level 1 only) Sets the "units" attribute of the given CSpecies_t
 * structure.
 *
 * This function copies the string given in @p sid.  If the string is @c NULL,
 * this function is equivalent to calling CSpecies_unsetUnits().
 *
 * @param s the CSpecies_t structure.
 *
 * @param sname the identifer to which the "units" attribute
 * should be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @note Using this function with an @p sname of NULL is equivalent to
 * unsetting the "units" attribute.
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(int) CSpecies_setUnits (CSpecies_t *s, const char *sname);


/**
 * Sets the "hasOnlySubstanceUnits" attribute of the given CSpecies_t
 * structure.
 *
 * @param s the CSpecies_t structure.
 *
 * @param value @c nonzero to indicate true, @c zero to indicate false.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_UNEXPECTED_ATTRIBUTE, OperationReturnValues_t}
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(int) CSpecies_setHasOnlySubstanceUnits (CSpecies_t *s, int value);


/**
 * Sets the "boundaryCondition" attribute of the given CSpecies_t
 * structure.
 *
 * @param s the CSpecies_t structure.
 *
 * @param value @c nonzero to indicate true, @c zero to indicate false.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(int) CSpecies_setBoundaryCondition (CSpecies_t *s, int value);


/**
 * Sets the "charge" attribute of the given CSpecies_t
 * structure.
 *
 * @param s the CSpecies_t structure.
 *
 * @param value the value of charge to assign to the "charge" attribute.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_UNEXPECTED_ATTRIBUTE, OperationReturnValues_t}
 *
 * @note Beginning in SBML Level 2 Version&nbsp;2, the "charge" attribute on
 * CSpecies_t in SBML is deprecated and its use strongly discouraged.  Its
 * presence is considered a misfeature in earlier definitions of SBML
 * because its implications for the mathematics of a model were never
 * defined, and in any case, no known modeling system ever used it.
 * Instead, models take account of charge values directly in their
 * definitions of species by (for example) having separate species
 * identities for the charged and uncharged versions of the same species.
 * This allows the condition to affect model mathematics directly.
 * LibSBML retains this method for easier compatibility with SBML Level 1.
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(int) CSpecies_setCharge (CSpecies_t *s, int value);


/**
 * Sets the "constant" attribute of the given CSpecies_t
 * structure.
 *
 * @param s the CSpecies_t structure.
 *
 * @param value @c nonzero to indicate true, @c zero to indicate false.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_UNEXPECTED_ATTRIBUTE, OperationReturnValues_t}
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(int) CSpecies_setConstant (CSpecies_t *s, int value);


/**
 * Sets the "conversionFactor" attribute of the given CSpecies_t structure.
 *
 * This function copies the string given in @p sid.  If the string
 * is @c NULL, this function is equivalent to calling
 * CSpecies_unsetConversionFactor().
 *
 * @param s the CSpecies_t structure.
 *
 * @param sid the identifer to which the "conversionFactor" attribute
 * should be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_UNEXPECTED_ATTRIBUTE, OperationReturnValues_t}
 *
 * @note Using this function with an @p sid of NULL is equivalent to
 * unsetting the "conversionFactor" attribute.
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(int) CSpecies_setConversionFactor (CSpecies_t *s, const char *sid);


/**
 * Unsets the "id" attribute of the given CSpecies_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(int) CSpecies_unsetId (CSpecies_t *s);


/**
 * Unsets the "name" attribute of the given CSpecies_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(int) CSpecies_unsetName(CSpecies_t *s);


/**
 * Unsets the value of the "constant" attribute of the given CSpecies_t
 * structure.
 *
 * @param c the CSpecies_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(int) CSpecies_unsetConstant (CSpecies_t *c);


/**
 * Unsets the "speciesType" attribute of the given CSpecies_t structure.
 *
 * @param s the CSpecies_t structure whose attribute is to be unset.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(int) CSpecies_unsetSpeciesType (CSpecies_t *s);


/**
 * Unsets the "initialAmount" attribute of the given CSpecies_t structure.
 *
 * @param s the CSpecies_t structure whose attribute is to be unset.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(int) CSpecies_unsetInitialAmount (CSpecies_t *s);


/**
 * Unsets the "initialConcentration" attribute of the given
 * CSpecies_t structure.
 *
 * @param s the CSpecies_t structure whose attribute is to be unset.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(int) CSpecies_unsetInitialConcentration (CSpecies_t *s);


/**
 * Unsets the "substanceUnits" attribute of the given
 * CSpecies_t structure.
 *
 * @param s the CSpecies_t structure whose attribute is to be unset.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(int) CSpecies_unsetSubstanceUnits (CSpecies_t *s);


/**
 * Unsets the "spatialSizeUnits" attribute of the given
 * CSpecies_t structure.
 *
 * @param s the CSpecies_t structure whose attribute is to be unset.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @copydetails doc_warning_species_spatialSizeUnits
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(int) CSpecies_unsetSpatialSizeUnits (CSpecies_t *s);


/**
 * Unsets the "units" attribute of the given
 * CSpecies_t structure.
 *
 * @param s the CSpecies_t structure whose attribute is to be unset.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(int) CSpecies_unsetUnits (CSpecies_t *s);


/**
 * Unsets the "charge" attribute of the given
 * CSpecies_t structure.
 *
 * @param s the CSpecies_t structure whose attribute is to be unset.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @note Beginning in SBML Level 2 Version&nbsp;2, the "charge" attribute on
 * CSpecies_t in SBML is deprecated and its use strongly discouraged.  Its
 * presence is considered a misfeature in earlier definitions of SBML
 * because its implications for the mathematics of a model were never
 * defined, and in any case, no known modeling system ever used it.
 * Instead, models take account of charge values directly in their
 * definitions of species by (for example) having separate species
 * identities for the charged and uncharged versions of the same species.
 * This allows the condition to affect model mathematics directly.
 * LibSBML retains this method for easier compatibility with SBML Level 1.
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(int) CSpecies_unsetCharge (CSpecies_t *s);

/**
 * Unsets the "conversionFactor" attribute of the given CSpecies_t structure.
 *
 * @param s the CSpecies_t structure whose attribute is to be unset.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(int) CSpecies_unsetConversionFactor (CSpecies_t *s);


/**
 * Unsets the "compartment" attribute of the given CSpecies_t structure.
 *
 * @param s the CSpecies_t structure whose attribute is to be unset.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(int) CSpecies_unsetCompartment (CSpecies_t *s);


/**
 * Unsets the "boundaryCondition" attribute of the given CSpecies_t structure.
 *
 * @param s the CSpecies_t structure whose attribute is to be unset.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(int) CSpecies_unsetBoundaryCondition (CSpecies_t *s);


/**
 * Unsets the "hasOnlySubstanceUnits" attribute of the given CSpecies_t structure.
 *
 * @param s the CSpecies_t structure whose attribute is to be unset.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(int) CSpecies_unsetHasOnlySubstanceUnits (CSpecies_t *s);


/**
 * Constructs and returns a UnitDefinition_t structure that expresses
 * the units of this CSpecies_t structure.
 *
 * @param s the CSpecies_t structure whose units are to be returned.
 *
 * @return a UnitDefinition_t structure that expresses the units
 * of this CSpecies_t strucuture.
 *
 * @note This function returns the units of the CSpecies_t expressed
 * as a UnitDefinition_t. The units may be those explicitly declared
 * or those derived from the default units of the Model_t containing
 * this CSpecies_t and it's Compartment_t.
 *
 * Note that the functionality that facilitates unit analysis depends
 * on the model as a whole.  Thus, in cases where the structure has not
 * been added to a model or the model itself is incomplete,
 * unit analysis is not possible and this method will return @c NULL.
 *
 *
 * @memberof CSpecies_t
 */
//CAPI_FUNC(UnitDefinition_t *) CSpecies_getDerivedUnitDefinition(CSpecies_t *s);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether
 * all the required attributes for this CSpecies_t structure
 * have been set.
 *
 * The required attributes for a CSpecies_t structure are:
 * @li id (name L1)
 * @li compartment
 * @li initialAmount (L1 only)
 * @li hasOnlySubstanceUnits (L3 on)
 * @li boundaryCondition (L3 on)
 * @li constant (L3 on)
 *
 * @param s the CSpecies_t structure to check.
 *
 * @return a true if all the required
 * attributes for this structure have been defined, @c 0 (false) otherwise.
 *
 * @memberof CSpecies_t
 */
CAPI_FUNC(int) CSpecies_hasRequiredAttributes (CSpecies_t *s);


/**
 * Returns the CSpecies_t structure having a given identifier.
 *
 * @param lo the ListOfCSpecies_t structure to search.
 * @param sid the "id" attribute value being sought.
 *
 * @return item in the @p lo ListOfSpecies with the given @p sid or a
 * null pointer if no such item exists.
 *
 * @see ListOf_t
 *
 * @memberof ListOfCSpecies_t
 */
//CAPI_FUNC(CSpecies_t *) ListOfCSpecies_getById (ListOf_t *lo, const char *sid);


/**
 * Removes a CSpecies_t structure based on its identifier.
 *
 * The caller owns the returned item and is responsible for deleting it.
 *
 * @param lo the list of CSpecies_t structures to search.
 * @param sid the "id" attribute value of the structure to remove.
 *
 * @return The CSpecies_t structure removed, or a null pointer if no such
 * item exists in @p lo.
 *
 * @see ListOf_t
 *
 * @memberof ListOfCSpecies_t
 */
//CAPI_FUNC(CSpecies_t *) ListOfCSpecies_removeById (ListOf_t *lo, const char *sid);


CAPI_DATA(PyTypeObject) CSpecies_Type;



#endif /* EXTERN_CARBON_INCLUDE_C_SPECIES_H_ */
