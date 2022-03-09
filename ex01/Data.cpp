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
