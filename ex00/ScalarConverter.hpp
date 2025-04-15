#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <cctype>
# include <climits>
# include <cfloat>
# include <cmath>

# define E_NOTATION_MIN 1e+06
# define ZERO_DECIMAL ".0"
# define FLOAT_SUFFIX "f"

// TYPES
# define CHAR 0
# define INT 1
# define FLOAT 2
# define DOUBLE 3

class ScalarConverter
{
    public:
        static void convert(std::string toConvert);
    private:
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter &other);
        ~ScalarConverter(void);

        const ScalarConverter &operator=(const ScalarConverter &other);
};

// Utils.cpp
bool	isNan(double d);
bool	isInf(double d);
bool	isCharLiteral(std::string toConvert);
bool	isInt(std::string toConvert);
bool	isFloat(std::string toConvert);
void    printChar(char c);
void    printFloat(float f);
void    printDouble(double d);

#endif