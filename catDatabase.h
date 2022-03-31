///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_10d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file catDatabase.h
/// @version 1.0
///
/// @author Jared Inouye <jinouye7@hawaii.edu>
/// @date   29_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once
#include <stdbool.h>
#include <time.h>
#define MAXLENGTH 50
#define MAXCATS 1024

enum Gender { UNKNOWN_GENDER = 0, MALE = 1, FEMALE = 2 };

enum Breed {UNKNOWN_BREED, MAINE_COON, MANX, SHORTHAIR, PERSIAN, SPHYNX};

enum Color {BLACK, WHITE, RED, BLUE, GREEN, PINK};

typedef float Weight;

typedef int NumCats;

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

    /// Zero out all of the member data
 //   virtual ~Cats();

public: /// Getters and Setters
    const char *getName() const noexcept ; /// Get the Cat's name
    void setName( const char* newName );   /// Set the Cat's name.  The name
    /// must not be empty and it must
    /// be <= MAX_CAT_NAME in length.

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

/// Declaring a Cat struct
struct Cat {
    char name[MAXLENGTH];
    enum Gender gender;
    enum Breed breed;
    bool isFixed;
    Weight weight;
    enum Color collarColor1;
    enum Color collarColor2;
    unsigned long long license;
    struct tm birthday;
};

extern struct Cat cats[MAXCATS];

extern NumCats currentNumberCats;


/// Functions that return a string for the name of the gender, color, and cat breeds
char* genderName (const enum Gender gender);
char* colorName (const enum Color color);
char* breedName (const enum Breed breed);
// Function to convert a string like " May 4, 2000" to a struct tm
int birthdayToStruct( const int index, const char *date);
//convert struct back to date
int structToDate(const int index);