/*
 * DescrObject.cpp
 *
 *  Created on: Mar 17, 2020
 *      Author: andy
 */
#include "carbon.h"
#include "c_descrobject.h"
#include "structmember.h"
#include <iostream>




struct Foo : PyHeapTypeObject {
    
    /** ID of this type */
    int id;
    
    /** Constant physical characteristics */
    double mass, imass, charge;
    
    /** Nonbonded interaction parameters. */
    double eps, rmin;
    
    /** Name of this paritcle type. */
    char name[64], name2[64];
    
} ;



/*[clinic input]
class mappingproxy "mappingproxyobject *" "&PyDictProxy_Type"
class property "propertyobject *" "&PyProperty_Type"
[clinic start generated code]*/
/*[clinic end generated code: output=da39a3ee5e6b4b0d input=556352653fd4c02e]*/

static void
descr_dealloc(CDescrObject *descr)
{
    _PyObject_GC_UNTRACK(descr);
    Py_XDECREF(descr->d_type);
    Py_XDECREF(descr->d_name);
    Py_XDECREF(descr->d_qualname);
    PyObject_GC_Del(descr);
}

static PyObject *
descr_name(CDescrObject *descr)
{
    if (descr->d_name != NULL && PyUnicode_Check(descr->d_name))
        return descr->d_name;
    return NULL;
}

static PyObject *
descr_repr(CDescrObject *descr, const char *format)
{
    PyObject *name = NULL;
    if (descr->d_name != NULL && PyUnicode_Check(descr->d_name))
        name = descr->d_name;

    return PyUnicode_FromFormat(format, name, "?", descr->d_type->tp_name);
}

static PyObject *
method_repr(PyMethodDescrObject *descr)
{
    return descr_repr((CDescrObject *)descr,
                      "<method '%V' of '%s' objects>");
}

static PyObject *
member_repr(CMemberDescrObject *descr)
{
    return descr_repr((CDescrObject *)descr,
                      "<member '%V' of '%s' objects>");
}

static PyObject *
getset_repr(PyGetSetDescrObject *descr)
{
    return descr_repr((CDescrObject *)descr,
                      "<attribute '%V' of '%s' objects>");
}


static int
descr_check(CDescrObject *descr, PyObject *obj, PyObject **pres)
{
    if (obj == NULL) {
        Py_INCREF(descr);
        *pres = (PyObject *)descr;
        return 1;
    }
    if (!PyObject_TypeCheck(obj, descr->d_type)) {
        PyErr_Format(PyExc_TypeError,
                     "descriptor '%V' for '%s' objects "
                     "doesn't apply to '%s' object",
                     descr_name((CDescrObject *)descr), "?",
                     descr->d_type->tp_name,
                     obj->ob_type->tp_name);
        *pres = NULL;
        return 1;
    }
    return 0;
}



static PyObject *
member_get(CMemberDescrObject *descr, PyObject *obj, PyObject *type)
{
    std::cout << MX_FUNCTION << std::endl;
    
    PyObject *res;

    if (descr_check((CDescrObject *)descr, obj, &res))
        return res;

    char *addr = NULL;

    if(descr->d_member.flags & CDESCR_INSTANCE) {
        addr = (char*)obj;
    }
    else if(descr->d_member.flags & CDESCR_TYPE) {
        addr = (char*)type;
    }
    else {
        return NULL;
    }
    
//    Foo *ft = (Foo*)type;
//
//    Foo *fo = (Foo*)obj;
//
//    char* fta = (char*)&ft->mass;
//
//    char* ftaa = (char*)(ft) + offsetof(Foo, mass);
//
//    char* xx = (char*)(ft) + descr->d_member.offset;
//
//    std::cout << *((double*)fta) << std::endl;
//    std::cout << *((double*)ftaa) << std::endl;
//    std::cout << *((double*)xx) << std::endl;

    return PyMember_GetOne(addr, &descr->d_member);
}

static PyObject *
getset_get(PyGetSetDescrObject *descr, PyObject *obj, PyObject *type)
{
    PyObject *res;

    if (descr_check((CDescrObject *)descr, obj, &res))
        return res;
    if (descr->d_getset->get != NULL)
        return descr->d_getset->get(obj, descr->d_getset->closure);
    PyErr_Format(PyExc_AttributeError,
                 "attribute '%V' of '%.100s' objects is not readable",
                 descr_name((CDescrObject *)descr), "?",
                 PyDescr_TYPE(descr)->tp_name);
    return NULL;
}



static int
descr_setcheck(CDescrObject *descr, PyObject *obj, PyObject *value,
               int *pres)
{
    assert(obj != NULL);
    if (!PyObject_TypeCheck(obj, descr->d_type)) {
        PyErr_Format(PyExc_TypeError,
                     "descriptor '%V' for '%.100s' objects "
                     "doesn't apply to '%.100s' object",
                     descr_name(descr), "?",
                     descr->d_type->tp_name,
                     obj->ob_type->tp_name);
        *pres = -1;
        return 1;
    }
    return 0;
}






static int
member_set(CMemberDescrObject *descr, PyObject *obj, PyObject *value)
{
    std::cout << MX_FUNCTION << std::endl;
    
    int res;

    if (descr_setcheck((CDescrObject *)descr, obj, value, &res))
        return res;
    
    char *addr = NULL;
    
    if(descr->d_member.flags & CDESCR_INSTANCE) {
        addr = (char*)obj;
    }
    else if(descr->d_member.flags & CDESCR_TYPE) {
        addr = (char*)obj->ob_type;
    }
    else {
        return -1;
    }
    
    return PyMember_SetOne(addr, &descr->d_member, value);
}

static int
getset_set(PyGetSetDescrObject *descr, PyObject *obj, PyObject *value)
{
    int res;

    if (descr_setcheck((CDescrObject *)descr, obj, value, &res))
        return res;
    if (descr->d_getset->set != NULL)
        return descr->d_getset->set(obj, value,
                                    descr->d_getset->closure);
    PyErr_Format(PyExc_AttributeError,
                 "attribute '%V' of '%.100s' objects is not writable",
                 descr_name((CDescrObject *)descr), "?",
                 PyDescr_TYPE(descr)->tp_name);
    return -1;
}


static PyObject *
calculate_qualname(CDescrObject *descr)
{
    PyObject *type_qualname, *res;
    _Py_IDENTIFIER(__qualname__);

    if (descr->d_name == NULL || !PyUnicode_Check(descr->d_name)) {
        PyErr_SetString(PyExc_TypeError,
                        "<descriptor>.__name__ is not a unicode object");
        return NULL;
    }

    type_qualname = _PyObject_GetAttrId((PyObject *)descr->d_type,
                                        &PyId___qualname__);
    if (type_qualname == NULL)
        return NULL;

    if (!PyUnicode_Check(type_qualname)) {
        PyErr_SetString(PyExc_TypeError, "<descriptor>.__objclass__."
                        "__qualname__ is not a unicode object");
        Py_XDECREF(type_qualname);
        return NULL;
    }

    res = PyUnicode_FromFormat("%S.%S", type_qualname, descr->d_name);
    Py_DECREF(type_qualname);
    return res;
}

static PyObject *
descr_get_qualname(CDescrObject *descr, void *Py_UNUSED(ignored))
{
    if (descr->d_qualname == NULL)
        descr->d_qualname = calculate_qualname(descr);
    Py_XINCREF(descr->d_qualname);
    return descr->d_qualname;
}

static PyObject *
descr_reduce(CDescrObject *descr)
{
    _Py_IDENTIFIER(getattr);
    //return Py_BuildValue("N(OO)", _PyEval_GetBuiltinId(&PyId_getattr),
    //                     PyDescr_TYPE(descr), PyDescr_NAME(descr));
    return NULL;
}

static PyMethodDef descr_methods[] = {
    {"__reduce__", (PyCFunction)descr_reduce, METH_NOARGS, NULL},
    {NULL, NULL}
};

static PyMemberDef descr_members[] = {
    {"__objclass__", T_OBJECT, offsetof(CDescrObject, d_type), READONLY},
    {"__name__", T_OBJECT, offsetof(CDescrObject, d_name), READONLY},
    {0}
};




static int
descr_traverse(PyObject *self, visitproc visit, void *arg)
{
    CDescrObject *descr = (CDescrObject *)self;
    Py_VISIT(descr->d_type);
    return 0;
}

static PyObject *
member_get_doc(CMemberDescrObject *descr, void *closure)
{
    if (descr->d_member.doc == NULL) {
        Py_RETURN_NONE;
    }
    return PyUnicode_FromString(descr->d_member.doc);
}

static PyGetSetDef member_getset[] = {
    {"__doc__", (getter)member_get_doc},
    {"__qualname__", (getter)descr_get_qualname},
    {0}
};


PyTypeObject CMemberDescr_Type = {
    PyVarObject_HEAD_INIT(&PyType_Type, 0)
    "member_descriptor",
    sizeof(CMemberDescrObject),
    0,
    (destructor)descr_dealloc,                  /* tp_dealloc */
    0,                                          /* tp_print */
    0,                                          /* tp_getattr */
    0,                                          /* tp_setattr */
    0,                                          /* tp_reserved */
    (reprfunc)member_repr,                      /* tp_repr */
    0,                                          /* tp_as_number */
    0,                                          /* tp_as_sequence */
    0,                                          /* tp_as_mapping */
    0,                                          /* tp_hash */
    0,                                          /* tp_call */
    0,                                          /* tp_str */
    PyObject_GenericGetAttr,                    /* tp_getattro */
    0,                                          /* tp_setattro */
    0,                                          /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HAVE_GC, /* tp_flags */
    0,                                          /* tp_doc */
    descr_traverse,                             /* tp_traverse */
    0,                                          /* tp_clear */
    0,                                          /* tp_richcompare */
    0,                                          /* tp_weaklistoffset */
    0,                                          /* tp_iter */
    0,                                          /* tp_iternext */
    descr_methods,                              /* tp_methods */
    descr_members,                              /* tp_members */
    member_getset,                              /* tp_getset */
    0,                                          /* tp_base */
    0,                                          /* tp_dict */
    (descrgetfunc)member_get,                   /* tp_descr_get */
    (descrsetfunc)member_set,                   /* tp_descr_set */
};





static CDescrObject *
descr_new(PyTypeObject *descrtype, PyTypeObject *type, const char *name)
{
    CDescrObject *descr;

    descr = (CDescrObject *)PyType_GenericAlloc(descrtype, 0);
    if (descr != NULL) {
        Py_XINCREF(type);
        descr->d_type = type;
        descr->d_name = PyUnicode_InternFromString(name);
        if (descr->d_name == NULL) {
            Py_DECREF(descr);
            descr = NULL;
        }
        else {
            descr->d_qualname = NULL;
        }
    }
    return descr;
}





PyObject *
CDescr_NewMember(PyTypeObject *type, const PyMemberDef *member)
{
    CMemberDescrObject *descr;

    descr = (CMemberDescrObject *)descr_new(&CMemberDescr_Type,
                                             type, member->name);
    if (descr != NULL)
        descr->d_member = *member;
    return (PyObject *)descr;
}



