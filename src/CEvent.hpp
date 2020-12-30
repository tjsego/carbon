/*
 * CEvent.hpp
 *
 *  Created on: Mar 30, 2020
 *      Author: andy
 */

#ifndef EXTERN_CARBON_SRC_CEVENT_HPP_
#define EXTERN_CARBON_SRC_CEVENT_HPP_

#include <carbon.h>


#include <vector>

typedef HRESULT (*timeevent_set_nexttime)(struct CEvent *);




struct CTimeEvent : CEvent {

    // time span between invocations of this event.
    double period;
    
    // time event should start firing, negative to start immediately
    double start_time;
    
    // time event should end, negative to last indefinitely
    double end_time;
    
    timeevent_propensityfunc propensity;
    
    // invokes the event target with the time

    // time_invoke should NOT call setNextTime, the
    // container will iterate over appropriate events to
    // determine which ones to update.
    timeevent_invoke te_invoke;
    
    // set the next event time on the event, makes decisions
    // based on event kind and if propensity and distribution
    // methods exist.
    timeevent_invoke te_setnexttime;
    
    // next time event should fire 
    double next_time;
    
};

struct CMulticastEvent : CEvent {

    /**
     * list of event callbacks.
     */
    std::vector<CEvent*> events;
};

struct CMulticastTimeEvent : CMulticastEvent {

};




CMulticastEvent *CMulticastEvent_New();




CAPI_FUNC(int) CTimeEvent_Init(CTimeEvent *event, PyObject *args, PyObject *kwargs);

CTimeEvent *CTimeEvent_NewPeriod(double period, PyObject *distribution, PyObject *target);

CTimeEvent *CTimeEvent_New();


HRESULT CMulticastTimeEvent_Invoke(CMulticastTimeEvent *event, double time);

HRESULT CMulticastTimeEvent_Add(CMulticastTimeEvent *me, CTimeEvent *te);


CMulticastTimeEvent *CMulticastTimeEvent_New();


/**
 * invoke method if target is a python function.
 */
HRESULT CTimeEvent_PyFunction_Invoke(CTimeEvent *event, double time);



/**
 * Invoke the individual time event.
 */
HRESULT CTimeEvent_Invoke(CTimeEvent *event, double time);

HRESULT _CEvent_Init(PyObject *m);

CAPI_DATA(PyTypeObject) CEvent_Type;
CAPI_DATA(PyTypeObject) CTimeEvent_Type;
CAPI_DATA(PyTypeObject) CMulticastEvent_Type;
CAPI_DATA(PyTypeObject) CMulticastTimeEvent_Type;



#endif /* EXTERN_CARBON_SRC_CEVENT_HPP_ */
