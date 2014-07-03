/*
 * This little programm will find the largest prime factor of N.
 */


#include <stdio.h>
#include <math.h>

#define N 9223372036854775807

static int isPrime(long x);

/*
 * we'll check specularly if i (between 3 and sqrt(N)) or N / i is prime.
 * if N/ i is prime, our work is finished. We are ready to print:
 * infact N/i will always be between sqrt(N) and N, being the largest prime factor possible.
 * If (for every i) N/i won't be a prime factor, we have to look at i. It will update
 * "largest" var every time it is a prime factor.
 * So, at the end of the for cycle, we'll have again the largest prime factor.
 */
int main (void)
{
	long i;
	long largest = 0;
	int inc = 1;
	if (N % 2 != 0)
		inc = 2;
	for (i = 3; i <= sqrt(N); i = i + inc) {
		if (N % i == 0) {
			if (N / i > largest && isPrime(N / i)) {
				largest = N / i;
				break;
			}
			if (i > largest && isPrime(i))
				largest = i;
		}
	}
	printf("%lu", largest);
	return 0;
}

static int isPrime(long x)
{
	long i;
	if (x % 2 == 0)
		return 0;
	for (i = 3; i <= sqrt(x); i = i + 2) {
		if (x % i == 0)
			return 0;
	}
	return 1;
}

