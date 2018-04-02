
#ifndef CONSOLESTREAMLISTENER_HPP
#define CONSOLESTREAMLISTENER_HPP

#include "StreamListener.hpp"

class ConsoleStreamListener : public StreamListener {

public:
    ConsoleStreamListener();
    virtual ~ConsoleStreamListener();

    void StreamWritten(StreamEvent& streamEvt)    override;
    void StreamRead(StreamEvent& streamEvt)       override;
    void StreamClosed(StreamEvent& streamEvt)     override;

};

#endif // CONSOLESTREAMLISTENER_HPP
