///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_10d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file reportCats.cpp
/// @version 1.0
///
/// @author Jared Inouye <jinouye7@hawaii.edu>
/// @date   31_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <string.h>
#include <cstring>
#include <stdexcept>
#include <iostream>
#include <cassert>

#include "reportCats.h"
#include "catDatabase.h"
#include "Cats.h"
#include "config.h"

bool printAllCats() {

    //validate database before printing
    assert( validateDatabase() ) ;

    //print each cat in database until nullptr
    for(Cats* i = catDatabaseHeadPointer ; i != nullptr ; i = i->next ) {
        i->print() ;
    }

    //validate database again
    assert( validateDatabase() ) ;

    return true;
}

Cats* findCatByName( const char* name ) {
    assert( Cats().validateName( name ) );

    //iterate through database until a name match is found
    for(Cats* i = catDatabaseHeadPointer ; i != nullptr ; i = i->next ) {
        if( strcmp( name, i->getName() ) == 0 ) {
            return i ;
        }
    }

    //error handling
    std::cout << "Unable to find cat.  Not in database" << std::endl;
    throw std::invalid_argument( PROGRAM_NAME ": Unable to find cat.  Not in database" );

}

