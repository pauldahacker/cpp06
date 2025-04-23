#include "Identify.hpp"

/*
https://cplusplus.com/reference/cstdlib/srand/
*/
int main(void)
{
	std::srand(time(NULL));
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