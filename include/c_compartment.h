/*
 * c_compartment.h
 *
 *  Created on: Jun 5, 2020
 *      Author: andy
 *
 *  copy of the libSBML API, originally written by Ben Bornstein
 */

#ifndef EXTERN_CARBON_INCLUDE_C_COMPARTMENT_H_
#define EXTERN_CARBON_INCLUDE_C_COMPARTMENT_H_

#include <c_port.h>

CAPI_STRUCT(CCompartment_t);
CAPI_STRUCT(UnitDefinition_t);
CAPI_STRUCT(ListOf_t);

/* ----------------------------------------------------------------------------
 * See the .cpp file for the documentation of the following functions.
 * --------------------------------------------------------------------------*/

/*
CAPI_FUNC(CCompartment_t *) CCompartment_createWithLevelVersionAndNamespaces (unsigned int level,
              unsigned int version, XMLNamespaces_t *xmlns);
*/

/**
 * Creates a new CCompartment_t structure using the given SBML @p level and @p
 * version values.
 *
 * @param level an unsigned int, the SBML Level to assign to this
 * CCompartment_t structure.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * CCompartment_t structure.
 *
 * @returns the newly-created CCompartment_t structure, or a null pointer if
 * an error occurred during constructions.
 *
 * @copydetails doc_note_setting_lv
 *
 * @memberof CCompartment_t
 */
CAPI_FUNC(CCompartment_t *) CCompartment_create (unsigned int level, unsigned int version);


/**
 * Creates a new CCompartment_t structure using the given SBMLNamespaces_t
 * structure, @p sbmlns.
 *
 * @copydetails doc_what_are_sbmlnamespaces
 *
 * It is worth emphasizing that although this constructor does not take an
 * identifier argument, in SBML Level&nbsp;2 and beyond, the "id"
 * (identifier) attribute of a CCompartment_t instance is required to have a
 * value.  Thus, callers are cautioned to assign a value after calling this
 * constructor.  Setting the identifier can be accomplished using the method
 * CCompartment_setId().
 *
 * @param sbmlns an SBMLNamespaces_t structure.
 *
 * @returns the newly-created CCompartment_t structure, or a null pointer if
 * an error occurred during constructions
 *
 * @copydetails doc_note_setting_lv
 *
 * @memberof CCompartment_t
 */
//CAPI_FUNC(CCompartment_t *) CCompartment_createWithNS (SBMLNamespaces_t *sbmlns);


/**
 * Frees the given CCompartment_t structure.
 *
 * @param c the CCompartment_t structure to be freed.
 *
 * @memberof CCompartment_t
 */
CAPI_FUNC(void) CCompartment_free (CCompartment_t *c);


/**
 * Creates a deep copy of the given CCompartment_t structure.
 *
 * @param c the CCompartment_t structure to be copied.
 *
 * @return a (deep) copy of the given CCompartment_t structure, or a null
 * pointer if a failure occurred.
 *
 * @memberof CCompartment_t
 */
CAPI_FUNC(CCompartment_t *) CCompartment_clone (const CCompartment_t* c);


/**
 * Initializes the fields of the given CCompartment_t structure to "typical"
 * default values.
 *
 * The SBML Compartment component has slightly different aspects and
 * default attribute values in different SBML Levels and Versions.
 * This method sets the values to certain common defaults, based
 * mostly on what they are in SBML Level&nbsp;2.  Specifically:
 *
 * @li Sets attribute "spatialDimensions" to @c 3
 * @li Sets attribute "constant" to @c 1 (true)
 * @li (Applies to Level&nbsp;1 models only) Sets attribute "volume" to @c 1.0
 * @li (Applies to Level&nbsp;3 models only) Sets attribute "units" to @c litre
 *
 * @param c the CCompartment_t structure.
 *
 * @memberof CCompartment_t
 */
CAPI_FUNC(void) CCompartment_initDefaults (CCompartment_t *c);


/**
 * Returns a list of XMLNamespaces_t structures associated with the given
 * CCompartment_t structure.
 *
 * @param c the CCompartment_t structure.
 *
 * @return pointer to the XMLNamespaces_t structure associated with this SBML
 * structure
 *
 * @memberof CCompartment_t
 */
//CAPI_FUNC(const XMLNamespaces_t *) CCompartment_getNamespaces(CCompartment_t *c);


/**
 * Returns the value of the "id" attribute of the given CCompartment_t
 * structure.
 *
 * @param c the CCompartment_t structure.
 *
 * @return the id of this structure.
 *
 * @memberof CCompartment_t
 */
CAPI_FUNC(const char *) CCompartment_getId (const CCompartment_t *c);


/**
 * Returns the value of the "name" attribute of the given CCompartment_t
 * structure.
 *
 * @param c the CCompartment_t structure.
 *
 * @return the name of the CCompartment_t structure @p c, as a pointer to a
 * string.
 *
 * @memberof CCompartment_t
 */
CAPI_FUNC(const char *) CCompartment_getName (const CCompartment_t *c);


/**
 * Get the value of the "compartmentType" attribute of the given CCompartment_t
 * structure.
 *
 * @param c the CCompartment_t structure.
 *
 * @return the value of the "compartmentType" attribute of the
 * CCompartment_t structure @p c as a string.
 *
 * @note The "compartmentType" attribute is only available in SBML
 * Level&nbsp;2 Versions&nbsp;2&ndash;4.
 *
 * @memberof CCompartment_t
 */
CAPI_FUNC(const char *) CCompartment_getCompartmentType (const CCompartment_t *c);


/**
 * Get the number of spatial dimensions of the given CCompartment_t structure.
 *
 * @param c the CCompartment_t structure.
 *
 * @return the value of the "spatialDimensions" attribute of the
 * CCompartment_t structure @p c as an unsigned integer
 *
 * @copydetails doc_note_spatial_dimensions_as_double
 *
 * @see CCompartment_getSpatialDimensionsAsDouble()
 *
 * @memberof CCompartment_t
 */
CAPI_FUNC(unsigned int) CCompartment_getSpatialDimensions (const CCompartment_t *c);


/**
 * Get the number of spatial dimensions of the given CCompartment_t structure,
 * as a double.
 *
 * @param c the CCompartment_t structure.
 *
 * @return the value of the "spatialDimensions" attribute of the
 * CCompartment_t structure @p c as a double.
 *
 * @copydetails doc_note_spatial_dimensions_as_double
 *
 * @see CCompartment_getSpatialDimensions()
 *
 * @memberof CCompartment_t
 */
CAPI_FUNC(double) CCompartment_getSpatialDimensionsAsDouble (const CCompartment_t *c);


/**
 * Get the size of the given CCompartment_t structure.
 *
 * @copydetails doc_compartment_both_size_and_volume
 *
 * @param c the CCompartment_t structure.
 *
 * @return the value of the "size" attribute ("volume" in Level 1) of
 * the CCompartment_t structure @p c as a floating point number.
 *
 * @note This method is identical to CCompartment_getVolume().
 *
 * @see CCompartment_isSetSize()
 * @see CCompartment_getVolume()
 *
 * @memberof CCompartment_t
 */
CAPI_FUNC(double) CCompartment_getSize (const CCompartment_t *c);


/**
 * Get the volume of the given CCompartment_t structure.
 *
 * @copydetails doc_compartment_both_size_and_volume
 *
 * @param c the CCompartment_t structure.
 *
 * @return the value of the "volume" attribute ("size" in Level&nbsp;2) of
 * @p c, as a floating-point number.
 *
 * @copydetails doc_note_compartment_volume
 *
 * @note This method is identical to CCompartment_getSize().
 *
 * @see CCompartment_isSetVolume()
 * @see CCompartment_getSize()
 *
 * @memberof CCompartment_t
 */
CAPI_FUNC(double) CCompartment_getVolume (const CCompartment_t *c);


/**
 * Get the units of the given CCompartment_t structure's size.
 *
 * The value of an SBML compartment's "units" attribute establishes the
 * unit of measurement associated with the compartment's size.
 *
 * @param c the CCompartment_t structure.
 *
 * @return the value of the "units" attribute of the CCompartment_t structure,
 * as a string.  An empty string indicates that no units have been assigned
 * to the value of the size.
 *
 * @copydetails doc_note_unassigned_unit_are_not_a_default
 *
 * @see CCompartment_isSetUnits()
 * @see CCompartment_setUnits()
 * @see CCompartment_getSize()
 *
 * @memberof CCompartment_t
 */
CAPI_FUNC(const char *) CCompartment_getUnits (const CCompartment_t *c);


/**
 * Get the identifier, if any, of the compartment that is designated
 * as being outside of the given CCompartment_t structure.
 *
 * @param c the CCompartment_t structure.
 *
 * @return the value of the "outside" attribute of this CCompartment_t
 * structure.
 *
 * @note The "outside" attribute is defined in SBML Level&nbsp;1 and
 * Level&nbsp;2, but does not exist in SBML Level&nbsp;3.
 *
 * @memberof CCompartment_t
 */
CAPI_FUNC(const char *) CCompartment_getOutside (const CCompartment_t *c);


/**
 * Get the value of the "constant" attribute of the given CCompartment_t
 * structure.
 *
 * @param c the CCompartment_t structure.
 *
 * @return @c 1 (true) if this compartment's size is flagged as being
 * constant, @c 0 (false) otherwise.
 *
 * @memberof CCompartment_t
 */
CAPI_FUNC(int) CCompartment_getConstant (const CCompartment_t *c);


/**
 * Predicate returning @c 1 (true) if the given CCompartment_t structure's "id"
 * attribute is set.
 *
 * @param c the CCompartment_t structure.
 *
 * @return @c 1 (true) if the "id" attribute of this CCompartment_t structure is
 * set, @c 0 (false) otherwise.
 *
 * @memberof CCompartment_t
 */
CAPI_FUNC(int) CCompartment_isSetId (const CCompartment_t *c);


/**
 * Predicate returning @c 1 (true) if the given CCompartment_t structure's "name"
 * attribute is set.
 *
 * @param c the CCompartment_t structure.
 *
 * @return @c 1 (true) if the "name" attribute of this CCompartment_t structure is
 * set, @c 0 (false) otherwise.
 *
 * @memberof CCompartment_t
 */
CAPI_FUNC(int) CCompartment_isSetName (const CCompartment_t *c);


/**
 * Predicate returning @c 1 (true) if the given CCompartment_t structure's
 * "compartmentType" attribute is set.
 *
 * @param c the CCompartment_t structure.
 *
 * @return @c 1 (true) if the "compartmentType" attribute of this CCompartment_t
 * structure is set, @c 0 (false) otherwise.
 *
 * @note The "compartmentType" attribute is only available in SBML
 * Level&nbsp;2 Versions&nbsp;2&ndash;4.
 *
 * @memberof CCompartment_t
 */
CAPI_FUNC(int) CCompartment_isSetCompartmentType (const CCompartment_t *c);


/**
 * Predicate returning @c 1 (true) if the given CCompartment_t structure's "size"
 * attribute is set.
 *
 * This method is similar but not identical to CCompartment_isSetVolume().
 * The latter should be used in the context of SBML Level&nbsp;1 models
 * instead of CCompartment_isSetSize() because CCompartment_isSetVolume()
 * performs extra processing to take into account the difference in default
 * values between SBML Levels&nbsp;1 and&nbsp;2.
 *
 * @param c the CCompartment_t structure.
 *
 * @return @c 1 (true) if the "size" attribute ("volume" in Level&nbsp;2) of
 * this CCompartment_t structure is set, @c 0 (false) otherwise.
 *
 * @see CCompartment_isSetVolume()
 * @see CCompartment_setSize()
 *
 * @memberof CCompartment_t
 */
CAPI_FUNC(int) CCompartment_isSetSize (const CCompartment_t *c);


/**
 * Predicate returning @c 1 (true) if the given CCompartment_t structures's "volume"
 * attribute is set.
 *
 * This method is similar but not identical to CCompartment_isSetSize().  The
 * latter should not be used in the context of SBML Level&nbsp;1 models
 * because the present method performs extra processing to take into account
 * the difference in default values between SBML Levels&nbsp;1 and&nbsp;2.
 *
 * @param c the CCompartment_t structure.
 *
 * @return @c 1 (true) if the "volume" attribute ("size" in Level&nbsp;2 and
 * above) of this CCompartment_t structure is set, @c 0 (false) otherwise.
 *
 * @copydetails doc_note_compartment_volume
 *
 * @see CCompartment_isSetSize()
 * @see CCompartment_setVolume()
 *
 * @memberof CCompartment_t
 */
CAPI_FUNC(int) CCompartment_isSetVolume (const CCompartment_t *c);


/**
 * Predicate returning @c 1 (true) if the given CCompartment_t structure's "units"
 * attribute is set.
 *
 * @param c the CCompartment_t structure.
 *
 * @return @c 1 (true) if the "units" attribute of this CCompartment_t structure
 * is set, @c 0 (false) otherwise.
 *
 * @copydetails doc_note_unassigned_unit_are_not_a_default
 *
 * @memberof CCompartment_t
 */
CAPI_FUNC(int) CCompartment_isSetUnits (const CCompartment_t *c);


/**
 * Predicate returning @c 1 (true) if the given CCompartment_t structure's "outside"
 * attribute is set.
 *
 * @param c the CCompartment_t structure.
 *
 * @return @c 1 (true) if the "outside" attribute of this CCompartment_t structure
 * is set, @c 0 (false) otherwise.
 *
 * @note The "outside" attribute is defined in SBML Level&nbsp;1 and
 * Level&nbsp;2, but does not exist in SBML Level&nbsp;3.
 *
 * @memberof CCompartment_t
 */
CAPI_FUNC(int) CCompartment_isSetOutside (const CCompartment_t *c);


/**
 * Predicate returning @c 1 (true) if the given CCompartment_t structure's
 * "spatialDimensions" attribute is set.
 *
 * @param c the CCompartment_t structure.
 *
 * @return @c 1 (true) if the "spatialDimensions" attribute of this CCompartment_t
 * structure is set, @c 0 (false) otherwise.
 *
 * @memberof CCompartment_t
 */
CAPI_FUNC(int) CCompartment_isSetSpatialDimensions (const CCompartment_t *c);


/**
 * Predicate returning @c 1 (true) if the given CCompartment_t structure's "constant"
 * attribute is set.
 *
 * @return @c 1 (true) if the "constant" attribute of this CCompartment_t
 * structure is set, @c 0 (false) otherwise.
 *
 * @memberof CCompartment_t
 */
CAPI_FUNC(int) CCompartment_isSetConstant (const CCompartment_t *c);


/**
 * Sets the value of the "id" attribute of the given CCompartment_t structure.
 *
 * The string @p sid is copied.
 *
 * @copydetails doc_id_attribute
 *
 * @param c the CCompartment_t structure.
 *
 * @param sid the identifier to which the structures "id" attribute should
 * be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @note Using this function with a null pointer for @p sid is equivalent to
 * unsetting the "id" attribute.
 *
 * @memberof CCompartment_t
 */
CAPI_FUNC(int) CCompartment_setId (CCompartment_t *c, const char *sid);


/**
 * Sets the "name" attribute of the given CCompartment_t structure.
 *
 * This function copies the string given in @p name.  If the string is
 * a null pointer, this function is equivalent to calling CCompartment_unsetName().
 *
 * @param c the CCompartment_t structure.
 *
 * @param name the string to which the structures "name" attribute should be
 * set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @note Using this function with a null pointer for @p name is equivalent to
 * unsetting the value of the "name" attribute.
 *
 * @memberof CCompartment_t
 */
CAPI_FUNC(int) CCompartment_setName (CCompartment_t *c, const char *name);


/**
 * Sets the "compartmentType" attribute of the given CCompartment_t
 * structure.
 *
 * @param c the CCompartment_t structure.
 * @param sid the identifier of a CompartmentType_t structure defined
 * elsewhere in the enclosing Model_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_UNEXPECTED_ATTRIBUTE, OperationReturnValues_t}
 *
 * @note Using this function with a null pointer for @p sid is equivalent to
 * unsetting the value of the "compartmentType" attribute.
 *
 * @note The "compartmentType" attribute is only available in SBML
 * Level&nbsp;2 Versions&nbsp;2&ndash;4.
 *
 * @memberof CCompartment_t
 */
CAPI_FUNC(int) CCompartment_setCompartmentType (CCompartment_t *c, const char *sid);


/**
 * Sets the "spatialDimensions" attribute of the given CCompartment_t
 * structure.
 *
 * @param c the CCompartment_t structure.
 * @param value an unsigned integer indicating the number of dimensions
 * of the given compartment.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_UNEXPECTED_ATTRIBUTE, OperationReturnValues_t}
 *
 * @memberof CCompartment_t
 */
CAPI_FUNC(int) CCompartment_setSpatialDimensions (CCompartment_t *c, unsigned int value);


/**
 * Sets the "spatialDimensions" attribute of the given CCompartment_t
 * structure.
 *
 * @param c the CCompartment_t structure.
 * @param value a double indicating the number of dimensions
 * of the given compartment.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_UNEXPECTED_ATTRIBUTE, OperationReturnValues_t}
 *
 * @memberof CCompartment_t
 */
CAPI_FUNC(int) CCompartment_setSpatialDimensionsAsDouble (CCompartment_t *c, double value);


/**
 * Sets the "size" attribute (or "volume" in SBML Level 1) of the given
 * CCompartment_t structure.
 *
 * @param c the CCompartment_t structure.
 * @param value a @c double representing the size of the given
 * CCompartment_t structure in whatever units are in effect.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @see CCompartment_isSetSize()
 * @see CCompartment_setVolume()
 *
 * @memberof CCompartment_t
 */
CAPI_FUNC(int) CCompartment_setSize (CCompartment_t *c, double value);


/**
 * Sets the "volume" attribute (or "size" in SBML Level 2) of the given
 * CCompartment_t structure.
 *
 * This method is identical to CCompartment_setSize() and is provided for
 * compatibility between SBML Level&nbsp;1 and higher Levels of SBML.
 *
 * @param c the CCompartment_t structure.
 *
 * @param value a @c double representing the volume of the given
 * CCompartment_t structure in whatever units are in effect.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_note_compartment_volume
 *
 * @see CCompartment_isSetVolume()
 * @see CCompartment_setSize()
 *
 * @memberof CCompartment_t
 */
CAPI_FUNC(int) CCompartment_setVolume (CCompartment_t *c, double value);


/**
 * Sets the "units" attribute of the given CCompartment_t structure.
 *
 * @param c the CCompartment_t structure.
 *
 * @param sid the identifier of the defined units to use.  The string will
 * be copied.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @note Using this function with a null pointer for @p sid is equivalent to
 * unsetting the value of the "units" attribute.
 *
 * @memberof CCompartment_t
 */
CAPI_FUNC(int) CCompartment_setUnits (CCompartment_t *c, const char *sid);


/**
 * Sets the "outside" attribute of the given CCompartment_t structure.
 *
 * @param c the CCompartment_t structure.
 *
 * @param sid the identifier of a compartment that encloses this one.  The
 * string will be copied.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @note Using this function with a null pointer for @p sid is equivalent to
 * unsetting the value of the "outside" attribute.
 *
 * @memberof CCompartment_t
 */
CAPI_FUNC(int) CCompartment_setOutside (CCompartment_t *c, const char *sid);


/**
 * Sets the value of the "constant" attribute of the given CCompartment_t
 * structure.
 *
 * @param c the CCompartment_t structure.
 *
 * @param value an integer indicating whether the size/volume of the
 * compartment @p c should be considered constant (indicated by a nonzero @p
 * value) or variable (@p value is zero).
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_UNEXPECTED_ATTRIBUTE, OperationReturnValues_t}
 *
 * @memberof CCompartment_t
 */
CAPI_FUNC(int) CCompartment_setConstant (CCompartment_t *c, int value);


/**
 * Unsets the "name" attribute of the given CCompartment_t structure.
 *
 * @param c the CCompartment_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof CCompartment_t
 */
CAPI_FUNC(int) CCompartment_unsetName (CCompartment_t *c);


/**
 * Unsets the value of the "compartmentType" attribute of the given
 * CCompartment_t structure.
 *
 * @param c the CCompartment_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof CCompartment_t
 */
CAPI_FUNC(int) CCompartment_unsetCompartmentType (CCompartment_t *c);


/**
 * Unsets the value of the "constant" attribute of the given CCompartment_t
 * structure.
 *
 * @param c the CCompartment_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof CCompartment_t
 */
CAPI_FUNC(int) CCompartment_unsetConstant (CCompartment_t *c);


/**
 * Unsets the value of the "size" attribute of the given CCompartment_t
 * structure.
 *
 * In SBML Level&nbsp;1, a compartment's volume has a default value
 * (@c 1.0) and therefore <em>should always be set</em>.  Calling this method
 * on a Level&nbsp;1 model resets the value to @c 1.0 rather than actually
 * unsetting it.  In Level&nbsp;2, a compartment's "size" is optional with
 * no default value, and unsetting it will result in the compartment having
 * no defined size.
 *
 * @param c the CCompartment_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof CCompartment_t
 */
CAPI_FUNC(int) CCompartment_unsetSize (CCompartment_t *c);


/**
 * (For SBML Level 1) Unsets the value of the "volume" attribute of the
 * given CCompartment_t structure.
 *
 * This method is identical to CCompartment_unsetSize().  Please refer to that
 * method's documentation for more information about its behavior.
 *
 * @param c the CCompartment_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_note_compartment_volume
 *
 * @see CCompartment_unsetSize()
 *
 * @memberof CCompartment_t
 */
CAPI_FUNC(int) CCompartment_unsetVolume (CCompartment_t *c);


/**
 * Unsets the value of the "units" attribute of the given CCompartment_t
 * structure.
 *
 * @param c the CCompartment_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof CCompartment_t
 */
CAPI_FUNC(int) CCompartment_unsetUnits (CCompartment_t *c);


/**
 * Unsets the value of the "outside" attribute of the given CCompartment_t
 * structure.
 *
 * @param c the CCompartment_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof CCompartment_t
 */
CAPI_FUNC(int) CCompartment_unsetOutside (CCompartment_t *c);


/**
 * Unsets the value of the "spatialDimensions" attribute of the given
 * CCompartment_t structure.
 *
 * In SBML Levels prior to Level&nbsp;3, compartments must always have a
 * value for the number of dimensions.  Consequently, calling this method
 * on a model of SBML Level 1&ndash;2 will result in a return value of
 * @sbmlconstant{LIBSBML_UNEXPECTED_ATTRIBUTE, OperationReturnValues_t}
 *
 * @param c the CCompartment_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof CCompartment_t
 */
CAPI_FUNC(int) CCompartment_unsetSpatialDimensions (CCompartment_t *c);


/**
 * Constructs and returns a UnitDefinition that corresponds to the units
 * of the given CCompartment_t structure's designated size.
 *
 * @copydetails doc_compartment_units
 *
 * @param c the CCompartment_t structure whose units are to be returned.
 *
 * @return a UnitDefinition_t structure that expresses the units
 * of the given CCompartment_t structure.
 *
 * @copydetails doc_note_unit_analysis_depends_on_model
 *
 * @see CCompartment_isSetUnits()
 * @see CCompartment_getUnits()
 *
 * @memberof CCompartment_t
 */
CAPI_FUNC(UnitDefinition_t *) CCompartment_getDerivedUnitDefinition(CCompartment_t *c);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether all the required
 * attributes for the given CCompartment_t structure have been set.
 *
 * The required attributes for a CCompartment_t structure are:
 * @li id (name in SBML Level 1 only)
 * @li constant (in SBML Level 3 only)
 *
 * @param c the CCompartment_t structure to check.
 *
 * @return @c 1 (true) if all the required attributes for this
 * structure have been defined, @c 0 (false) otherwise.
 *
 * @memberof CCompartment_t
 */
CAPI_FUNC(int) CCompartment_hasRequiredAttributes (CCompartment_t *c);


/**
 * Returns the CCompartment_t structure having a given identifier.
 *
 * @param lo the list of Compartments_t structures to search.
 * @param sid the "id" attribute value being sought.
 *
 * @return item in the @p lo ListOfCompartments with the given @p sid or a
 * null pointer if no such item exists.
 *
 * @see ListOf_t
 *
 * @memberof ListOfCompartments_t
 */
CAPI_FUNC(CCompartment_t *) ListOfCompartments_getById (ListOf_t *lo, const char *sid);


/**
 * Removes a CCompartment_t structure based on its identifier.
 *
 * The caller owns the returned item and is responsible for deleting it.
 *
 * @param lo the list of CCompartment_t structures to search.
 * @param sid the "id" attribute value of the structure to remove.
 *
 * @return The CCompartment_t structure removed, or a null pointer if no such
 * item exists in @p lo.
 *
 * @see ListOf_t
 *
 * @memberof ListOfCompartments_t
 */
CAPI_FUNC(CCompartment_t *) ListOfCompartments_removeById (ListOf_t *lo, const char *sid);


#endif /* EXTERN_CARBON_INCLUDE_C_COMPARTMENT_H_ */
