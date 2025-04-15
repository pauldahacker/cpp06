#include "ScalarConverter.hpp"

/*
https://en.wikipedia.org/wiki/IEEE_754-1985#Representation_of_non-numbers
https://www.doc.ic.ac.uk/~eedwards/compsys/float/nan.html

IEEE 754 standard:
INFINITY:
	sign = 0 for positive infinity, 1 for negative infinity.
	biased exponent = all 1 bits.
	fraction = all 0 bits.
NAN (Not a Number):
	sign = either 0 or 1.
	biased exponent = all 1 bits.
	fraction = anything except all 0 bits (since all 0 bits represents infinity).
All NaNs meet the condition that they are not equal to themselves.
*/
bool	isNan(double d)
{
	return (d != d);
}

/*
To check for infinity, first check that x != NaN.
The IEEE 754 has undefined operations, such as inf - inf, 0 / 0, etc.
-> if x is (+-)infinity, x - x = NaN.
*/
bool	isInf(double d)
{
	return (!isNan(d) && isNan(d - d));
}

bool	isCharLiteral(std::string toConvert)
{
	return (toConvert.length() == 3 &&
		toConvert[0] == '\'' && toConvert[2] == '\'');
}

bool	isInt(std::string toConvert)
{
	char	*endPtr;
	long	tmp = std::strtol(toConvert.c_str(), &endPtr, 10);
	return (tmp <= INT_MAX && tmp >= INT_MIN && endPtr[0] == '\0');
}

/*
The bounds of floats are [-FLT_MAX, FLT_MAX]
(FLT_MIN = smallest float value > 0)
*/
bool	isFloat(std::string toConvert)
{
	char	*endPtr;
	double tmp = std::strtod(toConvert.c_str(), &endPtr);
	return (endPtr[0] == 'f'
		&& (isNan(tmp) || isInf(tmp) || (tmp >= -FLT_MAX && tmp <= FLT_MAX)));
}

void printChar(char c)
{
    if (std::isprint(c))
        std::cout << "'" << c << "'";
    else
        std::cout << "Non displayable";
    std::cout << std::endl;
}

void printFloat(float f)
{
    std::cout << f;
    if (f < E_NOTATION_MIN && std::floor(f) == f
        && !isNan(f) && !isInf(f))
        std::cout << ZERO_DECIMAL;
    std::cout << FLOAT_SUFFIX;
    std::cout << std::endl;
}

void printDouble(double d)
{
    std::cout << d;
    if (d < E_NOTATION_MIN && std::floor(d) == d
        && !isNan(d) && !isInf(d))
        std::cout << ZERO_DECIMAL;
    std::cout << std::endl;
}