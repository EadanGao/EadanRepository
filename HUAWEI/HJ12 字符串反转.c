#include <stdio.h>
#include <string.h>

int main() {
    char string[1001];
    scanf("%s", string);
    int length = strlen(string);
    while(--length >= 0) printf("%c", string[length]);

    return 0;
}