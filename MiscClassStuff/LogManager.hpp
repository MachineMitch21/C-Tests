
#ifndef LOGMANAGER_HPP
#define LOGMANAGER_HPP

#include <string>
#include "ConsoleStreamListener.hpp"
#include "FileStream.hpp"

class LogManager : public ConsoleStreamListener {

public:
	LogManager(const std::string& log_file);
	~LogManager();
	
    void StreamWritten(StreamEvent& streamEvt)    override;
    void StreamRead(StreamEvent& streamEvt)       override;
    void StreamClosed(StreamEvent& streamEvt)     override;
    
    bool SetLogFile(const std::string& log_file);
    
private:
	const char* GetLoggableCurrentTime();
    
private:
	FileStream*		_fStream;
    
};

#endif // LOGMANAGER_HPP
