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

/// kingdom ///
std::string  Animal::getKingdom() const noexcept{
    return KINGDOM_NAME;
}

/// classification ///
std::string Animal::getClassification() const noexcept{
    return classification;
}

/// species ///
std::string Animal::getSpecies() const noexcept{
    return species;
}

/// gender ///
Gender Animal::getGender() const noexcept{
    return gender;
}

/// weight ///
Weight::t_weight Animal::getWeight() const noexcept{
    return weight.getWeight();
}

///////////////////////// validation /////////////////////////////////////////
bool Animal::validateClassification(const std::string &checkClassification) noexcept{
    if(checkClassification.compare("Mammalia")){
        return true;
    }
    if(checkClassification.compare("Aves")) {
        return true;
    }
    if(checkClassification.compare("Reptilia")){
        return true;
    }
    if(checkClassification.compare("Amphibia")) {
        return true;
    }
    if(checkClassification.compare("Osteichthyes")) {
        return true;
    }
    if(checkClassification.compare("Chrondrichtyes")){
        return true;
    }
    if(checkClassification.compare("Agnatha")) {
        return true;
    }

    std::cout << checkClassification << " is not a valid animal Class" << std::endl;
    return false;

}

bool Animal::validateSpecies(const std::string &checkSpecies) noexcept{
    if(checkSpecies.compare("Cat")){
        return true;
    }
    if(checkSpecies.compare("Dog")){
        return true;
    }

    std::cout << checkSpecies << " is not a valid Species" << std::endl;
    return false;

}

bool Animal::validate() const noexcept{
    if(!validateClassification(getClassification())){
        return false;
    }
    if (!validateSpecies(getSpecies())){
        return false;
    }
    if (KINGDOM_NAME.compare("Animalia")) {
        std::cout << "Invalid Kingdom for Animal" << std::endl;
        return false;
    }
    if(!Node::validate()){
        return false;
    }
    if(!weight.isWeightValid(getWeight())){
        std::cout <<"Invalid weight" << std::endl;
        return false;
    }
    return true;

}


///////////////////////// constructors ///////////////////////////////////////
Animal::Animal (const Weight::t_weight newMaxWeight, const std::string &newClassification, const std::string &newSpecies){
    weight.setMaxWeight(newMaxWeight);
    classification = newClassification;
    species = newSpecies;
}

Animal::Animal (const Gender newGender, const Weight::t_weight newWeight, const Weight::t_weight newMaxWeight, const std::string &newClassification, const std::string &newSpecies){
    setGender(newGender);
    setWeight(newWeight);
    weight.setMaxWeight(newMaxWeight);
    classification = newClassification;
    species = newSpecies;
}


//////////////////////////////dump/////////////////////////////////////////////
void Animal::dump() const noexcept {
    Node::dump();
    FORMAT_LINE_FOR_DUMP( "Animal", "this" ) << this << std::endl ;
    FORMAT_LINE_FOR_DUMP( "Animal", "kingdom" ) << getKingdom() << std::endl ;
    FORMAT_LINE_FOR_DUMP( "Animal", "classification" ) << getClassification() << std::endl;
    FORMAT_LINE_FOR_DUMP( "Animal", "species" ) << getSpecies() << std::endl ;
    FORMAT_LINE_FOR_DUMP( "Animal", "gender" ) << getGender() << std::endl ;
    FORMAT_LINE_FOR_DUMP( "Animal", "weight" ) << getWeight() << " out of " << weight.getMaxWeight() << weight.getUnitOfWeight() << std::endl;
    FORMAT_LINE_FOR_DUMP( "Animal", "species" ) << getSpecies() << std::endl ;

}
