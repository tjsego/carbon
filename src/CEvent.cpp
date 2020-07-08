/*
 * CEvent.cpp
 *
 *  Created on: Mar 30, 2020
 *      Author: andy
 */

#include <CEvent.hpp>
#include <random>
#include <iostream>
#include <limits>

std::default_random_engine generator;


static HRESULT timeevent_func_invoke(CTimeEvent *event, double time);

static HRESULT timeevent_method_invoke(CTimeEvent *event, double time);

static HRESULT timeevent_exponential_setnexttime(CTimeEvent *event, double time);

static HRESULT timeevent_classmethod_invoke(CTimeEvent *event, double time) ;



CMulticastEvent* CMulticastEvent_New()
{
}



CTimeEvent* CTimeEvent_NewPeriod(double period, PyObject *distribution,
        PyObject *target)
{
    CTimeEvent *event = NULL;
}



PyTypeObject CEvent_Type = {
  CVarObject_HEAD_INIT(NULL, 0)
  "Event"                   , // .tp_name
  sizeof(CEvent)            , // .tp_basicsize
  0                         , // .tp_itemsize
  0                         , // .tp_dealloc
  0                         , // .tp_print
  0                         , // .tp_getattr
  0                         , // .tp_setattr
  0                         , // .tp_as_async
  0                         , // .tp_repr
  0                         , // .tp_as_number
  0                         , // .tp_as_sequence
  0                         , // .tp_as_mapping
  0                         , // .tp_hash
  0                         , // .tp_call
  0                         , // .tp_str
  0                         , // .tp_getattro
  0                         , // .tp_setattro
  0                         , // .tp_as_buffer
  Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE , // .tp_flags
  0                         , // .tp_doc
  0                         , // .tp_traverse
  0                         , // .tp_clear
  0                         , // .tp_richcompare
  0                         , // .tp_weaklistoffset
  0                         , // .tp_iter
  0                         , // .tp_iternext
  0                         , // .tp_methods
  0                         , // .tp_members
  0                         , // .tp_getset
  0                         , // .tp_base
  0                         , // .tp_dict
  0                         , // .tp_descr_get
  0                         , // .tp_descr_set
  0                         , // .tp_dictoffset
  0                         , // .tp_init
  0                         , // .tp_alloc
  PyType_GenericNew         , // .tp_new
  0                         , // .tp_free
  0                         , // .tp_is_gc
  0                         , // .tp_bases
  0                         , // .tp_mro
  0                         , // .tp_cache
  0                         , // .tp_subclasses
  0                         , // .tp_weaklist
  0                         , // .tp_del
  0                         , // .tp_version_tag
  0                         , // .tp_finalize
#ifdef COUNT_ALLOCS
  0                         , // .tp_allocs
  0                         , // .tp_frees
  0                         , // .tp_maxalloc
  0                         , // .tp_prev
  0                         , // .tp_next =
#endif
};


PyTypeObject CTimeEvent_Type = {
  CVarObject_HEAD_INIT(NULL, 0)
  "TimeEvent"                   , // .tp_name
  sizeof(CTimeEvent)            , // .tp_basicsize
  0                         , // .tp_itemsize
  0                         , // .tp_dealloc
  0                         , // .tp_print
  0                         , // .tp_getattr
  0                         , // .tp_setattr
  0                         , // .tp_as_async
  0                         , // .tp_repr
  0                         , // .tp_as_number
  0                         , // .tp_as_sequence
  0                         , // .tp_as_mapping
  0                         , // .tp_hash
  0                         , // .tp_call
  0                         , // .tp_str
  0                         , // .tp_getattro
  0                         , // .tp_setattro
  0                         , // .tp_as_buffer
  Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE , // .tp_flags
  0                         , // .tp_doc
  0                         , // .tp_traverse
  0                         , // .tp_clear
  0                         , // .tp_richcompare
  0                         , // .tp_weaklistoffset
  0                         , // .tp_iter
  0                         , // .tp_iternext
  0                         , // .tp_methods
  0                         , // .tp_members
  0                         , // .tp_getset
  &CEvent_Type              , // .tp_base
  0                         , // .tp_dict
  0                         , // .tp_descr_get
  0                         , // .tp_descr_set
  0                         , // .tp_dictoffset
  0                         , // .tp_init
  0                         , // .tp_alloc
  PyType_GenericNew         , // .tp_new
  0                         , // .tp_free
  0                         , // .tp_is_gc
  0                         , // .tp_bases
  0                         , // .tp_mro
  0                         , // .tp_cache
  0                         , // .tp_subclasses
  0                         , // .tp_weaklist
  0                         , // .tp_del
  0                         , // .tp_version_tag
  0                         , // .tp_finalize
#ifdef COUNT_ALLOCS
  0                         , // .tp_allocs
  0                         , // .tp_frees
  0                         , // .tp_maxalloc
  0                         , // .tp_prev
  0                         , // .tp_next =
#endif
};


PyTypeObject CMulticastEvent_Type = {
  CVarObject_HEAD_INIT(NULL, 0)
  "MulticastEvent"                   , // .tp_name
  sizeof(CMulticastEvent)            , // .tp_basicsize
  0                         , // .tp_itemsize
  0                         , // .tp_dealloc
  0                         , // .tp_print
  0                         , // .tp_getattr
  0                         , // .tp_setattr
  0                         , // .tp_as_async
  0                         , // .tp_repr
  0                         , // .tp_as_number
  0                         , // .tp_as_sequence
  0                         , // .tp_as_mapping
  0                         , // .tp_hash
  0                         , // .tp_call
  0                         , // .tp_str
  0                         , // .tp_getattro
  0                         , // .tp_setattro
  0                         , // .tp_as_buffer
  Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE , // .tp_flags
  0                         , // .tp_doc
  0                         , // .tp_traverse
  0                         , // .tp_clear
  0                         , // .tp_richcompare
  0                         , // .tp_weaklistoffset
  0                         , // .tp_iter
  0                         , // .tp_iternext
  0                         , // .tp_methods
  0                         , // .tp_members
  0                         , // .tp_getset
  &CEvent_Type              , // .tp_base
  0                         , // .tp_dict
  0                         , // .tp_descr_get
  0                         , // .tp_descr_set
  0                         , // .tp_dictoffset
  0                         , // .tp_init
  0                         , // .tp_alloc
  0                         , // .tp_new
  0                         , // .tp_free
  0                         , // .tp_is_gc
  0                         , // .tp_bases
  0                         , // .tp_mro
  0                         , // .tp_cache
  0                         , // .tp_subclasses
  0                         , // .tp_weaklist
  0                         , // .tp_del
  0                         , // .tp_version_tag
  0                         , // .tp_finalize
#ifdef COUNT_ALLOCS
  0                         , // .tp_allocs
  0                         , // .tp_frees
  0                         , // .tp_maxalloc
  0                         , // .tp_prev
  0                         , // .tp_next =
#endif
};



PyTypeObject CMulticastTimeEvent_Type = {
  CVarObject_HEAD_INIT(NULL, 0)
  "MulticastTimeEvent"      , // .tp_name
  sizeof(CMulticastTimeEvent)   , // .tp_basicsize
  0                         , // .tp_itemsize
  0                         , // .tp_dealloc
  0                         , // .tp_print
  0                         , // .tp_getattr
  0                         , // .tp_setattr
  0                         , // .tp_as_async
  0                         , // .tp_repr
  0                         , // .tp_as_number
  0                         , // .tp_as_sequence
  0                         , // .tp_as_mapping
  0                         , // .tp_hash
  0 , // .tp_call
  0                         , // .tp_str
  0                         , // .tp_getattro
  0                         , // .tp_setattro
  0                         , // .tp_as_buffer
  Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE , // .tp_flags
  0                         , // .tp_doc
  0                         , // .tp_traverse
  0                         , // .tp_clear
  0                         , // .tp_richcompare
  0                         , // .tp_weaklistoffset
  0                         , // .tp_iter
  0                         , // .tp_iternext
  0                         , // .tp_methods
  0                         , // .tp_members
  0                         , // .tp_getset
  &CMulticastEvent_Type     , // .tp_base
  0                         , // .tp_dict
  0                         , // .tp_descr_get
  0                         , // .tp_descr_set
  0                         , // .tp_dictoffset
  0                         , // .tp_init
  0                         , // .tp_alloc
  0                         , // .tp_new
  0                         , // .tp_free
  0                         , // .tp_is_gc
  0                         , // .tp_bases
  0                         , // .tp_mro
  0                         , // .tp_cache
  0                         , // .tp_subclasses
  0                         , // .tp_weaklist
  0                         , // .tp_del
  0                         , // .tp_version_tag
  0                         , // .tp_finalize
#ifdef COUNT_ALLOCS
  0                         , // .tp_allocs
  0                         , // .tp_frees
  0                         , // .tp_maxalloc
  0                         , // .tp_prev
  0                         , // .tp_next =
#endif
};




HRESULT _CEvent_Init(PyObject *m)
{

    if (PyType_Ready((PyTypeObject*)&CEvent_Type) < 0)
        return E_FAIL;

    Py_INCREF(&CEvent_Type);
    if (PyModule_AddObject(m, "Event", (PyObject*)&CEvent_Type) < 0) {
        Py_DECREF(&CEvent_Type);
        return E_FAIL;
    }

    if (PyType_Ready((PyTypeObject*)&CTimeEvent_Type) < 0)
        return E_FAIL;

    Py_INCREF(&CTimeEvent_Type);
    if (PyModule_AddObject(m, "TimeEvent", (PyObject*)&CTimeEvent_Type) < 0) {
        Py_DECREF(&CTimeEvent_Type);
        return E_FAIL;
    }

    if (PyType_Ready((PyTypeObject*)&CMulticastEvent_Type) < 0)
        return E_FAIL;

    Py_INCREF(&CMulticastEvent_Type);
    if (PyModule_AddObject(m, "MulticastEvent", (PyObject*)&CMulticastEvent_Type) < 0) {
        Py_DECREF(&CMulticastEvent_Type);
        return E_FAIL;
    }

    if (PyType_Ready((PyTypeObject*)&CMulticastTimeEvent_Type) < 0)
        return E_FAIL;

    Py_INCREF(&CMulticastTimeEvent_Type);
    if (PyModule_AddObject(m, "MulticastTimeEvent", (PyObject*)&CMulticastTimeEvent_Type) < 0) {
        Py_DECREF(&CMulticastTimeEvent_Type);
        return E_FAIL;
    }

    return S_OK;
}

HRESULT CMulticastTimeEvent_Invoke(CMulticastTimeEvent *event, double time)
{
    for (CEvent *x : event->events) {
        
        CTimeEvent *e = (CTimeEvent*)x;

        if((e->flags & EVENT_ACTIVE) &&
            e->next_time <= time     &&
            e->start_time <= time    &&
            e->end_time > time       &&
            e->te_invoke) {
            e->te_invoke(e, time);
            e->te_setnexttime(e, e->next_time);
            e->last_fired = time;
        }
    }

    return S_OK;
}

HRESULT CTimeEvent_Invoke(CTimeEvent *event, double time)
{
    //return event->time_invoke(event, time);
}

HRESULT CTimeEvent_PyFunction_Invoke(CTimeEvent *event, double time) {
    if(event->next_time < time) {
        return S_OK;
    }

    PyObject *t = PyFloat_FromDouble(time);

    PyObject *args = PyTuple_Pack(1, t);

    // time expired, so invoke the event.
    PyObject *result = PyObject_Call((PyObject*)event->method, args, NULL);

    return S_OK;
}


HRESULT CMulticastTimeEvent_Add(CMulticastTimeEvent *me, CTimeEvent *te)
{
    me->events.push_back(te);
    Py_INCREF(te);
    return S_OK;
}

CMulticastTimeEvent *CMulticastTimeEvent_New() {
    CMulticastTimeEvent *result = PyObject_New(CMulticastTimeEvent, &CMulticastTimeEvent_Type);

    std::vector<CEvent*> *events = &result->events;

    // placement new, python allocated the memory.
    events = new(events) std::vector<CEvent*>();

    return result;
}

CTimeEvent* CTimeEvent_New()
{
    return PyObject_New(CTimeEvent, &CTimeEvent_Type);
}

static int setdbl(double *p, PyObject *kwargs, const char* name, double defval = -1) {
    if(CDict_ContainsItemString(kwargs, name) == 1) {
        double val = PyFloat_AsDouble(PyDict_GetItemString(kwargs, name));
        if(val == -1.0) {
            if(PyErr_Occurred()) {
                return -1;
            }
        }
        *p = val;
    }
    else {
        *p = defval;
    }
    return 0;
}

int CTimeEvent_Init(CTimeEvent *event, PyObject *args, PyObject *kwargs) {
    
    std::cout << "obj: " << PyUnicode_AsUTF8AndSize(PyObject_Str(event), NULL) << std::endl;
    std::cout << "args: " << PyUnicode_AsUTF8AndSize(PyObject_Str(args), NULL) << std::endl;
    std::cout << "kwargs: " << PyUnicode_AsUTF8AndSize(PyObject_Str(kwargs), NULL) << std::endl;

    std::cout << MX_FUNCTION << std::endl;

    if(!kwargs) {
        PyErr_SetString(PyExc_TypeError, "called without any keyword arguments");
        return NULL;
    }
    
    event->last_fired = 0;
    
    PyObject *method = NULL;
    
    if(args && PyTuple_GET_SIZE(args) > 0) {
        method = PyTuple_GET_ITEM(args, 0);
    }
    
    if(method == NULL) {
        method = PyDict_GetItemString(kwargs, "method");
    }
    
    // check if method is valid
    if(method) {
        if (PyObject_IsInstance(method, (PyObject *)&PyMethodDescr_Type)) {

            PyMethodDescrObject *methodDesc = (PyMethodDescrObject*)method;
            std::cout << "method descriptor: " << methodDesc->d_method->ml_name << std::endl;
            event->method = method;
            event->flags |= EVENT_METHODDESCR;
        }

        else if(PyFunction_Check(method)) {
            PyFunctionObject *func = (PyFunctionObject*)method;
            const char* name = PyUnicode_AsUTF8AndSize(func->func_name, NULL);
            std::cout << "python function object: " << name << std::endl;
            event->method = method;
            event->te_invoke = timeevent_func_invoke;
            event->flags |= EVENT_PYFUNC;
        }
        else if(PyType_Check(method) && PyCallable_Check(method)) {
            const char* name = PyUnicode_AsUTF8AndSize(PyObject_Str(method), NULL);
            std::cout << "python callable object: " << name << std::endl;
            event->method = method;
            event->te_invoke = timeevent_classmethod_invoke;
            event->flags |= EVENT_PYFUNC;
            event->flags |= EVENT_CLASS;
        }
    }

    if(setdbl(&event->period, kwargs, "period") != 0) {
        return -1;
    }

    if(setdbl(&event->start_time, kwargs, "start") != 0) {
        return -1;
    }

    if(setdbl(&event->end_time, kwargs, "end", std::numeric_limits<double>::max()) != 0) {
        return -1;
    }

    PyObject *dist = PyDict_GetItemString(kwargs, "distribution");
    if(dist && PyUnicode_CompareWithASCIIString(dist, "exponential") == 0) {
        event->flags |= EVENT_EXPONENTIAL;
        event->te_setnexttime = timeevent_exponential_setnexttime;
    }
    
    if((event->flags & EVENT_METHODDESCR) &&
        event->target &&
        event->method &&
        event->te_invoke &&
        event->te_setnexttime) {
        event->flags |= EVENT_ACTIVE;
    }
    
    if((event->flags & EVENT_PYFUNC) &&
        event->method &&
        event->te_invoke &&
        event->te_setnexttime) {
        event->flags |= EVENT_ACTIVE;
    }
    
    // set next time event should fire. Derived types
    // can re-set the next fire time. 
    if(event->te_setnexttime) {
        event->te_setnexttime(event, 0.);
    }

    return 0;
}

HRESULT timeevent_exponential_setnexttime(CTimeEvent *event, double time) {
    std::exponential_distribution<> d(1/event->period);
    event->next_time = time + d(CRandom);
    return S_OK;
}


// default invoke for stand alone pyfunc
HRESULT timeevent_func_invoke(CTimeEvent *event, double time) {
    if(event->next_time > time) {
        return S_OK;
    }
    
    PyObject *args = PyTuple_New(1);
    
    PyObject *t = PyFloat_FromDouble(time);
    PyTuple_SET_ITEM(args, 0, t);
    
    //std::cout << MX_FUNCTION << std::endl;
    //std::cout << "args: " << PyUnicode_AsUTF8AndSize(PyObject_Str(args), NULL) << std::endl;
    //std::cout << "method: " << PyUnicode_AsUTF8AndSize(PyObject_Str(event->method), NULL) << std::endl;
    
    // time expired, so invoke the event.
    PyObject *result = PyObject_CallObject((PyObject*)event->method, args);
    
    return S_OK;
}


// call class constructor
HRESULT timeevent_classmethod_invoke(CTimeEvent *event, double time) {
    if(event->next_time > time) {
        return S_OK;
    }
    

    
    //std::cout << MX_FUNCTION << std::endl;
    //std::cout << "args: " << PyUnicode_AsUTF8AndSize(PyObject_Str(args), NULL) << std::endl;
    //std::cout << "method: " << PyUnicode_AsUTF8AndSize(PyObject_Str(event->method), NULL) << std::endl;
    
    // time expired, so invoke the event.
    PyObject *result = PyObject_CallObject((PyObject*)event->method, NULL);
    
    return S_OK;
}

