# include "Serializer.hpp"

Serialize::Serialize()
{
}

Serialize::Serialize(const Serialize &src)
{
	*this = src;
}

Serialize &Serialize::operator=(const Serialize &src)
{
	if (this != &src)
		return (*this);
	return (*this);
}

Serialize::~Serialize()
{
}

uintptr_t	Serialize::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*		Serialize::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
