///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_10d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file catDatabase.h
/// @version 1.0
///
/// @author Jared Inouye <jinouye7@hawaii.edu>
/// @date   29_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once
#include <stdbool.h>
#include <time.h>
#include "config.h"
#include "Cats.h"



/// Declaring a Cat struct
struct Cat {
    char name[MAXLENGTH];
    enum Gender gender;
    enum Breed breed;
    bool isFixed;
    Weight weight;
    enum Color collarColor1;
    enum Color collarColor2;
    unsigned long long license;
    struct tm birthday;
};

extern struct Cat cats[MAXCATS];

extern NumCats currentNumberCats;


/// Functions that return a string for the name of the gender, color, and cat breeds
char* genderName (const enum Gender gender);
char* colorName (const enum Color color);
char* breedName (const enum Breed breed);
// Function to convert a string like " May 4, 2000" to a struct tm
int birthdayToStruct( const int index, const char *date);
//convert struct back to date
int structToDate(const int index);