///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_10d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file main.cpp
/// @version 1.0
///
/// @author Jared Inouye <jinouye7@hawaii.edu>
/// @date   02_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <iostream>
#include "catDatabase.h"
#include "addCats.h"
#include "reportCats.h"
#include "updateCats.h"
#include "deleteCats.h"
#include "config.h"
//#define DEBUG
#define MAX_NAME "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwx"
#define ILLEGAL_NAME "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxy"
//#define BIRTHDAY
//#define OLD


int main() {

Cats testCat = Cats();
testCat.print();

std:: cerr  << PROGRAM_NAME << " is the name of the program"  << std:: endl;



#ifdef OLD
    addCat( "Loki", MALE, PERSIAN, true, 8.5,  BLACK, WHITE, 101, "May 4, 2000") ;
    addCat( "Milo", MALE, MANX, true, 7.0 ,  BLACK, RED, 102, "May 4, 2000") ;
    addCat( "Bella", FEMALE, MAINE_COON, true, 18.2 , BLACK, BLUE, 103, "May 4, 2000") ;
    addCat( "Kali", FEMALE, SHORTHAIR, false, 9.2 , BLACK, GREEN, 104, "May 4, 2000") ;
    addCat( "Trin", FEMALE, MANX, true, 12.2, BLACK, PINK, 105, "May 4, 2000") ;
    addCat( "Chili", UNKNOWN_GENDER, SHORTHAIR, false, 19.0, WHITE, BLACK, 106, "May 4, 2000") ;


    printAllCats();

    int kali = findCat( "Kali" ) ;
    assert(updateCatName( kali, "Chili" ) == 1) ; // this should fail
    assert(printCat( kali ) == 0);
    assert(updateCatName( kali, "Capulet" ) == 0) ;
    assert(updateCatWeight( kali, 9.9 ) == 0) ;
    assert(fixCat( kali ) == 0) ;
    assert(updateCatCollar1( kali, RED) == 0);
    assert(updateCatCollar2( kali, BLUE) == 0);
    assert(updateLicense( kali, 111) == 0);
    assert(updateBirthday( kali, "March 17,2000") == 0);
    assert(printCat( kali ) == 0);
    assert(printAllCats() == 0);
    assert(deleteAllCats() == 0);
    assert(printAllCats() == 1); //this should fail (all cats deleted)

#endif


#ifdef DEBUG
    // Test for empty name
        assert( addCat( "", UNKNOWN_GENDER, SHORTHAIR,  false, 19.0, BLACK, WHITE, 101, "May 4, 2000" ) == 1 ) ;
        // Test for max name
        assert( addCat( MAX_NAME, UNKNOWN_GENDER, SHORTHAIR,  false, 19.0, WHITE, RED, 107, "May 4, 2000" ) == 1 ) ;
        // Test for name too long
        assert( addCat( ILLEGAL_NAME, UNKNOWN_GENDER, SHORTHAIR,  false, 19.0, WHITE, BLUE, 108, "May 4, 2000" ) == 1 ) ;
        // Test for duplicate cat name
        assert( addCat( "Chili", UNKNOWN_GENDER, SHORTHAIR,  false, 0, WHITE, GREEN, 109, "May 4, 2000" ) == 1 ) ;
        // Test for weight <= 0
        assert( addCat( "Neo", UNKNOWN_GENDER, SHORTHAIR,  false, 0, WHITE, BLACK, 110,"May 4, 2000") == 1 ) ;
        // Test for duplicate license
        assert( addCat( "testcat", UNKNOWN_GENDER, SHORTHAIR,  false, 19.0, BLACK, RED, 101, "May 4, 2000" ) == 0 );
        assert( addCat( "testcata", UNKNOWN_GENDER, SHORTHAIR,  false, 19.0, BLACK, PINK, 101, "May 4, 2000" ) == 1 ) ;
        // Test for duplicate collar color
        assert( addCat( "testcatb", UNKNOWN_GENDER, SHORTHAIR,  false, 19.0, WHITE, PINK, 111, "May 4, 2000" ) == 0 ) ;
        assert( addCat( "testcatc", UNKNOWN_GENDER, SHORTHAIR,  false, 19.0, WHITE, PINK, 112, "May 4, 2000" ) == 1 ) ;
        // Test for matching collar color 1 and 1
        assert( addCat( "testcatd", UNKNOWN_GENDER, SHORTHAIR,  false, 19.0, WHITE, WHITE, 113, "May 4, 2000" ) == 1 ) ;


#endif

//testing birthday stuff

#ifdef BIRTHDAY

    //testing string to struct tm and struct tm to string functions
       //birthdayToStruct(1, "May 4, 2010");
       //structToDate(1);
       //testing addCat
       addCat( "Loki", MALE, PERSIAN, true, 8.5,  BLACK, WHITE, 101, "May 4, 2000") ;
       addCat( "Milo", MALE, MANX, true, 7.0 ,  BLACK, RED, 102, "December 10, 2001") ;
       addCat( "Bella", FEMALE, MAINE_COON, true, 18.2 , BLACK, BLUE, 103, "March 17, 2000") ;

       //test report cat
       printAllCats();
       printCat(1);
       //testing update cat
       updateBirthday(1, "January 15, 2003" );
       //test report cat again
       printCat(1);

#endif



    return 0;
//yay

}


