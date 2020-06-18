/*
 * c_listof.cpp
 *
 *  Created on: Jun 18, 2020
 *      Author: andy
 */

#include <c_list.hpp>

CList_t * CList_create(unsigned int initSize)
{
    return 0;
}

CList_t * CList_createWithVersion(unsigned int level,
        unsigned int version)
{
    return 0;
}

void CList_free(CList_t *lo)
{
}

CList_t * CList_clone(const CList_t *lo)
{
    return 0;
}

int CList_append(CList_t *lo, const SBase_t *item)
{
    return 0;
}

int CList_appendAndOwn(CList_t *lo, SBase_t *disownedItem)
{
    return 0;
}

int CList_appendFrom(CList_t *lo, CList_t *list)
{
    return 0;
}

int CList_insert(CList_t *lo, int location, const SBase_t *item)
{
    return 0;
}

int CList_insertAndOwn(CList_t *lo, int location, SBase_t *disownedItem)
{
    return 0;
}

SBase_t * CList_get(CList_t *lo, unsigned int n)
{
    return 0;
}

void CList_clear(CList_t *lo, int doDelete)
{
}

SBase_t * CList_remove(CList_t *lo, unsigned int n)
{
    return 0;
}

unsigned int CList_size(const CList_t *lo)
{
    return 0;
}

int CList_getItemTypeCode(const CList_t *lo)
{
    return 0;
}
