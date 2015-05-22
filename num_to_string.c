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
    char final_str[100], temp[20];
    int x, i = 100000;
    final_str[0] = '\0';
    do {
        printf("Insert number:> ");
        scanf("%d", &x);
    } while (x > MAX);
    while (i != 0) {
        if (x / i != 0) {
            memset(temp, 0, strlen(temp));
            switch (i) {
            case 10: case 10000:
                if (x / i > 1)
                    sprintf(temp, "%s", dozens_str[(x / i) - 2]);
                break;
            default:
                sprintf(temp, "%s ", lower_str[x / i - 1]);
                break;
            }
            strcat(final_str, temp);
            if ((i == 100) || (i == 100000) || (i == 1000))
                strcat(final_str, high_str[(i / 1000) % 100]);
        }
        if (strlen(temp))
            x = x % i;
        i = i / 10;
    }
    printf("%s\n", final_str);
    return 0;
}