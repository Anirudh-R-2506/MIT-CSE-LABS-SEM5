#include "sockets.h"

int main()
{
    char msg[256];
    char *recd;
    int i;
    int sock = init(AF_INET, SOCK_STREAM);
    clientConnect(sock, 8089);
    while(1){
        printf("Enter msg: ");
        scanf("%[^\n]s", msg);
        give(sock, msg);
        recd = get(sock);
        if(strcmp(recd, "stop") == 0){
            printf("Quitting...");
            exit(0);
        }
        printf("Recd: %s\n", recd);
    }
}