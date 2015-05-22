#include <stdio.h>
#include <string.h>

const char lower_str[29][20] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
                    "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
const char dozens_str[8][20] = {"twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};
const char high_str[2][20] = {"hundred", "thousand"};

int main(void)
{
    char final_str[100];
    char temp[20];
    int x, i = 1000;
    final_str[0] = '\0';
    do {
        printf("Insert number:> ");
        scanf("%d", &x);
    } while (x > 99999);
    while (i != 0) {
        if (x / i != 0) {
            switch (i) {
            case 1000:
                if ((x / i < 20) || ((x / i) % 10 == 0))
                    sprintf(temp, "%s %s ", lower_str[x / i - 1], high_str[1]);
                else
                    sprintf(temp, "%s%s %s ", dozens_str[(x / (i * 10))  - 2], lower_str[(x % (i * 10) / 1000) - 1] , high_str[1]);
                break;
            case 100:
                sprintf(temp, "%s %s ", lower_str[x / i - 1], high_str[0]);
                break;
            case 10: case 1:
                if (x < 20) {
                    sprintf(temp, "%s", lower_str[x - 1]);
                    i = 0;
                } else {
                    sprintf(temp, "%s", dozens_str[(x / i) - 2]);
                }
                break;
            }
            strcat(final_str, temp);
        }
        if (i != 0) {
            x = x % i;
            i = i / 10;
        }
    }
    printf("%s\n", final_str);
    return 0;
}