#pragma once
#include "Utils/HelpTool.hpp"

#include <memory>

class Transport
{
public:
	virtual ~Transport() {}
	virtual void deliver() const = 0;
};

class Truck:public Transport
{
public:
	virtual void deliver() const override
	{
		PRINTN("Deliver by truck.");
	}
};


class Ship :public Transport
{
public:
	virtual void deliver() const override
	{
		PRINTN("Deliver by ship.");
	}
};


class LogisticsFactory
{
public:
	virtual ~LogisticsFactory() {}
	
	virtual std::shared_ptr<Transport> createTransport() const = 0;

};

class RoadLogisticsFactory:public LogisticsFactory
{
public:

	virtual std::shared_ptr<Transport> createTransport() const
	{
		return std::make_shared<Truck>();
	}

};


class SeaLogisticsFactory :public LogisticsFactory
{
public:

	virtual std::shared_ptr<Transport> createTransport() const
	{
		return std::make_shared<Ship>();
	}
};


class FactoryMethodTest
{
public:
	static void test()
	{
		TESTMODULE("FactoryMethod Test")
		{
			std::shared_ptr<LogisticsFactory> logistics = std::make_shared<RoadLogisticsFactory>();
			std::shared_ptr<Transport> transport = logistics->createTransport();
			transport->deliver();
		}

		{
			std::shared_ptr<LogisticsFactory> logistics = std::make_shared<SeaLogisticsFactory>();
			std::shared_ptr<Transport> transport = logistics->createTransport();
			transport->deliver();
		}
	}
};
