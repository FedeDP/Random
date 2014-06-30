#include <stdio.h>
#include <math.h>

#define N 600851475143

int isPrime(long x);

int main (void)
{
	long i;
	for (i = 3; i < N / 2; i = i + 2) {
		if ((N % i == 0) && isPrime(N / i))
			break;
	}
	printf("%lu", N / i);
	return 0;
}

int isPrime(long x) {
	long i;
	for (i = 2; i <= sqrt(x); i++) {
		if (x % i == 0)
			return 0;
	}
	return 1;
}
