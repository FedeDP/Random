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
    int x, i, n;
    for (x = atoi(argv[1]), n = 0, i = pow(10, (int) log10(x)); i != 0; x %= i, i /= 10, n = 0) {
        if (x / i != 0) {
            if ((i == 10) || (i == 10000)) {
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
    printf("\n");
    return 0;
}