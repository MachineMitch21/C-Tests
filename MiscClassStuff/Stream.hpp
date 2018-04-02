
#ifndef STREAM_HPP
#define STREAM_HPP

#include <string>
#include <list>

#include "StreamEvent.hpp"
#include "StreamListener.hpp"
class StreamListener;
class StreamEvent;

#define LIST_SIZE_T std::list<StreamListener*>::size_type
#define LIST_ITER   std::list<StreamListener*>::iterator

class Stream {

public:
    Stream();
    virtual ~Stream();

    virtual bool Write(std::string data)        = 0;
    virtual bool Read(std::string& read_data)   = 0;
    virtual bool Close()                        = 0;

    void AddListener(StreamListener* listener);
    void RemoveListener(StreamListener* listener);

protected:
    void FireWriteEvent(StreamEvent& se);
    void FireReadEvent(StreamEvent& se);
    void FireCloseEvent(StreamEvent& se);

private:
    std::list<StreamListener*> _listeners;
};

#endif // STREAM_HPP
