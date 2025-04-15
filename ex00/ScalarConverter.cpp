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

/*
https://cplusplus.com/reference/cstdlib/strtod/
std::strtof() was added in C++99
*/
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
    if (endPtr[0] == '\0' || endPtr[0] == 'f')
        printDouble(d);
    else
        std::cout << "Impossible" << std::endl;
}

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