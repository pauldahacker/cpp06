#include "ScalarConverter.hpp"

/*
In IEEE 754 standard, when a double (d) is NaN (Not a Number),
it meets the condition that d != d.
*/
bool	isNan(double d)
{
	return (d != d);
}

bool	isInf(double d)
{
	return (isNan(d - d));
}