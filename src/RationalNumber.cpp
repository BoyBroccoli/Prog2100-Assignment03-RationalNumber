//
// Created by admin on 3/12/2023.
//
#import "../inc/RationalNumber.h"


// DEFINING CONSTRUCTORS

// Default Constructor
RationalNumber::RationalNumber()
{
    std::cout<<"DEFAULT CONSTRUCTOR CALLED"<<endl;
    this->numerator=DEFAULT_NUMERATOR;
    this->denominator=DEFAULT_DENOMINATOR;
}


// Whole Number Constructor
RationalNumber::RationalNumber(int wholeNum)
{
    std::cout<<"WHOLE NUMBER CONSTRUCTOR CALLED"<<endl;
    if(wholeNum < 0){
        this->denominator= DEFAULT_DENOMINATOR * -1;
        this->numerator = wholeNum;
    } else {
        this->numerator=wholeNum;
        this->denominator= DEFAULT_DENOMINATOR;
    }

}


// Numerator and Denominator Constructor
RationalNumber::RationalNumber(int numerator, int denominator)
{
    std::cout<<"NUMERATOR AND DENOMINATOR CONSTRUCTOR CALLED"<<endl;
    if (numerator < 0 ){
        this->numerator = numerator;
        this->denominator = denominator * -1;
    } else if (denominator < 0){
        this->numerator = numerator * -1;
        this->denominator = denominator;
    } else {
        this->numerator=numerator;
        this->denominator=denominator;
    }

}


// String Constructor for either whole or numerator or denominator
RationalNumber::RationalNumber(std::string number)
{
    std::cout<<"STRING CONSTRUCTOR CALLED"<<endl;
    splitStringInput(number);
}


// Deconstructor
RationalNumber::~RationalNumber()
{

}


// DEFINING GETTERS AND SETTERS

// getter and setter for numerator
void RationalNumber::setNumerator(std::string& numerator) {
    this->numerator = std::stoi(numerator); // converting string to int
}

int RationalNumber::getNumerator() const
{
    return numerator;
}


// getter and setter for denominator
void RationalNumber::setDenominator(std::string& denominator)
{
    this->denominator = std::stoi(denominator); // converting string to int
}

int RationalNumber::getDenominator() const
{
    return denominator;
}

// method to convert string to int
int RationalNumber::convertStrToInt(std::string& numberStr)
{
    return std::stoi(numberStr);
}


// Defining splitString Method
void RationalNumber::splitStringInput(std::string& input)
{
    // source: https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
    size_t delimiterPosition = input.find("/");

    std::string numerator =input.substr(0, delimiterPosition);
    std::string denominator = input.substr(delimiterPosition +1);

    int convertedNumerator = convertStrToInt(numerator);
    int convertedDenominator = convertStrToInt(denominator);

    if(convertedNumerator < 0 ) // if numerator is negative
    {
        this->setNumerator(numerator);
        denominator = "-" + denominator; // converting to negative
        this->setDenominator(denominator);
    } else if (convertedDenominator < 0){ // if denominator is negative

        numerator = "-"+numerator; // converting to negative
        this->setNumerator(numerator);
        this->setDenominator(denominator);
    } else { // if both are positive or both negative

        this->setNumerator(numerator);
        this->setDenominator(denominator);
    }

}


// Defining findGCD
int RationalNumber::findGCD(int numerator, int denominator)
{
    if(denominator == 0){
        return numerator;
    } else {
        return findGCD(denominator, numerator % denominator);
    }
}

// Defining lowest Fraction
void RationalNumber::lowestFraction()
{
    int lowestDenom = findGCD(this->numerator, this->denominator);
    this->numerator /= lowestDenom;
    this->denominator /= lowestDenom;
}

// Defining common Denominator
void RationalNumber::commonDenominator(int &numerator, int &denominator)
{
    int lowestDenom = findGCD(numerator,denominator);
    this->numerator /= lowestDenom;
    this->denominator /= lowestDenom;
}

// Defining lowest common multiple
int RationalNumber::findLCM(int numerator, int denominator)
{
    int gcd = findGCD(this->denominator, denominator);
    return (this->denominator * denominator) / gcd;

}

// OVERLOADS


// Less than Comparison Overload
bool RationalNumber:: operator < (const RationalNumber& rn2)
{
    // checking to make sure denominators are positive
    if(this->denominator > 0 && rn2.denominator > 0){

        if((this->numerator * rn2.denominator) < (rn2.numerator * this->denominator)) {

            return true;
        }
    } else { // if not positive then it is less than

        return true;
    }
}

// Greater than Comparison Overload
bool RationalNumber:: operator > (const RationalNumber& rn2)
{
    // checking to make sure denominators are positive
    if(this->denominator > 0 && rn2.denominator > 0){

        if((this->numerator * rn2.denominator) > (rn2.numerator * this->denominator)) {

            return true;
        }
    } else { // if not positive then it is less than

        return false;
    }
}

// Equals Comparison Overload
bool RationalNumber:: operator == (const RationalNumber& rn2)
{
    // checking to make sure denominators are positive
    if(this->denominator > 0 && rn2.denominator > 0){

        if((this->numerator * rn2.denominator) == (rn2.numerator * this->denominator)) { // if they exactly equal

            return true;
        }
    } else { // if not positive then it is less than

        return false;
    }
}


// Defining Validation Method
bool RationalNumber::isValidNumber(std::string& numInput)
{

    try
    {
        const std::regex wholeNumRegex(WHOLE_NUM_REGEX_PATTERN);
        const std::regex fractionNumRegex(FRACTION_REGEX_PATTERN);

        if(std::regex_match(numInput, wholeNumRegex)) // if wholeNumRegex is true
        {
            int convertedNum = convertStrToInt(numInput);
            if(convertedNum < 0) // if negative
            {
                this->setNumerator(numInput);
                this->denominator=DEFAULT_DENOMINATOR * -1;

                return true;
            } else {
                this->setNumerator(numInput);
                this->denominator=DEFAULT_DENOMINATOR;

                return true;
            }
        } else if(std::regex_match(numInput, fractionNumRegex)) // if fraction is true
        {
            // split
             this->splitStringInput(numInput);

             return true;

        } else {
            return false;
        }

    }
    catch (const std::regex_error& e){
        std::cout<<"Regex Error Caught: " <<e.what()<<endl;
    }

}

// Multiplication Overload Definition
RationalNumber RationalNumber::operator*(RationalNumber &rn2)
{
    int rn3Numerator = this->numerator * rn2.numerator;
    int rn3Denominator = this->denominator * rn2.denominator;

    //commonDenominator(rn3Numerator, rn3Denominator); // setting the lowest common denominator

    return RationalNumber(rn3Numerator, rn3Denominator);

}


// Division Overload Definition
RationalNumber RationalNumber::operator/(RationalNumber &rn2)
{

    if (rn2.denominator == 0){

        return RationalNumber(); // default constructor
    } else {
        // Creating the reciprocal of rn2
//        int tempNumerator = rn2.numerator;
//        rn2.numerator = rn2.denominator;
//        rn2.denominator = tempNumerator;

        int rn3Numerator = this->numerator * rn2.denominator;
        int rn3Denominator = this->denominator * rn2.numerator;

        //commonDenominator(rn3Numerator, rn3Denominator);

        return RationalNumber(rn3Numerator, rn3Denominator);
    }
}

// Addition Overload Definition
RationalNumber RationalNumber::operator+(RationalNumber &rn2)
{
    int rn3Numerator = (this->numerator * rn2.denominator) + (rn2.numerator * this->denominator);
    int rn3Denominator = this->denominator * rn2.denominator;

    commonDenominator(rn3Numerator, rn3Denominator);

    return RationalNumber(rn3Numerator, rn3Denominator);
}


// Subtraction Overload Definition
RationalNumber RationalNumber::operator-(RationalNumber &rn2)
{
    int rn3Numerator = (this->numerator * rn2.denominator) - (rn2.numerator * this->denominator);
    int rn3Denominator = this->denominator * rn2.denominator;

    commonDenominator(rn3Numerator, rn3Denominator);

    return RationalNumber(rn3Numerator, rn3Denominator);
}

// Defining Friend Function
std::ostream& operator << (std::ostream& osStream, const RationalNumber rn)
{
    osStream<<rn.numerator << "/" << rn.denominator;
    return osStream;
}

