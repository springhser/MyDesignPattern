/*!
 * @file Observer.hpp
 *
 * @author chenj
 * @date 22/10/2024
 * @brief
 *     
 */
#pragma once

#include "Utils/HelpTool.hpp"

class Attacker
{
public:
	virtual void fight() const = 0;
};

class J20:public Attacker
{
public:
	virtual void fight() const override
	{
		PRINTN("Lanch PL-21 missile.");
	}
};

class Destoyer055 :public Attacker
{
public:
	virtual void fight() const override
	{
		PRINTN("Lanch YJ-21 missile.");
	}
};

class PHL16 :public Attacker
{
public:
	virtual void fight() const override
	{
		PRINTN("Lanch 100000 rocket guns.");
	}
};

class UAV
{
public:
	UAV() :m_detectEnemy(false) {}

	void attach(std::shared_ptr<Attacker> attacker)
	{
		m_attackers.push_back(attacker);
	}

	void setState(bool detectEnemy)
	{
		m_detectEnemy = detectEnemy;
	}

	void notify()
	{
		if (!m_detectEnemy)
			return;
		PRINTN("Detect enemy!!! Attack!!!");
		for (auto attacker : m_attackers)
		{
			attacker->fight();
		}
	}
private:
	std::vector<std::shared_ptr<Attacker>> m_attackers;
	bool m_detectEnemy;
};


class ObserverTest
{
public:
	static void test()
	{
		TESTMODULE("Observer Test");

		std::shared_ptr<UAV> uav = std::make_shared<UAV>();
		std::shared_ptr<Attacker> j20 = std::make_shared<J20>();
		std::shared_ptr<Attacker> destroyer = std::make_shared<Destoyer055>();
		std::shared_ptr<Attacker> phl = std::make_shared<PHL16>();

		uav->attach(j20);
		uav->attach(destroyer);
		uav->attach(phl);

		PRINTN("Detach the target!!!");
		uav->setState(true);
		uav->notify();


	}
};