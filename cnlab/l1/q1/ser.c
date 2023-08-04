#include "sockets.h"

int main()
{
    int sock, clientSock, i;
    char *msg, decMsg[256];
    sock = init(AF_INET, SOCK_STREAM);
    serverBind(sock, 8089);
    return 0;
    listen(sock, 1);
    while(1){
        printf("Waiting for clients...");
        clientSock = acceptClient(sock);
        msg = get(clientSock);
        for(i = 0; i < strlen(msg); i++)
        {
            decMsg[i] = msg[i] - 4;
        }
        printf("\nRecd: %s\n", msg);
    }
}