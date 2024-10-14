
#pragma once

#include <memory>
#include "Utils/HelpTool.hpp"

class Color
{
public:
	virtual ~Color() {}

	virtual void show() const = 0;
};

class Red :public Color
{
public:
	virtual void show() const override
	{
		PRINTN("Red color");
	}
};

class Green :public Color
{
public:
	virtual void show() const override
	{
		PRINTN("Green color");
	}
};

class Shape
{
public:
	Shape(std::shared_ptr<Color>& color) :m_color(color) {}
	virtual ~Shape() {}
	virtual void display() const = 0;

protected:
	std::shared_ptr<Color> m_color;
};

class Rectangle:public Shape
{
public:
	Rectangle(std::shared_ptr<Color> color) :Shape(color) {}
	void display() const override
	{
		PRINT("It is a Rectangle with ");
		m_color->show();
	}
};

class Circle :public Shape
{
public:
	Circle(std::shared_ptr<Color> color) :Shape(color) {}
	void display() const override
	{
		PRINT("It is a Circle with ");
		m_color->show();
	}
};


class BridgeTest
{
public:
	static void test()
	{
		TESTMODULE("Bridge Test");
		std::shared_ptr<Color> red = std::make_shared<Red>();
		std::shared_ptr<Color> green = std::make_shared<Green>();

		std::shared_ptr<Shape> redRec = std::make_shared<Rectangle>(red);

		redRec->display();


		std::shared_ptr<Shape> greenCircle = std::make_shared<Circle>(green);

		greenCircle->display();
	}
};