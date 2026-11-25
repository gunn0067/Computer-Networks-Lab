#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(void) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) { perror("socket"); return 1; }

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect"); close(sock); return 1;
    }

    char message[BUFFER_SIZE], reply[BUFFER_SIZE] = {0};
    printf("Enter message: ");
    if (!fgets(message, sizeof(message), stdin)) { close(sock); return 1; }
    send(sock, message, strlen(message), 0);
    ssize_t n = recv(sock, reply, sizeof(reply) - 1, 0);
    if (n > 0) printf("Server: %s\n", reply);

    close(sock);
    return 0;
}
