
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
