#include "Serializer.hpp"

Serializer::Serializer(const Serializer &other)
{
	*this = other;
}

const Serializer &Serializer::operator=(const Serializer &other)
{
	(void)other;
	return (*this);
}

uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}