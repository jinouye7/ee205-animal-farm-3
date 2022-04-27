///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal-farm-3 - EE 205 - Spr 2022
///
/// @file Cats.h
/// @version 1.0
///
/// @author Jared Inouye <jinouye7@hawaii.edu>
/// @date   16_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>
#include <cassert>
#include "config.h"
#include "Gender.h"
#include "Color.h"
#include "Node.h"
#include "Mammal.h"


//enum Breed {UNKNOWN_BREED, MAINE_COON, MANX, SHORTHAIR, PERSIAN, SPHYNX};




/// declaring a Cat class

class Cats : public Mammal {
public:/// Constants
    static const std::string      SPECIES_NAME;  ///< The scientific name for this species
    static const Weight::t_weight MAX_WEIGHT;
protected:
    /// Member Variables\
    /// @todo change to std
    std::string name;
    //enum Gender gender;
    //enum Breed breed;
    bool isFixed;
    //float weight;

public:  /// Public Member Variables
    Cats* next; ///next pointer for linked list

public:   /// Constructors
   /// Create a Cat with the minimum fields necessary to have a valid Cat
   explicit Cats( const std::string& newName ) : Mammal( MAX_WEIGHT, SPECIES_NAME ) {
       if( !validateName( newName) ) {
           /// @throws out_of_range If the Cat doesn't have a name
           throw std::out_of_range( "Cats must have a name" );
       }
       name = newName;
       isFixed = false;

       assert(Cats::validate());
   }

    ///create a valid cat
    Cats( const std::string&     newName
            ,const Color            newColor
            ,const bool             newIsFixed
            ,const Gender           newGender
            ,const Weight::t_weight newWeight
    ) : Mammal( newColor, newGender, newWeight, MAX_WEIGHT, SPECIES_NAME ) {
        if( !validateName( newName) ) {
            /// @throws out_of_range If the Cat doesn't have a name
            throw std::out_of_range( "Cats must have a name" );
        }
        name = newName;
        isFixed = newIsFixed;

        assert(Cats::validate());
        std::cout << "cat added " << std::endl;
    }


public: /// Getters and Setters
    std::string getName() const noexcept ; /// Get the Cat's name
    void setName( const std::string& newName );   /// Set the Cat's name
   // Gender getGender() const noexcept ;  /// Get the Cat's gender
   // Breed getBreed() const noexcept ;    /// Get the Cat's breed
    bool isCatFixed() const noexcept ;      /// Return true if the cat is fixed
    void fixCat() noexcept ;             /// Spay or neuter the cat
   // float getWeight() const noexcept ;  /// The weight of the cat or -1 if unknown
   // void setWeight(float newWeight) ;   /// Set the newWeight of the cat

protected: ///Protected Methods (setters for gender and breed)
public:
  //  void setGender(Gender newGender);  /// Set the cat's gender
  //  void setBreed(Breed newBreed);  /// Set the cat's breed

public: /// Public Methods
    std::string speak() const noexcept override;
    void dump() const noexcept override; ///output contents of container
    bool validate() const noexcept; ///check to see if the Cat object is valid

public: /// Static Public Methods
    static bool validateName( const std::string &newName ) ;  /// Check if `newName` is valid
    //static bool validateGender( const Gender newGender ) ; /// Check if `newGender` is valid
    //static bool validateBreed( const Breed newBreed ) ; /// Check if 'newBreed` is valid
    //static bool validateWeight( const float newWeight ) ; /// Check if `newWeight` is valid

};

