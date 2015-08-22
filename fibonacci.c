#include <stdio.h>
#include <time.h>
#include <stdint.h>

#define BILLION 1000000000L

static unsigned long fibonacci_rec(int n);
static unsigned long fibonacci_it(int n);

int main(void)
{
	int n;
    unsigned long res;
    uint64_t diff;
    struct timespec start, end;


    do {
        printf("Which number of fibonacci sequence do you want?\n");
        scanf("%d", &n);
    } while (n < 1);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
    res = fibonacci_rec(n);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
    diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    printf("\tRECURSIVE\nHere it is: %lu.\nIt took %llu nanoseconds\n", res, (long long unsigned int)diff);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
    res = fibonacci_it(n);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
    diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    printf("\tITERATIVE\nHere it is: %lu.\nIt took %llu nanoseconds\n", res, (long long unsigned int)diff);
	return 0;
}

static unsigned long fibonacci_rec(int n)
{
	if  ((n == 1) || (n == 2))
		return 1;
	return fibonacci_rec(n - 1) + fibonacci_rec(n - 2);
}

static unsigned long fibonacci_it(int n)
{
    int i;
    unsigned long res = 1, old_res[2] = {};

    for (i = 1; i < n; i++) {
        old_res[0] = res;
        res+=old_res[1];
        old_res[1] = old_res[0];
    }
    return res;
}