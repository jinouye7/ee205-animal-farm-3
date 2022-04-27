///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal-farm-3 - EE 205 - Spr 2022
///
/// @file Cats.cpp
/// @version 1.0
///
/// @author Jared Inouye <jinouye7@hawaii.edu>
/// @date   26_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include "Cats.h"
#include <stdexcept>
#include <iostream>
#include <iomanip>


#include "config.h"



/// Format a line for printing the members of a class
#define FORMAT_LINE( className, member ) cout << setw(8) << (className) << setw(20) << (member) << setw(52)


/////////////////// Constants  ///////////////////////////////////////////////////////////////////////////
const std::string Cats::SPECIES_NAME = "Felis Catus";  ///< The scientific name for this species
const Weight::t_weight Cats::MAX_WEIGHT = 40;


/////////////////// Name Getter & Setter  ////////////////////////////////////////////////////////////////

void Cats::setName(const std::string& newName) {

 name = newName;

}

std::string Cats::getName() const noexcept {
    return name;
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
/*
float Cats::getWeight() const noexcept {
    return weight;
}

void Cats::setWeight(float newWeight) {
    Cats::weight = newWeight;
}
*/
////////////////////    Validation    ///////////////////////////////////////////////////////////////////

/// validate name ///
bool Cats::validateName(const std::string& newName) {
    if( newName.empty() ) {
        std::cerr  << PROGRAM_NAME << ": name must not be empty"  << std::endl;
        return false;
    }

    return true;
}


/// validate cat ///

bool Cats::validate() const noexcept {
    if (validateName( Cats::getName() ) == false) {
        return false;
    }
    if (Animal::validate() == false) {
        return false;
    }
    return true;
}
/////////////////////////////// print   ////////////////////////////////////////////////////////////////////
void Cats::dump() const noexcept{
    /// assert( validate() ) ;

    Mammal::dump();
    FORMAT_LINE_FOR_DUMP( "Cat", "name" ) << getName() << std::endl ;
    FORMAT_LINE_FOR_DUMP( "Cat", "isFixed" ) << isCatFixed() << std::endl ;
/*
    cout << setw(80) << setfill( '=' ) << "" << endl ;
    cout << setfill( ' ' ) ;
    cout << left ;
    cout << boolalpha ;
    FORMAT_LINE( "Cat", "name" )         << getName()   << endl ;
    FORMAT_LINE( "Cat", "gender" )       << getGender() << endl ;
    FORMAT_LINE( "Cat", "breed" )        << breedName( getBreed() )   << endl ;
    FORMAT_LINE( "Cat", "isCatFixed" )      << isCatFixed()   << endl ;
    FORMAT_LINE( "Cat", "weight" )       << getWeight() << endl ;

    return true ;

    */
}

 std::string Cats::speak() const noexcept {
    return std::string( "Meow" );
}

