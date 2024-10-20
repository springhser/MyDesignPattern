
#include "Creation/AbstractFactory.hpp"
#include "Creation/SimpleFactory.hpp"
#include "Creation/FactoryMethod.hpp"
#include "Creation/Builder.hpp"
#include "Creation/Singleton.hpp"

#include "Structure/Adaptor.hpp"
#include "Structure/Bridge.hpp"
#include "Structure/Composite.hpp"
#include "Structure/Decorator.hpp"
#include "Structure/Facade.hpp"
#include "Structure/Flyweight.hpp"
#include "Structure/Proxy.hpp"

#include "Behavior/Strategy.hpp"

#include <iostream>

int main()
{
	std::cout << "Hello world" << std::endl;
	AbstractFactoryTest::test();

	SimpleFactoryTest::test();

	FactoryMethodTest::test();

	BuilderTest::test();

	SingletonTest::test();

	AdapterTest::test();

	BridgeTest::test();

	CompositeTest::test();

	DecoratorTest::test();

	FacadeTest::test();

	FlyweightTest::test();

	ProxyTest::test();

	StrategyTest::test();

	return 0;
}