/*
 * c-pyrun.cpp
 *
 *  Created on: Jan 22, 2020
 *      Author: andy
 */


#include <fstream>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <carbon.h>

int main( int argc , char** argv )
{
    
    C_Initialize(0);
    
    if(argc <= 1) {
        std::cout << "usage: c-pyrun filenane" << std::endl;
        return 0;
    }

    // open the script
    const char* pFilename = argv[1] ; // nb: first command-line argument
    FILE* fp = fopen(pFilename , "r" ) ;
    if(fp == NULL) {

        std::cout << "could not open file: " << pFilename << std::endl;

    }

    C_Initialize(0);

    // initialize Python
    Py_Initialize() ;



    // run the script
    int rc2 = PyRun_SimpleFile( fp , pFilename ) ;
    assert( rc2 == 0 ) ;

    // clean up
    fclose( fp ) ;
    Py_Finalize() ;

    return 0;
}




