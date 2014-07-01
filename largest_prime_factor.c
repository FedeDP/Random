#include <stdio.h>
#include <math.h>

#define N 600851475143

int isPrime(long x);

int main (void)
{
	long i;
	long largest = 0;
	for (i = 3; i < sqrt(N); i = i + 2) {
		if (N % i == 0) {
			if (isPrime(N / i) && N / i > largest)
				largest = N / i;
			else if (isPrime(i) && i > largest)
				largest = i;
		}
	}
	printf("%lu", largest);
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
