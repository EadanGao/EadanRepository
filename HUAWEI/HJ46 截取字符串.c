#include <stdio.h>
#include <string.h>

int main() {
    char str[1001];
    int k;
    scanf("%s", str);
    scanf("%d", &k);
    str[k] = '\0';
    printf("%s\n", str);
    return 0;
}