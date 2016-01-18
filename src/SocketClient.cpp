/*
    C ECHO client example using sockets
*/
#include<stdio.h> //printf
#include<string.h>    //strlen
#include<sys/socket.h>    //socket
#include<arpa/inet.h> //inet_addr
#include <unistd.h>
#include<stdlib.h>

int main(int argc , char *argv[])
{
	if (argc < 5) {
		perror("Not enough parameters");
		return 1;
	}

	char r = (char) atoi(argv[2]);
	char g = (char) atoi(argv[3]);
	char b = (char) atoi(argv[4]);

    int sock;
    struct sockaddr_in server;
    //char message[1000] , server_reply[2000];
    //int read_size;

    //Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
        printf("Could not create socket");
    }
    //puts("Socket created");

    //server.sin_addr.s_addr = inet_addr("127.0.0.1");
    //server.sin_addr.s_addr = inet_addr("192.168.1.120");
    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_family = AF_INET;
    server.sin_port = htons( 8888 );

    //Connect to remote server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("connect failed. Error");
        return 1;
    }

    //puts("Connected\n");

	char rgb[] = {r, g, b};

    //Send some data
    if( send(sock , rgb , 3, 0) < 0)
    {
        puts("Send failed");
        return 1;
    }

    /*

    //keep communicating with server
    while(1)
    {
        printf("Enter message : ");
        scanf("%s" , message);

        //Send some data
        if( send(sock , message , strlen(message) , 0) < 0)
        {
            puts("Send failed");
            return 1;
        }

        //Receive a reply from the server
        if( (read_size = recv(sock , server_reply , 2000 , 0)) < 0)
        {
            puts("recv failed");
            break;
        }

        server_reply[read_size] = 0;

        puts("Server reply :");
        puts(server_reply);
    }

    */

    close(sock);
    return 0;
}
