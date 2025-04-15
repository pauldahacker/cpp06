#include "ScalarConverter.hpp"

/*
https://en.wikipedia.org/wiki/IEEE_754-1985#Representation_of_non-numbers
https://www.doc.ic.ac.uk/~eedwards/compsys/float/nan.html

In IEEE 754 standard,
INFINITY is defined as:
	sign = 0 for positive infinity, 1 for negative infinity.
	biased exponent = all 1 bits.
	fraction = all 0 bits.
NANs (Not a Number) are defined as:
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
To check for infinity, it makes sense to first check that a value (x) != NaN.
The IEEE 754 standard has undefined operations, such as inf - inf, 0 / 0, etc.
Thus, the CPU is designed to detect these cases.
Knowing this: if x is infinity, then x - x results in a NaN.
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
Since floats work with a sign bit, the bounds of floats are
[-FLT_MAX, FLT_MAX], and not [FLT_MIN, FLT_MAX].
FLT_MIN = the smallest positive value representable as a float.
*/
bool	isFloat(std::string toConvert)
{
	char	*endPtr;
	double tmp = std::strtod(toConvert.c_str(), &endPtr);
	return (endPtr[0] == 'f'
		&& (isNan(tmp) || isInf(tmp) || (tmp >= -FLT_MAX && tmp <= FLT_MAX)));
}
