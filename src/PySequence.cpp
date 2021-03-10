/*
 * PySequence.cpp
 *
 *  Created on: Mar 9, 2021
 *      Author: andy
 */

#include <PySequence.hpp>
#include <stdexcept>

namespace carbon {

sequence::sequence(PyObject *o)
{
    if(PySequence_Check(o)) {
        obj = o;
    }
    else {
        throw std::invalid_argument("object is not a sequence");
    }
}

size_t sequence::size() const
{
    return PySequence_Size(obj);
}

PyObject* sequence::get(int i)
{
    return PySequence_GetItem(obj, i);
}

int sequence::set(int index, PyObject *value)
{
    return PySequence_SetItem(obj, index, value);
}

}


