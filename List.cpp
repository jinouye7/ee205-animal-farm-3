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


//Remove and return the first Node in the list

Node* List::pop_front() noexcept {

    if (head == nullptr) {
        return nullptr;
    }

    Node* temp = head;
    head = head -> next;
    count--;
    return temp;

}

// returns true if the node is in the list
bool List::isIn(Node* aNode) const {
    Node* currentNode = head;

    while (currentNode != nullptr) {
        if (aNode == currentNode) {
            return true;
        }
        currentNode = currentNode -> next;
    }

    return false;
}

//check to see if container is valid
bool List::validate() const noexcept {
    if (head == nullptr) {
        assert(size() == 0);
    } else {
        assert(size() != 0);
    }

    // count forward through the list
    unsigned int forwardCount = 0;
    Node* currentNode = head;
    while (currentNode != nullptr) {
        forwardCount++;
        currentNode = currentNode -> next;
    }
    //cout << forwardCount << endl;
    assert(size() == forwardCount);

    return true;
}

//output the contents of the container
void List::dump() const noexcept{
    Node* currentNode = head;
    while (currentNode != nullptr){
        currentNode->dump();
        currentNode = currentNode -> next;
    }

}

//delete all nodes in the list
void List::deleteAllNodes() noexcept{
    validate();
    Node* currentNode = head;
    while (currentNode != nullptr){
        pop_front();
        currentNode = currentNode -> next;
    }
    validate();
}