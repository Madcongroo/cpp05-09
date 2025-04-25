





#include "Base.hpp"
#include "B.hpp"
#include "A.hpp"
#include "C.hpp"

Base* generate( void )
{
	unsigned int	seed = 0;

	Base*		newBase;

	srand(time(NULL));
	seed = rand();

	switch (seed % 3)
	{
		case 0:
		return (dynamic_cast<A*>(newBase));

		case 1:
		//newBase = new B;
		return (dynamic_cast<B*>(newBase));

		case 2:
		//newBase = new C;
		return (dynamic_cast<C*>(newBase));
	}
	return (NULL);
}

void	identify( Base* p )
{
	(void)p;
}

void	identify( Base& p )
{
	(void)p;
}

int main()
{
	try
	{
		Base* test;

		test = generate();
		if (test == NULL)
			std::cout << "type cast failed" << std::endl;
		identify( test );
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);	
}
