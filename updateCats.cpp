///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file updateCats.cpp
/// @version 1.0
///
/// @author Jared Inouye <jinouye7@hawaii.edu>
/// @date   09_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "catDatabase.h"
#include "Cats.h"
#include "updateCats.h"
#include "config.h"

//function to update cat name at a specified index
int updateCatName(const int index, const char newName[]){
    if (index >= currentNumberCats){
        fprintf(stderr, "%s: no cat at index %d\n",PROGRAM_NAME, index);
        return 1;
    }
    if (index < 0){
        fprintf(stderr, "%s: index must be greater than 0\n", PROGRAM_NAME);
        return 1;
    }
    if (strlen(newName) == 0){
        fprintf(stderr, "%s: cat's name cannot be empty\n", PROGRAM_NAME);
        return 1;
    }

    if (strlen(newName) >= MAXLENGTH){
        fprintf(stderr, "%s: name must not be >= %d characters\n", PROGRAM_NAME, MAXLENGTH);
        return 1;
    }


    int i = 0;

    for (i = 0; i <= currentNumberCats; ++i){

        if (strcmp(newName, cats[i].name) == 0){
            fprintf(stderr, "%s: new name of cat must be unique\n", PROGRAM_NAME);
            return 1;
        }
    }

    strcpy(cats[index].name,newName);

    printf("The name of the cat at index %d has been changed to %s\n", index, newName);

    return 0;

}


//function to fix a cat at a specified index
int fixCat(const int index){
    if (index >= currentNumberCats){
        fprintf(stderr, "%s: no cat at index %d\n", PROGRAM_NAME, index);
        return 1;
    }
    if (index < 0){
        fprintf(stderr, "%s: index must be greater than 0\n", PROGRAM_NAME);
        return 1;
    }
    if(cats[index].isFixed == true){
        fprintf(stderr, "%s: cat is already fixed\n", PROGRAM_NAME);
        return 1;
    }

    cats[index].isFixed = true;

    printf("cat at index %d is now fixed\n", index);
    return 0;
}


//fuction to update cat weight at a specified index
int updateCatWeight(const int index,const Weight newWeight){
    if (index >= currentNumberCats){
        fprintf(stderr, "%s: no cat at index %d\n", PROGRAM_NAME,  index);
        return 1;
    }
    if (index < 0){
        fprintf(stderr, "%s: index must be greater than 0\n", PROGRAM_NAME);
        return 1;
    }

    if(newWeight <= 0){
        fprintf(stderr, "%s: cat weight must be greater than 0\n", PROGRAM_NAME);
        return 1;
    }

    cats[index].weight = newWeight;
    printf("weight of cat at index %d has been changed to %f\n", index, cats[index].weight);
    return 0;

}

//function to update collar color 1 at a specified index
int updateCatCollar1(const int index, const enum Color newColor1){
    if (index >= currentNumberCats){
        fprintf(stderr, "%s: no cat at index %d\n", PROGRAM_NAME,  index);
        return 1;
    }
    if (index < 0){
        fprintf(stderr, "%s: index must be greater than 0\n", PROGRAM_NAME);
        return 1;
    }

    if (newColor1 == cats[index].collarColor1){
        fprintf(stderr, "%s: new collar color 1 must not be the same as the old collar color 1\n", PROGRAM_NAME);
        return 1;
    }
    if (newColor1 ==  cats[index].collarColor2){
        fprintf(stderr, "%s: new collar color 1 must not match collar color 2\n", PROGRAM_NAME);
        return 1;
    }

    int i = 0;

    for (i = 0; i <= currentNumberCats; ++i){

        if (newColor1 == cats[i].collarColor1){
            if (cats[index].collarColor2 == cats[i].collarColor2){
                fprintf(stderr, "%s: new collar color combination must be unique\n", PROGRAM_NAME);
                return 1;
            }
        }

    }

    cats[index].collarColor1 = newColor1;
    printf("collar color 1 of cat at index %d has been changed to %d\n", index, cats[index].collarColor1);
    return 0;
}




//function to update collar color 2 at a specified index
int updateCatCollar2(const int index, const enum Color newColor2){
    if (index >= currentNumberCats){
        fprintf(stderr, "%s: no cat at index %d\n", PROGRAM_NAME,  index);
        return 1;
    }
    if (index < 0){
        fprintf(stderr, "%s: index must be greater than 0\n", PROGRAM_NAME);
        return 1;
    }

    if (newColor2 == cats[index].collarColor2){
        fprintf(stderr, "%s: new collar color 2 must not be the same as the old collar color 2\n", PROGRAM_NAME);
        return 1;
    }
    if (newColor2 ==  cats[index].collarColor1){
        fprintf(stderr, "%s: new collar color 2 must not match collar color 1\n", PROGRAM_NAME);
        return 1;
    }

    int i = 0;

    for (i = 0; i <= currentNumberCats; ++i){

        if (newColor2 == cats[i].collarColor2){
            if (cats[index].collarColor1 == cats[i].collarColor1){
                fprintf(stderr, "%s: new collar color combination must be unique\n", PROGRAM_NAME);
                return 1;
            }
        }

    }

    cats[index].collarColor2 = newColor2;
    printf("collar color 2 of cat at index %d has been changed to %d\n", index, cats[index].collarColor2);
    return 0;
}


//function to update license of cat at a specified index
int updateLicense(const int index, const unsigned long long license){

    if (index >= currentNumberCats){
        fprintf(stderr, "%s: no cat at index %d\n", PROGRAM_NAME,  index);
        return 1;
    }
    if (index < 0){
        fprintf(stderr, "%s: index must be greater than 0\n", PROGRAM_NAME);
        return 1;
    }


    int i = 0;

    for (i = 0; i <= currentNumberCats; ++i){

        if (license == cats[i].license){
            fprintf(stderr, "%s: new license must be unique\n", PROGRAM_NAME);
            return 1;

        }

    }

    cats[index].license = license;
    printf("license of cat at index %d has been changed to %llu\n", index, cats[index].license);

    return 0;
}

//function to update the birthday of a cat at a specified index;
int updateBirthday(const int index, const char *date){
    birthdayToStruct(index, date);
    printf("birthday of cat and index %d was changed to ", index);
    structToDate(index);
    return 0;
}

