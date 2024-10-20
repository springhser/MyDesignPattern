/*!
 * @file ChainOfResposibility.hpp
 *
 * @author chenj
 * @date 20/10/2024
 * @brief
 *     
 */
#pragma once

#include "Utils/HelpTool.hpp"

class Manager
{
public:
	Manager(std::shared_ptr<Manager> senior_manager):m_senior_manager(senior_manager){}
	virtual ~Manager(){}
	virtual void DealWithPayRaise(double pay) const = 0;

protected:
	std::shared_ptr<Manager>m_senior_manager;
};

class CommonManager :public Manager
{
public:
	CommonManager(std::shared_ptr<Manager> senior_manager):Manager(senior_manager){}
	virtual ~CommonManager(){}

	virtual void DealWithPayRaise(double pay) const
	{
		if (pay > 500.0)
		{
			m_senior_manager->DealWithPayRaise(pay);
			return;
		}
			
		PRINTN("CommonManager Approves salary increase " << pay << " Yuan!");
	}
};

class Majordomo :public Manager
{
public:
	Majordomo(std::shared_ptr<Manager> senior_manager) :Manager(senior_manager) {}
	virtual ~Majordomo() {}

	virtual void DealWithPayRaise(double pay) const
	{
		if (pay > 2000.0)
		{
			m_senior_manager->DealWithPayRaise(pay);
			return;
		}

		PRINTN("Majordomo Approves salary increase " << pay << " Yuan!");
	}
};

class GeneralManager :public Manager
{
public:
	GeneralManager() :Manager(nullptr) {}
	virtual ~GeneralManager() {}

	virtual void DealWithPayRaise(double pay) const
	{
		if (pay < 5000.0)
		{
			PRINTN("GeneralManager Approves salary increase " << pay << " Yuan!");
		}
		else
		{
			PRINTN("GeneralManager does not approves salary increase " << pay << " Yuan!");
		}
	}
};

class PayRaiseSystem
{
public:
	PayRaiseSystem(std::shared_ptr<Manager> mgr):m_mgr(mgr){}
	void request(double pay, std::string name)
	{
		PRINTN(name << " want a " << pay << " Yuan salary increase.");
		m_mgr->DealWithPayRaise(pay);
	}

private:
	std::shared_ptr<Manager> m_mgr;
};

class ChainOfResposibilityTest
{
public:
	static void test()
	{
		TESTMODULE("Chain of Resposibility Test");
		auto geMgr = std::make_shared<GeneralManager>();
		auto md = std::make_shared<Majordomo>(geMgr);
		auto cmMgr = std::make_shared<CommonManager>(md);

		PayRaiseSystem sys(cmMgr);

		sys.request(2000,"Didi");
		sys.request(300, "Anny");
		sys.request(50000, "Dog");

	}
};

