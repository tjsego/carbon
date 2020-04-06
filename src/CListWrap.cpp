/*
 * CListWrap.cpp
 *
 *  Created on: Mar 23, 2020
 *      Author: andy
 */
#include <carbon.h>


typedef struct {
    lenfunc sq_length;
    binaryfunc sq_concat;
    ssizeargfunc sq_repeat;
    ssizeargfunc sq_item;
    void *was_sq_slice;
    ssizeobjargproc sq_ass_item;
    void *was_sq_ass_slice;
    objobjproc sq_contains;

    binaryfunc sq_inplace_concat;
    ssizeargfunc sq_inplace_repeat;
} XXFoo;



static Py_ssize_t length(CListWrap *self) {
    return self->cl_length(self->cl_user_data);
}

static PyObject *concat(CListWrap *self, PyObject *obj) {
    return self->cl_concat(self->cl_user_data, obj);
}

static PyObject *repeat(CListWrap *self) {
    return NULL;
}

static PyObject *item(CListWrap *self) {
    return NULL;
}


static PyObject *ass_item(CListWrap *self) {
    return NULL;
}

static PyObject *contains(CListWrap *self) {
    return NULL;
}

static PyObject *inplace_concat(CListWrap *self) {
    return NULL;
}

static PyObject *inplace_repeat(CListWrap *self) {
    return NULL;
}


PySequenceMethods sequence = {
    .sq_length = (lenfunc)length,
    .sq_concat = (binaryfunc)concat,
    .sq_repeat = (ssizeargfunc)repeat,
    .sq_item = (ssizeargfunc)item,
    .was_sq_slice = NULL,
    .sq_ass_item = (ssizeobjargproc)ass_item,
    .was_sq_ass_slice = NULL,
    .sq_contains = (objobjproc)contains,
    .sq_inplace_concat = (binaryfunc)inplace_concat,
    .sq_inplace_repeat = (ssizeargfunc)inplace_repeat
};

PyTypeObject CListWrap_Type = {
        PyVarObject_HEAD_INIT(NULL, 0)
        .tp_name = "ListWrap",
        .tp_doc = "Custom objects",
        .tp_basicsize = sizeof(CListWrap),
        .tp_itemsize = 0,
        .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
        .tp_new = NULL,
        .tp_members = NULL,
        .tp_descr_get = (descrgetfunc)NULL,
        .tp_init = (initproc)NULL,
        .tp_as_sequence = &sequence
};





