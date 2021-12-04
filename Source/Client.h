#ifndef CLIENT_H
#define CLIENT_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/ioctl.h>
#include <netdb.h>

using namespace std;

//This class is used for client connections on a lan game
class Client
{
    public:
        Client(string server, int port);
        void writeD(string data);
        char* readD();
    private:
        int comSocket;



};

#endif