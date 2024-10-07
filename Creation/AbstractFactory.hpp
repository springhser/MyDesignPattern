#pragma once

#include "Utils/HelpTool.hpp"

class Chair
{
public:
	virtual void show() const= 0;
};

class ModernChair :public Chair
{
public:
	virtual void show() override const
	{
		PRINTN("It is a modern chair.");
	}
};

class VictorianChair :public Chair
{
public:
	virtual void show() override const
	{
		PRINTN("It is a victorian chair.");
	}
};