#include <iostream>
#include "Server.h"

using namespace std;


Server::Server(int port)
{

    int sockfd =  socket(AF_INET, SOCK_DGRAM, 0);
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

    //Implement later......
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

    socklen_t len = sizeof(cliaddr);
    int n = recvfrom(initSocket, (char *)buffer, 1024, MSG_WAITALL, ( struct sockaddr *) &cliaddr, &len);

    if (!n)
        return "";
    
    buffer[n] = '\0';
    return buffer;

}

void Server::writeData(string dat)
{
    const char* d = dat.c_str();
    sendto(initSocket, d, strlen(d), MSG_CONFIRM, (const struct sockaddr *) &cliaddr, sizeof(cliaddr));
}