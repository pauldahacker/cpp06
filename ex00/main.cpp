#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
        std::cout << "Incorrect number of arguments" << std::endl;
    else
        ScalarConverter::convert(argv[1]);
    return (0);
}
/*
int main(void)
{
    std::cout << "basic char" << std::endl;
	ScalarConverter::convert("'&'");
	std::cout << std::endl;

    std::cout << "basic int" << std::endl;
	ScalarConverter::convert("0");
	std::cout << std::endl;

	std::cout << "basic float" << std::endl;
	ScalarConverter::convert("111.1111f");
	std::cout << std::endl;

	std::cout << "basic double" << std::endl;
	ScalarConverter::convert("8888.42");
	std::cout << std::endl;

	std::cout << "MAX int" << std::endl;
	ScalarConverter::convert("+2147483647");
	std::cout << std::endl;

    std::cout << "MIN int" << std::endl;
	ScalarConverter::convert("-2147483648");
	std::cout << std::endl;

	std::cout << "int overflow" << std::endl;
	ScalarConverter::convert("2147483648");
	std::cout << std::endl;

	std::cout << "float overflow" << std::endl;
	ScalarConverter::convert("888888888888888888888888888888888888888.0000000000000000f");
	std::cout << std::endl;

	std::cout << "double overflow" << std::endl;
	ScalarConverter::convert("9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999.9");
	std::cout << std::endl;

	std::cout << "+inf" << std::endl;
	ScalarConverter::convert("+inf");
	std::cout << std::endl;

	std::cout << "+inff" << std::endl;
	ScalarConverter::convert("+inff");
	std::cout << std::endl;

    std::cout << "-inf" << std::endl;
	ScalarConverter::convert("+inf");
	std::cout << std::endl;

    std::cout << "-inff" << std::endl;
	ScalarConverter::convert("+inf");
	std::cout << std::endl;

	std::cout << "nan" << std::endl;
	ScalarConverter::convert("nan");
	std::cout << std::endl;

	std::cout << "nanf" << std::endl;
	ScalarConverter::convert("nan");
	std::cout << std::endl;

	return (0);
}
*/