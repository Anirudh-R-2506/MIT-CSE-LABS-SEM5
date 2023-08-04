#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int init(int domain, int type)
{
    int sock;
    sock = socket(domain, type, 0);
    if (sock < 0){
        printf("Unable to create server");
        exit(0);
    }
    return sock;
}

void serverBind(int sock, int port)
{
    printf("Binding server...");
    struct sockaddr_in addr;
    addr.sin_port = htons(port);
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("172.16.59.44");
    if (bind(sock,(struct sockaddr *)&addr,sizeof(addr)) < 0){
        printf("Unable to bind server");
        exit(0);
    }
}

int acceptClient(int sock)
{
    struct sockaddr_in client;
    int clilen = sizeof(client);
    int newSock = accept(sock, (struct sockaddr *)&client, &clilen);
    if (newSock < 0){
        printf("Could not accept connection");
        return -1;
    }
    return newSock;
}

char *get(int newSock)
{
    char *buf;
    int n;
    n = recv(newSock, buf, sizeof(buf), AF_INET);
    if (n < 0){
        printf("Unable to read from client");
        buf = "err";
        return buf;
    }
    return buf;
}

void give(int newSock, char *msg)
{
    int n;
    n = send(newSock, msg, sizeof(msg), AF_INET);
    if (n < 0){
        printf("Unable to send to client");
    }
}

void clientConnect(int sock, int port)
{
    struct sockaddr_in addr;
    addr.sin_port = htons(port);
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("172.16.59.44");
    if (connect(sock,(struct sockaddr *)&addr,sizeof(addr)) < 0){
        printf("Unable to connect to server");
        exit(0);
    }
}