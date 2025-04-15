#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    *this = other;
}

const ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return (*this);
}

static void printChar(char c)
{
    if (std::isprint(c))
        std::cout << "'" << c << "'";
    else
        std::cout << "Non displayable";
    std::cout << std::endl;
}

static void printFloat(float f)
{
    std::cout << f;
    if (f < E_NOTATION_MIN && std::floor(f) == f
        && !isNan(f) && !isInf(f))
        std::cout << ZERO_DECIMAL;
    std::cout << FLOAT_SUFFIX;
    std::cout << std::endl;
}

static void printDouble(double d)
{
    std::cout << d;
    if (d < E_NOTATION_MIN && std::floor(d) == d
        && !isNan(d) && !isInf(d))
        std::cout << ZERO_DECIMAL;
    std::cout << std::endl;
}

static bool isInRange(double val, int type)
{
    switch (type)
    {
        case (CHAR):
            return (val >= static_cast<double>(CHAR_MIN)
                && val <= static_cast<double>(CHAR_MAX));
        case (INT):
            return (val >= static_cast<double>(INT_MIN)
                && val <= static_cast<double>(INT_MAX));
        case (FLOAT):
            return (isNan(val) || isInf(val)
                || (val >= static_cast<double>(-FLT_MAX)
                && val <= static_cast<double>(FLT_MAX)));
    }
    return (true);
}

/*
This function is only used when we know toConvert is a char literal.
i.e. toConvert = "'c'", where c is any character.
*/
static void charConversion(std::string toConvert)
{
    char    c = toConvert[1];

    std::cout << "char: ";
    printChar(toConvert[1]);
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: ";
    printFloat(static_cast<float>(c));
    std::cout << "double: ";
    printDouble(static_cast<double>(c));
}

static void intConversion(std::string toConvert)
{
    int     i = std::strtol(toConvert.c_str(), NULL, 10);
    double  tmp = static_cast<double>(i);

    std::cout << "char: ";
    if (isInRange(tmp, CHAR))
        printChar(static_cast<char>(i));
    else
        std::cout << "Impossible" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: ";
    printFloat(static_cast<float>(i));
    std::cout << "double: ";
    printDouble(static_cast<double>(i));
}

static void floatConversion(std::string toConvert)
{
    double  tmp = std::strtod(toConvert.c_str(), NULL);
    float   f = static_cast<float>(tmp);

    std::cout << "char: ";
    if (isInRange(tmp, CHAR))
        printChar(static_cast<char>(f));
    else
        std::cout << "Impossible" << std::endl;
    std::cout << "int: ";
    if (isInRange(tmp, INT))
        std::cout << static_cast<int>(f) << std::endl;
    else
        std::cout << "Impossible" << std::endl;
    std::cout << "float: ";
    printFloat(f);
    std::cout << "double: ";
    printDouble(static_cast<double>(f));
}

static void doubleConversion(std::string toConvert)
{
    char    *endPtr;
    double  d = std::strtod(toConvert.c_str(), &endPtr);

    std::cout << "char: ";
    if (isInRange(d, CHAR) && endPtr[0] == '\0')
        printChar(static_cast<char>(d));
    else
        std::cout << "Impossible" << std::endl;
    std::cout << "int: ";
    if (isInRange(d, INT) && endPtr[0] == '\0')
        std::cout << static_cast<int>(d) << std::endl;
    else
        std::cout << "Impossible" << std::endl;
    std::cout << "float: ";
    if (isInRange(d, FLOAT) && endPtr[0] == '\0')
        printFloat(static_cast<float>(d));
    else
        std::cout << "Impossible" << std::endl;
    std::cout << "double: ";
    if (endPtr[0] == '\0')
        printDouble(d);
    else
        std::cout << "Impossible" << std::endl;
}

/*
First checks if toConvert represents a CHAR LITERAL (i.e. "'a'").
In this case, we can explicitly convert from CHAR to int, float and double.
Otherwise, we use strtod to check for the type of the literal passed as a parameter.
Check this out: https://cplusplus.com/reference/cstdlib/strtod/
Then we can convert from string to its actual type, and explicitly to the other types. 
*/
void ScalarConverter::convert(std::string toConvert)
{
    bool hasDecimalPoint = toConvert.find('.') != std::string::npos;

    if (isCharLiteral(toConvert))
        charConversion(toConvert);
    else if (!hasDecimalPoint && isInt(toConvert))
        intConversion(toConvert);
    else if (isFloat(toConvert))
        floatConversion(toConvert);
    else
        doubleConversion(toConvert);
}