/*
 * c_kineticlaw.h
 *
 *  Created on: Jun 4, 2020
 *      Author: andy
 *
 * copy of the libSBML API, originally written by Ben Bornstein
 */

#ifndef EXTERN_CARBON_INCLUDE_C_KINETICLAW_H_
#define EXTERN_CARBON_INCLUDE_C_KINETICLAW_H_

#include <c_port.h>

CAPI_STRUCT(CKineticLaw_t);
CAPI_STRUCT(ASTNode_t);
CAPI_STRUCT(Parameter_t);
CAPI_STRUCT(LocalParameter_t);
CAPI_STRUCT(ListOf_t);
CAPI_STRUCT(UnitDefinition_t);


/**
 * Creates a new CKineticLaw_t structure using the given SBML @p level
 * and @p version values.
 *
 * @param level an unsigned int, the SBML Level to assign to this
 * CKineticLaw_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * CKineticLaw_t.
 *
 * @return a pointer to the newly created CKineticLaw_t structure.
 *
 * @copydetails doc_note_setting_lv
 *
 * @memberof CKineticLaw_t
 */
CAPI_FUNC(CKineticLaw_t *) CKineticLaw_create (unsigned int level, unsigned int version);


/**
 * Creates a new CKineticLaw_t structure using the given
 * SBMLNamespaces_t structure.
 *
 * @param sbmlns SBMLNamespaces_t, a pointer to an SBMLNamespaces_t structure
 * to assign to this CKineticLaw_t.
 *
 * @return a pointer to the newly created CKineticLaw_t structure.
 *
 * @copydetails doc_note_setting_lv
 *
 * @memberof CKineticLaw_t
 */
//CAPI_FUNC(CKineticLaw_t *) CKineticLaw_createWithNS (SBMLNamespaces_t *sbmlns);


/**
 * Frees the given CKineticLaw_t structure.
 *
 * @param kl the CKineticLaw_t structure.
 *
 * @memberof CKineticLaw_t
 */
CAPI_FUNC(void) CKineticLaw_free (CKineticLaw_t *kl);


/**
 * Returns a deep copy of the given CKineticLaw_t structure.
 *
 * @param kl the CKineticLaw_t structure.
 *
 * @return a (deep) copy of this CKineticLaw_t structure.
 *
 * @memberof CKineticLaw_t
 */
CAPI_FUNC(CKineticLaw_t *) CKineticLaw_clone (const CKineticLaw_t *kl);


/**
 * Returns a list of XMLNamespaces_t associated with this CKineticLaw_t
 * structure.
 *
 * @param kl the CKineticLaw_t structure.
 *
 * @return pointer to the XMLNamespaces_t structure associated with
 * this structure
 *
 * @memberof CKineticLaw_t
 */
//CAPI_FUNC(const XMLNamespaces_t *) CKineticLaw_getNamespaces(CKineticLaw_t *kl);


/**
 * Gets the mathematical expression of this CKineticLaw_t structure as a
 * formula in text-string form.
 *
 * This is fundamentally equivalent to CKineticLaw_getMath().  It is
 * provided principally for compatibility with SBML Level 1.
 *
 * @param kl the CKineticLaw_t structure.
 *
 * @return the formula of this CKineticLaw_t structure.
 *
 * @see CKineticLaw_getMath().
 *
 * @note SBML Level 1 uses a text-string format for mathematical formulas.
 * Other levels of SBML use MathML, an XML format for representing mathematical
 * expressions.  LibSBML provides an Abstract Syntax Tree API for working
 * with mathematical expressions; this API is more powerful than working
 * with formulas directly in text form, and ASTs can be translated into
 * either MathML or the text-string syntax.  The libSBML methods that
 * accept text-string formulas directly (such as this constructor) are
 * provided for SBML Level 1 compatibility, but developers are encouraged
 * to use the AST mechanisms.  See CKineticLaw_createWithMath for a
 * version that takes an ASTNode_t structure.
 *
 * @memberof CKineticLaw_t
 */
CAPI_FUNC(const char *) CKineticLaw_getFormula (const CKineticLaw_t *kl);


/**
 * Gets the mathematical expression of this CKineticLaw_t structure as an
 * ASTNode_t structure.
 *
 * This is fundamentally equivalent to CKineticLaw_getFormula().  The latter
 * is provided principally for compatibility with SBML Level 1, which
 * represented mathematical formulas in text-string form.
 *
 * @param kl the CKineticLaw_t structure.
 *
 * @return the formula in the form of an ASTNode_t structure
 *
 * @see CKineticLaw_getFormula().
 *
 * @memberof CKineticLaw_t
 */
CAPI_FUNC(const ASTNode_t *) CKineticLaw_getMath (const CKineticLaw_t *kl);


/**
 * Gets the value of the "timeUnits" attribute of the given
 * CKineticLaw_t structure.
 *
 * @param kl the CKineticLaw_t structure.
 *
 * @return the "timeUnits" attribute value
 *
 * @warning In SBML Level 2 Version 2, the "timeUnits" and "substanceUnits"
 * attributes were removed.  For compatibility with new versions of SBML,
 * users are cautioned to avoid these attributes.
 *
 * @memberof CKineticLaw_t
 */
CAPI_FUNC(const char *) CKineticLaw_getTimeUnits (const CKineticLaw_t *kl);


/**
 * Gets the value of the "substanceUnits" attribute of the given
 * CKineticLaw_t structure.
 *
 * @param kl the CKineticLaw_t structure.
 *
 * @return the "substanceUnits" attribute value
 *
 * @warning In SBML Level 2 Version 2, the "timeUnits" and "substanceUnits"
 * attributes were removed.  For compatibility with new versions of SBML,
 * users are cautioned to avoid these attributes.
 *
 * @memberof CKineticLaw_t
 */
CAPI_FUNC(const char *) CKineticLaw_getSubstanceUnits (const CKineticLaw_t *kl);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on
 * whether the "formula" attribute of the given CKineticLaw_t structure is
 * set.
 *
 * This is fundamentally equivalent to CKineticLaw_isSetMath().  It is
 * provided principally for compatibility with SBML Level 1.
 *
 * @param kl the CKineticLaw_t structure.
 *
 * @return @c 1 (true) if the formula (or equivalently the
 * "math" subelement) of the given CKineticLaw_t structure is set,
 * @c 0 (false) otherwise.
 *
 * @note SBML Level 1 uses a text-string format for mathematical formulas.
 * Other levels of SBML use MathML, an XML format for representing mathematical
 * expressions.  LibSBML provides an Abstract Syntax Tree API for working
 * with mathematical expressions; this API is more powerful than working
 * with formulas directly in text form, and ASTs can be translated into
 * either MathML or the text-string syntax.  The libSBML methods that
 * accept text-string formulas directly (such as this constructor) are
 * provided for SBML Level 1 compatibility, but developers are encouraged
 * to use the AST mechanisms.  See CKineticLaw_createWithMath for a
 * version that takes an ASTNode_t structure.
 *
 * @memberof CKineticLaw_t
 */
CAPI_FUNC(int) CKineticLaw_isSetFormula (const CKineticLaw_t *kl);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on
 * whether the "math" subelement of the given CKineticLaw_t structure is
 * set.
 *
 * This is fundamentally equivalent to CKineticLaw_isSetFormula().  The
 * latter provided principally for compatibility with SBML Level 1, which
 * represented mathematical formulas in text-string form.
 *
 * @param kl the CKineticLaw_t structure.
 *
 * @return @c 1 (true) if the "math" subelement of the given
 * CKineticLaw_t structure is set, @c 0 (false) otherwise.
 *
 * @memberof CKineticLaw_t
 */
CAPI_FUNC(int) CKineticLaw_isSetMath (const CKineticLaw_t *kl);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on
 * whether the "timeUnits" attribute of the given CKineticLaw_t structure is
 * set.
 *
 * @param kl the CKineticLaw_t structure.
 *
 * @return @c 1 (true) if the "timeUnits" attribute of the given
 * CKineticLaw_t structure is set, @c 0 (false) otherwise.
 *
 * @warning In SBML Level 2 Version 2, the "timeUnits" and "substanceUnits"
 * attributes were removed.  For compatibility with new versions of SBML,
 * users are cautioned to avoid these attributes.
 *
 * @memberof CKineticLaw_t
 */
CAPI_FUNC(int) CKineticLaw_isSetTimeUnits (const CKineticLaw_t *kl);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on
 * whether the "timeUnits" attribute of the given CKineticLaw_t structure is
 * set.
 *
 * @param kl the CKineticLaw_t structure.
 *
 * @return @c 1 (true) if the "timeUnits" attribute of the given
 * CKineticLaw_t structure is set, @c 0 (false) otherwise.
 *
 * @warning In SBML Level 2 Version 2, the "timeUnits" and "substanceUnits"
 * attributes were removed.  For compatibility with new versions of SBML,
 * users are cautioned to avoid these attributes.
 *
 * @memberof CKineticLaw_t
 */
CAPI_FUNC(int) CKineticLaw_isSetSubstanceUnits (const CKineticLaw_t *kl);


/**
 * Sets the formula of the given CKineticLaw_t structure.
 *
 * This is fundamentally equivalent to CKineticLaw_setMath().  It is
 * provided principally for compatibility with SBML Level 1.
 *
 * @param kl the CKineticLaw_t structure.
 *
 * @param formula the mathematical expression, in text-string form.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @note SBML Level 1 uses a text-string format for mathematical formulas.
 * Other levels of SBML use MathML, an XML format for representing mathematical
 * expressions.  LibSBML provides an Abstract Syntax Tree API for working
 * with mathematical expressions; this API is more powerful than working
 * with formulas directly in text form, and ASTs can be translated into
 * either MathML or the text-string syntax.  The libSBML methods that
 * accept text-string formulas directly (such as this constructor) are
 * provided for SBML Level 1 compatibility, but developers are encouraged
 * to use the AST mechanisms.  See CKineticLaw_createWithMath for a
 * version that takes an ASTNode_t structure.
 *
 * @memberof CKineticLaw_t
 */
CAPI_FUNC(int) CKineticLaw_setFormula (CKineticLaw_t *kl, const char *formula);


/**
 * Sets the formula of the given CKineticLaw_t structure.
 *
 * This is fundamentally equivalent to CKineticLaw_setFormula().  The latter
 * provided principally for compatibility with SBML Level 1, which
 * represented mathematical formulas in text-string form.
 *
 * @param kl the CKineticLaw_t structure.
 *
 * @param math an ASTNode_t structure representing the mathematical formula.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof CKineticLaw_t
 */
CAPI_FUNC(int) CKineticLaw_setMath (CKineticLaw_t *kl, const ASTNode_t *math);


/**
 * Sets the "timeUnits" attribute of the given CKineticLaw_t structure.
 *
 * The identifier string @p sid is copied.
 *
 * @param kl the CKineticLaw_t structure.
 *
 * @param sid the identifier of the units.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_UNEXPECTED_ATTRIBUTE, OperationReturnValues_t}
 *
 * @note Using this function with an @p sid of NULL is equivalent to
 * unsetting the "timeUnits" attribute.
 *
 * @warning In SBML Level 2 Version 2, the "timeUnits" and "substanceUnits"
 * attributes were removed.  For compatibility with new versions of SBML,
 * users are cautioned to avoid these attributes.
 *
 * @memberof CKineticLaw_t
 */
CAPI_FUNC(int) CKineticLaw_setTimeUnits (CKineticLaw_t *kl, const char *sid);


/**
 * Sets the "substanceUnits" attribute of the given CKineticLaw_t structure.
 *
 * The identifier string @p sid is copied.
 *
 * @param kl the CKineticLaw_t structure.
 *
 * @param sid the identifier of the units.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_UNEXPECTED_ATTRIBUTE, OperationReturnValues_t}
 *
 * @note Using this function with an @p sid of NULL is equivalent to
 * unsetting the "substanceUnits" attribute.
 *
 * @warning In SBML Level 2 Version 2, the "timeUnits" and "substanceUnits"
 * attributes were removed.  For compatibility with new versions of SBML,
 * users are cautioned to avoid these attributes.
 *
 * @memberof CKineticLaw_t
 */
CAPI_FUNC(int) CKineticLaw_setSubstanceUnits (CKineticLaw_t *kl, const char *sid);


/**
 * Unsets the "timeUnits" attribute of the given CKineticLaw_t structure.
 *
 * @param kl the CKineticLaw_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @warning In SBML Level 2 Version 2, the "timeUnits" and "substanceUnits"
 * attributes were removed.  For compatibility with new versions of SBML,
 * users are cautioned to avoid these attributes.
 *
 * @memberof CKineticLaw_t
 */
CAPI_FUNC(int) CKineticLaw_unsetTimeUnits (CKineticLaw_t *kl);


/**
 * Unsets the "substanceUnits" attribute of the given CKineticLaw_t structure.
 *
 * @param kl the CKineticLaw_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @warning In SBML Level 2 Version 2, the "timeUnits" and "substanceUnits"
 * attributes were removed.  For compatibility with new versions of SBML,
 * users are cautioned to avoid these attributes.
 *
 * @memberof CKineticLaw_t
 */
CAPI_FUNC(int) CKineticLaw_unsetSubstanceUnits (CKineticLaw_t *kl);


/**
 * Adds a copy of the given Parameter_t structure to the list of local
 * parameters in the given CKineticLaw_t structure.
 *
 * @param kl the CKineticLaw_t structure.
 *
 * @param p a pointer to a Parameter_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_LEVEL_MISMATCH, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_VERSION_MISMATCH, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_DUPLICATE_OBJECT_ID, OperationReturnValues_t}
 *
 * @memberof CKineticLaw_t
 */
CAPI_FUNC(int) CKineticLaw_addParameter (CKineticLaw_t *kl, const Parameter_t *p);


/**
 * Adds a copy of the given LocalParameter_t structure to the list of local
 * parameters in the given CKineticLaw_t structure.
 * @copydetails doc_use_localparam_in_l3
 *
 * @param kl the CKineticLaw_t structure.
 *
 * @param p a pointer to a LocalParameter_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_LEVEL_MISMATCH, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_VERSION_MISMATCH, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_DUPLICATE_OBJECT_ID, OperationReturnValues_t}
 *
 * @memberof CKineticLaw_t
 */
CAPI_FUNC(int) CKineticLaw_addLocalParameter (CKineticLaw_t *kl, const LocalParameter_t *p);


/**
 * Creates a new Parameter_t structure, adds it to the given CKineticLaw_t
 * structures's list of parameters, and returns a pointer to the
 * Parameter_t created.
 * @copydetails doc_use_param_in_l2
 *
 * @param kl the CKineticLaw_t structure.
 *
 * @return a pointer to a Parameter_t structure, or @c NULL if @p kl is @c NULL,
 * or if its namepace indicates it is an SBML Level&nbsp;3 object.
 *
 * @see CKineticLaw_createLocalParameter()
 *
 * @memberof CKineticLaw_t
 */
CAPI_FUNC(Parameter_t *) CKineticLaw_createParameter (CKineticLaw_t *kl);


/**
 * Creates a new LocalParameter_t structure, adds it to the given CKineticLaw_t
 * structures's list of local parameters, and returns a pointer to the
 * LocalParameter_t created.
 * @copydetails doc_use_localparam_in_l3
 *
 * @param kl the CKineticLaw_t structure.
 *
 * @return a pointer to a LocalParameter_t structure, or @c NULL if @p kl is @c NULL,
 * or if its namepace indicates it is an SBML Level&nbsp;1 or 2 object.
 *
 * @see CKineticLaw_createParameter()
 *
 * @memberof CKineticLaw_t
 */
CAPI_FUNC(LocalParameter_t *) CKineticLaw_createLocalParameter (CKineticLaw_t *kl);


/**
 * Get the list of parameters defined for the given CKineticLaw_t
 * structure.
 * @copydetails doc_use_param_in_l2
 *
 * @param kl the CKineticLaw_t structure.
 *
 * @return a list of Parameters
 *
 * @memberof CKineticLaw_t
 */
CAPI_FUNC(ListOf_t *) CKineticLaw_getListOfParameters (CKineticLaw_t *kl);


/**
 * Get the list of local parameters defined for the given CKineticLaw_t
 * structure.
 * @copydetails doc_use_localparam_in_l3
 *
 * @param kl the CKineticLaw_t structure.
 *
 * @return a list of LocalParameters
 *
 * @memberof CKineticLaw_t
 */
CAPI_FUNC(ListOf_t *) CKineticLaw_getListOfLocalParameters (CKineticLaw_t *kl);


/**
 * Get the nth parameter in the list of parameters in the
 * given CKineticLaw_t structure.
 *
 * Callers should first find out how many parameters are in the list by
 * calling CKineticLaw_getNumParameters().
 * @copydetails doc_use_param_in_l2
 *
 * @param kl the CKineticLaw_t structure.
 *
 * @param n the index of the Parameter_t structure sought.
 *
 * @return a pointer to the Parameter_t structure
 *
 * @see CKineticLaw_getNumParameters().
 *
 * @memberof CKineticLaw_t
 */
CAPI_FUNC(Parameter_t *) CKineticLaw_getParameter (CKineticLaw_t *kl, unsigned int n);


/**
 * Get the nth parameter in the list of local parameters in the
 * given CKineticLaw_t structure.
 *
 * Callers should first find out how many parameters are in the list by
 * calling CKineticLaw_getNumLocalParameters().
 * @copydetails doc_use_localparam_in_l3
 *
 * @param kl the CKineticLaw_t structure.
 *
 * @param n the index of the LocalParameter_t structure sought.
 *
 * @return a pointer to the LocalParameter_t structure
 *
 * @see CKineticLaw_getNumLocalParameters().
 *
 * @memberof CKineticLaw_t
 */
CAPI_FUNC(LocalParameter_t *) CKineticLaw_getLocalParameter (CKineticLaw_t *kl, unsigned int n);


/**
 * Get a parameter with identifier "id" out of the list of local
 * parameters defined for the given CKineticLaw_t structure.
 * @copydetails doc_use_param_in_l2
 *
 * @param kl the CKineticLaw_t structure.
 *
 * @param sid the identifier of the Parameter_t structure sought.
 *
 * @return the Parameter_t structure with the given @p id, or @c NULL if no such
 * Parameter_t exists in the given CKineticLaw_t structure.
 *
 * @memberof CKineticLaw_t
 */
CAPI_FUNC(Parameter_t *) CKineticLaw_getParameterById (CKineticLaw_t *kl, const char *sid);


/**
 * Get a parameter with identifier "id" out of the list of local
 * parameters defined for the given CKineticLaw_t structure.
 * @copydetails doc_use_localparam_in_l3
 *
 * @param kl the CKineticLaw_t structure.
 *
 * @param sid the identifier of the LocalParameter_t structure sought.
 *
 * @return the LocalParameter_t structure with the given @p id, or @c NULL if no such
 * LocalParameter_t exists in the given CKineticLaw_t structure.
 *
 * @memberof CKineticLaw_t
 */
CAPI_FUNC(LocalParameter_t *) CKineticLaw_getLocalParameterById (CKineticLaw_t *kl, const char *sid);


/**
 * Get the number of parameters defined in the given CKineticLaw_t
 * structure.
 * @copydetails doc_use_param_in_l2
 *
 * @param kl the CKineticLaw_t structure.
 *
 * @return the number of Parameter_t structures in the given CKineticLaw_t
 * structure.
 *
 * @memberof CKineticLaw_t
 */
CAPI_FUNC(unsigned int) CKineticLaw_getNumParameters (const CKineticLaw_t *kl);


/**
 * Get the number of local parameters defined in the given CKineticLaw_t
 * structure.
 * @copydetails doc_use_localparam_in_l3
 *
 * @param kl the CKineticLaw_t structure.
 *
 * @return the number of LocalParameter_t structures in the given CKineticLaw_t
 * structure.
 *
 * @memberof CKineticLaw_t
 */
CAPI_FUNC(unsigned int) CKineticLaw_getNumLocalParameters (const CKineticLaw_t *kl);


/**
  * Calculates and returns a UnitDefinition_t that expresses the units
  * returned by the math expression of this CKineticLaw_t.
  *
  * @return a UnitDefinition_t that expresses the units of the math
  * expression of this CKineticLaw_t.
  *
  * Note that the functionality that facilitates unit analysis depends
  * on the model as a whole.  Thus, in cases where the object has not
  * been added to a model or the model itself is incomplete,
  * unit analysis is not possible and this method will return @c NULL.
  *
  * @note The units are calculated by applying the mathematics
  * from the expression to the units of the &lt;ci&gt; elements used
  * within the expression. Where there are parameters/numbers
  * with undeclared units the UnitDefinition_t returned by this
  * function may not accurately represent the units of the expression.
  *
  * @see CKineticLaw_containsUndeclaredUnits()
  *
 * @memberof CKineticLaw_t
 */
CAPI_FUNC(UnitDefinition_t *) CKineticLaw_getDerivedUnitDefinition(CKineticLaw_t *kl);


/**
  * Predicate returning @c true or @c false depending on whether
  * the math expression of this CKineticLaw_t contains
  * parameters/numbers with undeclared units.
  *
  * @return @c true if the math expression of this CKineticLaw_t
  * includes parameters/numbers
  * with undeclared units, @c false otherwise.
  *
  * @note a return value of @c true indicates that the UnitDefinition_t
  * returned by the getDerivedUnitDefinition function may not
  * accurately represent the units of the expression.
  *
  * @see CKineticLaw_getDerivedUnitDefinition()
  *
 * @memberof CKineticLaw_t
 */
CAPI_FUNC(int) CKineticLaw_containsUndeclaredUnits(CKineticLaw_t *kl);


/**
 * Removes the nth Parameter_t structure from the list of parameters
 * in this CKineticLaw_t structure and returns a pointer to it.
 *
 * The caller owns the returned structure and is responsible for deleting it.
 * @copydetails doc_use_param_in_l2
 *
 * @param kl the CKineticLaw_t structure.
 * @param n the integer index of the Parameter_t sought.
 *
 * @return the Parameter_t structure removed.  As mentioned above,
 * the caller owns the returned item. @c NULL is returned if the given index
 * is out of range.
 *
 * @memberof CKineticLaw_t
 */
CAPI_FUNC(Parameter_t *) CKineticLaw_removeParameter (CKineticLaw_t *kl, unsigned int n);


/**
 * Removes the nth LocalParameter_t structure from the list of local parameters
 * in this CKineticLaw_t structure and returns a pointer to it.
 *
 * The caller owns the returned structure and is responsible for deleting it.
 * @copydetails doc_use_localparam_in_l3
 *
 * @param kl the CKineticLaw_t structure.
 * @param n the integer index of the LocalParameter_t sought.
 *
 * @return the LocalParameter_t structure removed.  As mentioned above,
 * the caller owns the returned item. @c NULL is returned if the given index
 * is out of range.
 *
 * @memberof CKineticLaw_t
 */
CAPI_FUNC(LocalParameter_t *) CKineticLaw_removeLocalParameter (CKineticLaw_t *kl, unsigned int n);


/**
 * Removes the Parameter_t structure with the given "id" attribute
 * from the list of parameters in this CKineticLaw_t structure and
 * returns a pointer to it.
 *
 * The caller owns the returned structure and is responsible for deleting it.
 * @copydetails doc_use_param_in_l2
 *
 * @param kl the CKineticLaw_t structure.
 * @param sid the string of the "id" attribute of the Parameter_t sought.
 *
 * @return the Parameter_t structure removed.  As mentioned above, the
 * caller owns the returned structure. @c NULL is returned if no CKineticLaw_t
 * structure with the identifier exists in this CKineticLaw_t structure.
 *
 * @memberof CKineticLaw_t
 */
CAPI_FUNC(Parameter_t *) CKineticLaw_removeParameterById (CKineticLaw_t *kl, const char *sid);


/**
 * Removes the LocalParameter_t structure with the given "id" attribute
 * from the list of local parameters in this CKineticLaw_t structure and
 * returns a pointer to it.
 *
 * The caller owns the returned structure and is responsible for deleting it.
 * @copydetails doc_use_localparam_in_l3
 *
 * @param kl the CKineticLaw_t structure.
 * @param sid the string of the "id" attribute of the LocalParameter_t sought.
 *
 * @return the LocalParameter_t structure removed.  As mentioned above, the
 * caller owns the returned structure. @c NULL is returned if no CKineticLaw_t
 * structure with the identifier exists in this CKineticLaw_t structure.
 *
 * @memberof CKineticLaw_t
 */
CAPI_FUNC(LocalParameter_t *) CKineticLaw_removeLocalParameterById (CKineticLaw_t *kl, const char *sid);



#endif /* EXTERN_CARBON_INCLUDE_C_KINETICLAW_H_ */
