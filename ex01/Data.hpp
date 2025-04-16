#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>

class Data
{
	private:
		std::string	_name;
	public:
		Data(void);
		Data(std::string name);
		Data(const Data &other);
		~Data(void);

		const Data &operator=(const Data &other);

		std::string	getName(void) const;
};

#endif