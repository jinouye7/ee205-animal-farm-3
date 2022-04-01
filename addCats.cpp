///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file addCats.cpp
/// @version 1.0
///
/// @author Jared Inouye <jinouye7@hawaii.edu>
/// @date   29_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cassert>
#include <string.h>

#include "catDatabase.h"
#include "addCats.h"
#include "config.h"
#include "Cats.h"
//#define DEBUG

using namespace std;
bool addCats(Cats* newCat) {
    //new cat must not be nullptr
    assert( newCat != nullptr );
    //validate the newCat
    if (newCat->validate() ==  false){
        throw invalid_argument("BAD CAT");
    }

    //database must be valid before adding a new cat
    assert(validateDatabase()) ;

    //add the cat
    newCat->next = catDatabaseHeadPointer ;
    catDatabaseHeadPointer = newCat ;
    currentNumberCats++;

    //re-validate database after adding cat
    assert(validateDatabase());

    cout << "Added cat" <<endl;

    return true;

}
////////////////////// old add cat ////////////////////////////////////////////////////////////////////////////////

int addCat(const char name[], const enum Gender gender, const enum Breed breed, const bool isFixed, const Weight weight, const enum Color collarColor1, const enum Color collarColor2, const unsigned long long license, const char *date){
    if (currentNumberCats >=  MAXCATS){
        fprintf(stderr, "%s: number of cats exceeded\n", PROGRAM_NAME);
        return 1;
    }

    if (strlen(name) <= 0){
        fprintf(stderr, "%s: cat's name cannot be empty\n", PROGRAM_NAME);
        return 1;
    }

    if (strlen(name) >= MAXLENGTH){
        fprintf(stderr, "%s: name must not be >= %d characters\n", PROGRAM_NAME, MAXLENGTH);
        return 1;
    }

    if (weight <= 0 ) {
        fprintf(stderr, "%s: weight must be > 0\n", PROGRAM_NAME);
        return 1;
    }
    if (collarColor1 == collarColor2){
        fprintf(stderr, "%s: collar color 1 must not match collar color 2\n", PROGRAM_NAME);
        return 1;
    }

    int i = 0;

    for (i = 0; i <= currentNumberCats; ++i){

        if (strcmp(name, cats[i].name) == 0){
            fprintf(stderr, "%s: name of cat must be unique\n", PROGRAM_NAME);
            return 1;
        }
        if (license == cats[i].license){
            fprintf(stderr, "%s: license must be unique\n", PROGRAM_NAME);
            return 1;
        }
        if (collarColor1 == cats[i].collarColor1){
            if (collarColor2 == cats[i].collarColor2){
                fprintf(stderr, "%s: collar color combination must be unique\n", PROGRAM_NAME);
                return 1;
            }
        }

    }


    strcpy(cats[currentNumberCats].name,name);
    cats[currentNumberCats].gender = gender;
    cats[currentNumberCats].breed = breed;
    cats[currentNumberCats].isFixed = isFixed;
    cats[currentNumberCats].weight = weight;
    cats[currentNumberCats].collarColor1 = collarColor1;
    cats[currentNumberCats].collarColor2 = collarColor2;
    cats[currentNumberCats].license = license;
    birthdayToStruct(currentNumberCats, date);




    currentNumberCats += 1;

    printf("cat added\n");
    return 0;


}

