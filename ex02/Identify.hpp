#ifndef IDENTIFY_HPP
# define IDENTIFY_HPP

# include <iostream>
# include <string>
# include <cstdlib>

class	Base
{
	public:
		virtual ~Base(void);
};

class	A: public Base
{};

class	B: public Base
{};

class	C: public Base
{};

Base	*generate(void);
void	identify(Base* p);
void	identify(Base &p);

#endif