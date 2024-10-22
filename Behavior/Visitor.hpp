/*!
 * @file Visitor.hpp
 *
 * @author chenj
 * @date 22/10/2024
 * @brief
 *     
 */
#pragma once

#include "Utils/HelpTool.hpp"


class Video;
class Music;
class Text;

class Exporter
{
public:
	virtual void outputVideo(Video* video) = 0;
	virtual void outputMusic(Music* music) = 0;
	virtual void outputText(Text* text) = 0;
};

class Media
{
public:
    Media(int size, std::string name) :m_size(size), m_name(name) {}
    virtual int sizeMB() const
    {
        return m_size;
    }

    virtual std::string name() const
    {
        return m_name;
    }

    virtual void output(std::shared_ptr<Exporter> exporter) = 0;

private:
    int m_size;
    std::string m_name;
};

class Video :public Media
{
public:
    Video(int size, std::string name) :Media(size,  name) {}

    virtual void output(std::shared_ptr<Exporter> exporter) override
    {
        exporter->outputVideo(this);
    }
};

class Music :public Media
{
public:
    Music(int size, std::string name) :Media(size, name) {}

	virtual void output(std::shared_ptr<Exporter> exporter)
	{
		exporter->outputMusic(this);
	}
};

class Text :public Media
{
public:
    Text(int size, std::string name) :Media(size, name) {}

	virtual void output(std::shared_ptr<Exporter> exporter)
	{
		exporter->outputText(this);
	}
};

class DiskExporter :public Exporter
{
public:
    virtual void outputVideo(Video* video)
    {
        PRINTN("Save " << video->sizeMB() << " MB video " << video->name() << " to disk. ");
    }
    virtual void outputMusic(Music* music)
    {
        PRINTN("Save " << music->sizeMB() << " MB music " << music->name() << " to disk. ");
    }
    virtual void outputText(Text* text)
    {
        PRINTN("Save " << text->sizeMB() << " MB text " << text->name() << " to disk. ");
    }
};

class VisitorTest
{
public:
    static void test()
    {
        TESTMODULE("Visitor Test");
        std::shared_ptr<Exporter> disk = std::make_shared<DiskExporter>();
        std::shared_ptr<Video> video = std::make_shared<Video>(1024, "Oppenheimer");
        std::shared_ptr<Music> music = std::make_shared<Music>(40, "Lock me Up");
        std::shared_ptr<Text> text = std::make_shared<Text>(1, "Journey to the west");

        video->output(disk);
        music->output(disk);
        text->output(disk);
    }
};