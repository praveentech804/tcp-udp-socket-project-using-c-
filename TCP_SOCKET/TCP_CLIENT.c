#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main()
{
int serv_sock;
char buffer[1024] = {0};
struct sockaddr_in serv_addr;
char *message = "hello from client";

serv_sock = socket(AF_INET, SOCK_STREAM, 0);
n
serv_addr.sin_family = AF_INET;
serv_addr.sin_port = htons(40000);
inet_pton(AF_INET, "192.168.1.4", &serv_addr.sin_addr);

connect(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)); 
printf("please wait client connect to server.......\n"); 

send(serv_sock, message, strlen(message),0); 
printf("Send message to server\n"); 

read(serv_sock, buffer, 1024); 
printf("server reply: %s\n", buffer); 

close(serv_sock); 
return 0; 

}


