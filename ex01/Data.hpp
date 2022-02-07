#ifndef DATA_H
# define DATA_H

# include <iostream>

class Data{
public:
	Data();
	Data(Data const &src);
	virtual ~Data();

	Data	&operator=(Data const &src);

	uintptr_t	serialize(Data* ptr);
	Data*		deserialize(uintptr_t raw);

protected:

private:

};

#endif