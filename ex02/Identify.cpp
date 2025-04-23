#include "Identify.hpp"

Base::~Base(void)
{
	delete (this);
}

Base	*generate(void)
{
	int		random = rand() % 3 + 1;

	switch (random)
	{
		case (1):
			std::cout << "Generated class A" << std::endl;
			return (new A());
		case (2):
			std::cout << "Generated class B" << std::endl;
			return (new B());
		case (3):
			std::cout << "Generated class C" << std::endl;
			return (new C());
	}
	return (NULL);
}

void	identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "p points to class A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "p points to class B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "p points to class C" << std::endl;
	else
		std::cout << "p points to none of A, B or C" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		dynamic_cast<A &>(p);
		std::cout << "p references class A" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}
	try
	{
		dynamic_cast<B &>(p);
		std::cout << "p references class B" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}
	try
	{
		dynamic_cast<C &>(p);
		std::cout << "p references class C" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}
	std::cout << "p references none of A, B or C" << std::endl;
}