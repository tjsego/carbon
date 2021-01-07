/*
 * CSpeciesList.cpp
 *
 *  Created on: Dec 16, 2020
 *      Author: andy
 */

#include <CSpeciesList.hpp>
#include <CSpecies.hpp>
#include <CObject.hpp>
#include <CConvert.hpp>
#include <sbml/Species.h>
#include <sstream>
#include <iostream>
#include <iterator>

static int specieslist_init(CSpeciesList *self, PyObject *args, PyObject *kwargs) {
    std::cout << MX_FUNCTION << std::endl;

}

// get named attribute
static PyObject *specieslist_getattro(CSpeciesList *self, PyObject *attr) {
    
    CSpecies *species = self->item(attr);
    if(species) {
        Py_INCREF(species);
        return species;
    }
    
    PyTypeObject *type = self->ob_type;
    PyTypeObject *base = type->tp_base;
    return base->tp_getattro((PyObject*)self, attr);
}

//Set the value of the named attribute for the object.
// The value argument is set to NULL to delete the attribute.
static int specieslist_setattro(CSpeciesList *self, PyObject *attr, PyObject *value) {
    
}

static void specieslist_dealloc(CSpeciesList *self) {
    std::cout << MX_FUNCTION << std::endl;

    self->ob_type->tp_free(self);
}

static PyMethodDef specieslist_methods[] = {
        { NULL, NULL, 0, NULL }
};

static PyObject* specieslist_str(CSpeciesList *self) {
    std::stringstream  ss;
    
    
    ss << "SpeciesList([";
    for(int i = 0; i < self->size(); ++i) {
        CSpecies *s = self->item(i);
        ss << "'" << s->getId() << "'";

        if(i+1 < self->size()) {
            ss << ", ";
        }
    }
    ss << "])";
    return carbon::cast(ss.str());
}


// sq_length
static Py_ssize_t specieslist_length(PyObject *_self) {
    CSpeciesList *self = (CSpeciesList*)_self;
    return self->size();
}


// sq_item
static PyObject *specieslist_subscript(PyObject *_self, PyObject *i) {

    CSpeciesList *self = (CSpeciesList*)_self;
    CSpecies *s = self->item(i);
    
    if(s) {
        Py_INCREF(s);
        return s;
    }
    else {
        PyErr_SetString(PyExc_IndexError, "index out of range");
    }
    return NULL;
}

// sq_ass_item
static int specieslist_ass_item(PyObject *_self, Py_ssize_t i, PyObject *o) {
    PyErr_SetString(PyExc_IndexError, "SpeciesList does not support assignment");
    return -1;
}




static PyMappingMethods specieslist_mapping = {
     specieslist_length,      //mp_length
     specieslist_subscript,   //mp_subscript
     0, //mp_ass_subscript
};


PyTypeObject CSpeciesList_Type = {
  CVarObject_HEAD_INIT(NULL, 0)
  "SpeciesList"                         , // .tp_name
  sizeof(CSpeciesList)                  , // .tp_basicsize
  0                                     , // .tp_itemsize
  (destructor)specieslist_dealloc       , // .tp_dealloc
  0                                     , // .tp_print
  0                                     , // .tp_getattr
  0                                     , // .tp_setattr
  0                                     , // .tp_as_async
  (reprfunc)specieslist_str             , // .tp_repr
  0                                     , // .tp_as_number
  0                                     , // .tp_as_sequence
  &specieslist_mapping                  , // .tp_as_mapping
  0                                     , // .tp_hash
  0                                     , // .tp_call
  (reprfunc)specieslist_str             , // .tp_str
  (getattrofunc)specieslist_getattro    , // .tp_getattro                                     , // .tp_getattro
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
  specieslist_methods                   , // .tp_methods
  0                                     , // .tp_members
  0                                     , // .tp_getset
  0                                     , // .tp_base
  0                                     , // .tp_dict
  0                                     , // .tp_descr_get
  0                                     , // .tp_descr_set
  0                                     , // .tp_dictoffset
  (initproc)specieslist_init            , // .tp_init
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
  0                                     , // .tp_next =
#endif
};

CSpeciesList* CSpeciesList_NewFromPyArgs(PyObject *args) {
    if(args == NULL || !PySequence_Check(args)) {
        PyErr_SetString(PyExc_ValueError, "args must be a sequence");
        return NULL;
    }
    
    CSpeciesList *obj = (CSpeciesList*)PyType_GenericNew(&CSpeciesList_Type, NULL, NULL);
    if(!obj) {
        PyErr_SetString(PyExc_ValueError, "could not allocate new SpeciesList");
        return NULL;
    }
    
    obj->init();
    
    int size = PySequence_Size(args);
    for(int i = 0; i < size; ++i) {
        CSpecies *species = CSpecies_NewFromPyArgs(PySequence_GetItem(args, i), NULL);
        if(species) {
            obj->insert(species);
        }
        else {
            // CSpecies_NewFromPyArgs sets python error if it fails
            Py_DECREF(obj);
            return NULL;
        }
    }
    return obj;
}

C_BASIC_PYTHON_TYPE_INIT(SpeciesList)

int32_t CSpeciesList::index_of(PyObject *species_name) const
{
    int32_t result = -1;
    if(PyUnicode_Check(species_name)) {
        PyObject * temp_bytes = PyUnicode_AsASCIIString(species_name); // Owned reference
        if (temp_bytes != NULL) {
            const char* str = PyBytes_AS_STRING(temp_bytes);           // Borrowed pointer
            
            Map::const_iterator i = species_map.find(str);
            
            if(i != species_map.end()) {
                result = std::distance(species_map.begin(), i);
            }
            
            Py_DECREF(temp_bytes);
        }
    }
    else if(PyNumber_Check(species_name)) {
        return PyLong_AsLong(species_name);
    }
    return result;
}

int32_t CSpeciesList::index_of(const char *species_name) const
{
    int32_t result = -1;
    
    Map::const_iterator i = species_map.find(species_name);
    
    if(i != species_map.end()) {
        result = std::distance(species_map.begin(), i);
    }
    
    return result;
}

int32_t CSpeciesList::index_of(const std::string& s) const
{
    int32_t result = -1;
    
    Map::const_iterator i = species_map.find(s);
    
    if(i != species_map.end()) {
        result = std::distance(species_map.begin(), i);
    }
    
    return result;
}

int32_t CSpeciesList::size() const
{
    return species_map.size();
}

CSpecies* CSpeciesList::item(PyObject *index_or_key) const
{
    CSpecies *result = NULL;
    if(PyUnicode_Check(index_or_key)) {
        PyObject * temp_bytes = PyUnicode_AsASCIIString(index_or_key); // Owned reference
        if (temp_bytes != NULL) {
            const char* str = PyBytes_AS_STRING(temp_bytes);           // Borrowed pointer
            
            Map::const_iterator i = species_map.find(str);
            
            if(i != species_map.end()) {
                result = i->second;
            }
            
            Py_DECREF(temp_bytes);
            
            return result;
        }
    }
    
    long index = PyLong_AsLong(index_or_key);
    
    if(index >= 0 && index < size()) {
        return item(index);
    }
    
    // arg is probably not an integer, or maybe out of range,
    // just clear it, and return NULL.
    PyErr_Clear();
    
    return result;
}

CSpecies* CSpeciesList::item(const std::string &s) const
{
    Map::const_iterator i = species_map.find(s);
    if(i != species_map.end()) {
        return i->second;
    }
    return NULL;
}



CSpecies* CSpeciesList::item(int32_t index) const
{
    if(index < species_map.size()) {
        Map::const_iterator i = species_map.begin();
        i = std::next(i, index);
        return i->second;
    }
    return NULL;
}

HRESULT CSpeciesList::insert(CSpecies* s)
{
    species_map.emplace(s->getId(), s);
    return S_OK;
}

void CSpeciesList::init()
{
    new(&species_map) Map();
}
