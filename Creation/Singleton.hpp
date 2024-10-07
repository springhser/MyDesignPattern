/*!
 * @file Singleton.hpp
 *
 * @author chenj
 * @date 08/10/2024
 * @brief
 *     
 */
#pragma once

#include "Utils/HelpTool.hpp"

#include <thread>

class Singleton
{
public:
	static Singleton& getInstance(const std::string& name)
	{
		static Singleton s(name);
		return s;
	}

	std::string getName() const
	{
		return m_name;
	}

	Singleton(const Singleton& singleton) = delete;
	Singleton& operator=(const Singleton& singleton) = delete;

private:
	Singleton(const std::string& name) :m_name(name) {};
	~Singleton() = default;

	std::string m_name;

};

class ThreadFoo 
{
public:
	void operator()()
	{
		// Following code emulates slow initialization.
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		Singleton& singleton = Singleton::getInstance("Sally");
		PRINTN(singleton.getName());
	}
};

class ThreadBar
{
public:
	void operator()()
	{
		// Following code emulates slow initialization.
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		Singleton& singleton = Singleton::getInstance("Bob");
		PRINTN(singleton.getName());
	}
};

class SingletonTest
{
public:
	static void test()
	{
		TESTMODULE("Singleton Test");
		ThreadFoo foo;
		ThreadBar bar;
		std::thread t1(foo);
		std::thread t2(bar);
		t1.join();
		t2.join();
	}
};