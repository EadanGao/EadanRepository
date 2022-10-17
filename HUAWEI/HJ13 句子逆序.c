#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char sentence[1005];
    scanf("%[^\n]%*c", sentence);

    int length = strlen(sentence);
    while(--length >= 0){
        int * start = NULL;
        while(sentence[length] != ' ' && length >= 0) length--;
        start = &sentence[length + 1];
        printf("%s ", start);
        sentence[length] = '\0';
    }
    return 0;
}