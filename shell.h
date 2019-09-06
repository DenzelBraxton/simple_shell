#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>
#include "alias.h"
#include "builtins.h"
#include "command.h"
#include "ctype.h"
#include "dict.h"
#include "env.h"
#include "error.h"
#include "getline.h"
#include "info.h"
#include "list.h"
#include "quote.h"
#include "string.h"
#include "tokens.h"
#include "types.h"

extern char **environ;

int get_cmd(info_t *info);
int _get_cmd(info_t *info, char **lineptr, size_t *nptr);

int parse_cmd(info_t *info);

int exec_cmd(info_t *info);
int _exec_cmd(info_t *info);

char *search_path(info_t *info, list_t *path);

void expand_aliases(alias_t *aliases, char ***tokptr);
char *expand_alias(alias_t *aliases, char ***tokptr);

void expand_vars(info_t *info, char ***tokptr);
char **_expand_vars(info_t *info, char ***tokptr);

void remove_comments(cmdlist_t *cmd);

void open_script(info_t *info);

void _sigint(int signal);

#endif /* SHELL_H */
