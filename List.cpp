///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal-farm-3 - EE 205 - Spr 2022
///
/// @file List.cpp
/// @version 1.0
///
/// @author Jared Inouye <jinouye7@hawaii.edu>
/// @date   19_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include <cassert>
#include "config.h"
#include "List.h"

using namespace std;

//checks if list is empty
bool List::empty() const noexcept {
    if(head == nullptr){
        return true;
    }
    return false;
}

//gives size of list
unsigned int List::size() const noexcept {
    return count;
}

//get the first node in the list
Node* List::get_first() const noexcept {
    if(!empty()){
        return head;
    }
    return nullptr;
}

//get the next node in the list
 Node* List::get_next(const Node* currentNode) {
    return currentNode->next;
}


