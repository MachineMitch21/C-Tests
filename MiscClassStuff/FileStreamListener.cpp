
#include "FileStreamListener.hpp"

#include <stdio.h>

FileStreamListener::FileStreamListener()
    :   StreamListener()
{

}

FileStreamListener::~FileStreamListener()
{

}

void FileStreamListener::StreamWritten()
{
    printf("\nThe Stream was written to!\n");
}

void FileStreamListener::StreamRead()
{
    printf("\nThe Stream was read from!\n");
}

void FileStreamListener::StreamClosed()
{
    printf("\nThe Stream was closed! :(\n");
}
