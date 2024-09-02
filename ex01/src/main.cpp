#include "Serialize.hpp"
#include "Data.hpp"

int main()
{
	Data premier("qweqweqwe");
	Data *second;
	uintptr_t ptr;

	ptr = Serializer::serialize(&premier);
	second = Serializer::deserialize(ptr);
	std::cout << premier.getname() << std::endl;
	std::cout << second->getname() << std::endl;
	std::cout << "-------------" << std::endl;
	std::cout << reinterpret_cast<uintptr_t>(&premier) << std::endl;
	std::cout << reinterpret_cast<uintptr_t>(second) << std::endl;
	return (0);
}