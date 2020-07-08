
/*
 * c_util.cpp
 *
 *  Created on: Jun 30, 2020
 *      Author: andy
 */

#include <Python.h>
#include <c_util.h>


CRandomType CRandom;



int CDict_ContainsItemString(PyObject *p, const char *key)
{
    PyObject *kv;
    int rv;
    kv = PyUnicode_FromString(key);
    if (kv == NULL) {
        PyErr_Clear();
        return -1;
    }
    rv = PyDict_Contains(p, kv);
    Py_DECREF(kv);
    return rv;
}




