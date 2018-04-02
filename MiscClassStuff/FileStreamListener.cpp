
#include "FileStreamListener.hpp"

#include <stdio.h>

FileStreamListener::FileStreamListener()
    :   StreamListener()
{

}

FileStreamListener::~FileStreamListener()
{

}

void FileStreamListener::StreamWritten(StreamEvent& streamEvt)
{
    printf("\nThe Stream was written to!\n");
}

void FileStreamListener::StreamRead(StreamEvent& streamEvt)
{
    printf("\nThe Stream was read from!\n");
}

void FileStreamListener::StreamClosed(StreamEvent& streamEvt)
{
    printf("\nThe Stream was closed! :(\n");
}
