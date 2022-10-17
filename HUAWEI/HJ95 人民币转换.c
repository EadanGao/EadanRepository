#include <stdio.h>

char single[11][4] = {"零", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖", "拾"};

void thousands(long long integer)
{
    if (integer >= 1000)
    {
        long long temp = integer / 1000;
        printf("%s仟", single[temp]);
        integer = integer % 1000;
        if (integer < 100 && integer > 0)
            printf("零");
    }

    if (integer >= 100)
    {
        long long temp = integer / 100;
        printf("%s佰", single[temp]);
        integer = integer % 100;
        if (integer < 10 && integer > 0)
            printf("零");
    }

    if (integer >= 20)
    {
        long long temp = integer / 10;
        printf("%s拾", single[temp]);
        temp = integer % 10;
        if (temp)
            printf("%s", single[temp]);
    }
    else if (integer > 10)
    {
        int temp = integer % 10;
        printf("拾%s", single[temp]);
    }
    else if (integer > 0)
    {
        printf("%s", single[integer]);
    }
    return;
}

int main()
{
    double num;
    scanf("%lf", &num);
    long long integer = (long long)num;

    printf("人民币");

    if (integer >= 100000000)
    {
        long long ii = integer / 100000000;
        if (ii >= 10000)
        {
            long long temp = integer / 10000;
            thousands(temp);
            printf("%s万", single[temp]);
            temp = ii % 10000;
            if (ii < 1000 && ii > 0)
                printf("零");
            ii %= 10000;
            integer /= 10000;
        }

        thousands(ii);
        printf("亿");
        integer %= 100000000;
        // printf("\n%lld\n", integer);
        if (integer < 10000000 && integer > 0)
            printf("零");
    }

    if (integer >= 10000)
    {
        long long temp = integer / 10000;
        thousands(temp);
        printf("%s万", single[temp]);
        temp = integer % 10000;
        if (temp < 1000 && temp > 0)
            printf("零");
        integer %= 10000;
    }

    thousands(integer);
    if (integer >= 1)
        printf("元");

    integer = (long long)num;
    num = num - integer;
    integer = (long long)(num * 100 + 0.1);

    if (num == 0)
        printf("整");
    else
    {
        long long temp = integer / 10;
        if (temp > 0)
            printf("%s角", single[temp]);
        temp = integer % 10;
        if (temp)
            printf("%s分", single[temp]);
    }

    return 0;
}