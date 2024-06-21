#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rules.h"

Rule *rules = NULL;
int num_rules = 0;

int load_rules(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open ruleset file");
        return 0;
    }

    fscanf(file, "%d", &num_rules);
    rules = malloc(num_rules * sizeof(Rule));
    if (!rules) {
        perror("Failed to allocate memory for rules");
        fclose(file);
        return 0;
    }

    for (int i = 0; i < num_rules; ++i) {
        char proto_str[8];
        if (fscanf(file, "%15s %15s %7s %7s", rules[i].src_ip, rules[i].dst_ip, proto_str, rules[i].action) != 4) {
            strcpy(rules[i].src_ip, "*");
            strcpy(rules[i].dst_ip, "*");
            strcpy(proto_str, "*");
            fscanf(file, "%7s", rules[i].action);
        }
        if (strcmp(proto_str, "tcp") == 0) {
            rules[i].proto = 6;
        } else if (strcmp(proto_str, "udp") == 0) {
            rules[i].proto = 17;
        } else {
            rules[i].proto = -1;
        }
    }

    fclose(file);
    return 1;
}

void free_rules() {
    free(rules);
    rules = NULL;
    num_rules = 0;
}
