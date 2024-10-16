#pragma once
#include "Utils/HelpTool.hpp"

#include <map>

class Teacher
{
public:
	void answer() const
	{
		PRINTN("answer question");
	}
};

class SelfStudyRoom
{
public:

	static void init()
	{
		m_teachTeam.insert(std::make_pair(1, Teacher()));
		m_teachTeam.insert(std::make_pair(2, Teacher()));
	}

	static void ask(int id)
	{
		if (m_teachTeam.find(id) != m_teachTeam.end())
		{
			PRINT("Ask teacher " << id << " to ");
			m_teachTeam[id].answer();
		}
		else
		{
			PRINTN("Teacher " << id << " is not here.");
		}
			
	}
private:
	static std::map<int, Teacher> m_teachTeam;
};

std::map<int, Teacher> SelfStudyRoom::m_teachTeam;

class FlyweightTest
{
public:
	static void test()
	{
		TESTMODULE("Flyweight Test");
		SelfStudyRoom::init();
		SelfStudyRoom::ask(1);
		SelfStudyRoom::ask(2);
		SelfStudyRoom::ask(1);
		SelfStudyRoom::ask(2);
		SelfStudyRoom::ask(3);
	}
};