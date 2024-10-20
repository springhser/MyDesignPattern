#pragma once

#include "Utils/HelpTool.hpp"

class PathMaker
{
public:
	PathMaker(const std::string& makerName):m_name(makerName){}
	virtual ~PathMaker(){}
	virtual void execute()
	{
		PRINTN("Execute " << m_name << " maker.");
		check();
		prepare();
		calculate();
		output();
		PRINTN("End Process.\n");
	}
protected:
	virtual int check() = 0;
	virtual int prepare() = 0;
	virtual int calculate() = 0;
	virtual int output() = 0;

	const std::string m_name;
};

class NearestPathMaker: public PathMaker
{
public:
	NearestPathMaker():PathMaker("Nearest Path"){}
	virtual ~NearestPathMaker() {}

protected:
	virtual int check() override
	{
		PRINTN("Check the " << m_name <<" parameters");
		return 0;
	}

	virtual int prepare() override
	{
		PRINTN("Prepare " << m_name << " parameters");
		return 0;
	}
	virtual int calculate() override
	{
		PRINTN("Calculate " << m_name << " ...");
		return 0;
	}
	virtual int output() override 
	{
		PRINTN("Output " << m_name << " result.");
		return 0;
	}
};


class SmoothPathMaker : public PathMaker
{
public:
	SmoothPathMaker() :PathMaker("Smooth Path") {}
	virtual ~SmoothPathMaker() {}


protected:
	virtual int check() override
	{
		PRINTN("Dont Check the " << m_name << " parameters");
		return 0;
	}

	virtual int prepare() override
	{
		PRINTN("Prepare " << m_name << " parameters");
		return 0;
	}
	virtual int calculate() override
	{
		PRINTN("Calculate " << m_name << " ...");
		return 0;
	}
	virtual int output() override
	{
		PRINTN("Dont Output " << m_name << " result.");
		return 0;
	}
};


class TemplateMethodTest
{
public:
	static void test()
	{
		TESTMODULE("Template Method Test");
		std::shared_ptr<PathMaker> pathMaker = std::make_shared<SmoothPathMaker>();
		pathMaker->execute();

		std::shared_ptr<PathMaker> pathMaker2 = std::make_shared<NearestPathMaker>();
		pathMaker2->execute();
	}
};