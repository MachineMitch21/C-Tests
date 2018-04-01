
#ifndef STREAMLISTENER_HPP
#define STREAMLISTENER_HPP

class StreamListener {

public:
    StreamListener();
    virtual ~StreamListener();

    virtual void StreamWritten()    = 0;
    virtual void StreamRead()       = 0;
    virtual void StreamClosed()     = 0;

};

#endif // STREAMLISTENER_HPP
