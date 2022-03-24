///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file updateCats.h
/// @version 1.0
///
/// @author Jared Inouye <jinouye7@hawaii.edu>
/// @date   09_Mar_2022
///////////////////////////////////////////////////////////////////////////////
int updateCatName(const int index, const char newName[]);
int fixCat(const int index);
int updateCatWeight(const int index, const Weight newWeight);
int updateCatCollar1(const int index, const enum Color newColor1);
int updateCatCollar2(const int index, const enum Color newColor2);
int updateLicense(const int index, const unsigned long long license);
int updateBirthday(const int index, const char *date);

