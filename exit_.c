#include "shell.h"


int exit_(info_t *info)
{
	char *cmd_num;

	if (info->tokens[1])
	{
		if (_isnumber(info->tokens[1]) != 0)
			info->status = _atoi(info->tokens[1]);
		else
		{

			cmd_num = num_to_str(info->cmd_num);
			_perror(5, info->argv[0], cmd_num, info->tokens[0], "Illegal number", info->tokens[1]);
			free(cmd_num);
			info->status = 2;
			return (info->status);
		}
	}
	free(info->line);
	free_list(&info->path);
	free(info->cwd);
	free_env(&info->env);
	free(info->full_cmd);
	free_tokens(info->tokens);

	exit(info->status);
	return (0);
}
