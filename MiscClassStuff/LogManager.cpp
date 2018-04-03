
#include "LogManager.hpp"

#include <time.h>

LogManager::LogManager(const std::string& log_file)
	:	ConsoleStreamListener(),
		_fStream(new FileStream())
{
	SetLogFile(log_file);
}

LogManager::~LogManager()
{
	delete _fStream;
}

bool LogManager::SetLogFile(const std::string& log_file)
{
	return _fStream->SetFile(log_file, "a+");
}

std::string LogManager::GetLoggableCurrentTime()
{
	time_t rawtime;
    struct tm * timeinfo;
    char st [80];

    time (&rawtime);
    timeinfo = localtime (&rawtime);

    strftime (st,80,"%m/%d/20%y  %I:%M%p",timeinfo);

	return std::string(st);
}

void LogManager::StreamWritten(StreamEvent& streamEvt)
{
	StreamEventData evtData = streamEvt.GetEventData();

	std::string evtStr("--------------------LOG ENTRY--------------------");

	evtStr.append("\n\nEntry Reason: ConsoleWrite\n\n");
	evtStr.append("Entry Time: ");
	evtStr.append(GetLoggableCurrentTime());
	evtStr.append("\n\n");
	evtStr.append(std::string("Entry Data: ") + std::string(evtData._evtStr));

	evtStr.append("\n\n--------------------LOG DONE---------------------\n\n");

	_fStream->Write(evtStr);
}

void LogManager::StreamRead(StreamEvent& streamEvt)
{
	StreamEventData evtData = streamEvt.GetEventData();

	std::string evtStr("--------------------LOG ENTRY--------------------");

	evtStr.append("\n\nEntry Reason: ConsoleRead\n\n");
	evtStr.append("Entry Time: ");
	evtStr.append(GetLoggableCurrentTime());
	evtStr.append("\n\n");
	evtStr.append(std::string("Entry Data: ") + std::string(evtData._evtStr));

	evtStr.append("\n\n--------------------LOG DONE---------------------\n\n");

	_fStream->Write(evtStr);
}

void LogManager::StreamClosed(StreamEvent& streamEvt)
{

}
