#include <stdio.h>
#include <string.h>
#include <limits.h>
#define min(a, b) a < b ? a : b

// find the minimum except 0
int findMin(int table[], int length){
    int minNumber = INT_MAX;
    for(int i = 0; i < length; i++){
        if(!table[i]) continue;
        minNumber = min(minNumber, table[i]);
    }
    return minNumber;
}

int main() {
    char string[21];
    scanf("%s", string);
    int hashTable[26] = {0};
    int length = strlen(string);
    int i = length;
    while(--i > -1) hashTable[string[i] - 97]++;

    int minNumber = findMin(hashTable, 26);
    int pointer = 0;
    while(++i < length){
        if(hashTable[string[i] - 97] == minNumber) continue;
        string[pointer] = string[i];
        pointer++;
    }
    string[pointer] = '\0';
    printf("%s\n", string);

    return 0;
}