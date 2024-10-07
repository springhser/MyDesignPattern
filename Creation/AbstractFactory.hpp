#pragma once

#include "Utils/HelpTool.hpp"

#include <memory>

class Chair
{
public:
	virtual ~Chair() {}
	virtual void show() const = 0;
};

class ModernChair :public Chair
{
public:
	virtual void show()  const override
	{
		PRINTN("It is a modern chair.");
	}
};

class VictorianChair :public Chair
{
public:
	virtual void show()  const override
	{
		PRINTN("It is a victorian chair.");
	}
};

class CoffeeTable
{
public:
	virtual ~CoffeeTable() {}
	virtual void show() const = 0;
};

class ModernCoffeeTable :public CoffeeTable
{
public:
	virtual void show() const override
	{
		PRINTN("It is a modern coffee table.");
	}
};

class VictorianCoffeeTable :public CoffeeTable
{
public:
	virtual void show() const override
	{
		PRINTN("It is a victorian coffee table.");
	}
};

class FurnitureFactory
{
public:
	virtual std::shared_ptr<Chair> createChair() const = 0;
	virtual std::shared_ptr<CoffeeTable> createCoffeeTable() const = 0;
};

class ModernFurnitureFactory :public FurnitureFactory
{
public:
	virtual std::shared_ptr<Chair> createChair() const override
	{
		return std::make_shared<ModernChair>();
	}
	virtual std::shared_ptr<CoffeeTable> createCoffeeTable() const override
	{
		return std::make_shared<ModernCoffeeTable>();
	}
};

class VictorianFurnitureFactory :public FurnitureFactory
{
public:
	virtual std::shared_ptr<Chair> createChair() const override
	{
		return std::make_shared<VictorianChair>();
	}
	virtual std::shared_ptr<CoffeeTable> createCoffeeTable() const override
	{
		return std::make_shared<VictorianCoffeeTable>();
	}
};


class AbstractFactoryTest
{
public:
	static void test()
	{
		TESTMODULE("AbstractFactory Test")
		{
			std::shared_ptr<FurnitureFactory> furnitureFactory = std::make_shared<ModernFurnitureFactory>();
			std::shared_ptr<Chair> chair = furnitureFactory->createChair();
			std::shared_ptr<CoffeeTable> coffeeTable = furnitureFactory->createCoffeeTable();
			chair->show();
			coffeeTable->show();
		}

		{
			std::shared_ptr<FurnitureFactory> furnitureFactory = std::make_shared<VictorianFurnitureFactory>();
			std::shared_ptr<Chair> chair = furnitureFactory->createChair();
			std::shared_ptr<CoffeeTable> coffeeTable = furnitureFactory->createCoffeeTable();
			chair->show();
			coffeeTable->show();
		}

	}
};
