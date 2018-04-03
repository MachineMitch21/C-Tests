
#include "FileStream.hpp"

#include <string.h>
#include <assert.h>

FileStream::FileStream(std::string file, std::string mode)
    :   Stream(),
        _fp(NULL)
{
    if (OpenFile(file, mode))
    {
        printf("%s opened successfully!\n", file.c_str());
    }
    else
    {
        printf("Could not open %s!\n", file);
    }
}

FileStream::FileStream()
{

}

FileStream::~FileStream()
{

}

bool FileStream::OpenFile(std::string file, std::string mode)
{
    _fp = fopen(file.c_str(), mode.c_str());

    return (_fp != NULL);
}

bool FileStream::Write(std::string data)
{
    assert (_fp != NULL);

    const char* c_data = data.c_str();

    size_t size             = strlen(c_data);
    size_t bytes_written    = fwrite(c_data, sizeof(char), size, _fp);

    if (bytes_written != 0)
    {
    	StreamEventData sed = { this, c_data };
    	StreamEvent se(sed);
        FireWriteEvent(se);

        return true;
    }
    else if (bytes_written == 0)
    {
        return false;
    }

    return false;
}

bool FileStream::Read(std::string& read_data)
{
    assert (_fp != NULL);

    fseek(_fp, 0, SEEK_END);
    size_t size = ftell(_fp);
    rewind(_fp);

    char* buffer = (char*) malloc(sizeof(char) * size + 1);

    size_t bytes_read = fread(buffer, sizeof(char), size, _fp);

    if (bytes_read != 0)
    {
        read_data.append(buffer);

        StreamEventData sed = { this, read_data.c_str() };
        StreamEvent se(sed);
        FireReadEvent(se);

        free(buffer);
        return true;
    }

    free(buffer);
    return false;
}

bool FileStream::Close()
{
    fclose(_fp);

    StreamEventData sed = { this, "" };
    StreamEvent se(sed);
    FireCloseEvent(se);
    return true;
}

bool FileStream::SetFile(std::string file, std::string mode)
{
    return OpenFile(file, mode);
}
