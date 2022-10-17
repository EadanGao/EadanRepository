#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *a, char *b){
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
    return ;
}

int main() {
    char * string = (char *) malloc(1001 * sizeof(char));
    scanf("%s", string);
    int length = strlen(string);

    for(int i = 0; i < length - 1; i ++){
        for(int j = 0; j < length - 1; j++){
            if(string[j] > string[j + 1]) swap(&string[j], &string[j + 1]);
        }
    }

    for(int i = 0; i < length; i++) printf("%c", string[i]);
    printf("\n");

    return 0;
}