/*!
 * @file Memento.hpp
 *
 * @author chenj
 * @date 21/10/2024
 * @brief
 *     
 */
#pragma once

#include "Utils/HelpTool.hpp"

class EditRecord
{
public:
	EditRecord(std::string content = "NULL") :m_content(content) {}
	
	std::string getContent() const
	{
		return m_content;
	}

	bool isNone() const
	{
		return m_content == "NULL";
	}

private:
	std::string m_content;
};

class EditHistory
{
public:

	void addRecord(int time_stamp, EditRecord record)
	{
		m_histroy.insert(std::pair<int, EditRecord>(time_stamp, record));
	}

	EditRecord getRecord(int time_stamp)
	{
		if (m_histroy.find(time_stamp) == m_histroy.end())
			return EditRecord();
		return m_histroy[time_stamp];
	}

private:
	std::map<int, EditRecord> m_histroy;
};

class Writer
{
public:
	Writer(std::string init_cont = ""):m_cur_content(init_cont)
	{
	}


	EditRecord createRecord()
	{
		return EditRecord(m_cur_content);
	}

	void rollbackRecord(const EditRecord& record)
	{
		m_cur_content = record.getContent();
	}

	std::string getCurContent() const
	{
		return m_cur_content;
	}

	void setContent(const std::string& content)
	{
		m_cur_content = content;
	}

private:
	std::string m_cur_content;
};

class MementoTest
{
public:
	static void test()
	{
		TESTMODULE("Memonto Test");
		EditHistory history;

		helptool::Timer<> timer;
		int time_stamp1 = timer.getTimeStamp();

		Writer write("Start...");
		EditRecord r1 = write.createRecord();

		// Save first version.
		history.addRecord(time_stamp1, r1);

		timer.sleep(1);

		write.setContent("I love you...");

		PRINTN("Current content: " << write.getCurContent());

		// Save record.
		EditRecord r2 = write.createRecord();
		int time_stamp2 = timer.getTimeStamp();
		history.addRecord(time_stamp2, r2);

		// Roll back to start
		PRINTN("Rollback to first version.");
		EditRecord old_rec = history.getRecord(time_stamp1);
		write.rollbackRecord(old_rec);

		PRINTN("Current content: " << write.getCurContent());
	}
};
