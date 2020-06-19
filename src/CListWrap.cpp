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
  (lenfunc)length,                     // .sq_length
  (binaryfunc)concat,                     // .sq_concat
  (ssizeargfunc)repeat,                     // .sq_repeat
  (ssizeargfunc)item,                     // .sq_item
  NULL,                     // .was_sq_slice
  (ssizeobjargproc)ass_item,                     // .sq_ass_item
  NULL,                     // .was_sq_ass_slice
  (objobjproc)contains,                     // .sq_contains
  (binaryfunc)inplace_concat,                     // .sq_inplace_concat
  (ssizeargfunc)inplace_repeat                     // .sq_inplace_repeat
};

PyTypeObject CListWrap_Type = {
  CVarObject_HEAD_INIT(NULL, 0)
  "ListWrap",                     // .tp_name
  sizeof(CListWrap),                     // .tp_basicsize
  0,                     // .tp_itemsize
  0,                      // .tp_dealloc
  0,                      // .tp_print
  0,                      // .tp_getattr
  0,                      // .tp_setattr
  0,                      // .tp_as_async
  0,                      // .tp_repr
  0,                      // .tp_as_number
  &sequence,                     // .tp_as_sequence
  0,                      // .tp_as_mapping
  0,                      // .tp_hash
  0,                      // .tp_call
  0,                      // .tp_str
  0,                      // .tp_getattro
  0,                      // .tp_setattro
  0,                      // .tp_as_buffer
  Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                     // .tp_flags
  "Custom objects",                     // .tp_doc
  0,                      // .tp_traverse
  0,                      // .tp_clear
  0,                      // .tp_richcompare
  0,                      // .tp_weaklistoffset
  0,                      // .tp_iter
  0,                      // .tp_iternext
  0,                      // .tp_methods
  0,                      // .tp_members
  0,                      // .tp_getset
  0,                      // .tp_base
  0,                      // .tp_dict
  0,                      // .tp_descr_get
  0,                      // .tp_descr_set
  0,                      // .tp_dictoffset
  0,                      // .tp_init
  0,                      // .tp_alloc
  0,                      // .tp_new
  0,                      // .tp_free
  0,                      // .tp_is_gc
  0,                      // .tp_bases
  0,                      // .tp_mro
  0,                      // .tp_cache
  0,                      // .tp_subclasses
  0,                      // .tp_weaklist
  0,                      // .tp_del
  0,                      // .tp_version_tag
  0,                      // .tp_finalize
};





