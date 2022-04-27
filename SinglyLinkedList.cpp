///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal-farm-3 - EE 205 - Spr 2022
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
    std::cout << "Singly Linked List:  " << "head = [" << head << "]" <<std::endl;
}

//check to see if the container is valid
bool SinglyLinkedList::validate() const noexcept {

    if(!List::validate()){
        return false;
    }

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

//remove and return first Node in the List
Node* SinglyLinkedList::pop_front() noexcept {

    if (head == nullptr) {
        return nullptr;
    }

    Node* temp = head;
    head = head -> next;
    count--;
    SinglyLinkedList::validate();
    return temp;

}

//insert newNode to the beginning of the list
void SinglyLinkedList::push_front(Node* newNode) {
    if (newNode == nullptr) {
        return;
    }

    if (head != nullptr) {
        newNode -> next = head;
        head = newNode;
    } else {
        newNode -> next = nullptr;
        head = newNode;
    }
    count++;
    SinglyLinkedList::validate();
}


//insert newNode after the currentNode
void SinglyLinkedList::insert_after(Node* currentNode, Node* newNode) {
    if(List::empty()){
        throw std::logic_error(PROGRAM_NAME ": List is empty. Cannot insert after");
    }
    if (currentNode == nullptr) {
        throw std::invalid_argument(PROGRAM_NAME ": Cannot insert newNode after nullptr");
    }

    if (newNode == nullptr) {
        throw std::invalid_argument(PROGRAM_NAME ": newNode cannot be nullptr");
    }
    // checking if the nodes are in the list
    if(!isIn(currentNode)){
        throw std::logic_error( PROGRAM_NAME ": currentNode not in the list");
    }
    if(isIn(newNode)){
        throw std::logic_error( PROGRAM_NAME " newNode is already in the list");
    }
    //validate new node
    if(!newNode->validate()){
        throw std::domain_error( PROGRAM_NAME " newNode is not valid");
    }

    //insert newNode after currentNode
        newNode -> next = currentNode -> next;
        currentNode -> next = newNode;

        count++;

        SinglyLinkedList::validate();


}

//output the contents of the container
void SinglyLinkedList::dump() const noexcept{
    Node* currentNode = head;
    while (currentNode != nullptr){
        currentNode->dump();
        currentNode = currentNode -> next;
    }

}

