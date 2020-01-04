/*
 * CType.cpp
 *
 *  Created on: Feb 1, 2017
 *      Author: andy
 */

#include <carbon.h>



static_assert(sizeof(CType) == sizeof(PyTypeObject), "CType must be same as PyTypeObject");
static_assert(offsetof(CType, tp_finalize) == offsetof(PyTypeObject, tp_finalize), "CType offset different");


//static CType typeType{"CType", CObject_Type};

//CType *CType_Type = &typeType;

void CType_init(PyObject *m) {

}

//CType::CType(const char* name, CType* base) : CObject{CType_Type}
//{
//    tp_name = name;
 //   tp_base = base;
//}

/**
 * T1 : CObject
 * T2 : T1
 * T3 : T2
 * T4 : T1
 *
 *
 
 */

MxAPI_FUNC(int) CType_IsSubtype(CType *a, CType *b) {
    do {
        if (a == b)
            return 1;
        a = a->tp_base;
    } while (a != NULL && a != CObject_Type);
    return b == CObject_Type;
}
