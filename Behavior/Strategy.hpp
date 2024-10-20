#pragma once
#include "Utils/HelpTool.hpp"

class CookingMethod
{
public:
	virtual void cook() const = 0;
};

class FryFood :public CookingMethod
{
public:
	virtual void cook() const
	{
		PRINTN("Fry");
	}
};

class SteamFood :public CookingMethod
{
public:
	virtual void cook() const {
		PRINTN("Steam");
	}
};

class CookMaster
{
public:
	void SetCookMethod(std::shared_ptr<CookingMethod> method)
	{
		m_method = method;
	}

	void cookMeat()
	{
		PRINT("Procss meat by ");
		m_method->cook();
	}

private:
	std::shared_ptr<CookingMethod> m_method;
};


class StrategyTest
{
public:
	static void test()
	{
		TESTMODULE("Strategy Test");
		CookMaster master;
		std::shared_ptr<CookingMethod> fry = std::make_shared<FryFood>();
		master.SetCookMethod(fry);
		master.cookMeat();

		std::shared_ptr<CookingMethod> steam = std::make_shared<SteamFood>();
		PRINTN("The master try new method.");
		master.SetCookMethod(steam);
		master.cookMeat();

	}
};