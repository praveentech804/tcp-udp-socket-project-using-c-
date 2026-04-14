#include<stdio.h>
#include<unistd.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>

int main()
{
    int socket_fd;
    char *message = "hello from client";
    char buffer[1024] = {0};

    struct sockaddr_in server;
    socklen_t addrlen = sizeof(server);

    socket_fd = socket(AF_INET, SOCK_DGRAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(50000);
    inet_pton(AF_INET, "192.168.1.4", &server.sin_addr);



    sendto(socket_fd, message, strlen(message), 0, (struct sockaddr *)&server, addrlen);
    printf("client send data to server");


    recvfrom(socket_fd, buffer, 1024, 0, (struct sockaddr *)&server , &addrlen);
    printf("server reply :%s\n", buffer);

    


    close(socket_fd);

    return 0;

    




}
