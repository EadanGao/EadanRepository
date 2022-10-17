#include <stdio.h>
#include <string.h>

int main() {
    char str[251];
    scanf("%[^\n]%*c", str);
    int len = strlen(str); //printf("length = %d\n", len);
    int i = 0, cnt = 0;
    while(i < len){
        if(str[i] <= 'Z' && str[i] >= 'A') cnt++;
        i++;
    }
    printf("%d\n", cnt);

    return 0;
}