#include <stdio.h>
#include <math.h>

#define N 600851475143

int isPrime(long x);

int main (void)
{
	long i;
	long largest = 0;
	// Considero solo i numeri dispari (nessun pari sarà mai divisore del numero)
	for (i = 3; i < sqrt(N); i = i + 2) {
		// se i è divisore, e N / i è primo, N/i è il numero che stiamo cercando.
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
