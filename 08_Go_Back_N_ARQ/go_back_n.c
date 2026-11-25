#include <stdio.h>

int main(void) {
    int frames, window, base = 0, next = 0, ack;
    printf("Enter number of frames: ");
    if (scanf("%d", &frames) != 1 || frames <= 0) return 1;
    printf("Enter window size: ");
    if (scanf("%d", &window) != 1 || window <= 0) return 1;

    while (base < frames) {
        while (next < base + window && next < frames) {
            printf("Sending frame %d\n", next);
            next++;
        }
        printf("Enter ACK received (-1 for lost ACK, otherwise next expected frame): ");
        if (scanf("%d", &ack) != 1) return 1;

        if (ack == -1) {
            printf("Timeout! Retransmitting from frame %d\n", base);
            next = base;
        } else if (ack > base && ack <= next) {
            base = ack;
            printf("Cumulative ACK received. Next expected frame: %d\n", base);
        } else {
            printf("Invalid or duplicate ACK. Retransmitting outstanding frames.\n");
            next = base;
        }
    }

    printf("All frames transmitted successfully.\n");
    return 0;
}
