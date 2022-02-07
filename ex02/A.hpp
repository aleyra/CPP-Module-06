#ifndef A_H
# define A_H

# include "Base.hpp"

class A:public Base{
	public:
		A();
		A(A const &src);
		virtual ~A();

		A	&operator=(A const &src);
		
	protected:

	private:

};

#endif