#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h> // max number will be 4 294 967 295
#include <errno.h>

const char lower_str[27][20] = {"one", "two", "three", "four", "five", "six", "seven",
                                "eight", "nine", "ten", "eleven", "twelve", "thirteen",
                                "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen",
                                "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};
const char higher_str[4][20] = {"hundred", "thousand", "million", "billion"};

int main(int argc, char *argv[])
{
    int i, n = 0, p = 1, l;
    unsigned long x;
    if (argc < 2) {
        printf("Usage: %s $num1 $num2 $num3...\n", argv[0]);
        return 1;
    }
    for (p = 1; p < argc; p++, printf("\n")) {
        errno = 0;
        x = strtoul(argv[p], NULL, 10);
        if ((x > UINT_MAX) || ((x == ULONG_MAX) && (errno == ERANGE))) {
            printf("Limit exceeded.");
            continue;
        }
        printf("%lu: ", x);
        for (i = pow(10, (int)log10(x)); i != 0; x %= i, i /= 10, n = 0) {
            if (x / i != 0) {
                if ((i != 1) && ((int)(log10(i / 10)) % 3 == 0)) {
                    (x / i != 1) ? (n += 18) : (i /= 10);
                }
                n += (x / i) - 1;
                printf("%s", lower_str[n]);
                l = (int)(log10(i)) % 3;
                if ((i != 1) && ((l == 0) || (l == 2))) {
                    (l == 2) ? (l = 0) : (l = (int)(log10(i)) / 3);
                    printf(" %s ", higher_str[l]);
                }
            }
        }
    }
    return 0;
}