/*!
 * @file Builder.hpp
 * @author chenj
 * @date 07/10/2024
 * @brief
 *     The example of Builder Pattern.
 */
#pragma once
#include "Utils/HelpTool.hpp"

#include <memory>
/*
@brief
�ŵ㣺
	ʹ��������ģʽ�ɱ��� "�ص����캯�� (telescoping constructor)" �ĳ��֡�
���磺
class Pizza {
	Pizza(int size) { ���� }
	Pizza(int size, boolean cheese) { ���� }
	Pizza(int size, boolean cheese, boolean pepperoni) { ���� }
	// ����
};
*/

class Person
{
public:
	void show() const
	{
		std::string sex = m_sex ? "man" : "woman";
		PRINTN(m_name << " is a "<< m_age << " year old " << sex);
	}
	std::string m_name;
	int m_age;
	bool m_sex; // true: man, false: woman
};

class PersonBuilder
{
public:
	PersonBuilder& setName(const std::string& name)
	{
		m_person.m_name = name;
		return *this;
	}

	PersonBuilder& setAge(const int age)
	{
		m_person.m_age = age;
		return *this;
	}

	PersonBuilder& setGender(const bool sex)
	{
		m_person.m_sex = sex;
		return *this;
	}

	Person getPerson() const
	{
		return m_person;
	}

private:
	Person m_person;
};

class Director
{
public:
	Person createYoungWoman() const
	{
		PersonBuilder pb;
		pb.setName("Sally").setAge(20).setGender(false);
		return pb.getPerson();
	}

	Person createMiddleAgeMan() const
	{
		PersonBuilder pb;
		pb.setName("Bob").setAge(40).setGender(true);
		return pb.getPerson();
	}
};

class BuilderTest
{
public:
	static void test()
	{
		TESTMODULE("Builder Test");
		Director director;
		Person youndGirl = director.createYoungWoman();
		youndGirl.show();
		Person midAgeMan = director.createMiddleAgeMan();
		midAgeMan.show();
	}
};

