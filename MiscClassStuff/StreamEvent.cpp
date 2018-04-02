
#include "StreamEvent.hpp"

StreamEvent::StreamEvent(const StreamEventData& evtData)
	:	_evtData(evtData)
{

}

StreamEvent::~StreamEvent()
{

}

StreamEventData StreamEvent::GetEventData()
{
	return _evtData;
}
