#include <stdio.h>
#include <math.h>


#define N 9223372036854775807

static int isPrime(long x);

int main (void)
{
	long i;
	long largest = 0;
	for (i = 3; i <= sqrt(N) + 1; i++) {
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

