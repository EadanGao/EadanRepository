#include <stdio.h>
#include <string.h>

int main() {
    char string[505];
    scanf("%s", string);
    int length = strlen(string);
    int hashTable[127] = {0};

    
    int count = 0;
    while(--length >= 0){
        // printf("length = %d hashTable[string[length]] = %d\n", length, hashTable[string[length]]);
        if(hashTable[string[length]]++) continue;
        // printf("count = %d, string[length] = %c\n", count, string[length]);
        count++;
    }

    printf("%d\n", count);

    

    return 0;
}