#pragma once

class FoodProducer
{
public:
	virtual void sellFood(double money) = 0;
};

class FoodFactory:public FoodProducer
{
public:
	virtual void sellFood(double money)
	{
		PRINTN("sell food worth " << money << " yuan.");
	}
};

class Supermarket:public FoodProducer
{
public:
	virtual void sellFood(double money)
	{
		if (nullptr == m_realProducer)
			m_realProducer = std::make_shared<FoodFactory>();

		m_realProducer->sellFood(money);
	}
private:
	std::shared_ptr<FoodProducer> m_realProducer;
};


class ProxyTest
{
public:
	static void test()
	{
		TESTMODULE("Proxy Test");

		std::shared_ptr<FoodProducer> market = std::make_shared<Supermarket>();

		market->sellFood(10);
	}
};