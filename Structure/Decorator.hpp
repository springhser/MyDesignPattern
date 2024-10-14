#pragma once

#include "Utils/HelpTool.hpp"

class Data
{
public:
	virtual ~Data(){}

	virtual void writeData() const = 0;
};

class TxtData : public Data
{
public:
	virtual ~TxtData() {}

	virtual void writeData() const override
	{
		PRINTN("Write data to txt.");
	}
};

class DataDecorator :public Data
{
public:
	DataDecorator(std::shared_ptr<Data> data) :m_data(data) {}
	virtual ~DataDecorator(){}

protected:
	std::shared_ptr<Data> m_data;
};

class EncryptionData: public DataDecorator
{
public:
	EncryptionData(std::shared_ptr<Data> data) :DataDecorator(data) {}
	virtual ~EncryptionData(){}

	virtual void writeData() const
	{
		PRINT("Encrypt data. ");
		m_data->writeData();
	}
};

class CompressData : public DataDecorator
{
public:
	CompressData(std::shared_ptr<Data> data) :DataDecorator(data) {}
	virtual ~CompressData() {}

	virtual void writeData() const
	{
		PRINT("Compress data. ");
		m_data->writeData();
	}
};


class DecoratorTest
{
public:
	static void test()
	{
		TESTMODULE("Decorator Test");
		std::shared_ptr<Data>txt = std::make_shared<TxtData>();
		std::shared_ptr<Data> encryptTxt = std::make_shared<EncryptionData>(txt);
		std::shared_ptr<Data> compressEncTxt = std::make_shared<CompressData>(encryptTxt);

		compressEncTxt->writeData();

	}
};

