
#ifndef CONSOLESTREAMLISTENER_HPP
#define CONSOLESTREAMLISTENER_HPP

#include "StreamListener.hpp"

class ConsoleStreamListener : public StreamListener {

public:
    ConsoleStreamListener();
    virtual ~ConsoleStreamListener();

    void StreamWritten()    override;
    void StreamRead()       override;
    void StreamClosed()     override;

};

#endif // CONSOLESTREAMLISTENER_HPP
