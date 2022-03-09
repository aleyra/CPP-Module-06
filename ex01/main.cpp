#include "Data.hpp"

uintptr_t	serialize(Data *ptr){
	uintptr_t	raw;

	raw = reinterpret_cast<uintptr_t>(ptr);
	return (raw);
}

Data*	deserialize(uintptr_t raw){
	Data*	ptr;

	ptr = reinterpret_cast<Data *>(raw);
	return(ptr);
}

int	main(){
	Data*		ptr = new Data;
	uintptr_t	raw;

	std::cout << "data: " << ptr << std::endl;
	raw = serialize(ptr);
	std::cout << "raw: " << raw << std::endl;
	ptr = deserialize(raw);
	std::cout << "re data: " << ptr << std::endl;

	delete ptr;
	return (0);
}
