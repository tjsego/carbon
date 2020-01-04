/*
 * ca_object.h
 *
 *  Created on: Jun 30, 2015
 *      Author: andy
 */

#ifndef _INCLUDED_CA_OBJECT_H_
#define _INCLUDED_CA_OBJECT_H_

#include <c_port.h>



/**
 * Basic opaque Mechanica object type.
 */
MxAPI_STRUCT(CObject);




//#define Mx_REFCNT(ob)           (((CObject*)(ob))->refcount)
//#define Mx_TYPE(ob)             (((CObject*)(ob))->type)
//#define Mx_SIZE(ob)             (((MxVarObject*)(ob))->ob_size)
//
//#define Mx_INCREF(o) { Mx_IncRef((CObject*)(o)); }
//
//#define Mx_DECREF(o) { Mx_DecRef((CObject*)(o)); }

/* Safely decref `op` and set `op` to NULL, especially useful in tp_clear
 * and tp_dealloc implementations.
 *
 * Note that "the obvious" code can be deadly:
 *
 *     Mx_XDECREF(op);
 *     op = NULL;
 *
 * Typically, `op` is something like self->containee, and `self` is done
 * using its `containee` member.  In the code sequence above, suppose
 * `containee` is non-NULL with a refcount of 1.  Its refcount falls to
 * 0 on the first line, which can trigger an arbitrary amount of code,
 * possibly including finalizers (like __del__ methods or weakref callbacks)
 * coded in Mechanica, which in turn can release the GIL and allow other threads
 * to run, etc.  Such code may even invoke methods of `self` again, or cause
 * cyclic gc to trigger, but-- oops! --self->containee still points to the
 * object being torn down, and it may be in an insane state while being torn
 * down.  This has in fact been a rich historic source of miserable (rare &
 * hard-to-diagnose) segfaulting (and other) bugs.
 *
 * The safe way is:
 *
 *      Mx_CLEAR(op);
 *
 * That arranges to set `op` to NULL _before_ decref'ing, so that any code
 * triggered as a side-effect of `op` getting torn down no longer believes
 * `op` points to a valid object.
 *
 * There are cases where it's safe to use the naive code, but they're brittle.
 * For example, if `op` points to a Mechanica integer, you know that destroying
 * one of those can't cause problems -- but in part that relies on that
 * Mechanica integers aren't currently weakly referencable.  Best practice is
 * to use Mx_CLEAR() even if you can't think of a reason for why you need to.
 */
#define Mx_CLEAR(op)                            \
    do {                                        \
        CObject *_py_tmp = (CObject *)(op);   \
        if (_py_tmp != NULL) {                  \
            (op) = NULL;                        \
            Mx_DECREF(_py_tmp);                 \
        }                                       \
    } while (0)

/* Macros to use in case the object pointer may be NULL: */
#define Mx_XINCREF(op)                                \
    do {                                              \
        CObject *_py_xincref_tmp = (CObject *)(op); \
        if (_py_xincref_tmp != NULL)                  \
            Mx_INCREF(_py_xincref_tmp);               \
    } while (0)

#define Mx_XDECREF(op)                                \
    do {                                              \
        CObject *_py_xdecref_tmp = (CObject *)(op); \
        if (_py_xdecref_tmp != NULL)                  \
            Mx_DECREF(_py_xdecref_tmp);               \
    } while (0)

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * Print an object, o, on file, fp.  Returns -1 on
 * error.  The flags argument is used to enable certain printing
 * options. The only option currently supported is Mx_Print_RAW.
 */
MxAPI_FUNC(int) CObject_Print(CObject *o, FILE *fp, int flags);

/**
 * Returns 1 if o has the attribute attr_name, and 0 otherwise.
 * This is equivalent to the Mechanica expression:
 * hasattr(o,attr_name).
 *
 * This function always succeeds.
 */
MxAPI_FUNC(int) CObject_HasAttrString(CObject *o, const char *attr_name);

/**
 * Retrieve an attributed named attr_name form object o.
 * Returns the attribute value on success, or NULL on failure.
 * This is the equivalent of the Mechanica expression: o.attr_name.
 */
MxAPI_FUNC(CObject)* CObject_GetAttrString(CObject *o,
		const char *attr_name);


/**
 * Returns 1 if o has the attribute attr_name, and 0 otherwise.
 * This is equivalent to the Mechanica expression:
 * hasattr(o,attr_name).
 * This function always succeeds.
 */
MxAPI_FUNC(int) CObject_HasAttr(CObject *o, CObject *attr_name);

/**
 * Retrieve an attributed named attr_name form object o.
 * Returns the attribute value on success, or NULL on failure.
 * This is the equivalent of the Mechanica expression: o.attr_name.
 */
MxAPI_FUNC(CObject)* CObject_GetAttr(CObject *o, CObject *attr_name);

/**
 * Set the value of the attribute named attr_name, for object o,
 * to the value, v. Returns -1 on failure.  This is
 * the equivalent of the Mechanica statement: o.attr_name=v.
 */
MxAPI_FUNC(int) CObject_SetAttrString(CObject *o, const char *attr_name,
		CObject *v);

/**
 * Set the value of the attribute named attr_name, for object o,
 * to the value, v. Returns -1 on failure.  This is
 * the equivalent of the Mechanica statement: o.attr_name=v.
 */
MxAPI_FUNC(int) CObject_SetAttr(CObject *o, CObject *attr_name, CObject *v);

/**
 * Delete attribute named attr_name, for object o. Returns
 * -1 on failure.  This is the equivalent of the Mechanica
 * statement: del o.attr_name.
 */
MxAPI_FUNC(int) CObject_DelAttrString(CObject *o, const char *attr_name);

/**
 * Delete attribute named attr_name, for object o. Returns -1
 * on failure.  This is the equivalent of the Mechanica
 * statement: del o.attr_name.
 */
MxAPI_FUNC(int) CObject_DelAttr(CObject *o, CObject *attr_name);

/**
 * Compute the string representation of object, o.  Returns the
 * string representation on success, NULL on failure.  This is
 * the equivalent of the Mechanica expression: repr(o).
 *
 * Mxlled by the repr() built-in function.
 */
MxAPI_FUNC(CObject) *CObject_Repr(CObject *o);

/**
 * Compute the string representation of object, o.  Returns the
 * string representation on success, NULL on failure.  This is
 * the equivalent of the Mechanica expression: str(o).)
 *
 * Mxlled by the str() and print() built-in functions.
 */
MxAPI_FUNC(CObject) *CObject_Str(CObject *o);

/**
 * Mxll the method named m of object o with a variable number of
 * C arguments. Returns the result of the call
 * on success, or NULL on failure.  This is the equivalent of
 * the Mechanica expression: o.method(args).
 */
MxAPI_FUNC(CObject *) CObject_CallMethod(CObject *o,
		const char *method,
		const char *format, ...);

/**
 * Mxll the method named m of object o with a variable number of
 * C arguments.  The C arguments are provided as CObject *
 * values, terminated by NULL.  Returns the result of the call
 * on success, or NULL on failure.  This is the equivalent of
 * the Mechanica expression: o.method(args).
 */
MxAPI_FUNC(CObject *) CObject_CallMethodObjArgs(CObject *o,
		CObject *method, ...);

/**
 *  Compute and return the hash, hash_value, of an object, o.  On
 failure, return -1.  This is the equivalent of the Mechanica
 expression: hash(o).
 */

MxAPI_FUNC(long) CObject_Hash(CObject *o);

/**
 *  Returns 1 if the object, o, is considered to be true, 0 if o is
 considered to be false and -1 on failure. This is equivalent to the
 Mechanica expression: not not o
 */

MxAPI_FUNC(int) CObject_IsTrue(CObject *o);

/**
 * Returns 0 if the object, o, is considered to be true, 1 if o is
 considered to be false and -1 on failure. This is equivalent to the
 Mechanica expression: not o
 */
MxAPI_FUNC(int) CObject_Not(CObject *o);

/**
 * On success, returns a type object corresponding to the object
 * type of object o. On failure, returns NULL.  This is
 * equivalent to the Mechanica expression: type(o).
 */
MxAPI_DATA(struct CType*) CObject_Type;

/**
 * Return the size of object o.  If the object, o, provides
 * both sequence and mapping protocols, the sequence size is
 * returned. On error, -1 is returned.  This is the equivalent
 * to the Mechanica expression: len(o).
 */
MxAPI_FUNC(Mx_ssize_t) CObject_Size(CObject *o);

/**
 * Guess the size of object o using len(o) or o.__length_hint__().
 * If neither of those return a non-negative value, then return the
 * default value.  If one of the calls fails, this function returns -1.
 */
MxAPI_FUNC(Mx_ssize_t) CObject_Length(CObject *o);

/**
 * Return element of o corresponding to the object, key, or NULL
 * on failure. This is the equivalent of the Mechanica expression:
 * o[key].
 */
MxAPI_FUNC(CObject *) CObject_GetItem(CObject *o, CObject *key);

/**
 * Map the object, key, to the value, v.  Returns
 * -1 on failure.  This is the equivalent of the Mechanica
 * statement: o[key]=v.
 */
MxAPI_FUNC(int) CObject_SetItem(CObject *o, CObject *key, CObject *v);

/**
 * Remove the mapping for object, key, from the object *o.
 Returns -1 on failure.  This is equivalent to
 the Mechanica statement: del o[key].
 */

MxAPI_FUNC(int) CObject_DelItemString(CObject *o, const char *key);

/**
 * Delete the mapping for key from *o.  Returns -1 on failure.
 * This is the equivalent of the Mechanica statement: del o[key].
 */
MxAPI_FUNC(int) CObject_DelItem(CObject *o, CObject *key);


MxAPI_FUNC(int) CObject_IsInstance(CObject *object, CObject *typeorclass);
/* isinstance(object, typeorclass) */



MxAPI_FUNC(void) Mx_Dealloc(CObject *);

MxAPI_FUNC(uint32_t) Mx_IncRef(CObject *o);

MxAPI_FUNC(uint32_t) Mx_DecRef(CObject *o);

/**
 * Become
 * ======
 *
 *
 * The Miracle of become:
 *
 * From https://gbracha.blogspot.com/2009/07/miracle-of-become.html
 *
 * Mechanica objects support a type-save version of 'become', a object of one
 * type can 'become' another type provided the types are consistent, that is,
 * is a subtype, or structurally compatible (see structural vs. nomanative).
 *
 * One of Smalltalk’s most unique and powerful features is also one of the least known
 * outside the Smalltalk community. It’s a little method called become: .
 *
 * What become: does is swap the identities of its receiver and its argument.
 * That is, after
 *
 * a become: b
 *
 * all references to the object denoted by a before the call point refer to the
 * object that was denoted by b, and vice versa. Take a minute to internalize this;
 * you might misunderstand it as something trivial. This is not about swapping
 * two variables - it is literally about one object becoming another. I am not
 * aware of any other language that has this feature. It is a feature of
 * enormous power - and danger.
 *
 * Consider the task of extending your language to support persistent objects.
 * Say you want to load an object from disk, but don’t want to load all the objects
 * it refers to transitively (otherwise, it’s just plain object deserialization).
 * So you load the object itself, but instead of loading its direct references,
 * you replace them with husk objects.
 *
 * The husks stand in for the real data on secondary storage. That data is loaded
 * lazily. When you actually need to invoke a method on a husk, its doesNotUnderstand:
 * method loads the corresponding data object from disk (but again, not transitively).
 * Then, it does a become:, replacing all references to the husk with references to
 * the newly loaded object, and retries the call.
 *
 * Some persistence engines have done this sort of thing for decades - but they
 * usually relied on low level access to the representation. Become: lets you do
 * this at the source code level. Now go do this in Java. Or even in another dynamic
 * language. You will recognize that you can do a general form of futures this way,
 * and hence laziness. All without privileged access to the workings of the
 * implementation. It’s also useful for schema evolution - when you add an instance
 * variable to a class, for example. You can “reshape” all the instances as needed.
 *
 * Of course, you shouldn’t use become: casually. It comes at a cost, which may
 * be prohibitive in many implementations. In early Smalltalks, become: was cheap,
 * because all objects were referenced indirectly by means of an object table. In the
 * absence of an object table, become: traverses the heap in a manner similar to a
 * garbage collector. The more memory you have, the more expensive become: becomes.
 *
 * Having an object table takes up storage and slows down access; but it does buy
 * you a great deal of flexibility. Hardware support could ease the performance
 * penalty. The advantage is that many hard problems become quite tractable if you
 * are willing to pay the cost of indirection via an object table up front. Remember:
 * every problem in computer science can be solved with extra levels of indirection.
 *
 * Alex Warth has some very interesting work that fits in this category, for example.
 * Become: has several variations - one way become: changes the identity of an
 * object A to that of another object B, so that references to A now point at B;
 * references to B remain unchanged. It is often useful to do become: in bulk -
 * transmuting the identities of all objects in an array (either unidirectionally
 * or bidirectionally). A group become: which does it magic atomically is great
 * for implementing reflective updates to a system, for example. You can change a
 * whole set of classes and their instances in one go.
 *
 * You can even conceive of type safe become: . Two way become: is only type safe
 * if the type of A is identical to that of B, but one way become: only requires
 * that the new object be a subtype of the old one.
 *
 * It may be time to reconsider whether having an object table is actually a good thing.
 *
 * Posted by Gilad Bracha at 7:34 PM
 * Labels: Reflection
 */

MxAPI_FUNC(HRESULT) CObject_ChangeType(CObject *obj, const CType *type);




#ifdef __cplusplus
}
#endif

#endif /* _INCLUDED_CA_OBJECT_H_ */
