#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rules.h"

#define MAX_LINE_LENGTH 256

void process_packet(const char* src_ip, const char* dst_ip, int src_port, int dst_port, int proto) {
    for (int i = 0; i < num_rules; ++i) {
        Rule rule = rules[i];

        if ((strcmp(rule.src_ip, "*") == 0 || strcmp(rule.src_ip, src_ip) == 0) &&
            (strcmp(rule.dst_ip, "*") == 0 || strcmp(rule.dst_ip, dst_ip) == 0) &&
            (rule.proto == -1 || rule.proto == proto)) {
            printf("%s\n", rule.action);
            return;
        }
    }
    printf("DROP\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <ruleset file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (!load_rules(argv[1])) {
        fprintf(stderr, "Failed to load ruleset.\n");
        return EXIT_FAILURE;
    }

    char line[MAX_LINE_LENGTH];
    char src_ip[16], dst_ip[16];
    int src_port, dst_port, proto;

    while (fgets(line, sizeof(line), stdin)) {
        if (sscanf(line, "%15s %15s %d %d %d", src_ip, dst_ip, &src_port, &dst_port, &proto) != 5) {
            fprintf(stderr, "Error: Invalid input format.\n");
            continue;
        }
        process_packet(src_ip, dst_ip, src_port, dst_port, proto);
    }

    free_rules();
    return 0;
}
