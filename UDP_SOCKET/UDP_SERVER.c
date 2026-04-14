#include<stdio.h>
#include<unistd.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>

int main()
{
    int socket_fd;
    char *message = "hello from server";
    char buffer[1024] = {0};

    struct sockaddr_in server, client;
    socklen_t addrlen = sizeof(client);

    socket_fd = socket(AF_INET, SOCK_DGRAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(50000);
    inet_pton(AF_INET, "192.168.1.4", &server.sin_addr);



    bind(socket_fd, (struct sockaddr *)&server, sizeof(server));


    recvfrom(socket_fd, buffer, 1024, 0, (struct sockaddr *)&client , &addrlen);
    printf("client reply :%s\n", buffer);

    
    sendto(socket_fd, message, strlen(message), 0, (struct sockaddr *)&client, addrlen);
    printf("server send data to client\n");


    close(socket_fd);

    return 0;

    




}
