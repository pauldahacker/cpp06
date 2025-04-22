#include "Identify.hpp"

int main(void)
{
	for (int i = 0; i < 10; ++i)
	{
		Base *tmp = generate();
		identify(tmp);
		identify(*tmp);
		std::cout << "------------------------------" << std::endl;
	}
	std::cout << "Unidentifiable test" << std::endl << std::endl;
	Base *unidentifiable = NULL;
	identify(unidentifiable);
	identify(*unidentifiable);
	return (0);
}