#include "builtins.h"

/**
  * exit_ - exits from shell
  * @info: arguments passed
  * Return: int
  */
int exit_(info_t *info)
{
	char **args = info->tokens + 1;

	if (*args)
	{
		if (isnumber(*args) && atou(*args) <= INT_MAX)
		{
			info->status = atou(*args);
		}
		else
		{
			_lperror_default(info, *args, *info->tokens,
				"Illegal number", NULL);
			info->status = 2;

			return (info->status);
		}
	}
	if (info->script)
		close(STDIN_FILENO);

	free_info(info);
	exit(info->status);
}
