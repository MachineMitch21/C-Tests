
#ifndef FILESTREAMLISTENER_HPP
#define FILESTREAMLISTENER_HPP

#include "StreamListener.hpp"

class FileStreamListener : public StreamListener {

public:
    FileStreamListener();
    virtual ~FileStreamListener();

    void StreamWritten(StreamEvent& streamEvt)    override;
    void StreamRead(StreamEvent& streamEvt)       override;
    void StreamClosed(StreamEvent& streamEvt)     override;

};

#endif // FILESTREAMLISTENER_HPP
