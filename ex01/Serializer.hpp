# include <iostream>
#include <stdint.h>

struct Data
{
	std::string name;
	int age;
};

class Serialize
{
	private:
		Serialize();
		Serialize(Serialize const &other);
		Serialize &operator=(Serialize const &other);
		~Serialize();
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};
