#ifndef SERIALIZE_HPP
# define SERIALIZE_HPP

# include "Data.hpp"
# include <stdint.h>

/*
Note: Subject requires to use uintptr_t, even if it was introduced in C99...
Still compiles with -std=c++98.
https://www.thejat.in/learn/uintptr-t-in-stdint
*/

class Serializer
{
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data		 *deserialize(uintptr_t raw);
	private:
		Serializer(void);
		Serializer(const Serializer &other);
		~Serializer(void);

		const Serializer &operator=(const Serializer &other);
};
	
#endif