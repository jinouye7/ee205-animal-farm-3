///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file SinglyLinkedList.cpp
/// @version 1.0
///
/// @author Jared Inouye <jinouye7@hawaii.edu>
/// @date   21_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include <cassert>
#include <iostream>
#include "SinglyLinkedList.h"
#include "config.h"

//make a new singly linked list
SinglyLinkedList::SinglyLinkedList() {
    assert( SinglyLinkedList::validate() );
}

//check to see if the container is valid
bool SinglyLinkedList::validate() const noexcept {
   ///@todo if this returns false, return false now
    List::validate();

    // count forward through the list
    unsigned int forwardCount = 0;
    Node* currentNode = head;
    while (currentNode != nullptr) {
        assert(currentNode->validate());
        forwardCount++;
        currentNode = currentNode -> next;
    }
    //cout << forwardCount << endl;
    assert(size() == forwardCount);

    return true;
}


Node* SinglyLinkedList::pop_front() noexcept {

    if (head == nullptr) {
        return nullptr;
    }

    Node* temp = head;
    head = head -> next;
    count--;
    return temp;

}

//output the contents of the container
void SinglyLinkedList::dump() const noexcept{
    Node* currentNode = head;
    while (currentNode != nullptr){
        currentNode->dump();
        currentNode = currentNode -> next;
    }

}