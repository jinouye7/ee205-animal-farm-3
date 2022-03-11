///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file addCats.h
/// @version 1.0
///
/// @author Jared Inouye <jinouye7@hawaii.edu>
/// @date   09_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#include <stdbool.h>
#include "catDatabase.h"

int addCat(const char name[], const enum Gender gender, const enum Breed breed, const bool isFixed, const float weight, const enum Color collarColor1, const enum Color collarColor2, const unsigned long long license, const char *date);

