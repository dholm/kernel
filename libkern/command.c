#include <stddef.h>
#include <string.h>
#include <adt/tree.h>

#include "command.h"

static int command_compare(struct Command* lhs, struct Command* rhs)
{
    return strcmp(lhs->command, rhs->command);
}

SPLAY_HEAD(CommandTree, Command) command_tree;
SPLAY_PROTOTYPE(CommandTree, Command, node, command_compare);
SPLAY_GENERATE(CommandTree, Command, node, command_compare);

void command_init()
{
    SPLAY_INIT(&command_tree);
}

void command_add(struct Command* command)
{
    SPLAY_INSERT(CommandTree, &command_tree, command);
}

struct Command* command_find(const char* command)
{
    struct Command needle = {{NULL, NULL}, "", 0};
    strcat(needle.command, command);
    return SPLAY_FIND(CommandTree, &command_tree, &needle);
}
