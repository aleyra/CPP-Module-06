#include "conv.hpp"

conv::conv(){
	this->_str = NULL;
}

conv::conv(conv const & src){
	*this = src;
}

conv::conv(char *str){
	this->_str = str;
	std::string s(this->_str);
	if (s.length() == 1 && (s[0] > '9' || s[0] < '0'))
		this->_val = static_cast<double>(s[0]);
	else
		this->_val = std::atof(this->_str);
	this->_dot = false;
	this->_only0 = false;
	char *	dot = strchr(str, '.');
	if (dot)
		this->_dot = true;
	if (dot)
		this->_only0 = true;
	int	i = 1;
	while (dot && dot[i] != 0 && this->_only0 == true){
		if (dot[i] != '0')
			this->_only0 = false;
		i++;
	}
	if (dot && dot[i] == 0 && dot[i - 1] == 'f')
		this->_only0 = true;
}

conv::~conv(){}

conv &	conv::operator=(conv const &src){
	this->_str = src._str;
	this->_val = src._val;
	return (*this);
}

char *	conv::getStr(){
	return (this->_str);
}

double	conv::getVal(){
	return (this->_val);
}

float	conv::toFloat(){
	return (static_cast<float>(this->_val));
}

int	conv::toInt(){
	return (static_cast<int>(this->_val));
}

char	conv::toChar(){
	std::string str(this->_str);
	if (isalpha(this->_str[0]) && str.length() == 1)
		return (static_cast<char>(this->_str[0]));
	return (static_cast<char>(this->_val));
}

void	conv::printConv(){
	std::string str(this->_str);
	char	c = this->toChar();
	int		i = this->toInt();
	float	f = this->toFloat();
	double	d = this->_val;
	bool	is_nan = (str.compare("nan") == 0) ? true : false;
	bool	is_inf = (str.compare("inf") == 0) ? true : false;

	std::cout << "char: ";
	if (is_nan || is_inf)
		std::cout << "impossible";
	else if (!isprint(c))
		std::cout << "Non displayable";
	else
		std::cout << "'" << c << "'";
	std::cout << std::endl;

	std::cout << "int: ";
	if (is_nan || is_inf || d > INT32_MAX || d < INT32_MIN)
		std::cout << "impossible";
	else
		std::cout << i;
	std::cout << std::endl;

	std::cout << "float: ";
	if (is_nan)
		std::cout << "nan";
	else if (is_inf && d > 0)
		std::cout << "+inf";
	else if (is_inf && d < 0)
		std::cout << "-inf";
	else
		std::cout << f;
	if (is_nan && is_inf && ((this->_dot == true && this->_only0 == true) || this->_dot == false))
		std::cout << ".0";
	std::cout << "f" << std::endl;

	std::cout << "double: ";
	if (is_nan)
		std::cout << "nan";
	else if (is_inf && d > 0)
		std::cout << "+inf";
	else if (is_inf && d < 0)
		std::cout << "-inf";
	else
		std::cout << d;
	if (is_nan == true && is_inf == true && ((this->_dot == true && this->_only0 == true) || this->_dot == false))
		std::cout << ".0";
	std::cout << std::endl;
}
