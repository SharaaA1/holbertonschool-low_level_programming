#include "main.h"

/**
 * _strchr - locates a character in a string
 * @s: pointer to the string to be searched
 * @c: character to locate
 *
 * Return: pointer to the first occurrence of c in s, or NULL if not found
 */
char *_strchr(char *s, char c)
{
	int i;

	i = 0;
	while (1)
	{
		if (s[i] == c)
		{
			return (s + i);
		}
		if (s[i] == '\0')
		{
			break;
		}
		i++;
	}

	return (0);
}
