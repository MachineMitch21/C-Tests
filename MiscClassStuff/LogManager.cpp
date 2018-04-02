
#include "LogManager.hpp"

#include <time.h>
#include <chrono>

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

const char* LogManager::GetLoggableCurrentTime()
{
	auto log_time 				= std::chrono::system_clock::now();
	std::time_t	formatted_time 	= std::chrono::system_clock::to_time_t(log_time);
	
	return std::ctime(&formatted_time);
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
	evtStr.append("\n\nEntry Time: ");
	evtStr.append(GetLoggableCurrentTime());
	evtStr.append("\n\n");
	evtStr.append(std::string("Entry Data: ") + std::string(evtData._evtStr));
	
	evtStr.append("\n\n--------------------LOG DONE---------------------\n\n");
	
	_fStream->Write(evtStr);
}

void LogManager::StreamClosed(StreamEvent& streamEvt)
{
	
}
