#include "sockets.h"

int main()
{
    char msg[256], enc_msg[256];
    int i;
    int sock = init(AF_INET, SOCK_STREAM);
    clientConnect(sock, 8089);
    while(1){
        printf("Enter msg: ");
        scanf("%[^\n]s", msg);
        for(i = 0; i < strlen(msg); i++)
        {
            enc_msg[i] = msg[i] + 4;
        }
        give(sock, enc_msg);
    }
}