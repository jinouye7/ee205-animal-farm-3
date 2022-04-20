///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal-farm-3 - EE 205 - Spr 2022
///
/// @file Node.cpp
/// @version 1.0
///
/// @author Jared Inouye <jinouye7@hawaii.edu>
/// @date   19_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include "Node.h"

static bool compareByAddress (const Node *node1, const Node *node2);

bool Node::operator>(const Node& rightSide) {
    // this is the leftSide of the operator, so compare:
    // leftSide > rightSide

    if (this > &rightSide)
        return true;
    return false;
}