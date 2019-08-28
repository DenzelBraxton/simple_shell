#ifndef PARSE_H
#define PARSE_H

#include "shell.h"

/**
 * struct cmd_list - a linked list of command trees
 * @cmd: a command
 * @left: the next command
 */
typedef struct cmd_list
{
	char *cmd;
	struct cmd_list *next;
} cmd_list_t;

/**
 * struct cmd_list - a binary tree of commands
 * @cmd: a simple command with no separators
 * @left: the command to execute upon failure
 * @right: the command to execute upon success
 */
typedef struct cmd_tree
{
	char *cmd;
	struct cmd_tree *left;
	struct cmd_tree *right;
} cmd_tree_t;

cmd_list_t *cmd_to_list(const char *cmd);
cmd_list_t *add_cmd(cmd_list_t **headptr, const char *cmd);
cmd_list_t *add_cmd_end(cmd_list_t **headptr, const char *cmd);
cmd_list_t *remove_cmd(cmd_list_t **headptr, size_t index);
cmd_list_t *free_cmd_list(cmd_list_t **headptr);

cmd_tree_t *cmd_to_tree(const char *cmd);
cmd_tree_t *free_cmd_tree(cmd_tree_t **rootptr);

char **tokenize(char *str);
char **tokenize_old(char *str);
size_t count_tokens(const char *str);
size_t count_tokens_old(const char *str);
char **free_tokens(char **tokens);

#endif /* PARSE_H */
