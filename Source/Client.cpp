#include "Client.h"

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
    
    if (buffer[0] == '@') //A message that must be acknowledged
    {
        int num, i;
        string t = "";
        for (i = 1;i<n && buffer[i] != '$';i++)
            t += buffer[i];

        try
        {
            num = stoi(t);
        }
        catch(...)
        {
            return "";
        }

        string data = "@%" + to_string(num) + "#";
        for (int k =0;k<20;k++) //Send ack 20 times
        {
            writeD(data);
        }

        string finalres = "";
        for (;i<n;i++)
            finalres += buffer[i];

        return finalres;

    }

    //cout<<buffer<<endl;
    buffer[n] = '\0';
    return buffer;
}