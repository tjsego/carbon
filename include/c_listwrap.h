/*
 * c_listwrap.h
 *
 *  Created on: Mar 23, 2020
 *      Author: andy
 */

#ifndef EXTERN_CARBON_INCLUDE_C_LISTWRAP_H_
#define EXTERN_CARBON_INCLUDE_C_LISTWRAP_H_

#include <c_port.h>
#include <Python.h>

typedef Py_ssize_t (*cl_lenfunc)(void*);

typedef PyObject* (*cl_ssizeargfunc)(void*, Py_ssize_t);

typedef int (*cl_objobjproc)(void *, PyObject *);

typedef int(*cl_ssizeobjargproc)(void *, Py_ssize_t, PyObject *);

typedef PyObject* (*cl_binaryproc)(void *, PyObject *);

/**
 * C python wrapper for lists of stuff, where there is native storage,  but
 * each element will be accessible to python. Call needs to supply a set of callback
 * that access their underlying native data, and return a Python object.
 *
 * This structure holds pointers to the functions which an object uses to
 * implement the sequence protocol.
 *
 *
 */

typedef struct CListWrap
{
    PyObject_HEAD
    void *cl_user_data;

    /**
     * get the length of the sequence
     *
     *  It is also used for handling negative indices via the
     *  sq_item and the sq_ass_item slots.
     */
    cl_lenfunc cl_length;

    /**
     * ssizeargfunc PySequenceMethods.sq_repeat This function is used by
     * PySequence_Repeat() and has the same signature. It is also used by the
     * operator, after trying numeric multiplication via the nb_multiply slot.
     */
    ssizeargfunc sq_repeat;

    // old binary compibility stuff
    //void *was_sq_slice;
    //void *was_sq_ass_slice;

    /**
     * This function is used by PySequence_Concat() and has the same
     * signature. It is also used by the + operator, after trying the numeric
     * addition via the nb_add slot.
     */
    cl_binaryproc cl_concat;

    /**
     * ssizeargfunc PySequenceMethods.sq_item This function is used by
     * PySequence_GetItem() and has the same signature. It is also used by
     * PyObject_GetItem(), after trying the subscription via the mp_subscript
     * slot. This slot must be filled for the PySequence_Check() function to
     * return 1, it can be NULL otherwise.
     */

    /**
     * Negative indexes are handled as follows: if the sq_length slot is filled,
     * it is called and the sequence length is used to compute a positive index
     * which is passed to sq_item. If sq_length is NULL, the index is passed as is
     * to the function.
     */
    cl_ssizeargfunc cl_item;

    /**
     * ssizeobjargproc PySequenceMethods.sq_ass_item This function is used by
     * PySequence_SetItem() and has the same signature. It is also used by
     * PyObject_SetItem() and PyObject_DelItem(), after trying the item assignment
     * and deletion via the mp_ass_subscript slot. This slot may be left to NULL if
     * the object does not support item assignment and deletion.
     */
    cl_ssizeobjargproc sq_ass_item;

    /**
     * objobjproc PySequenceMethods.sq_contains This function may be used by
     * PySequence_Contains() and has the same signature. This slot may be left to
     * NULL, in this case PySequence_Contains() simply traverses the sequence
     * until it finds a match.
     */
    cl_objobjproc sq_contains;

    /**
     * binaryfunc PySequenceMethods.sq_inplace_concat This function is used by
     * PySequence_InPlaceConcat() and has the same signature. It should modify its
     * first operand, and return it. This slot may be left to NULL, in this case
     * PySequence_InPlaceConcat() will fall back to PySequence_Concat(). It is
     * also used by the augmented assignment +=, after trying numeric in-place
     * addition via the nb_inplace_add slot.
     */
    binaryfunc sq_inplace_concat;

    /**
     * ssizeargfunc PySequenceMethods.sq_inplace_repeat This function is used by
     * PySequence_InPlaceRepeat() and has the same signature. It should modify its
     * first operand, and return it. This slot may be left to NULL, in this case
     * PySequence_InPlaceRepeat() will fall back to PySequence_Repeat(). It is
     * also used by the augmented assignment *=, after trying numeric in-place
     * multiplication via the nb_inplace_multiply slot.
     */
    ssizeargfunc sq_inplace_repeat;



    uint32_t cl_flags;

} CListWrap;


/**
 * initializes a CListWrap object, sets the ref count and type pointer.
 * sets ref count to 1.
 */
HRESULT CListWrap_Init(CListWrap *obj);

/**
 * Type of the list wrapper
 */
CAPI_DATA(PyTypeObject) CListWrap_Type;

#endif /* EXTERN_CARBON_INCLUDE_C_LISTWRAP_H_ */
