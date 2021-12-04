#ifndef SERVER_H
#define SERVER_H

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/ioctl.h>
#include <iostream>

using namespace std;

//This class is used to act as the host, using sockets to check for data from the client connection
class Server
{
    private:
        int initSocket;
        int comSocket;

    public:
    Server(int port);
    void startListen();
    //Get buffered data
    string readData();
    void writeData(string dat);
};

#endif