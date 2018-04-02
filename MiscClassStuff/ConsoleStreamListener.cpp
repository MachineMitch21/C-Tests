
#include "ConsoleStreamListener.hpp"

#include <stdio.h>

ConsoleStreamListener::ConsoleStreamListener()
{

}

ConsoleStreamListener::~ConsoleStreamListener()
{

}

void ConsoleStreamListener::StreamWritten(StreamEvent& streamEvt)
{
    printf("\a");
}

void ConsoleStreamListener::StreamRead(StreamEvent& streamEvt)
{
    printf("\a");
}

void ConsoleStreamListener::StreamClosed(StreamEvent& streamEvt)
{
    printf("\a");
}
