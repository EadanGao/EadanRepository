#include <stdio.h>
#include <string.h>

int main() {
    char str[101];
    scanf("%s", str);
    int i = 0, len = strlen(str);
    int isHead = 0;
    while(i < len){
        if(str[i] < '0' || str[i] > '9'){
            if(isHead > 0){
                printf("*");
                isHead = 0;
            }
            printf("%c", str[i]);
            i++;
            continue;
        }
        if(isHead == 0){
            printf("*");
            isHead = 1;
        }
        printf("%c", str[i]);
        i++;
    }
    if(str[i - 1] >= '0' && str[i - 1] <= '9') printf("*");
    
    return 0;
}