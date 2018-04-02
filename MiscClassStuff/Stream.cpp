
#include "Stream.hpp"

Stream::Stream()
    :   _listeners({})
{

}

Stream::~Stream()
{

}

void Stream::AddListener(StreamListener* listener)
{
    _listeners.push_back(listener);
}

void Stream::RemoveListener(StreamListener* listener)
{
    _listeners.remove(listener);
}

void Stream::FireWriteEvent(StreamEvent& se)
{
    LIST_SIZE_T size = _listeners.size();

    for (LIST_ITER it = _listeners.begin(); it != _listeners.end(); it++)
    {
        (*it)->StreamWritten(se);
    }
}

void Stream::FireReadEvent(StreamEvent& se)
{
    LIST_SIZE_T size = _listeners.size();

    for (LIST_ITER it = _listeners.begin(); it != _listeners.end(); it++)
    {
        (*it)->StreamRead(se);
    }
}

void Stream::FireCloseEvent(StreamEvent& se)
{
    LIST_SIZE_T size = _listeners.size();

    for (LIST_ITER it = _listeners.begin(); it != _listeners.end(); it++)
    {
        (*it)->StreamClosed(se);
    }
}
