/*
Provide the client side and server side program for the connections oriented socket using C to the students keeping blanks in between. These blanks are mostly the API to be called with their respective parameters which is to be filled up by the studebnts 

TCP-client.c
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    const char *message = "Hello, Server!";

    // Step 1: Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Step 2: Set up server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Step 3: Connect to the server
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    printf("Connected to server at 127.0.0.1:%d\n", PORT);

    // Step 4: Send a message to the server
    send(sock, message, strlen(message), 0);
    printf("Message sent: %s\n", message);

    // Step 5: Receive server's response
    ssize_t recv_size = recv(sock, buffer, sizeof(buffer), 0);
    if (recv_size > 0) {
        buffer[recv_size] = '\0';
        printf("Server response: %s\n", buffer);
    }

    // Step 6: Close the socket
    close(sock);

    return 0;
}
