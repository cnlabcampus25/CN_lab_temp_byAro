/*
Provide the client side and server side program for the connections oriented socket using C to the students keeping blanks in between. These blanks are mostly the API to be called with their respective parameters which is to be filled up by the studebnts 

TCP-server.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int server_fd, new_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    socklen_t client_len;
    ssize_t read_size;

    // Step 1: Create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Step 2: Set up server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Step 3: Bind the socket
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Step 4: Listen for incoming connections
    if (listen(server_fd, 10) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d...\n", PORT);

    // Step 5: Accept a connection from the client
    client_len = sizeof(client_addr);
    new_socket = accept(server_fd, (struct sockaddr*)&client_addr, &client_len);
    if (new_socket < 0) {
        perror("Accept failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Client connected, waiting for message...\n");

    // Step 6: Communication loop
    while ((read_size = recv(new_socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[read_size] = '\0';  // Null-terminate the string
        printf("Received from client: %s\n", buffer);

        // Send a response to the client
        send(new_socket, "Message received", 16, 0);
    }

    if (read_size == 0) {
        printf("Client disconnected\n");
    } else if (read_size == -1) {
        perror("Recv failed");
    }

    // Step 7: Close sockets
    close(new_socket);
    close(server_fd);

    return 0;
}
