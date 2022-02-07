#include "conv.hpp"

int	main(int ac, char *av[]){
	if (ac == 1){
		std::cout << "nothing to convert\n";
		return (0);
	}
	if (ac > 2){
		std::cout << "Error : too many thingd to convert\n";
		return (0);
	}
	conv	c(av[1]);
	c.printConv();	

	return (0);
}