#include <stdio.h>

int isPalindrome(int x);

int main (void)
{
	int i,j;
	int prod = 0;
	for (i = 999; i >= 100; i--) {
		for (j = i; j >= 100; j--) {
			if (isPalindrome(i * j)) {
				if (i * j > prod)
					prod = i * j;
			}
		}
	}
	printf("%d", prod);
	return 0;
}

int isPalindrome(int x) {
	int inverted = 0;
	int num = x;
	while (x != 0) {
		inverted = inverted * 10 + x % 10;
		x = x / 10;
	}
	if (inverted != num)
		return 0;
	return 1;
}
