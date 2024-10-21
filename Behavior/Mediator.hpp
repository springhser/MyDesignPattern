/*!
 * @file Mediator.hpp
 *
 * @author chenj
 * @date 21/10/2024
 * @brief
 *     
 */
#pragma once

#include "Utils/HelpTool.hpp"

class AClient;

class Agency
{
public:
	virtual ~Agency() {}
	virtual void sendMsg(const std::string& msg, AClient* client)  = 0;

};

class AClient
{
public:
	AClient(Agency* agency) :m_agency(agency) {}
	virtual ~AClient(){}
	virtual void sendMsg(const std::string& msg)  = 0;
	virtual void recieveMsg(const std::string& msg)  = 0;

protected:
	Agency* m_agency;
};

class Landlord :public AClient
{
public:
	Landlord(Agency* agency) :AClient(agency) {}
	virtual ~Landlord(){}
	virtual void sendMsg(const std::string& msg) 
	{
		m_agency->sendMsg(msg, this);
	}
	virtual void recieveMsg(const std::string& msg) 
	{
		PRINTN("Landlord recieve the message: " << msg);
	}
};

class Renter :public AClient
{
public:
	Renter(Agency* agency) :AClient(agency) {}
	virtual ~Renter() {}
	virtual void sendMsg(const std::string& msg) 
	{
		m_agency->sendMsg(msg, this);
	}
	virtual void recieveMsg(const std::string& msg) 
	{
		PRINTN("Renter recieve the message: " << msg);
	}
};

class HouseAgent :public Agency
{
public:
	HouseAgent(){}

	void setClientPair(AClient* landLord,
		AClient* renter)
	{
		m_landLord = landLord;
		m_renter = renter;
	}

	virtual void sendMsg(const std::string& msg, AClient* client)  override
	{
		if (client == m_landLord)
			m_renter->recieveMsg(msg);
		else
			m_landLord->recieveMsg(msg);
	}
private:
	AClient* m_landLord;
	AClient* m_renter;
};

class MediatorTest
{
public:
	static void test()
	{
		TESTMODULE("Mediator Test");
		HouseAgent* houseAgent = new HouseAgent();
		Landlord* landLord = new Landlord(houseAgent);
		Renter* renter = new Renter(houseAgent);

		houseAgent->setClientPair(landLord, renter);

		renter->sendMsg("I want to rent house.");
		landLord->sendMsg("OK. 5000 yuan, please.");

		delete houseAgent;
		delete landLord;
		delete renter;

	}
};


