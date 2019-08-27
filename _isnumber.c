#include "shell.h"
/**
  * _isnumber - checks if the string consists of digits
  * @s: pointer to string
  * Return: int
  */

int _isnumber(char *s)
{
	while (*s)
	{
		if (_isdigit(*s) == 0)
			return (0);
		s++;
	}
	return (1);
}
