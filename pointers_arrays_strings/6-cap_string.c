#include "main.h"

/**
 * is_separator - checks if a character is a word separator
 * @c: character to check
 *
 * Return: 1 if separator, 0 otherwise
 */
int is_separator(char c)
{
	int i;
	char sep[] = " \t\n,;.!?\"(){}";

	i = 0;
	while (sep[i] != '\0')
	{
		if (c == sep[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

/**
 * cap_string - capitalizes all words of a string
 * @s: pointer to the string to be modified
 *
 * Return: pointer to the resulting string
 */
char *cap_string(char *s)
{
	int i;
	int cap_next;

	i = 0;
	cap_next = 1;
	while (s[i] != '\0')
	{
		if (is_separator(s[i]))
		{
			cap_next = 1;
		}
		else
		{
			if (cap_next && s[i] >= 'a' && s[i] <= 'z')
			{
				s[i] = s[i] - ('a' - 'A');
			}
			cap_next = 0;
		}
		i++;
	}

	return (s);
}
