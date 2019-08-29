#include "shell.h"
/**
 * _cd - changes the directory
 * @info: arguments passed
 * Return: int
 */
int _cd(info_t *info)
{
	char **tokens = info->tokens;
	char *setenv_tokens[] = { "setenv", "OLDPWD", NULL, NULL };
	char *dir, *cmd_num, *error;

	info->tokens = setenv_tokens;
	setenv_tokens[2] = info->cwd;

	if (tokens[1])
	{
		dir = _getenv(info->env, "OLDPWD");
		if (_strcmp(tokens[1], "-") == 0)
		{
			write(STDOUT_FILENO, dir, _strlen(dir));
			write(STDOUT_FILENO, "\n", 1);
		}
		else if (dir)
			dir = tokens[1];
		else
			dir = ".";
		info->status = chdir(dir);
	}
	else
	{
		dir = _getenv(info->env, "HOME");
		if (dir)
			info->status = chdir(dir);
	}
	if (info->status < 0)
	{
		cmd_num = num_to_str(info->cmd_num);
		error = strjoin("can't cd to", dir, ' ');
		_perror(3, info->argv[0], cmd_num, error);
		free(cmd_num);
		free(error);
		info->status = EXIT_FAILURE;
	}
	else
	{
		_setenv(info);
		free(info->cwd);
		info->cwd = getcwd(NULL, 0);
		setenv_tokens[1] = "PWD";
		setenv_tokens[2] = info->cwd;
		_setenv(info);
		info->status = EXIT_SUCCESS;
	}

	info->tokens = tokens;
	return (info->status);
}
