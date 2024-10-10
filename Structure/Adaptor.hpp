/*!
 * @file Adaptor.hpp
 *
 * @author chenj
 * @date 08/10/2024
 * @brief
 *     
 */
#pragma once

#include "Utils/HelpTool.hpp"

class Hdmi
{
public:
	virtual ~Hdmi() {}
	virtual void connectToPC() const
	{
		PRINTN("Connect to PC by hdmi");
	}
};

class TypeC
{
public:
	virtual void connectToNewPC() const
	{
		PRINTN("Connect to PC by typeC");
	}
};

class TypeCAdpater: public TypeC
{
public:
	TypeCAdpater(Hdmi* hdmi):m_hdmi(hdmi) {}

	virtual void connectToNewPC() const override
	{
		PRINT("Connect to new pc use typec adapter. ")
		m_hdmi->connectToPC();
	}

private:
	Hdmi* m_hdmi;
};


class AdapterTest
{
public:
	static void test()
	{
		TESTMODULE("Adapter Test")
		PRINTN("I have a hdmi line.");
		std::shared_ptr<Hdmi> hdmi = std::make_shared<Hdmi>();

		PRINTN("The new computer only support typeC.I need an adapter.");
		std::shared_ptr<TypeC> typeC = std::make_shared<TypeCAdpater>(hdmi.get());
		typeC->connectToNewPC();

	}
};