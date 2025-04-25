



#include "Serializer.hpp"

int main()
{
	
	Data		test(45, "Heinz");
	uintptr_t	ptr;
	Data*		test2;

	ptr = Serializer::serialize(&test);	
	std::cout << ptr << std::endl;
	test2 = Serializer::deserialize(ptr);	
	std::cout << test2->getAge() << std::endl;
	std::cout << test2->getName() << std::endl;

	return (0);
}
