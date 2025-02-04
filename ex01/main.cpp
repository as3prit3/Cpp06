# include "Serializer.hpp"

int main()
{
	Data ptr;
	ptr.name = "Rick Grimes";
	ptr.age = 42;


	std::cout << "Here is the original structs:" <<
				"\n\taddress: " << &ptr <<
				"\n\tname: " << ptr.name <<
				"\n\tage: " << ptr.age << std::endl;

	Data *reserialized_struct = Serialize::deserialize(Serialize::serialize(&ptr));

	std::cout << "Here is the reserialized structs:" <<
				"\n\taddress: " << reserialized_struct <<
				"\n\tname: " << reserialized_struct->name <<
				"\n\tage: " << reserialized_struct->age << std::endl;

	// std::string *ptr_int = reinterpret_cast<std::string *>(&ptr);

	// std::cout << "Here is the serialized structs:" <<
	// 			"\n\taddress: " << ptr_int << std::endl;
	// std::cout << "Here is the deserialized structs:" <<
	// 			"\n\taddress: " << reinterpret_cast<Data *>(ptr_int);

	// std::cout << "\n\n";

	// std::cout << "string name: " << *ptr_int << std::endl;
	// ptr_int++;
	// std::cout << "age: " << *(reinterpret_cast<int *>(ptr_int)) << std::endl;
}
