///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_10d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file catDatabase.cpp
/// @version 1.0
///
/// @author Jared Inouye <jinouye7@hawaii.edu>
/// @date   29_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include<memory.h>
#include<stdio.h>
#include<time.h>
#include <stdbool.h>


#include <cstring>
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <cassert>

#include "config.h"
#include "catDatabase.h"
#include "Cats.h"

using namespace std;

///////// setting up linked list for cat database////////////////////////////////////

/// initialize number of cats
NumCats currentNumberCats = 0;
/// head pointer
Cats* catDatabaseHeadPointer = nullptr ;

///////// database validation /////////////////////////////////////////////////////
extern bool validateDatabase() {
    int validCats = 0 ;

    /// revalidate all the cats in the list
    for(Cats* i = catDatabaseHeadPointer ; i != nullptr ; i = i->next ) {
        if( !i->validate() ) {
            return false ;
        }

        validCats++ ;
    }

    if( validCats != currentNumberCats ) {
        cerr << PROGRAM_NAME << ": Error:  numberOfCats [" << currentNumberCats
             << "] does not equal [" << validCats << "]" << endl ;
        return false ;
    }

    cout << PROGRAM_NAME << ": The database is valid." << endl ;

    return true ;  // The database is healthy
}

////////////////////////////////////// old code /////////////////////////////////////////////////////
struct Cat cats[MAXCATS];


//returns string counterpart for gender enum
char* genderName (const enum Gender gender) {

    char* strGender;

    switch (gender) {

        case 0: strGender = "Unknown Gender";
            break;

        case 1: strGender = "Male";
            break;

        case 2: strGender = "Female";
            break;

    }

    return strGender;

}



//returns string counterpart for breed enum

char* breedName (const enum Breed breed) {

    char* strBreed;

    switch (breed) {

        case 0: strBreed = "Unknown Breed";
            break;

        case 1: strBreed = "Main Coon";
            break;

        case 2: strBreed = "Manx";
            break;

        case 3: strBreed = "Short Hair";
            break;

        case 4: strBreed = "Persian";
            break;

        case 5: strBreed = "Sphynx";
            break;

    }

    return strBreed;
}


//returns string counterpart for color enum

char* colorName (const enum Color color) {

    char* strColor;

    switch (color) {

        case 0: strColor = "Black";
            break;

        case 1: strColor = "White";
            break;

        case 2: strColor = "Red";
            break;

        case 3: strColor = "Blue";
            break;

        case 4: strColor = "Green";
            break;

        case 5: strColor = "Pink";
            break;

    }

    return strColor;
}


int birthdayToStruct(const int index, const char *date){

    char* months[] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};


    memset(&cats[index].birthday, 0, sizeof cats[index].birthday);  // set all fields to 0
    char str[4];
    sscanf(date,"%3s",str);
    int i=0;
    for(i=0; i<12; i++)
    {
        if(!strcmp(str,months[i]))
        {
            //printf("Your month number is: %d",i+1);
            int value;
            value = i +1 ;
            cats[index].birthday.tm_mon = value;
            //debug
            //printf("storedmonth: %d\n", cats[index].birthday.tm_mon);

        }


    }

    //* means it will be read but not stored
    sscanf(date, "%*s %d, %d", &cats[index].birthday.tm_mday, &cats[index].birthday.tm_year);

    //debug
    //printf("storedday: %d\n", cats[index].birthday.tm_mday);
    //printf("storedyear: %d\n", cats[index].birthday.tm_year);


    // Adjust to struct tm references
    cats[index].birthday.tm_year -= 1899;
    cats[index].birthday.tm_mon--;

    return 0;
}


int structToDate(const int index){
    //char buf[200];
    //strftime(buf, 200, "struct birthday: %a %b %d %r %Z %G\n", &cats[index].birthday);
    //puts(buf);

    int year;
    int month;
    int day;

    year = cats[index].birthday.tm_year + 1899;
    month = cats[index].birthday.tm_mon + 1;
    day = cats[index].birthday.tm_mday;

    printf("birthday = [%d/%d/%d]\n", day, month, year);



    return 0;
}
