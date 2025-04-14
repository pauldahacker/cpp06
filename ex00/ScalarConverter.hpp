#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <cctype>
# include <climits>

# define ZERO_DECIMAL ".0"
# define FLOAT_SUFFIX "f"

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

#endif