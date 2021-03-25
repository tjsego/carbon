
/*
 * c_util.cpp
 *
 *  Created on: Jun 30, 2020
 *      Author: andy
 */

#include <carbon.h>
#include <c_util.h>
#include <vector>
#include <iostream>

#include <CConvert.hpp>

#if __APPLE__
#include <sys/types.h>
#include <sys/sysctl.h>
#endif


#include <signal.h>



CRandomType CRandom;



int CDict_ContainsItemString(PyObject *p, const char *key)
{
    PyObject *kv;
    int rv;
    kv = PyUnicode_FromString(key);
    if (kv == NULL) {
        PyErr_Clear();
        return -1;
    }
    rv = PyDict_Contains(p, kv);
    Py_DECREF(kv);
    return rv;
}

/*

// Function to generate N prime numbers using
// Sieve of Eratosthenes
void SieveOfEratosthenes(vector<int> &primes)
{
    // Create a boolean array "IsPrime[0..MAX_SIZE]" and
    // initialize all entries it as true. A value in
    // IsPrime[i] will finally be false if i is
    // Not a IsPrime, else true.
    bool IsPrime[MAX_SIZE];
    memset(IsPrime, true, sizeof(IsPrime));

    for (int p = 2; p * p < MAX_SIZE; p++)
    {
        // If IsPrime[p] is not changed, then it is a prime
        if (IsPrime[p] == true)
        {
            // Update all multiples of p greater than or
            // equal to the square of it
            // numbers which are multiple of p and are
            // less than p^2 are already been marked.
            for (int i = p * p; i <  MAX_SIZE; i += p)
                IsPrime[i] = false;
        }
    }

    // Store all prime numbers
    for (int p = 2; p < MAX_SIZE; p++)
       if (IsPrime[p])
            primes.push_back(p);

}
*/

// Function that returns true if n
// is prime else returns false
static bool isPrime(uint64_t n)
{
    // Corner cases
    if (n <= 1)  return false;
    if (n <= 3)  return true;

    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n%2 == 0 || n%3 == 0) return false;

    for (uint64_t i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;

    return true;
}

// Function to return the smallest
// prime number greater than N

uint64_t CMath_NextPrime(uint64_t N)
{

    // Base case
    if (N <= 1)
        return 2;

    uint64_t prime = N;
    bool found = false;

    // Loop continuously until isPrime returns
    // true for a number greater than n
    while (!found) {
        prime++;

        if (isPrime(prime))
            found = true;
    }

    return prime;
}

HRESULT CMath_FindPrimes(uint64_t start_prime, int n, uint64_t *result)
{
    for(int i = 0; i < n; ++i) {
        result[i] = CMath_NextPrime(start_prime);
        start_prime = result[i];
    }
    return 0;
}


CAPI_FUNC(PyObject*) CIPython_Get() {
    PyObject* moduleString = PyUnicode_FromString((char*)"IPython.core.getipython");
    
    if(!moduleString) {
        return NULL;
    }
    
    #if defined(__has_feature)
    #  if __has_feature(thread_sanitizer)
        std::cout << "thread sanitizer, returning NULL" << std::endl;
        return NULL;
    #  endif
    #endif
    
    PyObject* module = PyImport_Import(moduleString);
    if(!module) {
        return NULL;
    }
    
    // Then getting a reference to your function :

    PyObject* get_ipython = PyObject_GetAttrString(module,(char*)"get_ipython");
    
    if(!get_ipython) {
        return NULL;
    }

    PyObject* result = PyObject_CallObject(get_ipython, NULL);
    
    Py_DECREF(moduleString);
    Py_DECREF(module);
    Py_DECREF(get_ipython);
    
    return result;
}
    
// Read the maximum argument size for processes
static int psutil_sysctl_argmax() {
    int argmax;
    int mib[2];
    size_t size = sizeof(argmax);
    
    mib[0] = CTL_KERN;
    mib[1] = KERN_ARGMAX;
    
    if (sysctl(mib, 2, &argmax, &size, NULL, 0) == 0)
        return argmax;
    
    c_error(E_FAIL, "sysctl(KERN_ARGMAX)");
    return 0;
}
    
    /*
     * Check if PID exists. Return values:
     * 1: exists
     * 0: does not exist
     * -1: error (Python exception is set)
     */
    int
    psutil_pid_exists(pid_t pid) {
        int ret;
        
        // No negative PID exists, plus -1 is an alias for sending signal
        // too all processes except system ones. Not what we want.
        if (pid < 0)
            return 0;
        
        // As per "man 2 kill" PID 0 is an alias for sending the signal to
        // every process in the process group of the calling process.
        // Not what we want. Some platforms have PID 0, some do not.
        // We decide that at runtime.
        if (pid == 0) {
#if defined(PSUTIL_LINUX) || defined(PSUTIL_FREEBSD)
            return 0;
#else
            return 1;
#endif
        }
        
        ret = kill(pid , 0);
        if (ret == 0)
            return 1;
        else {
            if (errno == ESRCH) {
                // ESRCH == No such process
                return 0;
            }
            else if (errno == EPERM) {
                // EPERM clearly indicates there's a process to deny
                // access to.
                return 1;
            }
            else {
                // According to "man 2 kill" possible error values are
                // (EINVAL, EPERM, ESRCH) therefore we should never get
                // here. If we do let's be explicit in considering this
                // an error.
                PyErr_SetFromErrno(PyExc_OSError);
                return -1;
            }
        }
    }
    
// Read process argument space.
static int
psutil_sysctl_procargs(pid_t pid, char *procargs, size_t argmax) {
    int mib[3];
    
    mib[0] = CTL_KERN;
    mib[1] = KERN_PROCARGS2;
    mib[2] = pid;
    
    if (sysctl(mib, 3, procargs, &argmax, NULL, 0) < 0) {
        if (psutil_pid_exists(pid) == 0) {
            c_error(E_FAIL, "psutil_pid_exists -> 0");
            return 1;
        }
        // In case of zombie process we'll get EINVAL. We translate it
        // to NSP and _psosx.py will translate it to ZP.
        if (errno == EINVAL) {
            c_error(E_FAIL, "sysctl(KERN_PROCARGS2) -> EINVAL translated to NSP");
            c_error(E_FAIL, "sysctl(KERN_PROCARGS2) -> EINVAL");
            return 1;
        }
        // There's nothing we can do other than raising AD.
        if (errno == EIO) {
            c_error(E_FAIL, "sysctl(KERN_PROCARGS2) -> EIO translated to AD");
            c_error(E_FAIL, "sysctl(KERN_PROCARGS2) -> EIO");
            return 1;
        }
        c_error(E_FAIL, "sysctl(KERN_PROCARGS2)");
        return 1;
    }
    return 0;
}
    
    
// return process args as a python list
PyObject *psutil_get_cmdline_osx(pid_t pid) {
    int nargs;
    size_t len;
    char *procargs = NULL;
    char *arg_ptr;
    char *arg_end;
    char *curr_arg;
    size_t argmax;
    
    PyObject *py_arg = NULL;
    PyObject *py_retlist = NULL;
    
    // special case for PID 0 (kernel_task) where cmdline cannot be fetched
    if (pid == 0)
        return Py_BuildValue("[]");
    
    // read argmax and allocate memory for argument space.
    argmax = psutil_sysctl_argmax();
    if (! argmax)
        goto error;
    
    procargs = (char *)malloc(argmax);
    if (NULL == procargs) {
        PyErr_NoMemory();
        goto error;
    }
    
    if (psutil_sysctl_procargs(pid, procargs, argmax) != 0)
        goto error;
    
    arg_end = &procargs[argmax];
    // copy the number of arguments to nargs
    memcpy(&nargs, procargs, sizeof(nargs));
    
    arg_ptr = procargs + sizeof(nargs);
    len = strlen(arg_ptr);
    arg_ptr += len + 1;
    
    if (arg_ptr == arg_end) {
        free(procargs);
        return Py_BuildValue("[]");
    }
    
    // skip ahead to the first argument
    for (; arg_ptr < arg_end; arg_ptr++) {
        if (*arg_ptr != '\0')
            break;
    }
    
    // iterate through arguments
    curr_arg = arg_ptr;
    py_retlist = Py_BuildValue("[]");
    if (!py_retlist)
        goto error;
    while (arg_ptr < arg_end && nargs > 0) {
        if (*arg_ptr++ == '\0') {
            py_arg = PyUnicode_DecodeFSDefault(curr_arg);
            if (! py_arg)
                goto error;
            if (PyList_Append(py_retlist, py_arg))
                goto error;
            Py_DECREF(py_arg);
            // iterate to next arg and decrement # of args
            curr_arg = arg_ptr;
            nargs--;
        }
    }
    
    free(procargs);
    return py_retlist;
    
error:
    Py_XDECREF(py_arg);
    Py_XDECREF(py_retlist);
    if (procargs != NULL)
        free(procargs);
    return NULL;
}
    

PyObject *C_CmdLineArgsForPid(PyObject *ppid) {
    int pid = -1;
    try {
        if(ppid == NULL || ppid == Py_None) {
            pid = getpid();
        }
        else {
            pid = carbon::cast<int>(ppid);
        }
        
#if __APPLE__
        return psutil_get_cmdline_osx(pid);
#endif
        
    }
    catch(const std::exception &e) {
        C_EXP(e);
        return NULL;
    }
}
