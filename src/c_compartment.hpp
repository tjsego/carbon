/*
 * c_compartment.hpp
 *
 *  Created on: Jun 18, 2020
 *      Author: andy
 */

#ifndef EXTERN_CARBON_SRC_C_COMPARTMENT_HPP_
#define EXTERN_CARBON_SRC_C_COMPARTMENT_HPP_


#include <c_compartment.h>


namespace libsbml{
    class Compartment;
}

struct CCompartment_t {
    libsbml::Compartment *sbml_obj;
};


#endif /* EXTERN_CARBON_SRC_C_COMPARTMENT_HPP_ */
