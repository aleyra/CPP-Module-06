#ifndef DATA_H
# define DATA_H

# include <iostream>

class Data{
public:
	Data();
	Data(Data const &src);
	virtual ~Data();

	Data	&operator=(Data const &src);

protected:

private:
	void	*_proof;
};

#endif