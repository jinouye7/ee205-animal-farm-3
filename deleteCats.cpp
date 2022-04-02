///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file deleteCats.cpp
/// @version 1.0
///
/// @author Jared Inouye <jinouye7@hawaii.edu>
/// @date   09_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <string.h>
#include <stdio.h>
#include <cassert>
#include <iostream>


#include "deleteCats.h"
#include "catDatabase.h"
#include "Cats.h"
#include "config.h"

using namespace std;

bool deleteCat( Cats* goner ) {
    //can't delete null pointer
    assert( goner != nullptr ) ;

    //validate database
    assert( validateDatabase() ) ;

    // removing the first cat is a special case
    if( goner == catDatabaseHeadPointer ) {
        //head pointer reassigned to next cat in the list
        catDatabaseHeadPointer = catDatabaseHeadPointer->next ;
        //delete first cat
        delete goner ;
        currentNumberCats--;

        //validate database after removing cat
        assert( validateDatabase() ) ;
        cout <<"cat deleted"<< endl;
        return true ;
    }


    // to delete a cat that isn't the first in the list...
    // 1) go through list and find the cat before the "goner"
    Cats* i = catDatabaseHeadPointer ;
    while( i != nullptr ) {
        if( i->next == goner ) {
            // 2) reassign it's next pointer to cat after the "goner"
            i->next = goner->next ;
            // 3) "goner" is deleted
            delete goner ;
            currentNumberCats--;

            // re-validate database after removing cat
            assert( validateDatabase() ) ;
            cout <<"cat deleted"<< endl;
            return true ;
        }
        i = i->next ;
    }
    //if there was no match...
    //re-validate database
    assert( validateDatabase() ) ;

    //error handling
    throw invalid_argument( PROGRAM_NAME ": Cannot delete cat. Not in database" );
}


bool deleteAllCats() {
    // go through list and use the deleteCat function to delete cats
    while(catDatabaseHeadPointer != nullptr ) {
        deleteCat(catDatabaseHeadPointer ) ;
    }

    currentNumberCats == 0;

    cout <<  "All cats deleted" << endl ;
    //note: database empty, no need to re-validate

    return true ;
}

