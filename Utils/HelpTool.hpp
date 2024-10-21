/*
 * @Descripttion: 
 * @version: 
 * @Author: springhser
 * @Date: 2019-02-04 12:23:58
 * @LastEditors: springhser
 * @LastEditTime: 2020-02-29 12:42:46
 */
#ifndef HELP_TOOL_HPP
#define HELP_TOOL_HPP

#include <iostream>

#define TESTMODULE(exp) std::cout << "========= " << #exp << " =========" << std::endl;
#define TESTCASE(exp) std::cout << "--------- " << exp << " ---------" << std::endl;

#define PRINTN(exp) std::cout << exp << std::endl;
#define PRINT(exp) std::cout << exp;

#define EQUAL(exp) std::cout << #exp<< ": "<< (exp? "true" :"false") << std::endl;

#include <cassert>

// Use (void) to silent unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))


#include <chrono>
#include <random>
#include <vector>
#include <map>
#include <string>
#include <thread>

namespace helptool
{
template<typename T=std::chrono::microseconds>
class Timer
{
public:
    Timer(const std::string& unit="micro seconds"):
        m_t(std::chrono::high_resolution_clock::now()),
        m_unit(unit),
        times_(1)   // 次数默认为1
    {

    }

    void setTimes(int times)
    {
        times_ = times;
    }

    int getTimeStamp()
    {
        auto time_tamp = std::chrono::high_resolution_clock::now();
        return time_tamp.time_since_epoch().count();
    }

    void sleep(int t)
    {
        std::this_thread::sleep_for(std::chrono::seconds(t));
    }

    ~Timer()
    {
        auto duration = std::chrono::duration_cast<T>(std::chrono::high_resolution_clock::now()-m_t);
        PRINTN("The execution time is: " << duration.count()/times_ << " " << m_unit);
    }
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_t;
    std::string m_unit;
    int times_;
};



template<typename T>
class RandomGenerator
{
public:
    RandomGenerator(unsigned seed=0):seed_(seed)
    {
    }

    ~RandomGenerator(){}

    std::vector<T> genNumsSeq(int min_num, int max_num, size_t numbers)
    {
        // 每次调用这个函数都会生成相同的 numbers 个数
        std::default_random_engine e;
        e.seed(seed_);             //调用 seed 设置为一个新种子值
        std::uniform_int_distribution<T > u(min_num, max_num);
        std::vector<T> ret;
        for(size_t i = 0; i<numbers;i++)
            ret.push_back(u(e));
        return ret;
    }

    void setSeed(unsigned seed)
    {
        seed_ = seed;
    }

private:
    unsigned seed_;
};

template<typename T>
class PrintContainer
{
public:

    void PrintVec(std::vector<T> vec)
    {
        for(auto v : vec)
        {
            PRINT(v << ", ");
        }
        PRINTN("");
    }
};

}




#endif