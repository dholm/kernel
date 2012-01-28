#ifndef COMMAND_H
#define COMMAND_H

#include <adt/tree.h>

struct Command {
    SPLAY_ENTRY(Command) node;
    char command[128];
    int x;
};

void command_init();
void command_add(struct Command* command);
struct Command* command_find(const char* command);

#endif /* COMMAND_H */
