#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>

Base * generate(void){
	Base * ret = NULL;

	std::srand(time(NULL));
	int j = std::rand() % 3;
	
	switch (j){
		case 1:
			ret = new A;
			break;
		case 2:
			ret = new B;
			break;
		case 0:
			ret = new C;
			break;
		default:
			ret = NULL;
			break;
	}
	return (ret);
}

void identify(Base * p){
	A * a = dynamic_cast<A*>(p);
	B * b = dynamic_cast<B*>(p);
	C * c = dynamic_cast<C*>(p);
	std::cout << "this pointer is for a class ";
	if (a)
		std::cout << "A\n";
	else if (b)
		std::cout << "B\n";
	else if (c)
		std::cout << "C\n";
	else
		std::cout << "that dosn't exist\n";
}

void identify( Base & p){
	std::cout << "this reference is for a class ";
	try{
		A & a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A\n";
	}
	catch(std::bad_cast &bc){
		try{
			B & b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "B\n";
		}
		catch(std::bad_cast &bc){
			try{
				C & c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << "C\n";
			}
			catch(std::bad_cast &bc){
				std::cout << "that dosn't exist\n";
			}
		}
	}
}

int	main(){
	Base*	alea = generate();

	if (alea){
		identify (alea);
		identify (*alea);
	}

	if (alea)
		delete alea;
	return (0);
}