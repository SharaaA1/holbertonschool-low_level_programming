#include "main.h"

/**
 * leet - encodes a string into 1337
 * @s: pointer to the string to encode
 *
 * Return: pointer to the encoded string
 */
char *leet(char *s)
{
	int i;
	int j;
	char letters[] = "aAeEoOtTlL";
	char numbers[] = "4433007711";

	i = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (letters[j] != '\0')
		{
			if (s[i] == letters[j])
			{
				s[i] = numbers[j];
			}
			j++;
		}
		i++;
	}

	return (s);
}
