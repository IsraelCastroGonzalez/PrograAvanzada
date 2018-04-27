#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

int main() {
    struct sockaddr_in serverAddress;
    int serverSocket;
    int clientSocket;
    char clientMsg[1000];
    char *hello= "Hello World!";

    memset(&serverAddress, '0', sizeof(serverAddress));
    
    serverSocket = socket(PF_INET, SOCK_STREAM,0);

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddress.sin_port = htons(5000);
    bind(serverSocket,(struct sockaddr *)&serverAddress, sizeof(serverAddress));
    listen(serverSocket,10);
    while(1){
        clientSocket = accept(serverSocket,(struct sockaddr *)NULL,NULL);
        write(clientSocket,hello,strlen(hello));
        read(clientSocket, clientMsg,1000);
        printf("El cliente dice: %s\n", clientMsg);
        close(clientSocket);
    }

    return 0;
}