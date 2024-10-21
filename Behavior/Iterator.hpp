/*!
 * @file Iterator.hpp
 *
 * @author chenj
 * @date 21/10/2024
 * @brief
 *     
 */
#pragma once

#include "Utils/HelpTool.hpp"

template<typename T, typename Container>
class Iterator
{
public:
	using iter_type = typename std::vector<T>::iterator;

	Iterator(Container* data):m_data(data), m_curItr(data->m_vec.begin()){}
	virtual ~Iterator() { m_data = nullptr; }
	virtual void first() 
	{
		m_curItr = m_data->m_vec.begin();
	}
	virtual void next()
	{
		m_curItr++;
	}
	virtual bool isDone()
	{
		return m_curItr == m_data->m_vec.end();
	}

	T getCurItem()
	{
		return *m_curItr;
	}

private:
	Container* m_data;
	iter_type m_curItr;
};

class IntCollection
{
	friend class Iterator<int, IntCollection>;

public:
	IntCollection(){}
	~IntCollection(){}

	void pushBack(int val)
	{
		m_vec.push_back(val);
	}

	void popBack()
	{
		m_vec.pop_back();
	}

	std::shared_ptr<Iterator<int, IntCollection>> createIterator()
	{
		return std::make_shared<Iterator<int, IntCollection>>(this);
	}

private:
	std::vector<int> m_vec;
};

class CollectionClient
{
public:
	void TraverseCollection()
	{
		IntCollection intSet;
		intSet.pushBack(10);
		intSet.pushBack(9);
		intSet.pushBack(8);

		std::shared_ptr<Iterator<int, IntCollection>> iter = intSet.createIterator();
		for (iter->first(); !iter->isDone(); iter->next())
		{
			PRINTN(iter->getCurItem() << " ");
		}

	}
};

class IteratorTest
{
public:
	static void test()
	{
		TESTMODULE("Iterator Test");
		CollectionClient client;
		client.TraverseCollection();
	}
};