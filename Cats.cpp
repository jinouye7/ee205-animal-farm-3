///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_10d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file Cats.cpp
/// @version 1.0
///
/// @author Jared Inouye <jinouye7@hawaii.edu>
/// @date   31_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#include "Cats.h"
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


/// Format a line for printing the members of a class
#define FORMAT_LINE( className, member ) cout << setw(8) << (className) << setw(20) << (member) << setw(52)


using namespace std ;

void Cats::zeroOutMemberData() {
    memset( name, 0, MAXLENGTH );
    gender = UNKNOWN_GENDER ;
    breed = UNKNOWN_BREED ;
    isFixed = false ;
    weight = UNKNOWN_WEIGHT ;
    next = nullptr ;
}

/// constuctor with no parameters (all default values)
Cats::Cats() {
    zeroOutMemberData() ;
}

/// constructor with bare minimum for valid cat
Cats::Cats(const char *newName, const Gender newGender, const Breed newBreed, const Weight newWeight) : Cats() {
    setName( newName ) ;
    setGender( newGender ) ;
    setBreed( newBreed ) ;
    setWeight( newWeight ) ;

    /// @todo assert( validate() ) ;
}

/*
Cats::~Cats() {
    zeroOutMemberData() ;
}
*/

/////////////////// Name Getter & Setter  ////////////////////////////////////////////////////////////////

void Cats::setName(const char *newName) {

    memset( name, 0, MAXLENGTH );  /// erase the old name
    strcpy( name, newName );  /// sets new name
}

const char *Cats::getName() const noexcept {
    return name;
}


////////////////////    Gender Getter & Setter    ////////////////////////////////////////////////////////
void Cats::setGender(Gender newGender) {
    if( gender != UNKNOWN_GENDER ) {
        throw logic_error( PROGRAM_NAME ": The gender is already set" ) ;
    }

    // At this point, the gender must be UNKNOWN_GENDER
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
    Cats::breed = newBreed;
}

Breed Cats::getBreed() const noexcept {
    return breed;
}

////////////////////    isFixed Getter & Setter    ////////////////////////////////////////////////////////

//// setter to fix cat
void Cats::fixCat() noexcept {
    Cats::isFixed = true;
}

/// getter (is cat fixed)

bool Cats::isCatFixed() const noexcept {
    return isFixed;
}

////////////////////    Weight Getter & Setter    ////////////////////////////////////////////////////////

Weight Cats::getWeight() const noexcept {
    return weight;
}

void Cats::setWeight(Weight newWeight) {
    Cats::weight = newWeight;
}

////////////////////    Validation    ///////////////////////////////////////////////////////////////////

/// validate name ///
bool Cats::validateName(const char *newName) {
    if( newName == nullptr ) {
        cerr  << PROGRAM_NAME << ": name must not be NULL"  << endl;
        return false;
    }

    if( strlen( newName ) <= 0 ) {
        cerr  << PROGRAM_NAME << ": name must be > 0"  << endl;
        return false;
    }

    if( strlen( newName ) >= MAXLENGTH ) {
        cerr  << PROGRAM_NAME << ": name must be < MAX_CAT_NAME"  << endl;
        return false;
    }

    return true;
}

/// validate gender ///
bool Cats::validateGender(const Gender newGender) {
    if( newGender == UNKNOWN_GENDER ) {
        cerr  << PROGRAM_NAME << ": Gender must be known"  << endl;
        return false;
    }

    return true;
}

/// validate Breed ///
bool Cats::validateBreed(const Breed newBreed) {
    if( newBreed == UNKNOWN_BREED ) {
        cerr  << PROGRAM_NAME << ": Breed must be known"  << endl;
        return false;
    }

    return true;
}

/// validate weight ///
bool Cats::validateWeight(const Weight newWeight) {
    if( newWeight <= 0 ) {
        cerr  << PROGRAM_NAME << ": Weight must be > 0"  << endl;
        return false;
    }

    return true;
}


/// validate cat ///

bool Cats::validate() const noexcept {
    if (validateName( name ) == false) {
        return false;
    }
    if (validateGender( gender ) == false) {
        return false;
    }
    if (validateBreed( breed ) == false ) {
        return false;
    }
    if (validateWeight( weight ) == false ) {
        return false;
    }
    return true;
}
/////////////////////////////// print   ////////////////////////////////////////////////////////////////////
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
    FORMAT_LINE( "Cat", "weight" )       << getWeight() << endl ;

    return true ;
}



