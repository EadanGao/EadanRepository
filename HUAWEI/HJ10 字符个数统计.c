#include <stdio.h>
#include <string.h>

int main() {
    char string[505];
    scanf("%s", string);
    int length = strlen(string);
    int hashTable[127] = {0};

    
    int count = 0;
    while(--length >= 0){
        if(hashTable[string[length]]++) continue;
        count++;
    }

    printf("%d\n", count);

    

    return 0;
}