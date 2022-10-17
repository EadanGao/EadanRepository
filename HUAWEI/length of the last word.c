#include <stdio.h>
#include <string.h>

int main() {

    char str[5005];
    scanf("%[^\n]", str);
    // scanf("%[^\n]%*c", str);
    printf("%s\n", str);
    int length = strlen(str);
    int last_length = 0;

    while(str[--length] != ' ' && length > -1) last_length++;

    printf("%d\n", last_length);
    return 0;
}