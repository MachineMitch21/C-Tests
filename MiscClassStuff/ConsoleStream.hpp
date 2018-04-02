
#ifndef CONSOLESTREAM_HPP
#define CONSOLESTREAM_HPP

#include "Stream.hpp"

class ConsoleStream : public Stream {

public:
    ConsoleStream();
    virtual ~ConsoleStream();

    bool Write(std::string data)        override;
    bool Read(std::string& read_data)   override;
    bool Close()                        override;

private:
    char* getline();
};

#endif // CONSOLESTREAM_HPP
