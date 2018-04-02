
#ifndef STREAMEVENT_HPP
#define STREAMEVENT_HPP

#include <string>
#include "Stream.hpp"

class Stream;

struct StreamEventData{
	Stream*		_evtSrc;
	const char*	_evtStr;
};

class StreamEvent {

public:
	StreamEvent(const StreamEventData& evtData);
	~StreamEvent();
	
	StreamEventData	GetEventData();
	
private:
	StreamEventData	_evtData;
};

#endif // STREAMEVENT_HPP
