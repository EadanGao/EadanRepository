#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", (2 + 2 + (n - 1) * 3) * n / 2);

    return 0;
}