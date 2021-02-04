#include <stdio.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h> 
#include <time.h> 
#define SA struct sockaddr 
#define PORT 8080 

struct packet{

    int id;
    int packno;
    int data;
    time_t time; // opaque data type

}tcp_packet;

int Rand(int lower, int upper, int count) 
{ 
    int i,num; 
    for (i = 0; i < count; i++)
    { 
         num = (rand() % (upper - lower + 1)) + lower; 
    } 
    return num;
} 
int main(int argc, char const *argv[])
{
    int lower = 30, upper = 300, count = 1; 
    srand(time(1)); 

    tcp_packet.data = Randfunc(lower, upper, count);
    printf("Data=%d",tcp_packet.data);

    tcp_packet.id=117;
    printf("Packet Id=%d\n",tcp_packet.id);

    tcp_packet.packno=10;
    printf("Packet Id=%d\n",tcp_packet.packno);


    int sockfd, connfd; 
    struct sockaddr_in servaddr, cli; 
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) { 
        printf("socket creation failed...\n"); 
        exit(0); 
    } 
    else
    {
        printf("Socket successfully created..\n"); 
    }
    // Assign IP,Port
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
    servaddr.sin_port = htons(PORT);

    if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0)
    { 
        printf("connection with the server failed...\n"); 
        exit(0); 
    } 
    else
        printf("connected to the server..\n"); 
  
    return 0; 
}