
#include "ConsoleStreamListener.hpp"

#include <stdio.h>

ConsoleStreamListener::ConsoleStreamListener()
{

}

ConsoleStreamListener::~ConsoleStreamListener()
{

}

void ConsoleStreamListener::StreamWritten()
{
    printf("\a");
}

void ConsoleStreamListener::StreamRead()
{
    printf("\a");
}

void ConsoleStreamListener::StreamClosed()
{
    printf("\a");
}
