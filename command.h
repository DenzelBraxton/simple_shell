#ifndef COMMAND_H
#define COMMAND_H

#include <stdio.h>
#include <stdlib.h>
#include "quote.h"
#include "string.h"
#include "tokens.h"

/**
 * struct cmdlist - a linked list of command trees
 * @tokens: tokenized command
 * @next: next command
 */
typedef struct cmdlist
{
	char **tokens;
	struct cmdlist *next;
} cmdlist_t;

/**
 * struct cmdtree - a binary tree of commands
 * @cmd: a simple command with no separators
 * @left: the command to execute upon failure
 * @right: the command to execute upon success
 */
typedef struct cmdtree
{
	char *cmd;
	struct cmdtree *left;
	struct cmdtree *right;
} cmdtree_t;

size_t split_cmd(char *cmd);

cmdlist_t *cmd_to_list(const char *cmd);
cmdlist_t *_cmd_to_list(cmdlist_t **tailptr, const char *split, size_t count);

cmdlist_t *add_cmd(cmdlist_t **headptr, const char *cmd);
cmdlist_t *add_cmd_end(cmdlist_t **headptr, const char *cmd);
cmdlist_t *remove_cmd(cmdlist_t **headptr, size_t index);
void free_cmdlist(cmdlist_t **headptr);

cmdtree_t *cmd_to_tree(const char *cmd);
cmdtree_t *free_cmdtree(cmdtree_t **rootptr);

#endif /* COMMAND_H */
