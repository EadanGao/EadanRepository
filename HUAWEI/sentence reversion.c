#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char sentence[1001];
    scanf("%[^\n]%*c", sentencae);

    int length = strlen(sentence);

    while(--length >= 0){
        int * start = NULL;
        while(sentence[length] != ' ' && length >= 0) length--;
        start = &sentence[length + 1];
        printf("start: %s \n", start);
        sentence[length] = '\0';
        printf("sentence = %s, length = %d\n", sentence, length);
        // printf("length = %d\n", length);
    }
    return 0;
}