#include <stdio.h>
#include <time.h>

#define DATASET_SIZE 50000
#define SEED_VALUE 42u

static int dataset[DATASET_SIZE];

static unsigned int next_value(unsigned int *state)
{
	*state = (*state * 1103515245u) + 12345u;
	return (*state);
}

static void build_dataset(void)
{
	unsigned int state;
	int i;

	state = SEED_VALUE;

	for (i = 0; i < DATASET_SIZE; i++)
		dataset[i] = (int)(next_value(&state) % 100000);
}

static void process_dataset(void)
{
	int i;
	int v;

	for (i = 0; i < DATASET_SIZE; i++)
	{
		v = dataset[i];
		v = (v * 3) + (v / 7) - (v % 11);
		if (v < 0)
			v = -v;
		dataset[i] = v;
	}
}

static unsigned long reduce_checksum(void)
{
	unsigned long sum;
	int i;

	sum = 0;
	for (i = 0; i < DATASET_SIZE; i++)
		sum = (sum * 131ul) + (unsigned long)dataset[i];

	return (sum);
}

int main(void)
{
	unsigned long checksum;
	clock_t t_total_start, t_total_end;
	clock_t t_build_start, t_build_end;
	clock_t t_proc_start, t_proc_end;
	clock_t t_red_start, t_red_end;
	double total_sec, build_sec, proc_sec, red_sec;

	t_total_start = clock();

	t_build_start = clock();
	build_dataset();
	t_build_end = clock();

	t_proc_start = clock();
	process_dataset();
	t_proc_end = clock();

	t_red_start = clock();
	checksum = reduce_checksum();
	t_red_end = clock();

	t_total_end = clock();

	if (checksum == 0ul)
		printf("impossible\n");

	total_sec = (double)(t_total_end - t_total_start) / (double)CLOCKS_PER_SEC;
	build_sec = (double)(t_build_end - t_build_start) / (double)CLOCKS_PER_SEC;
	proc_sec = (double)(t_proc_end - t_proc_start) / (double)CLOCKS_PER_SEC;
	red_sec = (double)(t_red_end - t_red_start) / (double)CLOCKS_PER_SEC;

	printf("TOTAL seconds: %.6f\n", total_sec);
	printf("BUILD_DATA seconds: %.6f\n", build_sec);
	printf("PROCESS seconds: %.6f\n", proc_sec);
	printf("REDUCE seconds: %.6f\n", red_sec);

	return (0);
}
