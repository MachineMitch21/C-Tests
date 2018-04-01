
#ifndef FILESTREAMLISTENER_HPP
#define FILESTREAMLISTENER_HPP

#include "StreamListener.hpp"

class FileStreamListener : public StreamListener {

public:
    FileStreamListener();
    virtual ~FileStreamListener();

    void StreamWritten()    override;
    void StreamRead()       override;
    void StreamClosed()     override;

};

#endif // FILESTREAMLISTENER_HPP
