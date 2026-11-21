#include <stdio.h>

/**
 * main - finds and prints the largest prime factor of 612852475143
 *
 * Return: Always 0.
 */
int main(void)
{
	unsigned long n = 612852475143;
	unsigned long div = 2;

	while (div * div <= n)
	{
		if (n % div == 0)
		{
			n /= div;
		}
		else
		{
			div++;
		}
	}
	printf("%lu\n", n);

	return (0);
}
