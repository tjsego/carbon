/*
 * cspecies.cpp
 *
 *  Created on: Jun 4, 2020 *      Author: andy
 */

#include <CSpecies.hpp>
#include <c_object.hpp>
#include <CConvert.hpp>

#include <sbml/Species.h>
#include <sbml/SBMLNamespaces.h>

#include <iostream>
#include <regex>


static libsbml::SBMLNamespaces *sbmlns = NULL;

libsbml::SBMLNamespaces* C_GetSBMLNamespaces() {
    if(!sbmlns) {
        sbmlns = new libsbml::SBMLNamespaces();
    }
    return sbmlns;
}

CSpecies_t *CSpecies_create(unsigned int level,
        unsigned int version)
{
    return 0;
}

void CSpecies_free(CSpecies_t *s)
{
}

CSpecies_t *CSpecies_clone(const CSpecies_t *s)
{
    return 0;
}

void CSpecies_initDefaults(CSpecies_t *s)
{
}

PyObject* CSpecies_getId(const CSpecies_t *s)
{
    return 0;
}

PyObject* CSpecies_getName(const CSpecies_t *s)
{
    //lib
    //return carbon::cast(s->getNa)
    return NULL;
}

const char* CSpecies_getSpeciesType(const CSpecies_t *s)
{
    return 0;
}

const char* CSpecies_getCompartment(const CSpecies_t *s)
{
    return 0;
}

double CSpecies_getInitialAmount(const CSpecies_t *s)
{
    return 0;
}

double CSpecies_getInitialConcentration(const CSpecies_t *s)
{
    return 0;
}

const char* CSpecies_getSubstanceUnits(const CSpecies_t *s)
{
    return 0;
}

const char* CSpecies_getSpatialSizeUnits(const CSpecies_t *s)
{
    return 0;
}

const char* CSpecies_getUnits(const CSpecies_t *s)
{
    return 0;
}

int CSpecies_getHasOnlySubstanceUnits(const CSpecies_t *s)
{
    return 0;
}

int CSpecies_getBoundaryCondition(const CSpecies_t *s)
{
    return 0;
}

int CSpecies_getCharge(const CSpecies_t *s)
{
    return 0;
}

int CSpecies_getConstant(const CSpecies_t *s)
{
    return 0;
}

const char* CSpecies_getConversionFactor(const CSpecies_t *s)
{
    return 0;
}

int CSpecies_isSetId(const CSpecies_t *s)
{
    return 0;
}

int CSpecies_isSetName(const CSpecies_t *s)
{
    return 0;
}

int CSpecies_isSetSpeciesType(const CSpecies_t *s)
{
    return 0;
}

int CSpecies_isSetCompartment(const CSpecies_t *s)
{
    return 0;
}

int CSpecies_isSetInitialAmount(const CSpecies_t *s)
{
    return 0;
}

int CSpecies_isSetInitialConcentration(const CSpecies_t *s)
{
    return 0;
}

int CSpecies_isSetSubstanceUnits(const CSpecies_t *s)
{
    return 0;
}

int CSpecies_isSetSpatialSizeUnits(const CSpecies_t *s)
{
    return 0;
}

int CSpecies_isSetUnits(const CSpecies_t *s)
{
    return 0;
}

int CSpecies_isSetCharge(const CSpecies_t *s)
{
    return 0;
}

int CSpecies_isSetConversionFactor(const CSpecies_t *s)
{
    return 0;
}

int CSpecies_isSetConstant(const CSpecies_t *s)
{
    return 0;
}

int CSpecies_isSetBoundaryCondition(const CSpecies_t *s)
{
    return 0;
}

int CSpecies_isSetHasOnlySubstanceUnits(const CSpecies_t *s)
{
    return 0;
}

int CSpecies_setId(CSpecies_t *s, const char *sid)
{
    return 0;
}

int CSpecies_setName(CSpecies_t *s, const char *name)
{
    return 0;
}

int CSpecies_setSpeciesType(CSpecies_t *s, const char *sid)
{
    return 0;
}

int CSpecies_setCompartment(CSpecies_t *s, const char *sid)
{
    return 0;
}

int CSpecies_setInitialAmount(CSpecies_t *s, double value)
{
    return 0;
}

int CSpecies_setInitialConcentration(CSpecies_t *s, double value)
{
    return 0;
}

int CSpecies_setSubstanceUnits(CSpecies_t *s, const char *sid)
{
    return 0;
}

int CSpecies_setSpatialSizeUnits(CSpecies_t *s, const char *sid)
{
    return 0;
}

int CSpecies_setUnits(CSpecies_t *s, const char *sname)
{
    return 0;
}

int CSpecies_setHasOnlySubstanceUnits(CSpecies_t *s, int value)
{
    return 0;
}

int CSpecies_setBoundaryCondition(CSpecies_t *s, int value)
{
    return 0;
}

int CSpecies_setCharge(CSpecies_t *s, int value)
{
    return 0;
}

int CSpecies_setConstant(CSpecies_t *s, int value)
{
    return 0;
}

int CSpecies_setConversionFactor(CSpecies_t *s, const char *sid)
{
    return 0;
}

int CSpecies_unsetId(CSpecies_t *s)
{
    return 0;
}

int CSpecies_unsetName(CSpecies_t *s)
{
    return 0;
}

int CSpecies_unsetConstant(CSpecies_t *c)
{
    return 0;
}

int CSpecies_unsetSpeciesType(CSpecies_t *s)
{
    return 0;
}

int CSpecies_unsetInitialAmount(CSpecies_t *s)
{
    return 0;
}

int CSpecies_unsetInitialConcentration(CSpecies_t *s)
{
    return 0;
}

int CSpecies_unsetSubstanceUnits(CSpecies_t *s)
{
    return 0;
}

int CSpecies_unsetSpatialSizeUnits(CSpecies_t *s)
{
    return 0;
}

int CSpecies_unsetUnits(CSpecies_t *s)
{
    return 0;
}

int CSpecies_unsetCharge(CSpecies_t *s)
{
    return 0;
}

int CSpecies_unsetConversionFactor(CSpecies_t *s)
{
    return 0;
}

int CSpecies_unsetCompartment(CSpecies_t *s)
{
    return 0;
}

int CSpecies_unsetBoundaryCondition(CSpecies_t *s)
{
    return 0;
}

int CSpecies_unsetHasOnlySubstanceUnits(CSpecies_t *s)
{
    return 0;
}

int CSpecies_hasRequiredAttributes(CSpecies_t *s)
{
    return 0;
}

static int cspecies_init(CSpecies *self, PyObject *args, PyObject *kwargs) {
    std::string msg;
    PyObject *arg = NULL;
    std::string s;
    
    try {
        
        if(args && PyTuple_Check(args) && PyTuple_Size(args) == 1) {
            arg = PyTuple_GetItem(args, 0);
        }
        else {
            arg = args;
        }
        
        if(carbon::check<std::string>(arg)) {
            s = carbon::cast<std::string>(arg);
            
            static std::regex e ("\\s*(const\\s+)?(\\$)?(\\w+)(\\s+=\\s+)?([-+]?[0-9]*\\.?[0-9]+)?\\s*");
            
            std::smatch sm;    // same as std::match_results<string::const_iterator> sm;
            
            // if we have a match, it looks like this:
            // matches for "const S1 = 234234.5"
            // match(0):(19)"const S1 = 234234.5"
            // match(1):(6)"const "
            // match(2):(0)""
            // match(3):(2)"S1"
            // match(4):(3)" = "
            // match(5):(8)"234234.5"
            static const int CNST = 1;  // Windows complains if name is CONST
            static const int BOUNDARY = 2;
            static const int ID = 3;
            static const int EQUAL = 4;
            static const int INIT = 5;
            
            if(std::regex_match (s,sm,e) && sm.size() == 6) {
                // check if name is valid sbml id
                if(!sm[ID].matched || !libsbml::SyntaxChecker_isValidSBMLSId(sm[ID].str().c_str())) {
                    msg = "invalid Species id: \"" + sm[ID].str() + "\"";
                    PyErr_SetString(PyExc_ValueError, msg.c_str());
                    return -1;
                }
                
                if(sm[INIT].matched && !sm[EQUAL].matched) {
                    msg = "Species has initial assignemnt value without equal symbol: \"" + s + "\"";
                    PyErr_SetString(PyExc_ValueError, msg.c_str());
                    return -1;
                }
                
                self->species = new libsbml::Species(C_GetSBMLNamespaces());
                self->species->setId(sm[ID].str());
                self->species->setBoundaryCondition(sm[BOUNDARY].matched);
                self->species->setConstant(sm[CNST].matched);
                
                if(sm[INIT].matched) {
                    self->species->setInitialConcentration(std::stod(sm[INIT].str()));
                }
                
                return 0;
            }
            else {
                std::string msg = "invalid Species string: \"" + s + "\"";
                PyErr_SetString(PyExc_ValueError, msg.c_str());
                return -1;
            }
        }
        else {
            PyErr_SetString(PyExc_ValueError, "Species(args) must be a string");
            return -1;
        }
    }
    catch(const std::exception &e) {
        msg = "error creating Species(" + s + "\") : " + e.what();
        PyErr_SetString(PyExc_ValueError, "error creating Species");
        return -1;
    }
    return -1;
}

static void cspecies_dealloc(CSpecies *self) {
    delete self->species;
    self->ob_type->tp_free(self);
}

CSpecies* CSpecies_NewFromPyArgs(PyObject *args, PyObject *kwargs) {
    CSpecies *obj = (CSpecies*)PyType_GenericNew(&CSpecies_Type, NULL, NULL);
    if(!obj) {
        PyErr_SetString(PyExc_ValueError, "could not allocate CSpecies object");
        return NULL;
    }
    
    if(cspecies_init(obj, args, kwargs) != 0) {
        Py_DECREF(obj);
        return NULL;
    }
    
    return obj;
}

static PyMethodDef species_methods[] = {
        { NULL, NULL, 0, NULL }
};

PyGetSetDef cspecies_getsets[] = {
    {
        .name = "id",
        .get = [](PyObject *obj, void *p) -> PyObject* {
            CSpecies *self = (CSpecies*)obj;
            return PySpecies_getId(self);
        },
        .set = [](PyObject *obj, PyObject *val, void *p) -> int {
            CSpecies *self = (CSpecies*)obj;
            return PySpecies_setId(self, val);
        },
        .doc = "test doc",
        .closure = NULL
    },
    {
        .name = "name",
        .get = [](PyObject *obj, void *p) -> PyObject* {
            CSpecies *self = (CSpecies*)obj;
            return PySpecies_getName(self);
        },
        .set = [](PyObject *obj, PyObject *val, void *p) -> int {
            CSpecies *self = (CSpecies*)obj;
            return PySpecies_setName(self, val);
        },
        .doc = "test doc",
        .closure = NULL
    },
    {
        .name = "boundary",
        .get = [](PyObject *obj, void *p) -> PyObject* {
            CSpecies *self = (CSpecies*)obj;
            return PySpecies_getBoundaryCondition(self);
        },
        .set = [](PyObject *obj, PyObject *val, void *p) -> int {
            CSpecies *self = (CSpecies*)obj;
            return PySpecies_setBoundaryCondition(self, val);
        },
        .doc = "test doc",
        .closure = NULL
    },
    {
        .name = "initial_amount",
        .get = [](PyObject *obj, void *p) -> PyObject* {
            CSpecies *self = (CSpecies*)obj;
            return PySpecies_getInitialAmount(self);
        },
        .set = [](PyObject *obj, PyObject *val, void *p) -> int {
            CSpecies *self = (CSpecies*)obj;
            return PySpecies_setInitialAmount(self, val);
        },
        .doc = "test doc",
        .closure = NULL
    },
    {
        .name = "initial_concentration",
        .get = [](PyObject *obj, void *p) -> PyObject* {
            CSpecies *self = (CSpecies*)obj;
            return PySpecies_getInitialConcentration(self);
        },
        .set = [](PyObject *obj, PyObject *val, void *p) -> int {
            CSpecies *self = (CSpecies*)obj;
            return PySpecies_setInitialConcentration(self, val);
        },
        .doc = "test doc",
        .closure = NULL
    },
    {
        .name = "constant",
        .get = [](PyObject *obj, void *p) -> PyObject* {
            CSpecies *self = (CSpecies*)obj;
            return PySpecies_getConstant(self);
        },
        .set = [](PyObject *obj, PyObject *val, void *p) -> int {
            CSpecies *self = (CSpecies*)obj;
            return PySpecies_setConstant(self, val);
        },
        .doc = "test doc",
        .closure = NULL
    },
    {NULL}
};


static PyObject* species_str(CSpecies *self) {
    std::string s = "Species('";
    if(self->species->isSetBoundaryCondition() &&
       self->species->getBoundaryCondition()) {
        s += "$";
    }
    s += self->species->getId();
    s += "')";
    return carbon::cast(s);
}




PyTypeObject CSpecies_Type = {
  CVarObject_HEAD_INIT(NULL, 0)
  "Species"                             , // .tp_name
  sizeof(CSpecies)                      , // .tp_basicsize
  0                                     , // .tp_itemsize
  (destructor )cspecies_dealloc         , // .tp_dealloc
  0                                     , // .tp_print
  0                                     , // .tp_getattr
  0                                     , // .tp_setattr
  0                                     , // .tp_as_async
  (reprfunc)species_str                 , // .tp_repr
  0                                     , // .tp_as_number
  0                                     , // .tp_as_sequence
  0                                     , // .tp_as_mapping
  0                                     , // .tp_hash
  0                                     , // .tp_call
  (reprfunc)species_str                 , // .tp_str
  0                                     , // .tp_getattro
  0                                     , // .tp_setattro
  0                                     , // .tp_as_buffer
  Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE , // .tp_flags
  0                                     , // .tp_doc
  0                                     , // .tp_traverse
  0                                     , // .tp_clear
  0                                     , // .tp_richcompare
  0                                     , // .tp_weaklistoffset
  0                                     , // .tp_iter
  0                                     , // .tp_iternext
  species_methods                       , // .tp_methods
  0                                     , // .tp_members
  cspecies_getsets                      , // .tp_getset
  0                                     , // .tp_base
  0                                     , // .tp_dict
  0                                     , // .tp_descr_get
  0                                     , // .tp_descr_set
  0                                     , // .tp_dictoffset
  (initproc)cspecies_init               , // .tp_init
  0                                     , // .tp_alloc
  PyType_GenericNew                     , // .tp_new
  0                                     , // .tp_free
  0                                     , // .tp_is_gc
  0                                     , // .tp_bases
  0                                     , // .tp_mro
  0                                     , // .tp_cache
  0                                     , // .tp_subclasses
  0                                     , // .tp_weaklist
  0                                     , // .tp_del
  0                                     , // .tp_version_tag
  0                                     , // .tp_finalize
  #ifdef COUNT_ALLOCS
  0                                     , // .tp_allocs
  0                                     , // .tp_frees
  0                                     , // .tp_maxalloc
  0                                     , // .tp_prev
  0                                     , // .tp_next
  #endif
};

    
PyObject* PySpecies_getId(const CSpecies *cs)
{
    libsbml::Species *s = cs->species;
    if(s->isSetId()) {
        return carbon::cast(s->getId());
    }
    else {
        Py_RETURN_NONE;
    }
}

PyObject* PySpecies_getName(const CSpecies *cs)
{
    libsbml::Species *s = cs->species;
    if(s->isSetName()) {
        return carbon::cast(s->getName());
    }
    else {
        Py_RETURN_NONE;
    }
}

PyObject* PySpecies_getInitialAmount(const CSpecies *cs)
{
    libsbml::Species *s = cs->species;
    if(s->isSetInitialAmount()) {
        return carbon::cast(s->getInitialAmount());
    }
    else {
        Py_RETURN_NONE;
    }
}

PyObject* PySpecies_getInitialConcentration(const CSpecies *cs)
{
    libsbml::Species *s = cs->species;
    if(s->isSetInitialConcentration()) {
        return carbon::cast(s->getInitialConcentration());
    }
    else {
        Py_RETURN_NONE;
    }
}

PyObject* PySpecies_getBoundaryCondition(const CSpecies *cs)
{
    libsbml::Species *s = cs->species;
    if(s->isSetBoundaryCondition()) {
        return carbon::cast(s->getBoundaryCondition());
    }
    else {
        Py_RETURN_NONE;
    }
}

PyObject* PySpecies_getConstant(const CSpecies *cs)
{
    libsbml::Species *s = cs->species;
    if(s->isSetConstant()) {
        return carbon::cast(s->getConstant());
    }
    else {
        Py_RETURN_NONE;
    }
}

int PySpecies_setId(CSpecies *cs, PyObject *str)
{
    libsbml::Species *s = cs->species;
    return s->setId(carbon::cast<std::string>(str));
}

int PySpecies_setName(CSpecies *cs, PyObject *str)
{
    libsbml::Species *s = cs->species;
    return s->setName(carbon::cast<std::string>(str));
}

int PySpecies_setInitialAmount(CSpecies *cs, PyObject *value)
{
    libsbml::Species *s = cs->species;
    return s->setInitialAmount(carbon::cast<double>(value));
}

int PySpecies_setInitialConcentration(CSpecies *cs, PyObject *value)
{
    libsbml::Species *s = cs->species;
    return s->setInitialConcentration(carbon::cast<double>(value));
}

int PySpecies_setBoundaryCondition(CSpecies *cs, PyObject *value)
{
    libsbml::Species *s = cs->species;
    return s->setBoundaryCondition(carbon::cast<bool>(value));
}

int PySpecies_setConstant(CSpecies *cs, PyObject *value)
{
    libsbml::Species *s = cs->species;
    return s->setBoundaryCondition(carbon::cast<bool>(value));
}

C_BASIC_PYTHON_TYPE_INIT(Species)
