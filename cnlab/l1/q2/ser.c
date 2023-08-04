#include "sockets.h"

int main()
{
    int sock, clientSock, i;
    char *msg, decMsg[256];
    sock = init(AF_INET, SOCK_STREAM);
    serverBind(sock, 8089);
    while(1){
        printf("Waiting for clients...");
        clientSock = acceptClient(sock);
        msg = get(clientSock);
        if (strcmp(msg, "stop") == 0){
            give(clientSock, "stop");
            printf("Quitting...");
            exit(0);
        }
        printf("\nRecd: %s\n", msg);
    }
}