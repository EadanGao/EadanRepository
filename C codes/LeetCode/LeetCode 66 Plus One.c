#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* plusOne(int* digits, int digitsSize, int* returnSize){
    int * newDigits = (int *) malloc((digitsSize + 1) * sizeof(int));
    int i = digitsSize - 1;
    while(i > -1){
        if(digits[i] < 9){
            digits[i]++;
            *returnSize = digitsSize;
            return digits;
        }
        digits[i] = 0;
        i--;
    }
    *returnSize = digitsSize + 1;
    newDigits[0] = 1;
    for(int j = 1; j < *returnSize; j++) newDigits[j] = 0;
    // memcpy((newDigits + 1), digits, sizeof(digits));
    return newDigits;
}

int main(){
    int digits[] = {8,9,9,9};
    int digitsSize = sizeof(digits) / sizeof(digits[0]);
    int returnSize;
    for(int j = 0; j < digitsSize; j++) printf("%d ", digits[j] ); printf("\n\n");
    plusOne(digits, digitsSize, &returnSize);
    printf("%d\n", returnSize);
    return 0;
}