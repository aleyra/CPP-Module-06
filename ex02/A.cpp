#include "A.hpp"

A::A(){
}

A::A(A const &src){
	*this = src;
}

A::~A(){
}

A	&A::operator=(A const &src){
	(void)src;
	return (*this);
}
