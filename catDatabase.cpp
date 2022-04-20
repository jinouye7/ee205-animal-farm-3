///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_10d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file catDatabase.cpp
/// @version 1.0
///
/// @author Jared Inouye <jinouye7@hawaii.edu>
/// @date   29_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include<memory.h>
#include<stdio.h>
#include<time.h>
#include <stdbool.h>


#include <cstring>
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <cassert>

#include "config.h"
#include "catDatabase.h"
#include "Cats.h"

using namespace std;

///////// setting up linked list for cat database////////////////////////////////////

/// initialize number of cats
NumCats currentNumberCats = 0;
/// head pointer
Cats* catDatabaseHeadPointer = nullptr ;

///////// database validation /////////////////////////////////////////////////////
extern bool validateDatabase() {
    int validedCats = 0 ;

    /// revalidate all the cats in the list
    for(Cats* i = catDatabaseHeadPointer ; i != nullptr ; i = i->next ) {
        if( !i->validate() ) {
            return false ;
        }
        //keep track of the number of cats validated
        validedCats++ ;
    }

    if( validedCats != currentNumberCats ) {
        cerr << PROGRAM_NAME << ": Error:  numberOfCats [" << currentNumberCats
             << "] does not equal [" << validedCats << "]" << endl ;
        return false ;
    }

    //cout << PROGRAM_NAME << ": The database is valid." << endl ;

    return true ;  // The database is healthy
}

////////////////////////////////////// old code /////////////////////////////////////////////////////


/*
//returns string counterpart for gender enum
char* genderName (const enum Gender gender) {

    char* strGender;

    switch (gender) {

        case 0: strGender = "Unknown Gender";
            break;

        case 1: strGender = "Male";
            break;

        case 2: strGender = "Female";
            break;

    }

    return strGender;

}
*/


//returns string counterpart for breed enum

char* breedName (const enum Breed breed) {

    char* strBreed;

    switch (breed) {

        case 0: strBreed = "Unknown Breed";
            break;

        case 1: strBreed = "Main Coon";
            break;

        case 2: strBreed = "Manx";
            break;

        case 3: strBreed = "Short Hair";
            break;

        case 4: strBreed = "Persian";
            break;

        case 5: strBreed = "Sphynx";
            break;

    }

    return strBreed;
}


//returns string counterpart for color enum

char* colorName (const enum Color color) {

    char* strColor;

    switch (color) {

        case 0: strColor = "Black";
            break;

        case 1: strColor = "White";
            break;

        case 2: strColor = "Red";
            break;

        case 3: strColor = "Blue";
            break;

        case 4: strColor = "Green";
            break;

        case 5: strColor = "Pink";
            break;

    }

    return strColor;
}


