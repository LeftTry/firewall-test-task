#ifndef RULES_H
#define RULES_H

typedef struct {
    char src_ip[16];
    char dst_ip[16];
    int proto;
    char action[8];
} Rule;

extern Rule *rules;
extern int num_rules;

int load_rules(const char *filename);
void free_rules();

#endif
