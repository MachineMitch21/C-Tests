
#ifndef STREAMLISTENER_HPP
#define STREAMLISTENER_HPP

#include "StreamEvent.hpp"
class StreamEvent;

class StreamListener {

public:
    StreamListener();
    virtual ~StreamListener();

    virtual void StreamWritten(StreamEvent& streamEvt)    = 0;
    virtual void StreamRead(StreamEvent& streamEvt)       = 0;
    virtual void StreamClosed(StreamEvent& streamEvt)     = 0;

};

#endif // STREAMLISTENER_HPP
