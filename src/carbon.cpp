/**
 * mechanica.cpp
 *
 * Initialize the mechanica module, python init functions.
 *
 *  Created on: Apr 2, 2017
 *      Author: andy
 */


#include <carbon.hpp>

// only source module that calls import_array()
#define MX_IMPORTING_NUMPY_ARRAY

#include "CObject.hpp"
#include "CType.hpp"

#include <iostream>





static PyMethodDef methods[] = {
        { NULL, NULL, 0, NULL }
};

static struct PyModuleDef carbon_module = {
        PyModuleDef_HEAD_INIT,
        "carbon",   /* name of module */
        NULL, /* module documentation, may be NULL */
        -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
        methods
};

PyObject *Carbon_ModulePtr = NULL;

static PyObject * moduleinit(void)
{
    std::cout << MX_FUNCTION << std::endl;
    PyObject *m;


    std::cout << "creating carbon module" << std::endl;
    m = PyModule_Create(&carbon_module);


    if (m == NULL)
        return NULL;

    CType_init(m);

    CObject_init(m);

    if (PyType_Ready(&CMemberDescr_Type) < 0) {
        Py_FatalError("Can't initialize CMemberDescr_Type type");
        return NULL;
    }


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


    
    Carbon_ModulePtr = m;

    return m;
}


PyMODINIT_FUNC PyInit_carbon(void)
{
    return moduleinit();
}


/**
 * Initialize the entire runtime.
 */
CAPI_FUNC(HRESULT) C_Initialize(int) {
    std::cout << MX_FUNCTION << std::endl;

    if(!Py_IsInitialized()) {
        Py_Initialize();
    }


    std::cout << "creating carbon module" << std::endl;
    if(Carbon_ModulePtr == NULL) {

        Carbon_ModulePtr = PyModule_Create(&carbon_module);


        CType_init(Carbon_ModulePtr);

        CObject_init(Carbon_ModulePtr);

        if (PyType_Ready((PyTypeObject*)&CListWrap_Type) < 0) {
            std::cout << "could not initialize CListWrap_Type " << std::endl;
            return E_FAIL;
        }


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


    }

    return S_OK;
}

CAPI_FUNC(HRESULT) C_Finalize()
{
    return S_OK;
}
