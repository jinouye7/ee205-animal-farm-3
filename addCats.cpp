///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_10d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file addCats.cpp
/// @version 1.0
///
/// @author Jared Inouye <jinouye7@hawaii.edu>
/// @date   29_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cassert>
#include <string.h>

#include "catDatabase.h"
#include "addCats.h"
#include "config.h"
#include "Cats.h"
//#define DEBUG

using namespace std;
bool addCats(Cats* newCat) {
    //new cat must not be nullptr
    assert( newCat != nullptr );
    //validate the newCat
    if (newCat->validate() ==  false){
        throw invalid_argument("BAD CAT");
    }

    //database must be valid before adding a new cat
    assert(validateDatabase()) ;

    //add the cat
    newCat->next = catDatabaseHeadPointer ;
    catDatabaseHeadPointer = newCat ;
    currentNumberCats++;

    //re-validate database after adding cat
    assert(validateDatabase());

    cout << "Added cat" <<endl;

    return true;

}


