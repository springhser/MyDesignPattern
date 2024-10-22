/*!
 * @file Command.hpp
 *
 * @author chenj
 * @date 20/10/2024
 * @brief
 *     
 */
#pragma once

#include "Utils/HelpTool.hpp"

class CookChef
{
public:
	virtual ~CookChef(){}
};

class ChineseChef :public CookChef
{
public:
	virtual ~ChineseChef(){}
	void cookChuanFood() const
	{
		PRINTN("Do Chuan Food");
	}
	void cookYueFood() const
	{
		PRINTN("Do Yue Food");
	}

	void cookLuFood() const
	{
		PRINTN("Do Lu Food");
	}
};

class WestChef :public CookChef
{
public:
	virtual ~WestChef() {}
	void cookFrenchFood() const
	{
		PRINTN("Do French Food");
	}
};

class CookFood
{
public:
	virtual ~CookFood(){}

	virtual void setCookChef(std::shared_ptr<CookChef> chef) = 0;
	virtual void execute() const = 0;
};


class CookChineseFood:public CookFood
{
public:
	virtual ~CookChineseFood(){}
	virtual void setCookChef(std::shared_ptr<CookChef> chef) override
	{
		auto chineseChef = std::dynamic_pointer_cast<ChineseChef>(chef);
		if (nullptr == chineseChef)
		{
			PRINTN("Only chinese chef is accepted.");
			return;
		}
		m_chef = chineseChef;
			
	}
	virtual void execute() const override 
	{
		PRINTN("This is chinese food: ");
		if (!m_chef)
		{
			PRINTN("The chef is gone.");
			return;
		}

		m_chef->cookChuanFood();
		m_chef->cookYueFood();
		m_chef->cookLuFood();
	}

	std::shared_ptr<ChineseChef> m_chef;
};

class CookWestFood:public CookFood
{
public:
	virtual ~CookWestFood(){}

	virtual void setCookChef(std::shared_ptr<CookChef> chef) override
	{
		auto westChef = std::dynamic_pointer_cast<WestChef>(chef);
		if (nullptr == westChef)
		{
			PRINTN("Only west chef is accepted.");
				return;
		}
		m_chef = westChef;

	}
	virtual void execute() const override
	{
		PRINTN("This is chinese food: ");
		if (!m_chef)
		{
			PRINTN("The chef is gone.");
			return;
		}

		m_chef->cookFrenchFood();
	}

	std::shared_ptr<WestChef> m_chef;
};


class Restaurant
{
public:
	void setFoodStyle(std::shared_ptr<CookFood> cookFood)
	{
		m_cookCommands.push_back(cookFood);
	}

	void cookFood()
	{
		for (auto cmd : m_cookCommands)
		{
			cmd->execute();
		}
	}

private:
	std::vector<std::shared_ptr<CookFood>> m_cookCommands;
};


class CommandTest
{
public:
	static void test()
	{
		TESTMODULE("Command Test");
		PRINTN("The new restaurant has just opened")
		Restaurant room;
		auto chef1 = std::make_shared<ChineseChef>();
		auto cookFood1 = std::make_shared<CookChineseFood>();
		cookFood1->setCookChef(chef1);

		auto chef2 = std::make_shared<WestChef>();
		auto cookFood2 = std::make_shared<CookWestFood>();
		cookFood2->setCookChef(chef2);

		room.setFoodStyle(cookFood1);
		room.setFoodStyle(cookFood2);

		PRINTN("What can this dining room cook?");

		room.cookFood();

	}
};