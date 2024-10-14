#pragma once

#include "Utils/HelpTool.hpp"

class CAMSys
{
public:
	virtual ~CAMSys() {}

	virtual void calcTpath() const = 0;
};

class NXSys :public CAMSys
{
public:
	virtual ~NXSys(){}

	virtual void calcTpath() const
	{
		PRINTN("Calculate toolpath by NX");
	}
};

class ZwSys :public CAMSys
{
public:
	virtual ~ZwSys(){}

	virtual void calcTpath() const
	{
		PRINTN("calculate toolpath by Zw");
	}
};

class CAMFacade
{
public:

	void setCamSys(std::shared_ptr<CAMSys> cam)
	{
		m_cam = cam;
	}

	void calcTpath() const
	{
		m_cam->calcTpath();
	}
private:
	std::shared_ptr<CAMSys> m_cam;
};


class FacadeTest
{
public:
	static void test()
	{
		TESTMODULE("Facade Test");

		std::shared_ptr<CAMFacade> facade = std::make_shared<CAMFacade>();
		std::shared_ptr<CAMSys> nx = std::make_shared<NXSys>();
		facade->setCamSys(nx);
		facade->calcTpath();

		std::shared_ptr<ZwSys> zw = std::make_shared<ZwSys>();
		facade->setCamSys(zw);
		facade->calcTpath();

	}
};