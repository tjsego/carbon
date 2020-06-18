/*
 * c_model.h
 *
 *  Created on: Jun 18, 2020
 *      Author: andy
 */

#ifndef EXTERN_CARBON_INCLUDE_C_MODEL_H_
#define EXTERN_CARBON_INCLUDE_C_MODEL_H_

#include <c_port.h>

CAPI_STRUCT(CModel_t);
CAPI_STRUCT(SBMLNamespaces_t);
CAPI_STRUCT(XMLNamespaces_t);
CAPI_STRUCT(ModelHistory_t);
CAPI_STRUCT(FunctionDefinition_t);
CAPI_STRUCT(UnitDefinition_t);
CAPI_STRUCT(CompartmentType_t);
CAPI_STRUCT(SpeciesType_t);
CAPI_STRUCT(Compartment_t);
CAPI_STRUCT(Species_t);
CAPI_STRUCT(Parameter_t);
CAPI_STRUCT(InitialAssignment_t);
CAPI_STRUCT(Rule_t);
CAPI_STRUCT(Constraint_t);
CAPI_STRUCT(Reaction_t);
CAPI_STRUCT(Event_t);
CAPI_STRUCT(Unit_t);
CAPI_STRUCT(SpeciesReference_t);
CAPI_STRUCT(KineticLaw_t);
CAPI_STRUCT(LocalParameter_t);
CAPI_STRUCT(EventAssignment_t);
CAPI_STRUCT(Trigger_t);
CAPI_STRUCT(Delay_t);
CAPI_STRUCT(ListOf_t);

/**
 * Creates a new Model_t structure using the given SBML @p level
 * and @p version values.
 *
 * @param level an unsigned int, the SBML Level to assign to this
 * Model_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * Model_t.
 *
 * @return a pointer to the newly created Model_t structure.
 *
 * @copydetails doc_note_setting_lv
 *
 * @memberof Model_t
 */
CAPI_FUNC(CModel_t *) CModel_create (unsigned int level, unsigned int version);


/**
 * Creates a new CModel_t structure using the given
 * SBMLNamespaces_t structure.
 *
 * @param sbmlns SBMLNamespaces_t, a pointer to an SBMLNamespaces_t structure
 * to assign to this CModel_t.
 *
 * @return a pointer to the newly created CModel_t structure.
 *
 * @copydetails doc_note_setting_lv
 *
 * @memberof CModel_t
 */
CAPI_FUNC(CModel_t *) CModel_createWithNS (SBMLNamespaces_t *sbmlns);


/**
 * Creates and returns a deep copy of a given CModel_t structure.
 *
 * @param m the CModel_t structure to copy.
 *
 * @return a (deep) copy of this CModel_t structure.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(CModel_t *) CModel_clone (const CModel_t *m);


/**
 * Frees the given CModel_t structure.
 *
 * @param m the CModel_structure to free.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(void) CModel_free (CModel_t *m);


/**
 * Returns a list of XMLNamespaces_t associated with this CModel_t
 * structure.
 *
 * @param m the CModel_t structure.
 *
 * @return pointer to the XMLNamespaces_t structure associated with
 * this structure
 *
 * @memberof CModel_t
 */
CAPI_FUNC(const XMLNamespaces_t *) CModel_getNamespaces(CModel_t *m);


/**
 * Get the identifier of the given CModel_t structure.
 *
 * @param m the CModel_t structure.
 *
 * @return the id of this CModel_t structure.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(const char *) CModel_getId (const CModel_t *m);


/**
 * Get the name of the given CModel_t structure.
 *
 * @param m the CModel_t structure.
 *
 * @return the name of this CModel_t structure.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(const char *) CModel_getName (const CModel_t *m);


/**
 * Get the substanceUnits of the given CModel_t structure.
 *
 * @param m the CModel_t structure.
 *
 * @return the substanceUnits of this CModel_t structure.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(const char *) CModel_getSubstanceUnits (const CModel_t *m);


/**
 * Get the timeUnits of the given CModel_t structure.
 *
 * @param m the CModel_t structure.
 *
 * @return the timeUnits of this CModel_t structure.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(const char *) CModel_getTimeUnits (const CModel_t *m);


/**
 * Get the volumeUnits of the given CModel_t structure.
 *
 * @param m the CModel_t structure.
 *
 * @return the volumeUnits of this CModel_t structure.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(const char *) CModel_getVolumeUnits (const CModel_t *m);


/**
 * Get the areaUnits of the given CModel_t structure.
 *
 * @param m the CModel_t structure.
 *
 * @return the areaUnits of this CModel_t structure.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(const char *) CModel_getAreaUnits (const CModel_t *m);


/**
 * Get the lengthUnits of the given CModel_t structure.
 *
 * @param m the CModel_t structure.
 *
 * @return the lengthUnits of this CModel_t structure.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(const char *) CModel_getLengthUnits (const CModel_t *m);


/**
 * Get the extentUnits of the given CModel_t structure.
 *
 * @param m the CModel_t structure.
 *
 * @return the extentUnits of this CModel_t structure.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(const char *) CModel_getExtentUnits (const CModel_t *m);


/**
 * Get the conversionFactor of the given CModel_t structure.
 *
 * @param m the CModel_t structure.
 *
 * @return the conversionFactor of this CModel_t structure.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(const char *) CModel_getConversionFactor (const CModel_t *m);


/**
 * Predicate for testing whether the identifier of a given CModel_t
 * structure is assigned.
 *
 * @param m the CModel_t structure.
 *
 * @return @c 1 (true) if the "id" attribute of this CModel_t structure is
 * set, @c 0 (false) otherwise.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(int) CModel_isSetId (const CModel_t *m);


/**
 * Predicate for testing whether the name of a given CModel_t structure is
 * assigned.
 *
 * @param m the CModel_t structure.
 *
 * @return @c 1 (true) if the "name" attribute of this CModel_t structure is
 * set, @c 0 (false) otherwise.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(int) CModel_isSetName (const CModel_t *m);


/**
 * Predicate for testing whether the substanceUnits of a given CModel_t structure is
 * assigned.
 *
 * @param m the CModel_t structure.
 *
 * @return @c 1 (true) if the "substanceUnits" attribute of this CModel_t structure is
 * set, @c 0 (false) otherwise.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(int) CModel_isSetSubstanceUnits (const CModel_t *m);


/**
 * Predicate for testing whether the timeUnits of a given CModel_t structure is
 * assigned.
 *
 * @param m the CModel_t structure.
 *
 * @return @c 1 (true) if the "timeUnits" attribute of this CModel_t structure is
 * set, @c 0 (false) otherwise.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(int) CModel_isSetTimeUnits (const CModel_t *m);


/**
 * Predicate for testing whether the volumeUnits of a given CModel_t structure is
 * assigned.
 *
 * @param m the CModel_t structure.
 *
 * @return @c 1 (true) if the "volumeUnits" attribute of this CModel_t structure is
 * set, @c 0 (false) otherwise.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(int) CModel_isSetVolumeUnits (const CModel_t *m);


/**
 * Predicate for testing whether the areaUnits of a given CModel_t structure is
 * assigned.
 *
 * @param m the CModel_t structure.
 *
 * @return @c 1 (true) if the "areaUnits" attribute of this CModel_t structure is
 * set, @c 0 (false) otherwise.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(int) CModel_isSetAreaUnits (const CModel_t *m);


/**
 * Predicate for testing whether the lengthUnits of a given CModel_t structure is
 * assigned.
 *
 * @param m the CModel_t structure.
 *
 * @return @c 1 (true) if the "lengthUnits" attribute of this CModel_t structure is
 * set, @c 0 (false) otherwise.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(int) CModel_isSetLengthUnits (const CModel_t *m);


/**
 * Predicate for testing whether the extentUnits of a given CModel_t structure is
 * assigned.
 *
 * @param m the CModel_t structure.
 *
 * @return @c 1 (true) if the "extentUnits" attribute of this CModel_t structure is
 * set, @c 0 (false) otherwise.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(int) CModel_isSetExtentUnits (const CModel_t *m);


/**
 * Predicate for testing whether the conversionFactor of a given CModel_t structure is
 * assigned.
 *
 * @param m the CModel_t structure.
 *
 * @return @c 1 (true) if the "conversionFactor" attribute of this CModel_t structure is
 * set, @c 0 (false) otherwise.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(int) CModel_isSetConversionFactor (const CModel_t *m);


/**
 * Set the identifier of a given CModel_t structure.
 *
 * This copies the string in @p sid.
 *
 * @param m the CModel_t structure.
 * @param sid the identifier string.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @note Using this function with an @p sid of NULL is equivalent to
 * unsetting the "id" attribute.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(int) CModel_setId (CModel_t *m, const char *sid);


/**
 * Set the identifier of the given CModel_t structure.
 *
 * This copies the string in @p name.
 *
 * @param m the CModel_t structure.
 * @param name the name string.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @note Using this function with the name set to NULL is equivalent to
 * unsetting the "name" attribute.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(int) CModel_setName (CModel_t *m, const char *name);


/**
 * Set the substanceUnits attribute of a given CModel_t structure.
 *
 * This copies the string in @p units.
 *
 * @param m the CModel_t structure.
 * @param units the identifier string.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_UNEXPECTED_ATTRIBUTE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @note Using this function with units NULL is equivalent to
 * unsetting the "substanceUnits" attribute.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(int) CModel_setSubstanceUnits (CModel_t *m, const char *units);


/**
 * Set the timeUnits attribute of a given CModel_t structure.
 *
 * This copies the string in @p units.
 *
 * @param m the CModel_t structure.
 * @param units the identifier string.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_UNEXPECTED_ATTRIBUTE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @note Using this function with units NULL is equivalent to
 * unsetting the "timeUnits" attribute.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(int) CModel_setTimeUnits (CModel_t *m, const char *units);


/**
 * Set the volumeUnits attribute of a given CModel_t structure.
 *
 * This copies the string in @p units.
 *
 * @param m the CModel_t structure.
 * @param units the identifier string.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_UNEXPECTED_ATTRIBUTE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @note Using this function with units NULL is equivalent to
 * unsetting the "volumeUnits" attribute.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(int) CModel_setVolumeUnits (CModel_t *m, const char *units);


/**
 * Set the areaUnits attribute of a given CModel_t structure.
 *
 * This copies the string in @p units.
 *
 * @param m the CModel_t structure.
 * @param units the identifier string.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_UNEXPECTED_ATTRIBUTE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @note Using this function with units NULL is equivalent to
 * unsetting the "areaUnits" attribute.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(int) CModel_setAreaUnits (CModel_t *m, const char *units);


/**
 * Set the lengthUnits attribute of a given CModel_t structure.
 *
 * This copies the string in @p units.
 *
 * @param m the CModel_t structure.
 * @param units the identifier string.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_UNEXPECTED_ATTRIBUTE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @note Using this function with units NULL is equivalent to
 * unsetting the "lengthUnits" attribute.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(int) CModel_setLengthUnits (CModel_t *m, const char *units);


/**
 * Set the extentUnits attribute of a given CModel_t structure.
 *
 * This copies the string in @p units.
 *
 * @param m the CModel_t structure.
 * @param units the identifier string.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_UNEXPECTED_ATTRIBUTE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @note Using this function with units NULL is equivalent to
 * unsetting the "extentUnits" attribute.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(int) CModel_setExtentUnits (CModel_t *m, const char *units);


/**
 * Set the conversionFactor attribute of a given CModel_t structure.
 *
 * This copies the string in @p sid.
 *
 * @param m the CModel_t structure.
 * @param sid the identifier string.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_UNEXPECTED_ATTRIBUTE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @note Using this function with sid NULL is equivalent to
 * unsetting the "conversionFactor" attribute.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(int) CModel_setConversionFactor (CModel_t *m, const char *sid);


/**
 * Unsets the "id" attribute of the given CModel_t structure.
 *
 * @param m the CModel_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof CModel_t
 */
CAPI_FUNC(int) CModel_unsetId (CModel_t *m);


/**
 * Unsets the "name" attribute of the given CModel_t structure.
 *
 * @param m the CModel_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof CModel_t
 */
CAPI_FUNC(int) CModel_unsetName (CModel_t *m);


/**
 * Unsets the "substanceUnits" attribute of the given CModel_t structure.
 *
 * @param m the CModel_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_UNEXPECTED_ATTRIBUTE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof CModel_t
 */
CAPI_FUNC(int) CModel_unsetSubstanceUnits (CModel_t *m);


/**
 * Unsets the "timeUnits" attribute of the given CModel_t structure.
 *
 * @param m the CModel_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_UNEXPECTED_ATTRIBUTE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof CModel_t
 */
CAPI_FUNC(int) CModel_unsetTimeUnits (CModel_t *m);


/**
 * Unsets the "volumeUnits" attribute of the given CModel_t structure.
 *
 * @param m the CModel_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_UNEXPECTED_ATTRIBUTE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof CModel_t
 */
CAPI_FUNC(int) CModel_unsetVolumeUnits (CModel_t *m);


/**
 * Unsets the "areaUnits" attribute of the given CModel_t structure.
 *
 * @param m the CModel_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_UNEXPECTED_ATTRIBUTE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof CModel_t
 */
CAPI_FUNC(int) CModel_unsetAreaUnits (CModel_t *m);


/**
 * Unsets the "lengthUnits" attribute of the given CModel_t structure.
 *
 * @param m the CModel_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_UNEXPECTED_ATTRIBUTE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof CModel_t
 */
CAPI_FUNC(int) CModel_unsetLengthUnits (CModel_t *m);


/**
 * Unsets the "extentUnits" attribute of the given CModel_t structure.
 *
 * @param m the CModel_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_UNEXPECTED_ATTRIBUTE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof CModel_t
 */
CAPI_FUNC(int) CModel_unsetExtentUnits (CModel_t *m);


/**
 * Unsets the "conversionFactor" attribute of the given CModel_t structure.
 *
 * @param m the CModel_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_UNEXPECTED_ATTRIBUTE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof CModel_t
 */
CAPI_FUNC(int) CModel_unsetConversionFactor (CModel_t *m);


/**
 * Returns the ModelHistory_t of the given CModel_t structure.
 *
 * @return the ModelHistory_t of the given CModel_t structure.
 *
 * @param m the CModel_t structure.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(ModelHistory_t *) CModel_getModelHistory(CModel_t *m);


/**
 * Predicate for testing whether the ModelHistory_t of a given CModel_t structure is
 * assigned.
 *
 * @param m the CModel_t structure.
 *
 * @return @c 1 (true) if the ModelHistory_t of this CModel_t structure is
 * set, @c 0 (false) otherwise.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(int) CModel_isSetModelHistory(CModel_t *m);


/**
 * Set the ModelHistory_t of the given CModel_t structure.
 *
 * @param m the CModel_t structure.
 * @param history the ModelHistory_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof CModel_t
 */
CAPI_FUNC(int) CModel_setModelHistory(CModel_t *m, ModelHistory_t *history);


/**
 * Unsets the ModelHistory_t of the given CModel_t structure.
 *
 * @param m the CModel_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof CModel_t
 */
CAPI_FUNC(int) CModel_unsetModelHistory(CModel_t *m);


/**
 * Adds a copy of a FunctionDefinition_t structure to a given CModel_t
 * structure.
 *
 * @param m the CModel_t structure.
 * @param fd the FunctionDefinition_t structure to copy and add.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_LEVEL_MISMATCH, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_VERSION_MISMATCH, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_DUPLICATE_OBJECT_ID, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof CModel_t
 */
CAPI_FUNC(int) CModel_addFunctionDefinition (CModel_t *m, const FunctionDefinition_t *fd);


/**
 * Adds a copy of a UnitDefinition_t structure to a given CModel_t structure.
 *
 * @param m the CModel_t structure.
 * @param ud the UnitDefinition_t structure to copy and add.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_LEVEL_MISMATCH, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_VERSION_MISMATCH, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_DUPLICATE_OBJECT_ID, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof CModel_t
 */
CAPI_FUNC(int) CModel_addUnitDefinition (CModel_t *m, const UnitDefinition_t *ud);


/**
 * Adds a copy of a CompartmentType_t structure to a given CModel_t structure.
 *
 * @param m the CModel_t structure.
 * @param ct the CompartmentType_t structure to copy and add.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_LEVEL_MISMATCH, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_VERSION_MISMATCH, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_DUPLICATE_OBJECT_ID, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof CModel_t
 */
CAPI_FUNC(int) CModel_addCompartmentType (CModel_t *m, const CompartmentType_t *ct);


/**
 * Adds a copy of a SpeciesType_t structure to a given CModel_t structure.
 *
 * @param m the CModel_t structure.
 * @param st the SpeciesType_t structure to copy and add.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_LEVEL_MISMATCH, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_VERSION_MISMATCH, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_DUPLICATE_OBJECT_ID, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof CModel_t
 */
CAPI_FUNC(int) CModel_addSpeciesType (CModel_t *m, const SpeciesType_t *st);


/**
 * Adds a copy of a Compartment_t structure to a given CModel_t structure.
 *
 * @param m the CModel_t structure.
 * @param c the Compartment_t structure to copy and add.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_LEVEL_MISMATCH, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_VERSION_MISMATCH, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_DUPLICATE_OBJECT_ID, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof CModel_t
 */
CAPI_FUNC(int) CModel_addCompartment (CModel_t *m, const Compartment_t *c);


/**
 * Adds a copy of a Species_t structure to a given CModel_t structure.
 *
 * @param m the CModel_t structure.
 * @param s the Species_t structure to copy and add.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_LEVEL_MISMATCH, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_VERSION_MISMATCH, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_DUPLICATE_OBJECT_ID, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof CModel_t
 */
CAPI_FUNC(int) CModel_addSpecies (CModel_t *m, const Species_t *s);


/**
 * Adds a copy of a Parameter_t structure to a given CModel_t structure.
 *
 * @param m the CModel_t structure.
 * @param p the Parameter_t structure to copy and add.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_LEVEL_MISMATCH, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_VERSION_MISMATCH, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_DUPLICATE_OBJECT_ID, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof CModel_t
 */
CAPI_FUNC(int) CModel_addParameter (CModel_t *m, const Parameter_t *p);


/**
 * Adds a copy of a InitialAssignment_t structure to a given CModel_t structure.
 *
 * @param m the CModel_t structure.
 * @param ia the InitialAssignment_t structure to copy and add.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_LEVEL_MISMATCH, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_VERSION_MISMATCH, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_DUPLICATE_OBJECT_ID, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof CModel_t
 */
CAPI_FUNC(int) CModel_addInitialAssignment (CModel_t *m, const InitialAssignment_t *ia);


/**
 * Adds a copy of a Rule_t structure to a given CModel_t structure.
 *
 * @param m the CModel_t structure.
 * @param r the Rule_t structure to copy and add.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_LEVEL_MISMATCH, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_VERSION_MISMATCH, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_DUPLICATE_OBJECT_ID, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof CModel_t
 */
CAPI_FUNC(int) CModel_addRule (CModel_t *m, const Rule_t *r);


/**
 * Adds a copy of a Constraint_t structure to a given CModel_t structure.
 *
 * @param m the CModel_t structure.
 * @param c the Constraint_t structure to copy and add.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_LEVEL_MISMATCH, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_VERSION_MISMATCH, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof CModel_t
 */
CAPI_FUNC(int) CModel_addConstraint (CModel_t *m, const Constraint_t *c);


/**
 * Adds a copy of a Reaction_t structure to a given CModel_t structure.
 *
 * @param m the CModel_t structure.
 * @param r the Reaction_t structure to copy and add.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_LEVEL_MISMATCH, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_VERSION_MISMATCH, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_DUPLICATE_OBJECT_ID, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof CModel_t
 */
CAPI_FUNC(int) CModel_addReaction (CModel_t *m, const Reaction_t *r);


/**
 * Adds a copy of a Event_t structure to a given CModel_t structure.
 *
 * @param m the CModel_t structure.
 * @param e the Event_t structure to copy and add.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_LEVEL_MISMATCH, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_VERSION_MISMATCH, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_DUPLICATE_OBJECT_ID, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof CModel_t
 */
CAPI_FUNC(int) CModel_addEvent (CModel_t *m, const Event_t *e);


/**
 * Creates a new FunctionDefinition_t structure inside the given CModel_t
 * and returns a pointer to it.
 *
 * @param m the CModel_t structure.
 *
 * @return the new FunctionDefinition_t structure
 *
 * @memberof CModel_t
 */
CAPI_FUNC(FunctionDefinition_t *) CModel_createFunctionDefinition (CModel_t *m);


/**
 * Creates a new UnitDefinition_t structure inside the given CModel_t and
 * returns a pointer to it.
 *
 * @param m the CModel_t structure.
 *
 * @return the new UnitDefinition_t structure
 *
 * @memberof CModel_t
 */
CAPI_FUNC(UnitDefinition_t *) CModel_createUnitDefinition (CModel_t *m);


/**
 * Creates a new Unit_t structure inside the last UnitDefinition_t
 * structure created in this model and returns a pointer to it.
 *
 * The mechanism by which the UnitDefinition_t structure was created is not
 * significant.  If a UnitDefinition_t does not exist in this model, a new
 * Unit_t structure is @em not created and @c NULL is returned instead.
 *
 * @param m the CModel_t structure.
 *
 * @return the Unit_t structure created, or @c NULL.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(Unit_t *) CModel_createUnit (CModel_t *m);


/**
 * Creates a new CompartmentType_t structure inside the given CModel_t and
 * returns a pointer to it.
 *
 * @param m the CModel_t structure.
 *
 * @return the CompartmentType_t structure created
 *
 * @memberof CModel_t
 */
CAPI_FUNC(CompartmentType_t *) CModel_createCompartmentType (CModel_t *m);


/**
 * Creates a new SpeciesType_t structure inside the given CModel_t and
 * returns a pointer to it.
 *
 * @param m the CModel_t structure.
 *
 * @return the SpeciesType_t structure created
 *
 * @memberof CModel_t
 */
CAPI_FUNC(SpeciesType_t *) CModel_createSpeciesType (CModel_t *m);


/**
 * Creates a new Compartment_t structure inside the given CModel_t and
 * returns a pointer to it.
 *
 * @param m the CModel_t structure.
 *
 * @return the Compartment_t structure created
 *
 * @memberof CModel_t
 */
CAPI_FUNC(Compartment_t *) CModel_createCompartment (CModel_t *m);


/**
 * Creates a new Species_t structure inside the given CModel_t and returns a
 * pointer to it.
 *
 * @param m the CModel_t structure.
 *
 * @return the Species_t structure created
 *
 * @memberof CModel_t
 */
CAPI_FUNC(Species_t *) CModel_createSpecies (CModel_t *m);


/**
 * Creates a new Parameter_t structure inside the given CModel_t and returns
 * a pointer to it.
 *
 * @param m the CModel_t structure.
 *
 * @return the Parameter_t structure created
 *
 * @memberof CModel_t
 */
CAPI_FUNC(Parameter_t *) CModel_createParameter (CModel_t *m);


/**
 * Creates a new InitialAssignment_t structure inside the given CModel_t
 * structure and returns it.
 *
 * @param m the CModel_t structure.
 *
 * @return the InitialAssignment_t structure created
 *
 * @memberof CModel_t
 */
CAPI_FUNC(InitialAssignment_t *) CModel_createInitialAssignment (CModel_t *m);


/**
 * Creates a new AlgebraicRule_t structure inside the given CModel_t
 * structure and returns a pointer to it.
 *
 * @param m the CModel_t structure.
 *
 * @return the AlgebraicRule_t structure created.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(Rule_t *) CModel_createAlgebraicRule (CModel_t *m);


/**
 * Creates a new AssignmentRule_t structure inside the given CModel_t
 * structure and returns a pointer to it.
 *
 * @param m the CModel_t structure.
 *
 * @return the AssignmentRule_t structure created
 *
 * @memberof CModel_t
 */
CAPI_FUNC(Rule_t *) CModel_createAssignmentRule (CModel_t *m);


/**
 * Creates a new RateRule_t structure inside the given CModel_t structure
 * and returns a pointer to it.
 *
 * @param m the CModel_t structure.
 *
 * @return the RateRule_t structure created.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(Rule_t *) CModel_createRateRule (CModel_t *m);


/**
 * Creates a new Constraint_t structure inside the given CModel_t structure
 * and returns it.
 *
 * @param m the CModel_t structure.
 *
 * @return the Constraint_t structure created.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(Constraint_t *) CModel_createConstraint (CModel_t *m);


/**
 * Creates a new Reaction_t structure inside the given CModel_t structure
 * and returns a pointer to it.
 *
 * @param m the CModel_t structure.
 *
 * @return the Reaction_t structure created.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(Reaction_t *) CModel_createReaction (CModel_t *m);


/**
 * Creates a new SpeciesReference_t structure for a reactant inside the
 * last Reaction_t structure in the given CModel_t structure, and returns a
 * pointer to it.
 *
 * The mechanism by which the last Reaction_t structure was created and
 * added to @p m is not significant.  It could have been created in a
 * variety of ways, for example using CModel_createReaction().  If a
 * Reaction_t structure does not exist, a new SpeciesReference_t structure
 * is @em not created and @c NULL is returned instead.
 *
 * @param m the CModel_t structure.
 *
 * @return the SpeciesReference_t structure created
 *
 * @memberof CModel_t
 */
CAPI_FUNC(SpeciesReference_t *) CModel_createReactant (CModel_t *m);


/**
 * Creates a new SpeciesReference_t structure for a product inside the
 * last Reaction_t structure in the given CModel_t structure, and returns a
 * pointer to it.
 *
 * The mechanism by which the last Reaction_t structure was created and
 * added to @p m is not significant.  It could have been created in a
 * variety of ways, for example using CModel_createReaction().  If a
 * Reaction_t structure does not exist, a new SpeciesReference_t structure
 * is @em not created and @c NULL is returned instead.
 *
 * @param m the CModel_t structure.
 *
 * @return the SpeciesReference_t structure created
 *
 * @memberof CModel_t
 */
CAPI_FUNC(SpeciesReference_t *) CModel_createProduct (CModel_t *m);


/**
 * Creates a new modifier SpeciesReference_t structure for a reactant inside
 * the last Reaction_t structure in the given CModel_t structure, and
 * returns a pointer to it.
 *
 * The mechanism by which the last Reaction_t structure was created and
 * added to @p m is not significant.  It could have been created in a
 * variety of ways, for example using CModel_createReaction().  If a
 * Reaction_t structure does not exist, a new modifier SpeciesReference_t
 * structure is @em not created and @c NULL is returned instead.
 *
 * @param m the CModel_t structure.
 *
 * @return the modifier SpeciesReference_t structure created
 *
 * @memberof CModel_t
 */
CAPI_FUNC(SpeciesReference_t *) CModel_createModifier (CModel_t *m);


/**
 * Creates a new KineticLaw_t structure inside the last Reaction_t
 * structure in the given CModel_t structure, and returns a pointer to it.
 *
 * The mechanism by which the last Reaction_t structure was created and
 * added to @p m is not significant.  It could have been created in a
 * variety of ways, for example using CModel_createReaction().  If a
 * Reaction_t structure does not exist for the model, or a Reaction_t
 * structure exists but already contains a KineticLaw_t structure, a new
 * KineticLaw_t is @em not created and @c NULL is returned instead.
 *
 * @param m the CModel_t structure.
 *
 * @return the KineticLaw_t structure created
 *
 * @memberof CModel_t
 */
CAPI_FUNC(KineticLaw_t *) CModel_createKineticLaw (CModel_t *m);


/**
 * Creates a new local Parameter_t structure inside the KineticLaw_t
 * structure of the last Reaction_t structure created inside the given
 * model, and returns a pointer to it.
 *
 * The last KineticLaw_t structure could have been created in a variety of
 * ways.  For example, it could have been added using
 * CModel_createKineticLaw(), or it could be the result of using
 * Reaction_createKineticLaw() on the Reaction_t structure created by a
 * CModel_createReaction().  If a Reaction_t structure does not exist for
 * this model, or the last Reaction_t structure does not contain a
 * KineticLaw_t structure, a new Parameter_t is @em not created and NULL is
 * returned instead.
 *
 * @param m the CModel_t structure.
 *
 * @return the Parameter_t structure created
 *
 * @memberof CModel_t
 */
CAPI_FUNC(Parameter_t *) CModel_createKineticLawParameter (CModel_t *m);


/**
 * Creates a new LocalParameter_t structure inside the KineticLaw_t
 * structure of the last Reaction_t structure created inside the given
 * model, and returns a pointer to it.
 *
 * The last KineticLaw_t structure could have been created in a variety of
 * ways.  For example, it could have been added using
 * CModel_createKineticLaw(), or it could be the result of using
 * Reaction_createKineticLaw() on the Reaction_t structure created by a
 * CModel_createReaction().  If a Reaction_t structure does not exist for
 * this model, or the last Reaction_t structure does not contain a
 * KineticLaw_t structure, a new LocalParameter_t is @em not created and NULL is
 * returned instead.
 *
 * @param m the CModel_t structure.
 *
 * @return the LocalParameter_t structure created
 *
 * @memberof CModel_t
 */
CAPI_FUNC(LocalParameter_t *) CModel_createKineticLawLocalParameter (CModel_t *m);


/**
 * Creates a new Event inside the given CModel_t structure and returns a
 * pointer to it.
 *
 * @param m the CModel_t structure.
 *
 * @return a new Event_t structure
 *
 * @memberof CModel_t
 */
CAPI_FUNC(Event_t *) CModel_createEvent (CModel_t *m);


/**
 * Creates a new EventAssignment_t structure inside the last Event_t
 * structure created in the given CModel_t structure, and returns a pointer
 * to it.
 *
 * The mechanism by which the last Event_t structure was created is not
 * significant.  It could have been created in a variety of ways, for
 * example by using CModel_createEvent().  If an Event_t structure does not
 * exist, a new EventAssignment_t structure is @em not created and NULL is
 * returned instead.
 *
 * @param m the CModel_t structure.
 *
 * @return the new EventAssignment_t structure
 *
 * @memberof CModel_t
 */
CAPI_FUNC(EventAssignment_t *) CModel_createEventAssignment (CModel_t *m);


/**
 * Creates a new Trigger_t structure inside the last Event_t
 * structure created in the given CModel_t structure, and returns a pointer
 * to it.
 *
 * The mechanism by which the last Event_t structure was created is not
 * significant.  It could have been created in a variety of ways, for
 * example by using CModel_createEvent().  If an Event_t structure does not
 * exist, a new Trigger_t structure is @em not created and NULL is
 * returned instead.
 *
 * @param m the CModel_t structure.
 *
 * @return the new Trigger_t structure
 *
 * @memberof CModel_t
 */
CAPI_FUNC(Trigger_t *) CModel_createTrigger (CModel_t *m);


/**
 * Creates a new Delay_t structure inside the last Event_t
 * structure created in the given CModel_t structure, and returns a pointer
 * to it.
 *
 * The mechanism by which the last Event_t structure was created is not
 * significant.  It could have been created in a variety of ways, for
 * example by using CModel_createEvent().  If an Event_t structure does not
 * exist, a new Delay_t structure is @em not created and NULL is
 * returned instead.
 *
 * @param m the CModel_t structure.
 *
 * @return the new Delay_t structure
 *
 * @memberof CModel_t
 */
CAPI_FUNC(Delay_t *) CModel_createDelay (CModel_t *m);


/**
 * Get the list of FunctionDefinition_t structures contained in the given
 * CModel_t structure.
 *
 * @param m the CModel_t structure.
 *
 * @return the list of FunctionDefinition_t structures
 *
 * @memberof CModel_t
 */
CAPI_FUNC(ListOf_t *) CModel_getListOfFunctionDefinitions (CModel_t *m);


/**
 * Get the list of UnitDefinition_t structures contained in the given
 * CModel_t structure.
 *
 * @param m the CModel_t structure.
 *
 * @return the list of UnitDefinition_t structures.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(ListOf_t *) CModel_getListOfUnitDefinitions (CModel_t *m);


/**
 * Get the list of CompartmentType_t structures contained in the given
 * CModel_t structure.
 *
 * @param m the CModel_t structure.
 *
 * @return the list of CompartmentType_t structures.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(ListOf_t *) CModel_getListOfCompartmentTypes (CModel_t *m);


/**
 * Get the list of SpeciesType_t structures contained in the given CModel_t
 * structure.
 *
 * @param m the CModel_t structure.
 *
 * @return the list of SpeciesType_t structures.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(ListOf_t *) CModel_getListOfSpeciesTypes (CModel_t *m);


/**
 * Get the list of Compartment_t structures contained in the given CModel_t
 * structure.
 *
 * @param m the CModel_t structure.
 *
 * @return the list of Compartment_t structures.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(ListOf_t *) CModel_getListOfCompartments (CModel_t *m);


/**
 * Get the list of Species_t structures contained in the given CModel_t
 * structure.
 *
 * @param m the CModel_t structure.
 *
 * @return the list of Species_t structures.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(ListOf_t *) CModel_getListOfSpecies (CModel_t *m);


/**
 * Get the list of Parameter_t structures contained in the given CModel_t
 * structure.
 *
 * @param m the CModel_t structure.
 *
 * @return the list of Parameter_t structures.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(ListOf_t *) CModel_getListOfParameters (CModel_t *m);


/**
 * Get the list of InitialAssignment_t structures contained in the given
 * CModel_t structure.
 *
 * @param m the CModel_t structure.
 *
 * @return the list of InitialAssignment_t structures.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(ListOf_t *) CModel_getListOfInitialAssignments (CModel_t* m);


/**
 * Get the list of Rule_t structures contained in the given CModel_t
 * structure.
 *
 * @param m the CModel_t structure.
 *
 * @return the list of Rule_t structures.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(ListOf_t *) CModel_getListOfRules (CModel_t *m);


/**
 * Get the list of Constraint_t structures contained in the given CModel_t
 * structure.
 *
 * @param m the CModel_t structure.
 *
 * @return the list of Constraint_t structures.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(ListOf_t *) CModel_getListOfConstraints (CModel_t* m);


/**
 * Get the list of Reaction_t structures contained in the given CModel_t
 * structure.
 *
 * @param m the CModel_t structure.
 *
 * @return the list of Reaction_t structures.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(ListOf_t *) CModel_getListOfReactions (CModel_t *m);


/**
 * Get the list of Event_t structures contained in the given CModel_t
 * structure.
 *
 * @param m the CModel_t structure.
 *
 * @return the list of Event_t structures.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(ListOf_t *) CModel_getListOfEvents (CModel_t *m);


/**
 * Get the nth FunctionDefinition_t structure contained in the given
 * CModel_t structure.
 *
 * @param m the CModel_t structure.
 * @param n the integer index of the FunctionDefinition_t sought.
 *
 * @return the FunctionDefinition_t if found, or @c NULL if not found
 *
 * @memberof CModel_t
 */
CAPI_FUNC(FunctionDefinition_t *) CModel_getFunctionDefinition (CModel_t *m, unsigned int n);


/**
 * Get the FunctionDefinition_t structure whose identifier is @p sid in the
 * given CModel_t structure.
 *
 * @param m the CModel_t structure.
 * @param sid the identifier of the FunctionDefinition_t structure sought.
 *
 * @return the FunctionDefinition_t if found, or @c NULL if not found
 *
 * @memberof CModel_t
 */
CAPI_FUNC(FunctionDefinition_t *) CModel_getFunctionDefinitionById (CModel_t *m, const char *sid);


/**
 * Get the nth UnitDefinition_t structure contained in the given
 * CModel_t structure.
 *
 * @param m the CModel_t structure.
 * @param n the integer index of the UnitDefinition_t sought.
 *
 * @return the UnitDefinition_t if found, or @c NULL if not found
 *
 * @memberof CModel_t
 */
CAPI_FUNC(UnitDefinition_t *) CModel_getUnitDefinition (CModel_t *m, unsigned int n);


/**
 * Get the UnitDefinition_t structure whose identifier is @p sid in the
 * given CModel_t structure.
 *
 * @param m the CModel_t structure.
 * @param sid the identifier of the UnitDefinition_t structure sought.
 *
 * @return the UnitDefinition_t if found, or @c NULL if not found
 *
 * @memberof CModel_t
 */
CAPI_FUNC(UnitDefinition_t *) CModel_getUnitDefinitionById (CModel_t *m, const char *sid);


/**
 * Get the nth CompartmentType_t structure contained in the given
 * CModel_t structure.
 *
 * @param m the CModel_t structure.
 * @param n the integer index of the CompartmentType_t sought.
 *
 * @return the CompartmentType_t if found, or @c NULL if not found
 *
 * @memberof CModel_t
 */
CAPI_FUNC(CompartmentType_t *) CModel_getCompartmentType (CModel_t *m, unsigned int n);


/**
 * Get the CompartmentType_t structure whose identifier is @p sid in the
 * given CModel_t structure.
 *
 * @param m the CModel_t structure.
 * @param sid the identifier of the CompartmentType_t structure sought.
 *
 * @return the CompartmentType_t if found, or @c NULL if not found
 *
 * @memberof CModel_t
 */
CAPI_FUNC(CompartmentType_t *) CModel_getCompartmentTypeById (CModel_t *m, const char *sid);


/**
 * Get the nth SpeciesType_t structure contained in the given
 * CModel_t structure.
 *
 * @param m the CModel_t structure.
 * @param n the integer index of the SpeciesType_t sought.
 *
 * @return the SpeciesType_t if found, or @c NULL if not found
 *
 * @memberof CModel_t
 */
CAPI_FUNC(SpeciesType_t *) CModel_getSpeciesType (CModel_t *m, unsigned int n);


/**
 * Get the SpeciesType_t structure whose identifier is @p sid in the
 * given CModel_t structure.
 *
 * @param m the CModel_t structure.
 * @param sid the identifier of the SpeciesType_t structure sought.
 *
 * @return the SpeciesType_t if found, or @c NULL if not found
 *
 * @memberof CModel_t
 */
CAPI_FUNC(SpeciesType_t *) CModel_getSpeciesTypeById (CModel_t *m, const char *sid);


/**
 * Get the nth Compartment_t structure contained in the given
 * CModel_t structure.
 *
 * @param m the CModel_t structure.
 * @param n the integer index of the Compartment_t sought.
 *
 * @return the Compartment_t if found, or @c NULL if not found
 *
 * @memberof CModel_t
 */
CAPI_FUNC(Compartment_t *) CModel_getCompartment (CModel_t *m, unsigned int n);


/**
 * Get the Compartment_t structure whose identifier is @p sid in the
 * given CModel_t structure.
 *
 * @param m the CModel_t structure.
 * @param sid the identifier of the Compartment_t structure sought.
 *
 * @return the Compartment_t if found, or @c NULL if not found
 *
 * @memberof CModel_t
 */
CAPI_FUNC(Compartment_t *) CModel_getCompartmentById (CModel_t *m, const char *sid);


/**
 * Get the nth Species_t structure contained in the given
 * CModel_t structure.
 *
 * @param m the CModel_t structure.
 * @param n the integer index of the Species_t sought.
 *
 * @return the Species_t if found, or @c NULL if not found
 *
 * @memberof CModel_t
 */
CAPI_FUNC(Species_t *) CModel_getSpecies (CModel_t *m, unsigned int n);


/**
 * Get the Species_t structure whose identifier is @p sid in the
 * given CModel_t structure.
 *
 * @param m the CModel_t structure.
 * @param sid the identifier of the Species_t structure sought.
 *
 * @return the Species_t if found, or @c NULL if not found
 *
 * @memberof CModel_t
 */
CAPI_FUNC(Species_t *) CModel_getSpeciesById (CModel_t *m, const char *sid);


/**
 * Get the nth Parameter_t structure contained in the given
 * CModel_t structure.
 *
 * @param m the CModel_t structure.
 * @param n the integer index of the Parameter_t sought.
 *
 * @return the Parameter_t if found, or @c NULL if not found
 *
 * @memberof CModel_t
 */
CAPI_FUNC(Parameter_t *) CModel_getParameter (CModel_t *m, unsigned int n);


/**
 * Get the Parameter_t structure whose identifier is @p sid in the
 * given CModel_t structure.
 *
 * @param m the CModel_t structure.
 * @param sid the identifier of the Parameter_t structure sought.
 *
 * @return the Parameter_t if found, or @c NULL if not found
 *
 * @memberof CModel_t
 */
CAPI_FUNC(Parameter_t *) CModel_getParameterById (CModel_t *m, const char *sid);


/**
 * Get the nth InitialAssignment_t structure contained in the given
 * CModel_t structure.
 *
 * @param m the CModel_t structure.
 * @param n the integer index of the InitialAssignment_t sought.
 *
 * @return the InitialAssignment_t if found, or @c NULL if not found
 *
 * @memberof CModel_t
 */
CAPI_FUNC(InitialAssignment_t *) CModel_getInitialAssignment (CModel_t *m, unsigned int n);


/**
 * @return the InitialAssignment_t in this CModel_t with the given symbol or
 * @c NULL if no such InitialAssignment_t exists.
 *
 * @param m the CModel_t structure.
 * @param symbol the symbol to search for.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(InitialAssignment_t *) CModel_getInitialAssignmentBySym (CModel_t *m, const char *symbol);


/**
 * Get the nth Rule_t structure contained in the given
 * CModel_t structure.
 *
 * @param m the CModel_t structure.
 * @param n the integer index of the Rule_t sought.
 *
 * @return the Rule_t if found, or @c NULL if not found
 *
 * @memberof CModel_t
 */
CAPI_FUNC(Rule_t *) CModel_getRule (CModel_t *m, unsigned int n);


/**
 * @return the Rule_t in this CModel_t with the given variable or @c NULL if no
 * such Rule_t exists.
 *
 * @param m the CModel_t structure.
 * @param variable the variable to search for.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(Rule_t *) CModel_getRuleByVar (CModel_t *m, const char *variable);


/**
 * Get the nth Constraint_t structure contained in the given
 * CModel_t structure.
 *
 * @param m the CModel_t structure.
 * @param n the integer index of the Constraint_t sought.
 *
 * @return the Constraint_t if found, or @c NULL if not found
 *
 * @memberof CModel_t
 */
CAPI_FUNC(Constraint_t *) CModel_getConstraint (CModel_t *m, unsigned int n);


/**
 * Get the nth Reaction_t structure contained in the given
 * CModel_t structure.
 *
 * @param m the CModel_t structure.
 * @param n the integer index of the Reaction_t sought.
 *
 * @return the Reaction_t if found, or @c NULL if not found
 *
 * @memberof CModel_t
 */
CAPI_FUNC(Reaction_t *) CModel_getReaction (CModel_t *m, unsigned int n);


/**
 * Get the Reaction_t structure whose identifier is @p sid in the
 * given CModel_t structure.
 *
 * @param m the CModel_t structure.
 * @param sid the identifier of the Reaction_t structure sought.
 *
 * @return the Reaction_t if found, or @c NULL if not found
 *
 * @memberof CModel_t
 */
CAPI_FUNC(Reaction_t *) CModel_getReactionById (CModel_t *m, const char *sid);


/**
 * Get the SpeciesReference_t structure whose identifier is @p sid in the
 * given CModel_t structure.
 *
 * @param m the CModel_t structure.
 * @param sid the identifier of the SpeciesReference_t structure sought.
 *
 * @return the SpeciesReference_t if found, or @c NULL if not found
 *
 * @memberof CModel_t
 */
CAPI_FUNC(SpeciesReference_t *) CModel_getSpeciesReferenceById (CModel_t *m, const char *sid);


/**
 * Get the nth Event_t structure contained in the given
 * CModel_t structure.
 *
 * @param m the CModel_t structure.
 * @param n the integer index of the Event_t sought.
 *
 * @return the Event_t if found, or @c NULL if not found
 *
 * @memberof CModel_t
 */
CAPI_FUNC(Event_t *) CModel_getEvent (CModel_t *m, unsigned int n);


/**
 * Get the Event_t structure whose identifier is @p sid in the
 * given CModel_t structure.
 *
 * @param m the CModel_t structure.
 * @param sid the identifier of the Event_t structure sought.
 *
 * @return the Event_t if found, or @c NULL if not found
 *
 * @memberof CModel_t
 */
CAPI_FUNC(Event_t *) CModel_getEventById (CModel_t *m, const char *sid);


/**
 * Get the number of FunctionDefinition_t structures in the given
 * CModel_t structure
 *
 * @param m the CModel_t structure.
 *
 * @return an unsigned integer as the count of FunctionDefinition_t
 * structures in @p m
 *
 * @memberof CModel_t
 */
CAPI_FUNC(unsigned int) CModel_getNumFunctionDefinitions (const CModel_t *m);


/**
 * Get the number of UnitDefinition_t structures in the given
 * CModel_t structure
 *
 * @param m the CModel_t structure.
 *
 * @return an unsigned integer as the count of UnitDefinition_t
 * structures in @p m
 *
 * @memberof CModel_t
 */
CAPI_FUNC(unsigned int) CModel_getNumUnitDefinitions (const CModel_t *m);


/**
 * Get the number of CompartmentType_t structures in the given
 * CModel_t structure
 *
 * @param m the CModel_t structure.
 *
 * @return an unsigned integer as the count of CompartmentType_t
 * structures in @p m
 *
 * @memberof CModel_t
 */
CAPI_FUNC(unsigned int) CModel_getNumCompartmentTypes (const CModel_t *m);


/**
 * Get the number of SpeciesType_t structures in the given
 * CModel_t structure
 *
 * @param m the CModel_t structure.
 *
 * @return an unsigned integer as the count of SpeciesType_t
 * structures in @p m
 *
 * @memberof CModel_t
 */
CAPI_FUNC(unsigned int) CModel_getNumSpeciesTypes (const CModel_t *m);


/**
 * Get the number of Compartment_t structures in the given
 * CModel_t structure
 *
 * @param m the CModel_t structure.
 *
 * @return an unsigned integer as the count of Compartment_t
 * structures in @p m
 *
 * @memberof CModel_t
 */
CAPI_FUNC(unsigned int) CModel_getNumCompartments (const CModel_t *m);


/**
 * Get the number of Species_t structures in the given
 * CModel_t structure
 *
 * @param m the CModel_t structure.
 *
 * @return an unsigned integer as the count of Species_t
 * structures in @p m
 *
 * @memberof CModel_t
 */
CAPI_FUNC(unsigned int) CModel_getNumSpecies (const CModel_t *m);


/**
 * Get the number of Species_t structure in this CModel_t structure having
 * nonzero values for their "boundaryCondition" attribute.
 *
 * @param m the CModel_t structure.
 *
 * @return an unsigned integer as the count of Species_t structures
 *
 * @memberof CModel_t
 */
CAPI_FUNC(unsigned int) CModel_getNumSpeciesWithBoundaryCondition (const CModel_t *m);


/**
 * Get the number of Parameter_t structures in the given
 * CModel_t structure
 *
 * @param m the CModel_t structure.
 *
 * @return an unsigned integer as the count of Parameter_t
 * structures in @p m
 *
 * @memberof CModel_t
 */
CAPI_FUNC(unsigned int) CModel_getNumParameters (const CModel_t *m);


/**
 * Get the number of InitialAssignment_t structures in the given
 * CModel_t structure
 *
 * @param m the CModel_t structure.
 *
 * @return an unsigned integer as the count of InitialAssignment_t
 * structures in @p m
 *
 * @memberof CModel_t
 */
CAPI_FUNC(unsigned int) CModel_getNumInitialAssignments (const CModel_t *m);


/**
 * Get the number of Rule_t structures in the given
 * CModel_t structure
 *
 * @param m the CModel_t structure.
 *
 * @return an unsigned integer as the count of Rule_t
 * structures in @p m
 *
 * @memberof CModel_t
 */
CAPI_FUNC(unsigned int) CModel_getNumRules (const CModel_t *m);


/**
 * Get the number of Constraint_t structures in the given
 * CModel_t structure
 *
 * @param m the CModel_t structure.
 *
 * @return an unsigned integer as the count of Constraint_t
 * structures in @p m
 *
 * @memberof CModel_t
 */
CAPI_FUNC(unsigned int) CModel_getNumConstraints (const CModel_t *m);


/**
 * Get the number of Reaction_t structures in the given
 * CModel_t structure
 *
 * @param m the CModel_t structure.
 *
 * @return an unsigned integer as the count of Reaction_t
 * structures in @p m
 *
 * @memberof CModel_t
 */
CAPI_FUNC(unsigned int) CModel_getNumReactions (const CModel_t *m);


/**
 * Get the number of Event_t structures in the given
 * CModel_t structure
 *
 * @param m the CModel_t structure.
 *
 * @return an unsigned integer as the count of Event_t
 * structures in @p m
 *
 * @memberof CModel_t
 */
CAPI_FUNC(unsigned int) CModel_getNumEvents (const CModel_t *m);

/** @cond doxygenLibsbmlInternal */
/**
 * Populates the list of FormulaDataUnits with the units derived
 * for the model. The list contains elements of class
 * FormulaUnitsData.
 *
 * The first element of the list refers to the default units
 * of 'substance per time' derived from the model and has the
 * unitReferenceId 'subs_per_time'. This facilitates the comparison of units
 * derived from mathematical formula with the expected units.
 *
 * The next elements of the list record the units of the
 * compartments and species established from either explicitly
 * declared or default units.
 *
 * The next elements record the units of any parameters.
 *
 * Subsequent elements of the list record the units derived for
 * each mathematical expression encountered within the model.
 *
 * @param m the CModel_t structure.
 *
 * @note This function is utilised by the Unit Consistency Validator.
 * The List is populated prior to running the validation and thus
 * the consistency of units can be checked by accessing the members
 * of the list and comparing the appropriate data.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(void) CModel_populateListFormulaUnitsData(CModel_t *m);
/** @endcond */


/** @cond doxygenLibsbmlInternal */
/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether
 * the list of FormulaUnitsData is populated.
 *
 * @param m the CModel_t structure.
 *
 * @return @c 1 (true) if the list of FormulaUnitsData is populated,
 * @c 0 (false) otherwise.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(int) CModel_isPopulatedListFormulaUnitsData(CModel_t *m);
/** @endcond */


/**
 * Removes the nth FunctionDefinition_t structure from this CModel_t structure and
 * returns a pointer to it.
 *
 * The caller owns the returned structure and is responsible for deleting it.
 *
 * @param m the CModel_t structure.
 * @param n the integer index of the FunctionDefinition_t sought.
 *
 * @return the FunctionDefinition_t structure removed.  As mentioned above,
 * the caller owns the returned item. @c NULL is returned if the given index
 * is out of range.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(FunctionDefinition_t*) CModel_removeFunctionDefinition (CModel_t *m, unsigned int n);


/**
 * Removes the FunctionDefinition_t structure with the given "id" attribute
 * from this CModel_t structure and returns a pointer to it.
 *
 * The caller owns the returned structure and is responsible for deleting it.
 *
 * @param m the CModel_t structure.
 * @param sid the string of the "id" attribute of the FunctionDefinition_t sought.
 *
 * @return the FunctionDefinition_t structure removed.  As mentioned above, the
 * caller owns the returned structure. @c NULL is returned if no FunctionDefinition_t
 * structure with the identifier exists in this CModel_t structure.
 *
 *
 * @memberof CModel_t
 */
CAPI_FUNC(FunctionDefinition_t*) CModel_removeFunctionDefinitionById (CModel_t *m, const char* sid);


/**
 * Removes the nth UnitDefinition_t structure from this CModel_t structure and
 * returns a pointer to it.
 *
 * The caller owns the returned structure and is responsible for deleting it.
 *
 * @param m the CModel_t structure.
 * @param n the integer index of the UnitDefinition_t sought.
 *
 * @return the UnitDefinition_t structure removed.  As mentioned above,
 * the caller owns the returned item. @c NULL is returned if the given index
 * is out of range.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(UnitDefinition_t*) CModel_removeUnitDefinition (CModel_t *m, unsigned int n);


/**
 * Removes the UnitDefinition_t structure with the given "id" attribute
 * from this CModel_t structure and returns a pointer to it.
 *
 * The caller owns the returned structure and is responsible for deleting it.
 *
 * @param m the CModel_t structure.
 * @param sid the string of the "id" attribute of the UnitDefinition_t sought.
 *
 * @return the UnitDefinition_t structure removed.  As mentioned above, the
 * caller owns the returned structure. @c NULL is returned if no UnitDefinition_t
 * structure with the identifier exists in this CModel_t structure.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(UnitDefinition_t*) CModel_removeUnitDefinitionById (CModel_t *m, const char* sid);


/**
 * Removes the nth CompartmentType_t structure from this CModel_t structure and
 * returns a pointer to it.
 *
 * The caller owns the returned structure and is responsible for deleting it.
 *
 * @param m the CModel_t structure.
 * @param n the integer index of the CompartmentType_t sought.
 *
 * @return the CompartmentType_t structure removed.  As mentioned above,
 * the caller owns the returned item. @c NULL is returned if the given index
 * is out of range.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(CompartmentType_t*) CModel_removeCompartmentType (CModel_t *m, unsigned int n);


/**
 * Removes the CompartmentType_t structure with the given "id" attribute
 * from this CModel_t structure and returns a pointer to it.
 *
 * The caller owns the returned structure and is responsible for deleting it.
 *
 * @param m the CModel_t structure.
 * @param sid the string of the "id" attribute of the CompartmentType_t sought.
 *
 * @return the CompartmentType_t structure removed.  As mentioned above, the
 * caller owns the returned structure. @c NULL is returned if no CompartmentType_t
 * structure with the identifier exists in this CModel_t structure.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(CompartmentType_t*) CModel_removeCompartmentTypeById (CModel_t *m, const char* sid);


/**
 * Removes the nth SpeciesType_t structure from this CModel_t structure and
 * returns a pointer to it.
 *
 * The caller owns the returned structure and is responsible for deleting it.
 *
 * @param m the CModel_t structure.
 * @param n the integer index of the SpeciesType_t sought.
 *
 * @return the SpeciesType_t structure removed.  As mentioned above,
 * the caller owns the returned item. @c NULL is returned if the given index
 * is out of range.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(SpeciesType_t*) CModel_removeSpeciesType (CModel_t *m, unsigned int n);


/**
 * Removes the SpeciesType_t structure with the given "id" attribute
 * from this CModel_t structure and returns a pointer to it.
 *
 * The caller owns the returned structure and is responsible for deleting it.
 *
 * @param m the CModel_t structure.
 * @param sid the string of the "id" attribute of the SpeciesType_t sought.
 *
 * @return the SpeciesType_t structure removed.  As mentioned above, the
 * caller owns the returned structure. @c NULL is returned if no SpeciesType_t
 * structure with the identifier exists in this CModel_t structure.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(SpeciesType_t*) CModel_removeSpeciesTypeById (CModel_t *m, const char* sid);


/**
 * Removes the nth Compartment_t structure from this CModel_t structure and
 * returns a pointer to it.
 *
 * The caller owns the returned structure and is responsible for deleting it.
 *
 * @param m the CModel_t structure.
 * @param n the integer index of the Compartment_t sought.
 *
 * @return the Compartment_t structure removed.  As mentioned above,
 * the caller owns the returned item. @c NULL is returned if the given index
 * is out of range.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(Compartment_t*) CModel_removeCompartment (CModel_t *m, unsigned int n);


/**
 * Removes the Compartment_t structure with the given "id" attribute
 * from this CModel_t structure and returns a pointer to it.
 *
 * The caller owns the returned structure and is responsible for deleting it.
 *
 * @param m the CModel_t structure.
 * @param sid the string of the "id" attribute of the Compartment_t sought.
 *
 * @return the Compartment_t structure removed.  As mentioned above, the
 * caller owns the returned structure. @c NULL is returned if no Compartment_t
 * structure with the identifier exists in this CModel_t structure.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(Compartment_t*) CModel_removeCompartmentById (CModel_t *m, const char* sid);


/**
 * Removes the nth Species_t structure from this CModel_t structure and
 * returns a pointer to it.
 *
 * The caller owns the returned structure and is responsible for deleting it.
 *
 * @param m the CModel_t structure.
 * @param n the integer index of the Species_t sought.
 *
 * @return the Species_t structure removed.  As mentioned above,
 * the caller owns the returned item. @c NULL is returned if the given index
 * is out of range.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(Species_t*) CModel_removeSpecies (CModel_t *m, unsigned int n);


/**
 * Removes the Species_t structure with the given "id" attribute
 * from this CModel_t structure and returns a pointer to it.
 *
 * The caller owns the returned structure and is responsible for deleting it.
 *
 * @param m the CModel_t structure.
 * @param sid the string of the "id" attribute of the Species_t sought.
 *
 * @return the Species_t structure removed.  As mentioned above, the
 * caller owns the returned structure. @c NULL is returned if no Species_t
 * structure with the identifier exists in this CModel_t structure.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(Species_t*) CModel_removeSpeciesById (CModel_t *m, const char* sid);


/**
 * Removes the nth Parameter_t structure from this CModel_t structure and
 * returns a pointer to it.
 *
 * The caller owns the returned structure and is responsible for deleting it.
 *
 * @param m the CModel_t structure.
 * @param n the integer index of the Parameter_t sought.
 *
 * @return the Parameter_t structure removed.  As mentioned above,
 * the caller owns the returned item. @c NULL is returned if the given index
 * is out of range.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(Parameter_t*) CModel_removeParameter (CModel_t *m, unsigned int n);


/**
 * Removes the Parameter_t structure with the given "id" attribute
 * from this CModel_t structure and returns a pointer to it.
 *
 * The caller owns the returned structure and is responsible for deleting it.
 *
 * @param m the CModel_t structure.
 * @param sid the string of the "id" attribute of the Parameter_t sought.
 *
 * @return the Parameter_t structure removed.  As mentioned above, the
 * caller owns the returned structure. @c NULL is returned if no Parameter_t
 * structure with the identifier exists in this CModel_t structure.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(Parameter_t*) CModel_removeParameterById (CModel_t *m, const char* sid);


/**
 * Removes the nth InitialAssignment_t structure from this CModel_t structure and
 * returns a pointer to it.
 *
 * The caller owns the returned structure and is responsible for deleting it.
 *
 * @param m the CModel_t structure.
 * @param n the integer index of the InitialAssignment_t sought.
 *
 * @return the InitialAssignment_t structure removed.  As mentioned above,
 * the caller owns the returned item. @c NULL is returned if the given index
 * is out of range.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(InitialAssignment_t*) CModel_removeInitialAssignment (CModel_t *m, unsigned int n);


/**
 * Removes the InitialAssignment_t structure with the given "symbol" attribute
 * from this CModel_t structure and returns a pointer to it.
 *
 * The caller owns the returned structure and is responsible for deleting it.
 *
 * @param m the CModel_t structure.
 * @param symbol the string of the "symbol" attribute of the InitialAssignment_t sought.
 *
 * @return the InitialAssignment_t structure removed.  As mentioned above, the
 * caller owns the returned structure. @c NULL is returned if no InitialAssignment_t
 * structure with the "symbol" attribute exists in this CModel_t structure.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(InitialAssignment_t*) CModel_removeInitialAssignmentBySym (CModel_t *m, const char* symbol);


/**
 * Removes the nth Rule_t structure from this CModel_t structure and
 * returns a pointer to it.
 *
 * The caller owns the returned structure and is responsible for deleting it.
 *
 * @param m the CModel_t structure.
 * @param n the integer index of the Rule_t sought.
 *
 * @return the Rule_t structure removed.  As mentioned above,
 * the caller owns the returned item. @c NULL is returned if the given index
 * is out of range.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(Rule_t*) CModel_removeRule (CModel_t *m, unsigned int n);


/**
 * Removes the Rule_t structure with the given "variable" attribute
 * from this CModel_t structure and returns a pointer to it.
 *
 * The caller owns the returned structure and is responsible for deleting it.
 *
 * @param m the CModel_t structure.
 * @param variable the string of the "variable" attribute of the Rule_t sought.
 *
 * @return the Rule_t structure removed.  As mentioned above, the
 * caller owns the returned structure. @c NULL is returned if no Rule_t
 * structure with the "variable" attribute exists in this CModel_t structure.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(Rule_t*) CModel_removeRuleByVar (CModel_t *m, const char* variable);


/**
 * Removes the nth Constraint_t structure from this CModel_t structure and
 * returns a pointer to it.
 *
 * The caller owns the returned structure and is responsible for deleting it.
 *
 * @param m the CModel_t structure.
 * @param n the integer index of the Constraint_t sought.
 *
 * @return the Constraint_t structure removed.  As mentioned above,
 * the caller owns the returned item. @c NULL is returned if the given index
 * is out of range.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(Constraint_t*) CModel_removeConstraint (CModel_t *m, unsigned int n);


/**
 * Removes the nth Reaction_t structure from this CModel_t structure and
 * returns a pointer to it.
 *
 * The caller owns the returned structure and is responsible for deleting it.
 *
 * @param m the CModel_t structure.
 * @param n the integer index of the Reaction_t sought.
 *
 * @return the Reaction_t structure removed.  As mentioned above,
 * the caller owns the returned item. @c NULL is returned if the given index
 * is out of range.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(Reaction_t*) CModel_removeReaction (CModel_t *m, unsigned int n);


/**
 * Removes the Reaction_t structure with the given "id" attribute
 * from this CModel_t structure and returns a pointer to it.
 *
 * The caller owns the returned structure and is responsible for deleting it.
 *
 * @param m the CModel_t structure.
 * @param sid the string of the "id" attribute of the Reaction_t sought.
 *
 * @return the Reaction_t structure removed.  As mentioned above, the
 * caller owns the returned structure. @c NULL is returned if no Reaction_t
 * structure with the identifier exists in this CModel_t structure.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(Reaction_t*) CModel_removeReactionById (CModel_t *m, const char* sid);


/**
 * Removes the nth Event_t structure from this CModel_t structure and
 * returns a pointer to it.
 *
 * The caller owns the returned structure and is responsible for deleting it.
 *
 * @param m the CModel_t structure.
 * @param n the integer index of the Event_t sought.
 *
 * @return the Event_t structure removed.  As mentioned above,
 * the caller owns the returned item. @c NULL is returned if the given index
 * is out of range.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(Event_t*) CModel_removeEvent (CModel_t *m, unsigned int n);


/**
 * Removes the Event_t structure with the given "id" attribute
 * from this CModel_t structure and returns a pointer to it.
 *
 * The caller owns the returned structure and is responsible for deleting it.
 *
 * @param m the CModel_t structure.
 * @param sid the string of the "id" attribute of the Event_t sought.
 *
 * @return the Event_t structure removed.  As mentioned above, the
 * caller owns the returned structure. @c NULL is returned if no Event_t
 * structure with the identifier exists in this CModel_t structure.
 *
 * @memberof CModel_t
 */
CAPI_FUNC(Event_t*) CModel_removeEventById (CModel_t *m, const char* sid);

/* not yet exposed but leave in case we need them

 * Adds a copy of the given FormulaUnitsData_t structure to this CModel_t.
 *
 * @param m the CModel_t structure.
 * @param fud the FormulaUnitsData_t structure to add.

CAPI_FUNC(void) CModel_addFormulaUnitsData (CModel_t *m, FormulaUnitsData_t* fud);


 * Creates a new FormulaUnitsData_t inside this CModel_t and returns it.
 *
 * @param m the CModel_t structure.
 *
 * @return the FormulaUnitsData_t structure created

CAPI_FUNC(FormulaUnitsData_t*) CModel_createFormulaUnitsData (CModel_t *m);


 * Get the nth FormulaUnitsData_t structure in this CModel_t.
 *
 * @param m the CModel_t structure.
 *
 * @return the nth FormulaUnitsData_t of this CModel_t.

CAPI_FUNC(FormulaUnitsData_t*) CModel_getFormulaUnitsData (CModel_t *m, unsigned int n);


 * Get a FormulaUnitsData_t structure based on its unitReferenceId and typecode.
 *
 * @param m the CModel_t structure.
 *
 * @return the FormulaUnitsData_t in this CModel_t with the unitReferenceId @p sid
 * and the typecode (int) @p typecode or @c NULL
 * if no such FormulaUnitsData exists.
 *
 * @note The typecode (int) parameter is necessary as the unitReferenceId
 * of the FormulaUnitsData_t need not be unique. For example if a Species_t
 * with id 's' is assigned by an AssignmentRule_t there will be two
 * elements of the FormulaUnitsData_t List with the unitReferenceId 's';
 * one with
 * typecode 'SBML_SPECIES' referring to the units related to the species,
 * the other with typecode 'SBML_ASSIGNMENT_RULE' referring to the units
 * derived from the math element of the AssignmentRule_t.

CAPI_FUNC(FormulaUnitsData_t*) CModel_getFormulaUnitsDataById(CModel_t *m, const char* sid, int);


 * Get the number of FormulaUnitsData_t structures in this CModel_t.
 *
 * @param m the CModel_t structure.
 *
 * @return the number of FormulaUnitsData_t in this CModel_t.

CAPI_FUNC(unsigned int) CModel_getNumFormulaUnitsData (CModel_t *m);


 * Get the list of FormulaUnitsData_t structure in this CModel_t.
 *
 * @param m the CModel_t structure.
 *
 * @return the list of FormulaUnitsData_t for this CModel_t.

CAPI_FUNC(List_t*) CModel_getListFormulaUnitsData (CModel_?t *m);

*/




#endif /* EXTERN_CARBON_INCLUDE_C_MODEL_H_ */
