///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab10d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file Cats.h
/// @version 1.0
///
/// @author Jared Inouye <jinouye7@hawaii.edu>
/// @date   31_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once
#include "config.h"
#include "Gender.h"
#include "Color.h"
#include "Node.h"

//enum Gender { UNKNOWN_GENDER = 0, MALE = 1, FEMALE = 2 };

enum Breed {UNKNOWN_BREED, MAINE_COON, MANX, SHORTHAIR, PERSIAN, SPHYNX};

//enum Color {BLACK, WHITE, RED, BLUE, GREEN, PINK};



/// declaring a Cat class

class Cats {
protected:
    /// Member Variables
    char name[MAXLENGTH];
    enum Gender gender;
    enum Breed breed;
    bool isFixed;
    Weight weight;

public:  /// Public Member Variables
    Cats* next; ///next pointer for linked list

private:  /// Private Methods
    void zeroOutMemberData();  ///zero out member data

public:   /// Constructors
    Cats();  /// create cat with default values

    ///create a valid cat
    Cats(const char *newName, const Gender newGender, const Breed newBreed, const Weight newWeight);


public: /// Getters and Setters
    const char *getName() const noexcept ; /// Get the Cat's name
    void setName( const char* newName );   /// Set the Cat's name
    Gender getGender() const noexcept ;  /// Get the Cat's gender
    Breed getBreed() const noexcept ;    /// Get the Cat's breed
    bool isCatFixed() const noexcept ;      /// Return true if the cat is fixed
    void fixCat() noexcept ;             /// Spay or neuter the cat
    Weight getWeight() const noexcept ;  /// The weight of the cat or -1 if unknown
    void setWeight(Weight newWeight) ;   /// Set the newWeight of the cat

protected: ///Protected Methods (setters for gender and breed)
public:
    void setGender(Gender newGender);  /// Set the cat's gender
    void setBreed(Breed newBreed);  /// Set the cat's breed

public: /// Public Methods
    bool print() const noexcept; /// Print cat
    bool validate() const noexcept; ///check to see if the Cat object is valid

public: /// Static Public Methods
    static bool validateName( const char* newName ) ;  /// Check if `newName` is valid
    static bool validateGender( const Gender newGender ) ; /// Check if `newGender` is valid
    static bool validateBreed( const Breed newBreed ) ; /// Check if 'newBreed` is valid
    static bool validateWeight( const Weight newWeight ) ; /// Check if `newWeight` is valid


};

