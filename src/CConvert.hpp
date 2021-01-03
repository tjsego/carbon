/*
 * MxConvert.hpp
 *
 *  Created on: Nov 18, 2020
 *      Author: andy
 */

#ifndef _INCLUDE_CCONVERT_HPP_
#define _INCLUDE_CCONVERT_HPP_

#include <c_port.h>
#include <string>

namespace carbon {

/**
 * convert from c++ to python type
 */
template <typename T>
PyObject *cast(const T& x);

/**
 * convert from c++ to python type
 */
//template <typename T>
//PyObject *cast(T x);

/**
 * convert from python to c++ type
 */
template <typename T>
T cast(PyObject *o);

template<>
PyObject* cast(const float &f);

template<>
float cast(PyObject *obj);

template<>
PyObject* cast(const bool &f);

template<>
bool cast(PyObject *obj);

template<>
PyObject* cast(const double &f);

template<>
double cast(PyObject *obj);

template<>
PyObject* cast(const int &i);

template<>
int cast(PyObject *obj);



template<>
PyObject* cast(const std::string &s);

template<>
std::string cast(PyObject *o);

/**
 * check if type can be converted
 */
template <typename T>
bool check(PyObject *o);

template <>
bool check<bool>(PyObject *o);

template <>
bool check<std::string>(PyObject *o);

template <>
bool check<float>(PyObject *o);


/**
 * grab either the i'th arg from the args, or keywords.
 *
 * gets a reference to the object, NULL if not exist.
 */
PyObject *arg(const char* name, int index, PyObject *_args, PyObject *_kwargs);

}

#define C_BASIC_PYTHON_TYPE_INIT(type) \
HRESULT _C ## type ## _Init(PyObject* m) { \
    if (PyType_Ready((PyTypeObject*)&C ## type ## _Type) < 0) { \
        return E_FAIL; \
    } \
    \
    Py_INCREF(&C ## type ## _Type); \
    if (PyModule_AddObject(m, #type, (PyObject *)&C ## type ## _Type) < 0) { \
        Py_DECREF(&C ## type ## _Type); \
        return E_FAIL; \
    } \
    \
    return S_OK;\
}




#endif /* _INCLUDE_CCONVERT_HPP_ */
