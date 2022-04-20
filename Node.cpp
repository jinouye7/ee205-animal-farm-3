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

static bool compareByAddress (const Node *node1, const Node *node2){
    if (&node1 > &node2) {
        return true;
    }
    return false;
}

bool Node::operator>(const Node& rightSide) {
    // "this" is the objects own address and the leftSide of the operator, so compare:
    // leftSide > rightSide

    if (this > &rightSide) {
    return true;
    }
    return false;
}

void Node::dump() const {
   // FORMAT_LINE_FOR_DUMP( "Node", "this" ) << this << std::endl ;
  //  FORMAT_LINE_FOR_DUMP( "Node", "next" ) << next << std::endl ;

}

bool Node::validate	(	)	const{

}
