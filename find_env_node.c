#include "env.h"

/**
  * find_env_node - finds the node by the key
  * @head: pointer to head
  * @key: key name
  * Return: node
  */
env_t *find_env_node(env_t *head, const char *key)
{
	if (!head)
		return (NULL);
	if (!_strcmp(head->key, key))
		return (head);
	return (find_env_node(head->next, key));
}
