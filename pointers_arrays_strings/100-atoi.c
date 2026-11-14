#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: pointer to the string to be converted
 *
 * Return: the converted integer, or 0 if no numbers exist
 */
int _atoi(char *s)
{
	int i;
	int sign;
	int res;
	int started;

	i = 0;
	sign = 1;
	res = 0;
	started = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
		{
			sign *= -1;
		}
		else if (s[i] >= '0' && s[i] <= '9')
		{
			started = 1;
			res = (res * 10) - (s[i] - '0');
		}
		else if (started == 1)
		{
			break;
		}
		i++;
	}

	if (sign > 0)
	{
		res = -res;
	}

	return (res);
}
