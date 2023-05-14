#include "shell.h"

/**
 * _print_env - prints the current environment variables
 * @info: structure containing arguments and environment variables
 * Return: Always 0
 */
int _print_env(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _get_env_var - gets the value of an environment variable
 * @info: structure containing arguments and environment variables
 * @name: name of the environment variable to get
 * Return: the value of the environment variable, or NULL if it is not found
 */
char *_get_env_var(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *value;

	while (node)
	{
		value = starts_with(node->str, name);
		if (value && *value)
			return (value);
		node = node->next;
	}
	return (NULL);
}

/**
 * _set_env_var - sets the value of an environment variable
 *or creates a new one
 * @info: structure containing arguments and environment variables
 * Return: Always 0
 */
int _set_env_var(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguments\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _unset_env_var - removes an environment variable
 * @info: structure containing arguments and environment variables
 * Return: Always 0
 */
int _unset_env_var(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few arguments.\n");
		return (1);
	}
	for (i = 1; i < info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * populate_env_list - populates env linked list
 * @info: structure containing arguments and environment variables
 * Return: Always 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
