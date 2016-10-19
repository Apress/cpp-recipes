// Windows.cpp : Defines the entry point for the console application.
//

#ifdef _MSC_VER
#define main _tmain
#include <tchar.h>

#pragma comment(lib, "Ws2_32.lib")
#endif

#ifndef _MSC_VER
using SOCKET = int;
#endif

#include <iostream>
#include <winsock2.h>
#include <WS2tcpip.h>

using namespace std;

int main(int argc, char* argv[])
{
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        return 1;
    }

    addrinfo hints{};
    hints.ai_family = AF_UNSPEC;     // don't care IPv4 or IPv6
    hints.ai_socktype = SOCK_STREAM; // TCP stream sockets

    // get ready to connect
    addrinfo* servinfo{};  // will point to the results
    getaddrinfo("www.google.com", "80", &hints, &servinfo);

    SOCKET sockfd{ socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol) };
    int connectionResult{ connect(sockfd, servinfo->ai_addr, servinfo->ai_addrlen) };
    if (connectionResult == -1)
    {
        cout << "Connection failed!" << endl;
    }
    else
    {
        cout << "Connection successful!" << endl;
    }

    freeaddrinfo(servinfo);

    WSACleanup();

	return 0;
}

