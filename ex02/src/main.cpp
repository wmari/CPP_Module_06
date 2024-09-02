#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

Base *generate(void)
{
	std::srand(std::time(0));
	int randint = std::rand() % 3;
	if (randint == 0)
		return (dynamic_cast<Base *>(new A));
	else if (randint == 1)
		return (dynamic_cast<Base *>(new B));
	else
		return (dynamic_cast<Base *>(new C));
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "B" << std::endl;
	else
		std::cout << "C" << std::endl;
}

void identify(Base &p)
{
	if (dynamic_cast<A *>(&p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(&p) != NULL)
		std::cout << "B" << std::endl;
	else
		std::cout << "C" << std::endl;
}

int main()
{
	Base *p = generate();
	std::cout << "identify with *p" << std::endl;
	identify(p);
	std::cout << "identify with &p" << std::endl;
	identify(*p);
	return (0);
}