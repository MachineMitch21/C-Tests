
#include "ConsoleStream.hpp"

#include <string>   // C++ strings
#include <string.h> // C strings

ConsoleStream::ConsoleStream()
    :   Stream()
{

}

ConsoleStream::~ConsoleStream()
{

}

bool ConsoleStream::Write(std::string data)
{
    printf("%s", data.c_str());

    StreamEventData sed = { this, data.c_str() };
    StreamEvent se(sed);
    FireWriteEvent(se);
    return true;
}

bool ConsoleStream::Read(std::string& read_data)
{
    char* line = getline();

    read_data.append(line);

	StreamEventData sed = { this, line };
	StreamEvent se(sed);
    FireReadEvent(se);

    free(line);
    return true;
}

bool ConsoleStream::Close()
{
    printf("Attempting to close console stream does nothing!\n");

    StreamEventData sed = { this, "" };
    StreamEvent se(sed);
    FireCloseEvent(se);
    return true;
}

char* ConsoleStream::getline() {
    char* line = (char*) malloc(100), *linep = line;
    size_t lenmax = 100, len = lenmax;
    int c;

    if(line == NULL)
        return NULL;

    for(;;) {
        c = fgetc(stdin);
        if(c == EOF)
            break;

        if(--len == 0) {
            len = lenmax;
            char * linen = (char*) realloc(linep, lenmax *= 2);

            if(linen == NULL) {
                free(linep);
                return NULL;
            }
            line = linen + (line - linep);
            linep = linen;
        }

        if((*line++ = c) == '\n')
            break;
    }
    *line = '\0';
    return linep;
}
