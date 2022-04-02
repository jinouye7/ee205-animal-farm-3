///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_10d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file reportCats.cpp
/// @version 1.0
///
/// @author Jared Inouye <jinouye7@hawaii.edu>
/// @date   31_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <string.h>
#include <cstring>
#include <stdexcept>
#include <iostream>
#include <cassert>

#include "reportCats.h"
#include "catDatabase.h"
#include "Cats.h"
#include "config.h"

bool printAllCats() {
    int numCats = 0 ;

    //validate database before printing
    assert( validateDatabase() ) ;

    //print each cat in database until nullptr
    for(Cats* i = catDatabaseHeadPointer ; i != nullptr ; i = i->next ) {
        i->print() ;
        numCats++ ;
    }

    //validate database again
    assert( validateDatabase() ) ;

    return true;
}

Cats* findCatByName( const char* name ) {
    assert( Cats().validateName( name ) );

    //iterate through database until a name match is found
    for(Cats* i = catDatabaseHeadPointer ; i != nullptr ; i = i->next ) {
        if( strcmp( name, i->getName() ) == 0 ) {
            return i ;
        }
    }

    //error handling
    std::cout << "Unable to find cat.  Not in database" << std::endl;
    throw std::invalid_argument( PROGRAM_NAME ": Unable to find cat.  Not in database" );

}

//@todo char printCat(const char* name)

#ifdef OLD
int printCat(const int index){
    //print if cat is not in database
    if (index < 0){
        fprintf(stderr, "%s: Bad cat [%d]\n", PROGRAM_NAME, index);
        return 1;
    }
    if (index >= currentNumberCats){
        fprintf(stderr, "%s: Bad cat [%d]\n", PROGRAM_NAME, index);
        return 1;
    }

    //print if cat is in database
    printf("cat index = [%d] name=[%s] gender=[%s] breed=[%s] isFixed=[%d] weight=[%f] color1=[%s] color2=[%s] license=[%llu] ",
           index, cats[index].name, genderName(cats[index].gender), breedName(cats[index].breed), cats[index].isFixed, cats[index].weight, colorName(cats[index].collarColor1), colorName(cats[index].collarColor2), cats[index].license);

    //print birthday function
    structToDate(index);

    //printf("the print thing is working\n");
    return 0;
}



int printAllCats(){
    if (currentNumberCats == 0){
        fprintf(stderr, "%s: there are no cats\n", PROGRAM_NAME);
        return 1;
    }
    int i = 0;
    for (i = 0; i < currentNumberCats; ++i){

        printf("cat index = [%d] name=[%s] gender=[%s] breed=[%s] isFixed=[%d] weight=[%f] color1=[%s] color2=[%s] license=[%llu] ",
               i, cats[i].name, genderName(cats[i].gender), breedName(cats[i].breed), cats[i].isFixed, cats[i].weight, colorName(cats[i].collarColor1), colorName(cats[i].collarColor2), cats[i].license);

        //function to print bithday as string
        structToDate(i);

    }
    //printf("print all is going\n");
    return 0;
}



int findCat(const char name[]){

    int i = 0;

    if (strlen(name) <= 0){
        fprintf(stderr, "%s: cat's name cannot be empty\n", PROGRAM_NAME);
        return 0;
    }

    if (strlen(name) >= MAXLENGTH){
        fprintf(stderr, "%s: name must not be > %d characters\n", PROGRAM_NAME, MAXLENGTH);
        return 0;
    }

    for (i = 0; i < currentNumberCats; ++i){

        if (strcmp(name, cats[i].name) == 0){

            printf("cat match at index %d\n", i);
            return i;
        }

    }
    fprintf(stderr, "%s: cat is not there\n", PROGRAM_NAME);
    return 1;

}


#endif