#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isLetter(char c){
    if((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) return 1;
    return 0;
}

int main() {
    char * string  = (char *) malloc(10001 * sizeof(char));
    scanf("%[^\n]%*c", string);
    int length  = strlen(string) - 1;
    int pointer = 0;

    while(length > -1){
        while(isLetter(string[length - pointer]) && (length - pointer) > -1)  pointer++;
        if(pointer){
            int temp = length - pointer;
            while(pointer > 0) printf("%c",string[length + 1 - pointer--]);
            pointer = 0, length = temp;
        }

        while(!isLetter(string[length]) && (length - pointer) > -1) length--;
        printf(" ");       
    }

    free(string);
    return 0;
}