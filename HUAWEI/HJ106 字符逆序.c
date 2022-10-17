#include <stdio.h>
#include <string.h>

int main() {
    char str[10001];
    scanf("%[^\n]%*c", str);
    int len = strlen(str);
    while(-- len > -1){
        printf("%c", str[len]);
    }
    return 0;
}