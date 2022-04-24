///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal-farm-3 - EE 205 - Spr 2022
///
/// @file Mammal.cpp
/// @version 1.0
///
/// @author Jared Inouye <jinouye7@hawaii.edu>
/// @date   21_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include "Mammal.h"


void Mammal::dump() const noexcept{
    Animal::dump();
    FORMAT_LINE_FOR_DUMP( "Mammal", "color" ) << getColor() << std::endl ;
}

const std::string Mammal:: MAMMAL_NAME = "Mammilian";
