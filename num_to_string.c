#include <stdio.h>
#include <string.h>

#define MAX 999999

const char lower_str[19][20] = {"one", "two", "three", "four", "five", "six", "seven",
                                "eight", "nine", "ten", "eleven", "twelve", "thirteen",
                                "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
const char dozens_str[8][20] = {"twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};
const char high_str[2][20] = {"hundred ", "thousand "};

int main(void)
{
    int x, i = 100000;
    do {
        printf("Insert number:> ");
        scanf("%d", &x);
    } while (x > MAX);
    while (i != 0) {
        if (x / i != 0) {
            switch (i) {
            case 10: case 10000:
                if (x / i > 1) {
                    printf("%s", dozens_str[(x / i) - 2]);
                    x = x % i;
                }
                break;
            default:
                printf("%s ", lower_str[x / i - 1]);
                x = x % i;
                break;
            }
            if ((i == 100) || (i == 100000) || (i == 1000))
                printf("%s", high_str[(i / 1000) % 100]);
        }
        i = i / 10;
    }
    printf("\n");
    return 0;
}