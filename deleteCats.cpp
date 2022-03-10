///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file deleteCats.cpp
/// @version 1.0
///
/// @author Jared Inouye <jinouye7@hawaii.edu>
/// @date   09_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <string.h>
#include <stdio.h>
#include "deleteCats.h"
#include "catDatabase.h"
#include "config.h"

int deleteAllCats(){
    //commented out code used in animalFarm0
    /* memset(arrName, 0, sizeof arrName);
    memset(arrGender, 0, sizeof arrGender);
    memset(arrBreed, 0, sizeof arrBreed);
    memset(arrIsFixed, 0, sizeof arrIsFixed);
    memset(arrWeight, 0, sizeof arrWeight);*/
    currentNumberCats = 0;
    printf("all cats deleted\n");
    return 0;
}


