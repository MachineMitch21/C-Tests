
#ifndef FILESTREAM_HPP
#define FILESTREAM_HPP

#include <stdio.h>
#include "Stream.hpp"

class FileStream : public Stream {

public:
    FileStream(std::string file, std::string mode);
    FileStream();
    ~FileStream();

    bool Write(std::string data)        override;
    bool Read(std::string& read_data)   override;
    bool Close()                        override;

    bool SetFile(std::string file, std::string mode);

protected:
    bool OpenFile(std::string file, std::string mode);

private:
    FILE* _fp;
};

#endif // FILESTREAM_HPP
