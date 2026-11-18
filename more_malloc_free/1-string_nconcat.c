#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - concatenates two strings using at most n bytes from s2
 * @s1: first string
 * @s2: second string
 * @n: maximum number of bytes to copy from s2
 *
 * Return: pointer to the newly allocated space in memory containing
 * the concatenated string, or NULL on failure
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *concat;
	unsigned int i, j, len1 = 0, len2 = 0;

	if (s1 != NULL)
	{
		while (s1[len1] != '\0')
			len1++;
	}
	if (s2 != NULL)
	{
		while (s2[len2] != '\0')
			len2++;
	}

	if (n < len2)
		len2 = n;

	concat = malloc(sizeof(char) * (len1 + len2 + 1));
	if (concat == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		concat[i] = s1[i];

	for (j = 0; j < len2; j++)
		concat[i + j] = s2[j];

	concat[i + j] = '\0';

	return (concat);
}
