#include "shell.h"

/**
 * bfree - Frees a pointer and sets the address to NULL
 * @ptr: Address of the pointer to free
 *
 *This function frees the memory pointed to by the given pointer and sets the
 * pointer address to NULL.
 *
 * Return: 1 if freed successfully, 0 otherwise.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
