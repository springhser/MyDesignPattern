
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
#include "Behavior/TemplateMethod.hpp"
#include "Behavior/Command.hpp"
#include "Behavior/ChainOfResposibility.hpp"
#include "Behavior/Iterator.hpp"
#include "Behavior/Mediator.hpp"
#include "Behavior/Memento.hpp"
#include "Behavior/State.hpp"
#include "Behavior/Observer.hpp"
#include "Behavior/Visitor.hpp"

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

	TemplateMethodTest::test();

	CommandTest::test();

	ChainOfResposibilityTest::test();

	IteratorTest::test();

	MediatorTest::test();

	MementoTest::test();

	StateTest::test();

	ObserverTest::test();

	VisitorTest::test();

	return 0;
}