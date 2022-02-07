#ifndef CONV_H
# define CONV_H

# include <iostream>
# include <string>
# include <cmath>
# include <limits>
# include <cstring>

class conv{
public:
	conv();
	conv(conv const & src);
	conv(char *str);
	virtual ~conv();

	conv	&operator=(conv const &src);

	char *		getStr();
	double		getVal();
	float		toFloat();
	int			toInt();
	char		toChar();
	void		printConv();

protected:

private:
	char*		_str;
	double		_val;
	bool		_dot;
	bool		_only0;
};

#endif