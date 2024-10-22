/*!
 * @file Prototype.hpp
 *
 * @author chenj
 * @date 22/10/2024
 * @brief
 *     
 */
#pragma once

class UnmanWeapon
{
public:
	UnmanWeapon(double price, double endurance) :m_endurance(endurance), m_price(price) {}
	virtual void info() const = 0;
	virtual std::shared_ptr<UnmanWeapon> clone() = 0;

protected:
	double m_endurance;
	double m_price;
};

class RobotSoldier:public UnmanWeapon
{
public:
	RobotSoldier(double price, double endurance, double height) :UnmanWeapon(price, endurance), m_height(height){}
	virtual void info() const
	{
		PRINTN("This is a robot soldier with " << m_height << " m tall. It can work continuously for "
			<< m_endurance << " hours.Its price is " << m_price << " Yuan.");
	}

	virtual std::shared_ptr<UnmanWeapon> clone()
	{
		return std::make_shared<RobotSoldier>(m_price, m_endurance, m_height);
	}

private:
	 double m_height;
};


class WeaponFactory
{
public:
	WeaponFactory() {}
	
	void designRobotSoldier(std::string name, double price, double endurance, double height)
	{
		if (m_weapon_templates.find(name) != m_weapon_templates.end())
		{
			PRINTN("This type robot soldier has been in the factory.");
		}

		m_weapon_templates[name] = std::make_shared<RobotSoldier>(price,endurance, height);
	}

	std::shared_ptr<UnmanWeapon> productWeapon(std::string name)
	{
		if(m_weapon_templates.find(name) == m_weapon_templates.end())
		{
			PRINTN("The factory can't product this type "<< name << " weapon");
		}

		return m_weapon_templates[name]->clone();
	}

private:
	std::map < std::string, std::shared_ptr<UnmanWeapon>> m_weapon_templates;
};

class PrototypeTest
{
public:
	static void test()
	{
		TESTMODULE("Prototype Test");

		WeaponFactory factory;
		factory.designRobotSoldier("T800", 10000, 10, 2);

		std::vector<std::shared_ptr<UnmanWeapon> > robot_soldier_corps;

		robot_soldier_corps.push_back(factory.productWeapon("T800"));
		robot_soldier_corps.push_back(factory.productWeapon("T800"));
		robot_soldier_corps.push_back(factory.productWeapon("T800"));

		for (auto soldier : robot_soldier_corps)
		{
			soldier->info();
		}
	}
};