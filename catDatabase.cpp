///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_2 - EE 205 - Spr 2022
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

/// Format a line for printing the members of a class
#define FORMAT_LINE( className, member ) cout << setw(8) << (className) << setw(20) << (member) << setw(52)


NumCats currentNumberCats = 0;

using namespace std ;

void Cats::zeroOutMemberData() {
    memset( name, 0, MAXLENGTH );
    gender = UNKNOWN_GENDER ;
    breed = UNKNOWN_BREED ;
    isFixed = false ;
    weight = -1 ;
    next = nullptr ;
}

/// constuctor with no parameters (all default values)
Cats::Cats() {
    zeroOutMemberData() ;
}

/// constructor with bare minimum for valid cat
Cats::Cats(const char *newName, const Gender newGender, const Breed newBreed, const Weight newWeight) : Cats() {
    setName( newName ) ;
    /// @todo
    setGender( newGender ) ;
    /// setBreed( newBreed ) ;
    /// setWeight( newWeight ) ;

    /// @todo assert( validate() ) ;
}

/*
Cats::~Cats() {
    zeroOutMemberData() ;
}
*/

/////////////////// Name Getter & Setter  ////////////////////////////////////////////////////////////////

void Cats::setName(const char *newName) {
    /// @todo validateName( newName ) ;  // Throws an exception if there's a problem.

    memset( name, 0, MAXLENGTH );  /// erase the old name
    strcpy( name, newName );  /// sets new name
}

const char *Cats::getName() const noexcept {
    return name;
}


////////////////////    Gender Getter & Setter    ////////////////////////////////////////////////////////
void Cats::setGender(Gender newGender) {
    if( gender != UNKNOWN_GENDER ) {
        throw logic_error( PROGRAM_NAME ": The gender is already set, you can't change it" ) ;
    }

    // At this point, the gender must be UNKNOWN_GENDER
    ///validateGender( newGender );
    Cats::gender = newGender ;
}

Gender Cats::getGender() const noexcept {
    return gender;
}


////////////////////    Breed Getter & Setter    ////////////////////////////////////////////////////////

void Cats::setBreed(Breed newBreed) {
    if( breed != UNKNOWN_BREED ) {
        throw logic_error( PROGRAM_NAME ": The breed is already set, you can't change it" ) ;
    }
    // breed is unknown so we can set the breed
    /// validateBreed( newBreed ) ;
    Cats::breed = newBreed;
}

    Breed Cats::getBreed() const noexcept {
        return breed;
    }

////////////////////    Breed Getter & Setter    ////////////////////////////////////////////////////////

//// setter to fix cat
void Cats::fixCat() noexcept {
    Cats::isFixed = true;
}

/// getter (is cat fixed)

bool Cats::isCatFixed() const noexcept {
    return isFixed;
}

//////////////////////////////////////////////////////////////////////////////////////
bool Cats::print() const noexcept {
    /// assert( validate() ) ;

    cout << setw(80) << setfill( '=' ) << "" << endl ;
    cout << setfill( ' ' ) ;
    cout << left ;
    cout << boolalpha ;
    FORMAT_LINE( "Cat", "name" )         << getName()   << endl ;
    FORMAT_LINE( "Cat", "gender" )       << genderName( getGender() ) << endl ;
    FORMAT_LINE( "Cat", "breed" )        << breedName( getBreed() )   << endl ;
    FORMAT_LINE( "Cat", "isCatFixed" )      << isCatFixed()   << endl ;
    ///FORMAT_LINE( "Cat", "weight" )       << getWeight() << endl ;

    return true ;
}






////////////////////////////////////// old code /////////////////////////////////////////////////////
struct Cat cats[MAXCATS];


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


int birthdayToStruct(const int index, const char *date){

    char* months[] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};


    memset(&cats[index].birthday, 0, sizeof cats[index].birthday);  // set all fields to 0
    char str[4];
    sscanf(date,"%3s",str);
    int i=0;
    for(i=0; i<12; i++)
    {
        if(!strcmp(str,months[i]))
        {
            //printf("Your month number is: %d",i+1);
            int value;
            value = i +1 ;
            cats[index].birthday.tm_mon = value;
            //debug
            //printf("storedmonth: %d\n", cats[index].birthday.tm_mon);

        }


    }

    //* means it will be read but not stored
    sscanf(date, "%*s %d, %d", &cats[index].birthday.tm_mday, &cats[index].birthday.tm_year);

    //debug
    //printf("storedday: %d\n", cats[index].birthday.tm_mday);
    //printf("storedyear: %d\n", cats[index].birthday.tm_year);


    // Adjust to struct tm references
    cats[index].birthday.tm_year -= 1899;
    cats[index].birthday.tm_mon--;

    return 0;
}


int structToDate(const int index){
    //char buf[200];
    //strftime(buf, 200, "struct birthday: %a %b %d %r %Z %G\n", &cats[index].birthday);
    //puts(buf);

    int year;
    int month;
    int day;

    year = cats[index].birthday.tm_year + 1899;
    month = cats[index].birthday.tm_mon + 1;
    day = cats[index].birthday.tm_mday;

    printf("birthday = [%d/%d/%d]\n", day, month, year);



    return 0;
}
