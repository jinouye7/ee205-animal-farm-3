///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal-farm-3 - EE 205 - Spr 2022
///
/// @file Animal.cpp
/// @version 1.0
///
/// @author Jared Inouye <jinouye7@hawaii.edu>
/// @date   21_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include <cassert>
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include "config.h"
#include "Animal.h"

//constant name of kingdom
const std::string Animal::KINGDOM_NAME = "Animalia";

//////////////////////////////// setters //////////////////////////////////////
///weight///
void    Animal::setWeight (const Weight::t_weight newWeight){
    weight.setWeight(newWeight);
};

///gender///
void Animal::setGender(const Gender newGender) {
    if( gender != Gender::UNKNOWN_GENDER ) {
        throw std::logic_error( PROGRAM_NAME ": The gender is already set" ) ;
    }

    // At this point, the gender must be UNKNOWN_GENDER
    Animal::gender = newGender ;
}

///////////////////////////// getters ////////////////////////////////////////





