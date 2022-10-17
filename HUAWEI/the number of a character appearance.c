#include <stdio.h>
#include<string.h>
int hashTable[43];

int main() {
    char str[1005];
    char target;
    scanf("%[^\n]%*c", str);
    scanf("%c", &target);
    int len = strlen(str);
    
    if(target > 90) target = target - 32;

    while(--len >= 0){
        // printf("str[len] = %c, %d len = %d\n", str[len], str[len], len);
        if(str[len]< 48) continue;
        if(str[len] > 90) str[len] = str[len] - 32;
        // printf("str[len] = %c, %d len = %d\n\n", str[len], str[len], len);
        hashTable[str[len] - 48]++;
    }
    printf("%d\n", hashTable[target - 48]);
    return 0;
}