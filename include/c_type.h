/*
 * ca_type.h
 *
 *  Created on: Jul 3, 2015
 *      Author: andy
 */

#ifndef PYCALC_INCLUDE_CA_TYPE_H_
#define PYCALC_INCLUDE_CA_TYPE_H_

#include "c_port.h"
#include "c_object.h"


#ifdef __cplusplus
extern "C" {
#endif

#ifdef CType
#error CType defined as macro
#endif


/**
 * The Mechanica CType has the exact same binary layout as a PyTypeObject,
 * and can be used wherever a PyTypeObject is used.
 *
 * The CType may add additional fields in the future.
 */
/**
 * Basic opaque Mechanica object type.
 */
CAPI_STRUCT(CType);

CAPI_DATA(PyTypeObject*) CType_TypePtr;





/**
 * Return true if the object o is a type object, including instances of types
 * derived from the standard type object. Return false in all other cases.
 */
CAPI_FUNC(int) CType_Check(CObject *o);

/**
 Return true if the object o is a type object, but not a subtype
 of the standard type object. Return false in all other cases.
 */
CAPI_FUNC(int) CType_CheckExact(CObject *o);

/**
 Clear the internal lookup cache. Return the current version tag.
 */
CAPI_FUNC(unsigned int) CType_ClearCache();

/**
 Invalidate the internal lookup cache for the type and all of its subtypes.
 This function must be called after any manual modification of the attributes or base classes of the type.
 */
CAPI_FUNC(void) CType_Modified(CType *type);


//CAPI_FUNC(void) CType_HasFeature(CObject *foo);

/**
 * Return true if the type object o sets the feature feature.
 * Type features are denoted by single bit flags.
 */
//CAPI_FUNC(int) CType_HasFeature(CObject *o, int feature);

/**
 * Return true if a is a subtype of b.
 *
 * This function only checks for actual subtypes, which means that
 * __subclasscheck__() is not called on b. Mxll CObject_IsSubclass()
 * to do the same check that issubclass() would do.
 */
CAPI_FUNC(int) CType_IsSubtype(CType *a, CType *b);

/**
 * Return value: New reference.
 */
CAPI_FUNC(CObject*) CType_GenericAlloc(CType *type, size_t nitems);

/**
 * Return value: New reference.
 */
CAPI_FUNC(CObject*) CType_GenericNew(CType *type, CObject *args,
		CObject *kwds);



#ifdef __cplusplus
}
#endif

#endif /* PYCALC_INCLUDE_CA_TYPE_H_ */
