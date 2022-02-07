#include "Data.hpp"

int	main(){
	Data*		ptr = new Data;
	uintptr_t	raw;

	std::cout << "data: " << ptr << std::endl;
	raw = ptr->serialize(ptr);
	std::cout << "raw: " << raw << std::endl;
	ptr = ptr->deserialize(raw);
	std::cout << "re data: " << ptr << std::endl;

	delete ptr;
	return (0);
}
