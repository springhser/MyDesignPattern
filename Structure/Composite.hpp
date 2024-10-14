
#pragma once

#include "Utils/HelpTool.hpp"

class BaseShape
{
public:
	virtual ~BaseShape() {};

	virtual void draw() const = 0;
};

class Square :public BaseShape
{
public:
	virtual ~Square() {}
	virtual void draw() const override
	{
		PRINTN("Draw a square.");
	}
};


class Eclipse :public BaseShape
{
public:
	virtual ~Eclipse() {}
	virtual void draw() const override
	{
		PRINTN("Draw a eclipse.");
	}
};

class Dot : public BaseShape
{
public:
	virtual ~Dot() {}
	virtual void draw() const override
	{
		PRINTN("Draw a eclipse.");
	}
};

class ComplexShape : public BaseShape
{
public:
	virtual ~ComplexShape() {};

	void addSubShape(std::shared_ptr<BaseShape> subShape)
	{
		m_children.push_back(subShape);
	}

	virtual void draw() const override
	{
		PRINTN("Draw a complex shape:{");
		for (const auto& child : m_children)
		{
			PRINT("\t");
			child->draw();
		}
		PRINTN("}");
	}
private:
	std::vector<std::shared_ptr<BaseShape>> m_children;

};


class CompositeTest
{
public:
	static void test()
	{
		TESTMODULE("Composite Test");
		std::shared_ptr<BaseShape> square = std::make_shared<Square>();
		std::shared_ptr<BaseShape> eclipse = std::make_shared<Eclipse>();
		std::shared_ptr<BaseShape> dot = std::make_shared<Dot>();

		square->draw();
		eclipse->draw();
		dot->draw();

		std::shared_ptr<ComplexShape> complexShape = std::make_shared<ComplexShape>();
		complexShape->addSubShape(square);
		complexShape->addSubShape(eclipse);
		complexShape->addSubShape(dot);
		complexShape->draw();
	}
};
