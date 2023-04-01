//
// Created by admin on 3/12/2023.
//

#ifndef ASSIGNMENT03_RATIONALNUMBER_H
#define ASSIGNMENT03_RATIONALNUMBER_H
#define DEFAULT_DENOMINATOR 1
#define DEFAULT_NUMERATOR 0

#define WHOLE_NUM_REGEX_PATTERN "(^-?\\d+$)"
#define FRACTION_REGEX_PATTERN "(^-?\\d+\\/?-?[1-9]*$)"

#include <string>
#include <iostream>
#include <regex>

using namespace std;

class RationalNumber{

private:
    int             numerator; // to convert numeratorStr to
    int             denominator; // to convert denominatorStr to


public:

    // CONSTRUCTORS

    // Default Constructor
    RationalNumber();


    // Whole Number Constructor
    RationalNumber(int wholeNum);


    // Numerator and Denominator Constructor
    RationalNumber(int numerator, int denominator);


    // String Constructor for either whole or numerator or denominator
    RationalNumber(std::string number);

    // destructor
    ~RationalNumber();



    // GETTERS AND SETTERS

    // getter and setter for numerator
    void setNumerator(std::string& numerator);

    int getNumerator() const;


    // getter and setter for denominator
    void setDenominator(std::string& denominator);

    int getDenominator() const;


    // method to split the string
    void splitStringInput(std::string& input);

    // method to validate Number Input
    bool isValidNumber(std::string& numInput); // for a single number str

    // method to convert string to int
    int convertStrToInt(std::string& numberStr);


    // method to find the greatest common denominator
    int findGCD(int numerator, int denominator);

    // method to find the lowest common multiple
    int findLCM(int numerator, int denominator);

    // method to get the lowest fraction
    void lowestFraction();


    // OVERLOADS

    // less than overload
    bool operator < (const RationalNumber& rn2);

    // greater than overload
    bool operator > (const RationalNumber& rn2);

    // equals overload
    bool operator == (const RationalNumber& rn2);

    // multiplication overload
    RationalNumber operator * (RationalNumber& rn2);

    // division overload
    RationalNumber operator / (RationalNumber& rn2);

    // addition overload
    RationalNumber operator + (RationalNumber& rn2);

    // subtraction overload
    RationalNumber operator - (RationalNumber& rn2);

    void commonDenominator (int &numerator, int &denominator);


    // Friend Function
    friend std::ostream& operator << (std::ostream& osStream, const RationalNumber rn);

};



#endif //ASSIGNMENT03_RATIONALNUMBER_H
