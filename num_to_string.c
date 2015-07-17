#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h> // max number will be 4 294 967 295

const char lower_str[27][20] = {"one", "two", "three", "four", "five", "six", "seven",
                                "eight", "nine", "ten", "eleven", "twelve", "thirteen",
                                "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen",
                                "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};
const char higher_str[4][20] = {"hundred", "thousand", "million", "billion"};

int main(int argc, char *argv[])
{
    int i, n, p = 1, l;
    unsigned int x;
    if (argc < 2) {
        printf("Usage: nts $num $num2 $num3...\n");
        return 1;
    }
    for (p = 1; p < argc; p++, printf("\n")) {
        x = atoi(argv[p]);
        if (x > UINT_MAX)
            continue;
        for (n = 0, i = pow(10, (int)log10(x)); i != 0; x %= i, i /= 10, n = 0) {
            if (x / i != 0) {
                if ((i != 1) && ((int)(log10(i / 10)) % 3 == 0)) {
                    if (x / i != 1)
                        n += 18;
                    else
                        i /= 10;
                }
                n += (x / i) - 1;
                printf("%s", lower_str[n]);
                l = (int)(log10(i)) % 3;
                if ((i != 1) && ((l == 0) || (l == 2))) {
                    if (l == 2)
                        l = 0;
                    else
                        l = (int)(log10(i)) / 3;
                    printf(" %s ", higher_str[l]);
                }
            }
        }
    }
    return 0;
}