/*
 * c_event.h
 *
 *  Created on: Mar 30, 2020
 *      Author: andy
 */

#ifndef EXTERN_CARBON_INCLUDE_C_EVENT_H_
#define EXTERN_CARBON_INCLUDE_C_EVENT_H_

#include <c_port.h>



typedef double (*timeevent_propensityfunc)(PyObject *);

typedef HRESULT (*event_invoke)(PyObject *);

typedef HRESULT (*timeevent_invoke)(struct CTimeEvent *, double time);


enum CEvent_Kind {
    CEvent_Interval,
    TimeEvent_Propensity,
    TimeEvent_Exponential
};

enum CEvent_Flags {
    EVENT_ACTIVE                = 1 << 0,
    EVENT_EXPONENTIAL           = 1 << 1,
    EVENT_METHODDESCR           = 1 << 2,
    EVENT_PYFUNC                = 1 << 3,
    EVENT_CLASS                 = 1 << 4 , // method is a class constructor
    // re-scale the time interval to the number of objects that a multi-cast
    // event acts on. If there are many objects, time period is period / (instance count)
    EVENT_PERIOD_RESCALE = 1 << 5
};

/**
 * Expose the CEvent struct, used heavily internally
 */
typedef struct CEvent : PyObject {
    CEvent_Kind kind;
    uint32_t flags;
    
    double last_fired;
    event_invoke invoke;
    
    /**
     * type or object instance, may be null.
     */
    PyObject *target;
    
    /**
     * pointer to method or function declaration.
     */
    PyObject *method;
    
    /**
     * pointer to a method or function declaration that determines should this
     * event fire on the object. Could also be a string, or other object.
     */
    PyObject *predicate;
} CEvent;




CAPI_STRUCT(CMulticastEvent);


/**
 * The Carbon Event
 */

CEvent *CEvent_New();

HRESULT CEvent_Invoke(PyObject *args, PyObject *kw_args);

HRESULT CEvent_AddDelegate(PyObject *delegate);

HRESULT CEvent_RemoveDelegate(PyObject *delegate);


/**
 * timestep the delegate
 */
HRESULT CEvent_Timestep(CEvent *event, double timestep);





#endif /* EXTERN_CARBON_INCLUDE_C_EVENT_H_ */
