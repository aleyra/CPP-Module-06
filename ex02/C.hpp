#ifndef C_H
# define C_H

# include "Base.hpp"

class C:public Base{
	public:
		C();
		C(C const &src);
		virtual ~C();

		C	&operator=(C const &src);
		
	protected:

	private:

};

#endif