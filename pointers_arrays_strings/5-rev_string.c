#include "main.h"

/**
 * rev_string - reverses a string in place
 * @s: pointer to the string to be reversed
 *
 * Return: void
 */
void rev_string(char *s)
{
	int i;
	int j;
	char temp;

	j = 0;
	while (s[j] != '\0')
	{
		j++;
	}
	j--;

	i = 0;
	while (i < j)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}
}
