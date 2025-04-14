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
}

static void printFloat(float f)
{
    if (f != f)
        std::cout << "nan";
    else
    {
        std::cout << f;
        if (f == static_cast<int>(f))
            std::cout << ZERO_DECIMAL;   
    }
    std::cout << FLOAT_SUFFIX;
}

static void printDouble(double d)
{
    if (d != d)
        std::cout << "nan";
    else
    {
        std::cout << d;
        if (d == static_cast<int>(d))
            std::cout << ZERO_DECIMAL;   
    }
}

static void charConversion(double val, char *endPtr)
{
    std::cout << "char: ";
    if (val >= CHAR_MIN && val <= CHAR_MAX && val == val
        && (endPtr[0] == '\0' || endPtr[0] == 'f'))
        printChar(static_cast<char>(val));
    else
        std::cout << "Impossible";
    std::cout << std::endl;
}

static void charLiteralConversion(char c)
{
    std::cout << "char: ";
    printChar(c);
    std::cout << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: ";
    printFloat(static_cast<float>(c));
    std::cout << std::endl;
    std::cout << "double: ";
    printDouble(static_cast<double>(c));
    std::cout << std::endl;
}

static void intConversion(double val, char *endPtr)
{
    std::cout << "int: ";
    if (val >= INT_MIN && val <= INT_MAX && val == val
        && (endPtr[0] == '\0' || endPtr[0] == 'f'))
        std::cout << static_cast<int>(val);
    else
        std::cout << "Impossible";
    std::cout << std::endl;
}

void ScalarConverter::convert(std::string toConvert)
{
    char    *endPtr;

    if (toConvert.length() == 3 && toConvert[0] == '\'' && toConvert[2] == '\'')
        return (charLiteralConversion(toConvert[1]));
    double val = std::strtod(toConvert.c_str(), &endPtr);
    charConversion(val, endPtr);
    std::cout << "int: " << std::endl;
    std::cout << "float: " << std::endl;
    std::cout << "double: " << std::endl;
}