# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

int main()
{
	srand(time(NULL));
	for (int i = 0; i < 3; i++)
	{
		Base *base = generate();
		identify(base);
		identify(*base);
		std::cout << std::endl;
	}
	return 0;
}
