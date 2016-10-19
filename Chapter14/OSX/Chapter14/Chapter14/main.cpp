//
//  main.cpp
//  Chapter14
//
//  Created by Bruce Sutherland on 28/02/2015.
//  Copyright (c) 2015 Apress Publishing. All rights reserved.
//

#include <iostream>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>

using SOCKET = int;

using namespace std;

int main(int argc, const char * argv[])
{
    addrinfo hints{};
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    
    addrinfo *servinfo{};
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
    
    return 0;
}

