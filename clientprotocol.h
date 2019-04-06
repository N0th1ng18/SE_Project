#ifndef CLIENTPROTOCOL_H
#define CLIENTPROTOCOL_H

#include <QDebug>

class ClientProtocol
{
public:
    ClientProtocol();
    ~ClientProtocol();
    static void connectMainServer();
    static void disconnectMainServer();

};

#endif // CLIENTPROTOCOL_H
