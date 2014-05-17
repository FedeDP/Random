#include <stdio.h>

static int fibonacci_rec(int n);

int main(void)
{
	int n;
	printf("Which number of fibonacci sequence do you want?\n");
	scanf("%d", &n);
	n = fibonacci_rec(n);
	printf("Here it is: %d\n", n);
	return 0;
}

static int fibonacci_rec(int n)
{
	if  ((n == 1) || (n == 2))
		return 1;
	return fibonacci_rec(n - 1) + fibonacci_rec(n - 2);
}
