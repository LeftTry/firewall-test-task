#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PACKETS 100

void generate_random_ip(char *ip) {
    sprintf(ip, "%d.%d.%d.%d",
            rand() % 256,
            rand() % 256,
            rand() % 256,
            rand() % 256);
}

void generate_random_packet() {
    char src_ip[16], dst_ip[16];
    int src_port, dst_port, proto;

    generate_random_ip(src_ip);
    generate_random_ip(dst_ip);
    src_port = rand() % 65536;
    dst_port = rand() % 65536;

    int proto_choice = rand() % 4;
    switch (proto_choice) {
        case 0:
            proto = 6;  // TCP
            break;
        case 1:
            proto = 17; // UDP
            break;
        case 2:
            proto = 1;  // ICMP
            break;
        default:
            proto = rand() % 256; // Other protocols
    }

    printf("%s %s %d %d %d\n", src_ip, dst_ip, src_port, dst_port, proto);
}

int main(int argc, char *argv[]) {
    int num_packets = 10; // Default number of packets

    if (argc > 1) {
        num_packets = atoi(argv[1]);
        if (num_packets <= 0 || num_packets > MAX_PACKETS) {
            fprintf(stderr, "Invalid number of packets. Using default value: 10.\n");
            num_packets = 10;
        }
    }

    srand(time(NULL));

    for (int i = 0; i < num_packets; ++i) {
        generate_random_packet();
    }

    return 0;
}
