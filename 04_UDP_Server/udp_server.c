#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8081
#define BUFFER_SIZE 1024

int main(void) {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) { perror("socket"); return 1; }

    struct sockaddr_in server, client;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    if (bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind"); close(sock); return 1;
    }

    char buffer[BUFFER_SIZE];
    socklen_t len = sizeof(client);
    printf("UDP server listening on port %d...\n", PORT);
    ssize_t n = recvfrom(sock, buffer, sizeof(buffer) - 1, 0,
                         (struct sockaddr *)&client, &len);
    if (n >= 0) {
        buffer[n] = '\0';
        printf("Client: %s\n", buffer);
        const char *reply = "Message received by UDP server";
        sendto(sock, reply, strlen(reply), 0,
               (struct sockaddr *)&client, len);
    }

    close(sock);
    return 0;
}
