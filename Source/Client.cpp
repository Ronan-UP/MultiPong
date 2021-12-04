#include "Client.h"

using namespace std;

Client::Client(string serv, int port)
{
    struct hostent *server = gethostbyname(serv.c_str());
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;

    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
    comSocket = sockfd;
    //delete server; //Watch out
}

void Client::writeD(string t)
{
    const char* b = t.c_str();
    write(comSocket, b, strlen(b));
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
    read(comSocket, buffer, 1024);
    return buffer;
}