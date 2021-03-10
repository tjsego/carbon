/*
 * PySequence.h
 *
 *  Created on: Mar 9, 2021
 *      Author: andy
 */

#ifndef EXTERN_CARBON_SRC_PYSEQUENCE_H_
#define EXTERN_CARBON_SRC_PYSEQUENCE_H_

#include <c_port.h>

namespace carbon {

/**
 * Simple wrapper around python sequence
 */
class sequence
{
public:
    sequence(PyObject *o);
    
    size_t size() const;
    
    PyObject *get(int);
    
    int set(int index, PyObject *value);

    PyObject *obj;
};

}

#endif /* EXTERN_CARBON_SRC_PYSEQUENCE_H_ */
