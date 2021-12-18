#include <iostream>
#include "Server.h"

using namespace std;


Server::Server(int port)
{
    ackNo = 0;

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
    sendto(initSocket, d, strlen(d), MSG_CONFIRM, (const struct sockaddr*)&cliaddr, sizeof(cliaddr));
}

//Send data and wait for Ack. Lazy man's TCP. Disregards all incoming packets and looks for ack.
//l is the number of times the message is sent
void Server::writeDataAck(string dat, int l)
{
    int checkNum = ackNo++;
    string add = "@" + to_string(checkNum) + dat;
    const char* d = add.c_str();

    cout<<"Sending:"<<d<<endl;
    bool rec = false;
    while (!rec && l>0)
    {
        sendto(initSocket, d, strlen(d), MSG_CONFIRM, (const struct sockaddr*)&cliaddr, sizeof(cliaddr));
        string res = readData();

        sleep(0.1);

        string val = "";
        int i =0;
        for (;i<res.length() && res[i] != '@';i++)
        {}

        if (i<res.length() && res[i+1] == '%')
        {
            i+= 2;
            string text = "";
            while (res[i] != '#')
                text += res[i++];

            try
            {
                int found = stoi(text);
                if (found == checkNum) //Packet acknowledged
                    rec = true;
            }
            catch (...) {}

        }

        l--;        
    }
}