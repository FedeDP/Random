#include <stdio.h>

int square_digit_sum(int num);

int main()
{
    int num;
    do {
        printf("Insert your number to be tested.\n");
        scanf("%d", &num);
    } while (num < 1);
    while ((num != 1) && (num != 4))
        num = square_digit_sum(num);
    if (num == 1)
        printf("Yep, it was a happy number :D\n");
    else
        printf("It was so sad :(\n");
    return 0;
}

int square_digit_sum(int num)
{
    int digit, sum = 0;
    do {
        digit = num % 10;
        if (digit != 0)
            sum = sum + (digit * digit);
        num = num / 10;
    } while (num != 0);
    return sum;
}