///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal-farm-3 - EE 205 - Spr 2022
///
/// @file Mammal.h
/// @version 1.0
///
/// @author Jared Inouye <jinouye7@hawaii.edu>
/// @date   21_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "Animal.h"
#include "Color.h"


/// Mammals have more fun
class Mammal : public Animal {
public:   //////////////////////// Constants ///////////////////////////////////
    static const std::string MAMMAL_NAME;  ///< The scientific name for Mammals

protected:  ///////////////////////// Member Variables /////////////////////////
    Color color = Color::UNKNOWN_COLOR;  ///< The primary color of the Mammal

public:   /////////////////////// Constructors ////////////////////////////////
    /// Create a Mammal with the *minimum* required fields
    Mammal( const Weight::t_weight newMaxWeight
            ,const std::string&     newSpecies
    ) : Animal( newMaxWeight, MAMMAL_NAME, newSpecies ) {};

    /// Create a Mammal, populating *all* of the member variables
   Mammal( const Color            newColor
            ,const Gender           newGender
            ,const Weight::t_weight newWeight
            ,const Weight::t_weight newMaxWeight
            ,const std::string&     newSpecies
    ) : Animal( newGender, newWeight, newMaxWeight, MAMMAL_NAME, newSpecies ) {
        setColor( newColor );
    };


public:  ////////////////////////// Getters & Setters //////////////////////////
    Color getColor() const noexcept { return color; }  ///< Get the color
    void setColor( const Color newColor ) noexcept { color = newColor; }  ///< Set the color

public:  /////////////////////////// Public Methods ////////////////////////////
    void dump() const noexcept override;  ///< Print the contents of this object (and its parents)
};
