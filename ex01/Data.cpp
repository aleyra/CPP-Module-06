#include "Data.hpp"

Data::Data(){
	this->_proof = NULL;
}

Data::Data(Data const &src){
	*this = src;
}

Data::~Data(){
}

Data	&Data::operator=(Data const &src){
	this->_proof = src._proof;
	return(*this);
}

uintptr_t	Data::serialize(Data *ptr){
	uintptr_t	raw;

	raw = reinterpret_cast<uintptr_t>(ptr);
	return (raw);
}

Data*	Data::deserialize(uintptr_t raw){
	Data*	ptr;

	ptr = reinterpret_cast<Data *>(raw);
	return(ptr);
}
