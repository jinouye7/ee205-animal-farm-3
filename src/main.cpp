///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal-farm-3 - EE 205 - Spr 2022
///
/// @file main.cpp
/// @version 1.0
///
/// @author Jared Inouye <jinouye7@hawaii.edu>
/// @date   31_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <iostream>
#include <exception>
#include "Animal.h"
#include "Gender.h"
#include "Cats.h"
#include "SinglyLinkedList.h"
#include "config.h"
#define DEBUG
#define MAX_NAME "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwx"
#define ILLEGAL_NAME "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxy"
//#define BIRTHDAY
//#define OLD

using namespace std ;


int main() {

    cout << "Starting " << PROGRAM_TITLE << endl ;
    SinglyLinkedList catDB ;
    catDB.push_front( new Cats( "Loki", Color::CREAM, true, Gender::MALE, 1 ) ) ;
    catDB.push_front( new Cats( "Milo", Color::BLACK, true, Gender::MALE, 1.1 ) ) ;
    catDB.push_front( new Cats( "Bella", Color::BROWN, true, Gender::FEMALE, 1.2 ) ) ;
    catDB.push_front( new Cats( "Kali", Color::CALICO, true, Gender::FEMALE, 1.3 ) ) ;
    catDB.push_front( new Cats( "Trin", Color::WHITE, true, Gender::FEMALE, 1.4 ) ) ;
    catDB.insert_after(catDB.get_first(), new Cats( "Chili", Color::GINGER, true,
                                                   Gender::MALE, 1.5 ) );
    for( Animal* pAnimal = (Animal*)catDB.get_first() ; pAnimal != nullptr ; pAnimal =
                                                                                     (Animal*)List::get_next( (Node*)pAnimal ) ) {
        cout << pAnimal->speak() << endl;
    }
    catDB.validate() ;
    catDB.dump() ;
    catDB.deleteAllNodes() ;
    catDB.dump() ;
    cout << "Done with " << PROGRAM_TITLE ;
    return( EXIT_SUCCESS ) ;

#ifdef DEBUG
    std::cout << Color::UNKNOWN_COLOR << endl;
    std::cout << Color::BLACK << endl;
    std::cout << Color::BROWN << endl;
    std::cout << Color::WHITE << endl;
    std::cout << Color::RED << endl;
    std::cout << Color::BLUE << endl;
    std::cout << Color::GREEN << endl;
    std::cout << Color::GINGER << endl;
    std::cout << Color::CREAM << endl;
    std::cout << Color::CINNAMON << endl;
    std::cout << Color::CALICO << endl;

    Node testnode1;
    Node testnode2;

    testnode1.dump();
    testnode2.dump();
    std::cout << testnode1.operator>(testnode2) << endl;

    std::cout<<"testing SinglyLinkedList"<<endl;

    SinglyLinkedList testList1;

    testList1.push_front(&testnode1);
    testList1.push_front(&testnode2);
    testList1.push_front(new Node);
    testList1.push_front(new Node);
    testList1.insert_after(&testnode1, new Node);

    testList1.dump();

    std::cout<<"testing popfront"<<endl;

    testList1.pop_front();
    testList1.dump();


    //Animal(Gender::MALE, 30, 40, "Mammalia", "Cat");




#endif

    return 0;
}


