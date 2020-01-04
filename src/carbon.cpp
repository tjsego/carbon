/**
 * mechanica.cpp
 *
 * Initialize the mechanica module, python init functions.
 *
 *  Created on: Apr 2, 2017
 *      Author: andy
 */

// only source module that calls import_array()
#define MX_IMPORTING_NUMPY_ARRAY

#include "CObject.hpp"
//#include "CType.hpp"

#include <iostream>





static PyMethodDef methods[] = {
        { NULL, NULL, 0, NULL }
};

static struct PyModuleDef carbon_module = {
        PyModuleDef_HEAD_INIT,
        "_carbon",   /* name of module */
        NULL, /* module documentation, may be NULL */
        -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
        methods
};

static PyObject *carbonModule = NULL;

static PyObject * moduleinit(void)
{
    std::cout << MX_FUNCTION << std::endl;
    PyObject *m;


    m = PyModule_Create(&carbon_module);


    if (m == NULL)
        return NULL;

    CObject_init(m);


    /*

    if (empty_tuple == NULL)
        empty_tuple = PyTuple_New(0);

    ProxyType.tp_free = _PyObject_GC_Del;

    if (PyType_Ready(&ProxyType) < 0)
        return NULL;

    Py_INCREF(&ProxyType);
    PyModule_AddObject(m, "ProxyBase", (PyObject *)&ProxyType);

    if (api_object == NULL) {
        api_object = PyCObject_FromVoidPtr(&wrapper_capi, NULL);
        if (api_object == NULL)
        return NULL;
    }
    Py_INCREF(api_object);
    PyModule_AddObject(m, "_CAPI", api_object);

     */


    
    carbonModule = m;

    return m;
}


PyMODINIT_FUNC PyInit__carbon(void)
{
    return moduleinit();
}


/**
 * Initialize the entire runtime.
 */
MxAPI_FUNC(int) Mx_Initialize(int) {
    if(!Py_IsInitialized()) {
        Py_Initialize();
    }
    
    if(carbonModule == NULL) {
        moduleinit();
    }
    
    return 0;
}






