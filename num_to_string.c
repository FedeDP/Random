#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX 999999

const char lower_str[27][20] = {"one", "two", "three", "four", "five", "six", "seven",
                                "eight", "nine", "ten", "eleven", "twelve", "thirteen",
                                "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen",
                                "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};
const char higher_str[2][20] = {"hundred ", "thousand "};

int main(int argc, char *argv[])
{
    int x, i, n, p = 1;
    if (argc < 2) {
        printf("Usage: nts $num $num2 $num3...\n");
        return 1;
    }
    for (p = 1; argv[p]; p++, printf("\n")) {
        x = atoi(argv[p]);
        if (x > MAX)
            continue;
        for (n = 0, i = pow(10, (int) log10(x)); i != 0; x %= i, i /= 10, n = 0) {
            if (x / i != 0) {
                if ((int)(log10(i / 10)) % 3 == 0) {
                    if (x / i != 1)
                        n += 18;
                    else
                        i /= 10;
                }
                n += (x / i) - 1;
                printf("%s", lower_str[n]);
                if ((i == 100) || (i == 100000) || (i == 1000))
                    printf(" %s", higher_str[(i / 1000) % 100]);
            }
        }
    }
    return 0;
}