#include <stdio.h>

int main(void) {
    int n, capacity, output_rate, bucket = 0;
    printf("Enter number of incoming packets: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;
    printf("Enter bucket capacity: ");
    if (scanf("%d", &capacity) != 1 || capacity <= 0) return 1;
    printf("Enter output rate per time unit: ");
    if (scanf("%d", &output_rate) != 1 || output_rate <= 0) return 1;

    for (int i = 0; i < n; i++) {
        int packet;
        printf("Enter packet size at time %d: ", i + 1);
        if (scanf("%d", &packet) != 1 || packet < 0) return 1;

        if (bucket + packet > capacity)
            printf("Packet of size %d dropped (bucket overflow).\n", packet);
        else {
            bucket += packet;
            printf("Packet accepted. Bucket occupancy: %d\n", bucket);
        }

        int sent = bucket < output_rate ? bucket : output_rate;
        bucket -= sent;
        printf("Transmitted: %d, remaining: %d\n", sent, bucket);
    }

    while (bucket > 0) {
        int sent = bucket < output_rate ? bucket : output_rate;
        bucket -= sent;
        printf("Transmitted: %d, remaining: %d\n", sent, bucket);
    }
    return 0;
}
