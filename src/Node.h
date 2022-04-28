///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal-farm-3 - EE 205 - Spr 2022
///
/// @file Node.h
/// @version 1.0
///
/// @author Jared Inouye <jinouye7@hawaii.edu>
/// @date   19_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once
#include <iostream>
#include "config.h"

class Node {
    friend class 	List;
    friend class 	SinglyLinkedList;

    ///////////////////////////// public member functions//////////////////
public:
    virtual void dump() const; /// output the contents of this object

    virtual bool validate() const noexcept; ///check to see if Node is valid

    virtual bool 	operator> (const Node &rightSide); /// compare two nodes

    //////////////////////////// static protected Member Functions////////
protected:
    static bool 	compareByAddress (const Node *node1, const Node *node2);

    //////////////////////////// protected attributes/////////////////////
    Node* next = nullptr;  /// point to the next Node in the list or nullptr if its the last node


};


