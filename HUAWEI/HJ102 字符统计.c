#include <stdio.h>
#include <string.h>

void swap(int *a, int *b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
    return;
}

int main()
{
    char str;
    int cnt[36] = {0};
    while (~scanf("%c", &str))
    {
        if (str >= '0' && str <= '9')
            cnt[str - '0']++;
        cnt[str - 'a' + 10]++;
    }
    int seq[36];
    for (int i = 0; i < 36; i++)
        seq[i] = i;
    for (int i = 0; i < 35; i++)
    {
        for (int j = 0; j < 35; j++)
        {
            if (cnt[j] < cnt[j + 1])
            {
                swap(&seq[j], &seq[j + 1]);
                swap(&cnt[j], &cnt[j + 1]);
            }
        }
    }
    int i = 0;
    while (cnt[i] > 0 && i < 36)
    {
        if (seq[i] < 10)
            printf("%d", seq[i]);
        else
            printf("%c", (char)seq[i] - 10 + 'a');
        i++;
    }

    return 0;
}