/*
 * c_listof.h
 *
 *  Created on: Jun 18, 2020
 *      Author: andy
 */

#ifndef EXTERN_CARBON_INCLUDE_C_LIST_H_
#define EXTERN_CARBON_INCLUDE_C_LIST_H_

#include <c_port.h>

CAPI_STRUCT(CList_t);
CAPI_STRUCT(SBase_t);


/**
 * Creates a new instance of a ListOf_t structure.
 *
 * @param initSize initial size of the list.
 *
 * @return a pointer to the newly-created ListOf_t structure.
 *
 * @copydetails doc_note_bare_listof
 *
 * @memberof CList_t
 */
CAPI_FUNC(CList_t *) CList_create (unsigned int initSize);

/**
 * Creates a new instance of a ListOf_t structure.
 *
 * @param level an unsigned int, the SBML Level to assign to this
 * ListOf_t structure.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * ListOf_t structure.
 *
 * @return a pointer to the newly-created ListOf_t structure.
 *
 * @copydetails doc_note_bare_listof
 *
 * @memberof CList_t
 */
CAPI_FUNC(CList_t *) CList_createWithVersion(unsigned int level, unsigned int version);


/**
 * Frees the given CList_t structure.
 *
 * This function assumes each item in the list is derived from SBase_t.
 *
 * @param lo the CList_t structure to be freed.
 *
 * @memberof CList_t
 */
CAPI_FUNC(void) CList_free (CList_t *lo);


/**
 * Creates a deep copy of the given CList_t structure.
 *
 * @param lo the CList_t structure to be copied.
 *
 * @return a (deep) copy of the given CList_t structure, or a null
 * pointer if a failure occurred.
 *
 * @memberof CList_t
 */
CAPI_FUNC(CList_t *) CList_clone (const CList_t *lo);


/**
 * Adds a copy of a given item to the end of a CList_t list.
 *
 * @param lo the CList_t structure to which the @p item should be appended.
 * @param item the item to append to the list.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @see CList_appendAndOwn()
 *
 * @memberof CList_t
 */
CAPI_FUNC(int) CList_append (CList_t *lo, const SBase_t *item);


/**
 * Adds the given item to the end of a CList_t list.
 *
 * @param lo the CList_t structure to which the @p disownedItem should be appended.
 * @param disownedItem the item to append to the list.
 * Will become a child of the parent list.
 *
 * Unlike CList_append(), this function does not copy the @p disownedItem.
 * The given @p lo list will contain the original item, and becomes responsible
 * for its deletion.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @see CList_append()
 *
 * @memberof CList_t
 */
CAPI_FUNC(int) CList_appendAndOwn (CList_t *lo, SBase_t *disownedItem);


/**
 * Adds clones of one list of items to another.
 *
 * @param lo the CList_t list to which @p list will be appended.
 * @param list the list of items to append to @p lo.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof CList_t
 */
CAPI_FUNC(int) CList_appendFrom (CList_t *lo, CList_t *list);


/**
 * Inserts a copy of an item into a CList_t list at a given position.
 *
 * @param lo the list into which @p item will be inserted.
 * @param location the starting index for the @p item in the @p lo list.
 * @param item the item to append to insert into @p lo.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof CList_t
 */
CAPI_FUNC(int) CList_insert (CList_t *lo, int location, const SBase_t *item);


/**
 * Inserts an item into a CList_t list at a given position.
 *
 * Unlike CList_insert(), this function does not clone @p disownedItem before
 * inserting it into @p lo, which means that @p lo becomes the owner.
 *
 * @param lo the list into which @p disownedItem will be inserted.
 * @param location the starting index for the @p disownedItem in the @p lo list.
 * @param disownedItem the item to append to insert into @p lo.
 * Will become a child of the parent list.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof CList_t
 */
CAPI_FUNC(int) CList_insertAndOwn (CList_t *lo, int location, SBase_t *disownedItem);


/**
 * Returns the <em>n</em>th item of a given list.
 *
 * @param lo the list from which to retrieve the item.
 * @param n the index of the item to retrieve.
 *
 * @return the <em>n</em>th item in this ListOf items, or a null pointer if
 * the index number @p n refers to a nonexistent position in @p lo.
 *
 * @see CList_size()
 *
 * @memberof CList_t
 */
CAPI_FUNC(SBase_t *) CList_get (CList_t *lo, unsigned int n);


#if (0)
/**
 * @return item in this CList_t items with the given @p sid or @c NULL if no such
 * item exists.
 *
 * @memberof CList_t
 */
CAPI_FUNC(SBase_t *) CList_getById (CList_t *lo, const char *sid);
#endif


/**
 * Removes all items in this CList_t structure.
 *
 * If @p doDelete is @c nonzero (true), all items in this CList_t structure
 * are both deleted and cleared, and thus the caller doesn't have to delete
 * those items.  Otherwise, if @p doDelete is @c 0 (false), all items are
 * only cleared from this CList_t structure and the caller is responsible
 * for deleting all items.  (In the latter case, callers are advised to store
 * pointers to all items elsewhere before calling this function.)
 *
 * @param lo the CList_t structure to clear.
 * @param doDelete whether to delete the items.
 *
 * @memberof CList_t
 */
CAPI_FUNC(void) CList_clear (CList_t *lo, int doDelete);


/**
 * Removes the <em>n</em>th item from this CList_t list and returns it.
 *
 * The caller owns the returned item and is responsible for deleting it.
 *
 * @param lo the list from which the item should be removed.
 * @param n the index number of the item to remove.
 *
 * @return the item removed, or a null pointer if no item existed at the
 * index @p n.
 *
 * @memberof CList_t
 */
CAPI_FUNC(SBase_t *) CList_remove (CList_t *lo, unsigned int n);


#if (0)
/**
 * Removes item in this CList_t items with the given @p sid or @c NULL if no such
 * item exists.  The caller owns the returned item and is repsonsible for
 * deleting it.
 *
 * @memberof CList_t
 */
CAPI_FUNC(SBase_t *) CList_removeById (CList_t *lo, const char *sid);
#endif


/**
 * Returns the number of items in this CList_t items.
 *
 * @param lo the CList_t structure to count.
 *
 * @return the number of items in @p lo.
 *
 * @memberof CList_t
 */
CAPI_FUNC(unsigned int) CList_size (const CList_t *lo);


/**
 * Get the type code of the objects contained in the given CList_t
 * structure.
 *
 * @copydetails doc_what_are_typecodes
 *
 * @param lo the CList_t whose item type codes are sought.
 *
 * @return the type code corresponding to the objects in @p lo,
 * or @sbmlconstant{SBML_UNKNOWN, SBMLTypeCode_t}.
 *
 * @memberof CList_t
 */
CAPI_FUNC(int) CList_getItemTypeCode (const CList_t *lo);



#endif /* EXTERN_CARBON_INCLUDE_C_LIST_H_ */
