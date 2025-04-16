#include "Serializer.hpp"

int main(void)
{
	Data myData("Paul");
	std::cout << "------------------------------------------" << std::endl
		<< "Original Data address = " << &myData << std::endl
		<< "Name: " << myData.getName() << std::endl;

	uintptr_t myRaw = Serializer::serialize(&myData);
	std::cout << "------------------------------------------" << std::endl
		<< "Testing serialize function on original Data pointer" << std::endl
		<< "Return value (uintptr_t) = " << myRaw << std::endl
		<< "In hex: " << std::showbase << std::hex << myRaw << std::endl;

	Data *newData = Serializer::deserialize(myRaw);
	std::cout << "------------------------------------------" << std::endl
		<< "Testing deserialize function on Raw Data" << std::endl
		<< "Return value (Data *) = " << newData << std::endl
		<< "Name: " << newData->getName() << std::endl
		<< "------------------------------------------" << std::endl;
	return (0);
}