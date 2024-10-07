
#include "Creation/AbstractFactory.hpp"
#include "Creation/SimpleFactory.hpp"
#include "Creation/FactoryMethod.hpp"
#include "Creation/Builder.hpp"
#include "Creation/Singleton.hpp"

#include <iostream>

int main()
{
	std::cout << "Hello world" << std::endl;
	AbstractFactoryTest::test();

	SimpleFactoryTest::test();

	FactoryMethodTest::test();

	BuilderTest::test();

	SingletonTest::test();
	return 0;
}