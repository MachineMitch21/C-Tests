
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

void Stream::FireWriteEvent()
{
    LIST_SIZE_T size = _listeners.size();

    for (LIST_ITER it = _listeners.begin(); it != _listeners.end(); it++)
    {
        (*it)->StreamWritten();
    }
}

void Stream::FireReadEvent()
{
    LIST_SIZE_T size = _listeners.size();

    for (LIST_ITER it = _listeners.begin(); it != _listeners.end(); it++)
    {
        (*it)->StreamRead();
    }
}

void Stream::FireCloseEvent()
{
    LIST_SIZE_T size = _listeners.size();

    for (LIST_ITER it = _listeners.begin(); it != _listeners.end(); it++)
    {
        (*it)->StreamClosed();
    }
}
