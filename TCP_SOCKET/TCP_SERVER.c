#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h> 

int main()
{
int socket_fd, client_fd;
char buffer[1024] = {0};
struct sockaddr_in sockaddr, clientaddr;
socklen_t addresslen = sizeof(clientaddr);
char *msg = "hello from server";

socket_fd = socket(AF_INET, SOCK_STREAM, 0);

sockaddr.sin_family = AF_INET;
sockaddr.sin_port = htons(40000);
inet_pton(AF_INET, "192.168.1.4", &sockaddr.sin_addr);


if(bind(socket_fd, (struct sockaddr *)&sockaddr, sizeof(sockaddr)) < 0)
{
    perror("Bind connection failed");
   
}

listen(socket_fd, 5);


client_fd = accept(socket_fd, (struct sockaddr *)&clientaddr, &addresslen);

int read_return = read(client_fd, buffer, 1024);

if(read_return > 0)
{
    buffer[read_return] = '\0';
}
printf("client_Msg : %s\n", buffer);


send(client_fd, msg, strlen(msg), 0);
printf("server sended data to reciver \n");

close(socket_fd);
close(client_fd);

return 0;



}


