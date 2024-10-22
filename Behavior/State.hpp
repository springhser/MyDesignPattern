/*!
 * @file State.hpp
 *
 * @author chenj
 * @date 22/10/2024
 * @brief
 *     
 */
#pragma once

#include "Utils/HelpTool.hpp"

class Student;

class State
{
public:
    virtual void handle(Student* stu) = 0;
};

class Student
{
public:
    Student(std::shared_ptr<State> state, std::string name) :m_state(state), m_name(name) {}

    void changeState(std::shared_ptr<State> state)
    {
        m_state = state;
    }

    void doing()
    {
        m_state->handle(this);
    }

    const std::string& name() const
    {
        return m_name;
    }
private:
    std::shared_ptr<State> m_state;
    std::string m_name;
};

class Study: public State
{
public:
    virtual void handle(Student* stu)
    {
        PRINTN(stu->name() << " is in study.");
    }
};

class Sleep: public State
{
public:
    virtual void handle(Student* stu)
    {
        PRINTN(stu->name() << " is in sleep.");
    }
};

class Eat: public State
{
public:
    virtual void handle(Student* stu)
    {
        PRINTN(stu->name() << " is in eat food.");
    }
};


class StateTest
{
public:
    static void test()
    {
        TESTMODULE("State Test");
        std::shared_ptr<State> study = std::make_shared<Study>();
        std::shared_ptr<State> sleep = std::make_shared<Sleep>();
        std::shared_ptr<State> eat = std::make_shared<Eat>();
        std::shared_ptr<Student> stu = std::make_shared<Student>(sleep, "Jumbo");
        stu->doing();
        stu->changeState(eat);
        stu->doing();
        stu->changeState(study);
        stu->doing();
    }
};

