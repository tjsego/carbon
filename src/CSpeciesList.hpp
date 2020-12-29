/*
 * CSpeciesList.hpp
 *
 *  Created on: Dec 16, 2020
 *      Author: andy
 */

#ifndef EXTERN_CARBON_SRC_CSpeciesList_HPP_
#define EXTERN_CARBON_SRC_CSpeciesList_HPP_

#include <c_port.h>
#include <map>

struct CSpecies;

struct CSpeciesList : PyObject
{
    // get the index of a species name, arg should be
    // a py_unicode object.
    // returns >= 0 on success, -1 on failure,
    // does not set any error.
    int32_t index_of(PyObject *species_name) const;
    
    int32_t size() const;
    
    CSpecies *item(PyObject *index_or_key) const;
    
    CSpecies *item(int32_t index) const;
    
    CSpecies *item(const std::string &s) const;
    
    /**
     * inserts and steals a CSpecies* object
     */
    HRESULT insert(CSpecies*);
    
    void init();
    
private:
    
    typedef std::map<std::string, CSpecies*> Map;
    Map species_map;
};

CAPI_FUNC(CSpeciesList*) CSpeciesList_NewFromPyArgs(PyObject *args);

CAPI_DATA(PyTypeObject) CSpeciesList_Type;

HRESULT _CSpeciesList_Init(PyObject *m);

#endif /* EXTERN_CARBON_SRC_CSpeciesList_HPP_ */
