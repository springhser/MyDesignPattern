#pragma once

#include "Utils/HelpTool.hpp"

class PathMaker
{
public:
	PathMaker(const std::string& makerName):m_name(makerName){}
	virtual ~PathMaker(){}
	virtual void Execute()
	{
		PRINTN("Execute " << m_name << " maker.");
		Check();
		Prepare();
		Calculate();
		Output();
		PRINTN("End Process.\n");
	}
protected:
	virtual int Check() = 0;
	virtual int Prepare() = 0;
	virtual int Calculate() = 0;
	virtual int Output() = 0;

	const std::string m_name;
};

class NearestPathMaker: public PathMaker
{
public:
	NearestPathMaker():PathMaker("Nearest Path"){}
	virtual ~NearestPathMaker() {}

protected:
	virtual int Check() override
	{
		PRINTN("Check the " << m_name <<" parameters");
		return 0;
	}

	virtual int Prepare() override
	{
		PRINTN("Prepare " << m_name << " parameters");
		return 0;
	}
	virtual int Calculate() override
	{
		PRINTN("Calculate " << m_name << " ...");
		return 0;
	}
	virtual int Output() override 
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
	virtual int Check() override
	{
		PRINTN("Dont Check the " << m_name << " parameters");
		return 0;
	}

	virtual int Prepare() override
	{
		PRINTN("Prepare " << m_name << " parameters");
		return 0;
	}
	virtual int Calculate() override
	{
		PRINTN("Calculate " << m_name << " ...");
		return 0;
	}
	virtual int Output() override
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
		pathMaker->Execute();

		std::shared_ptr<PathMaker> pathMaker2 = std::make_shared<NearestPathMaker>();
		pathMaker2->Execute();
	}
};