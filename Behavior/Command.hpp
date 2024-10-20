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

class CookChief
{
public:
	virtual ~CookChief(){}
};

class ChineseChief :public CookChief
{
public:
	virtual ~ChineseChief(){}
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

class WestChief :public CookChief
{
public:
	virtual ~WestChief() {}
	void cookFrenchFood() const
	{
		PRINTN("Do French Food");
	}
};

class CookFood
{
public:
	virtual ~CookFood(){}

	virtual void setCookChief(std::shared_ptr<CookChief> chief) = 0;
	virtual void execute() const = 0;
};


class CookChineseFood:public CookFood
{
public:
	virtual ~CookChineseFood(){}
	virtual void setCookChief(std::shared_ptr<CookChief> chief) override
	{
		auto chineseChief = std::dynamic_pointer_cast<ChineseChief>(chief);
		if (nullptr == chineseChief)
		{
			PRINTN("Only chinese chief is accepted.");
			return;
		}
		m_chief = chineseChief;
			
	}
	virtual void execute() const override 
	{
		PRINTN("This is chinese food: ");
		if (!m_chief)
		{
			PRINTN("The chief is gone.");
			return;
		}

		m_chief->cookChuanFood();
		m_chief->cookYueFood();
		m_chief->cookLuFood();
	}

	std::shared_ptr<ChineseChief> m_chief;
};

class CookWestFood:public CookFood
{
public:
	virtual ~CookWestFood(){}

	virtual void setCookChief(std::shared_ptr<CookChief> chief) override
	{
		auto westChief = std::dynamic_pointer_cast<WestChief>(chief);
		if (nullptr == westChief)
		{
			PRINTN("Only west chief is accepted.");
				return;
		}
		m_chief = westChief;

	}
	virtual void execute() const override
	{
		PRINTN("This is chinese food: ");
		if (!m_chief)
		{
			PRINTN("The chief is gone.");
			return;
		}

		m_chief->cookFrenchFood();
	}

	std::shared_ptr<WestChief> m_chief;
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
		auto chief1 = std::make_shared<ChineseChief>();
		auto cookFood1 = std::make_shared<CookChineseFood>();
		cookFood1->setCookChief(chief1);

		auto chief2 = std::make_shared<WestChief>();
		auto cookFood2 = std::make_shared<CookWestFood>();
		cookFood2->setCookChief(chief2);

		room.setFoodStyle(cookFood1);
		room.setFoodStyle(cookFood2);

		PRINTN("What can this dining room cook?");

		room.cookFood();

	}
};