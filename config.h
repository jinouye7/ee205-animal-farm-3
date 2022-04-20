///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_10d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file config.h
/// @version 1.0
///
/// @author Jared Inouye <jinouye7@hawaii.edu>
/// @date   29_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once
#include <iomanip>
#define PROGRAM_TITLE "Animal Farm 3"
#define PROGRAM_NAME "animalFarm3"
#define FORMAT_LINE_FOR_DUMP(className, member) std::cout << std::setfill( ' ' )  /* Space pad    */  \
                                                          << std::left            /* Left justify */  \
                                                          << std::boolalpha  /* Print `true` or `false` for `bool`s */ \
                                                          << std::setw( 8) << (className)             \
                                                          << std::setw(20) << (member)                \
                                                          << std::setw(52)  /* (data) */

#define PRINT_HEADING_FOR_DUMP std::cout << std::setw(80) << std::setfill( '=' ) << "" << std::endl






#define MAXLENGTH 50 /// maximum name length
#define MAXCATS 1024 /// maximum number of cats




typedef float Weight ;
typedef int NumCats;
const Weight UNKNOWN_WEIGHT = -1 ;  /// Weight is unknown
