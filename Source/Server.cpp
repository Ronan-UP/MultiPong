#include <iostream>
#include "Server.h"

using namespace std;


Server::Server(int port)
{

    int sockfd =  socket(AF_INET, SOCK_STREAM, 0);
     if (sockfd < 0) 
     {
          cout<<"ERROR opening socket"<<endl;
          return;
     }

     sockaddr_in serv_addr;
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(port);

     int b = bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
     if (b<0)
     {
         cout<<"Could not bind socket"<<endl;
         return;
     }

    initSocket = sockfd;


}


bool Server::startListen()
{

    listen(initSocket, 1);
    sockaddr_in cli_addr;

    socklen_t clilen = sizeof(cli_addr);

    struct pollfd pfds[1];

    pfds[0].fd = initSocket;
    pfds[0].events = POLLIN;
    int num_events = poll(pfds, 1, 500);

    if (num_events == 0)
        return false;

    comSocket = accept(initSocket, (struct sockaddr*)&cli_addr, &clilen);
    return true;
}

string Server::readData() //Should be revised
{
    int bCount;
    ioctl(comSocket, FIONREAD, &bCount);

    if (bCount<1)
        return "";

    char buffer[256];
    bzero(buffer, 256);

    read(comSocket, buffer, 256);

    return buffer;
}

void Server::writeData(string dat)
{
    send(comSocket, dat.c_str(), dat.length(), 0);
}