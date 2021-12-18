#include "Client.h"
#include <iostream>

using namespace std;

Client::Client(string serv, int port)
{
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = inet_addr(serv.c_str());

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    comSocket = sockfd;
}

void Client::writeD(string t)
{
    const char* b = t.c_str();
    sendto(comSocket, b, strlen(b), MSG_CONFIRM, (const struct sockaddr *) &serv_addr, sizeof(serv_addr));
}

string Client::readD()
{

    int bCount;
    ioctl(comSocket, FIONREAD, &bCount);
    if (bCount < 1) //Nothing there
        return "";

     //1KB buffer
     char buffer[1024];
     bzero(buffer, 1024);
     socklen_t len;

    int n = recvfrom(comSocket, (char *)buffer, 1024, MSG_WAITALL, (struct sockaddr *) &serv_addr, &len);

    if (!n)
        return "";
    
    buffer[n] = '\0';
    return buffer;
}