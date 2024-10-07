#pragma once
#include "Utils/HelpTool.hpp"
enum class DringType
{
	Wine = 1,
	OrangeJuice,
	Water

};

class Drink
{
public:
	virtual ~Drink(){}
	virtual void show() const = 0;
};

class Wine :public Drink
{
public:
	virtual void show() const override
	{
		PRINTN("It is wine");
	}
};

class OrangeJuice :public Drink
{
public:
	virtual void show() const override
	{
		PRINTN("It is orange juice");
	}
};

class Water :public Drink
{
public:
	virtual void show() const override
	{
		PRINTN("It is water");
	}
};

class DrinkFactory
{
public:
	static std::shared_ptr<Drink> createDrink(DringType type)
	{
		std::shared_ptr<Drink> drink = nullptr;
		switch (type)
		{
		case DringType::Wine:
			drink = std::make_shared<Wine>();
			break;
		case DringType::OrangeJuice:
			drink = std::make_shared<OrangeJuice>();
			break;
		case DringType::Water:
			drink = std::make_shared<Water>();
			break;
		default:
			break;
		}
		return drink;
	}
};

class SimpleFactoryTest
{
public:
	static void test()
	{
		TESTMODULE("SimpleFactory Test");
		{
			std::shared_ptr<Drink> drink = DrinkFactory::createDrink(DringType::OrangeJuice);
			drink->show();
		}

		{
			std::shared_ptr<Drink> drink = DrinkFactory::createDrink(DringType::Wine);
			drink->show();
		}

		{
			std::shared_ptr<Drink> drink = DrinkFactory::createDrink(DringType::Water);
			drink->show();
		}
	}

};
