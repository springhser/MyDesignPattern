
#include "Creation/AbstractFactory.hpp"
#include "Creation/SimpleFactory.hpp"
#include <iostream>

int main()
{
	std::cout << "Hello world" << std::endl;
	AbstractFactoryTest::test();

	SimpleFactoryTest::test();
	return 0;
}