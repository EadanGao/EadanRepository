#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isSameErro(int i, int *line, int *count, char (*record)[16], char *temp, int templine){
    for(int j = 0; j < i; j++){
        printf("%s\n", *(*record + j));

        if(strcmp(temp, record[j]) == 0 && line[j] == templine){
            count[j]++;
            return 1;
        }
    }
    return 0;
}

int main() {
    char address[105], record[101][16];
    int linein, line[101], count[101] = {0}, i = 0;

    while(scanf("%s %d", address, &linein) != EOF){
        int length = strlen(address);
        char *start = NULL;
        while(--length > 0){
            if(!isalpha(address[length])){
                start = &address[length - 1];
                break;
            }
        }
        while(strlen(start) > 16){
            start++;
        }

        int a = isSameErro(i, line, count, record, start, linein);
        printf("a = %d");

        if(!isSameErro(i, line, count, record, start, linein)){
            // record[i] = *start;
            strcpy(record[i], start);
            line[i] = linein;
            count[i]++;
        }
        i++;
    }

    int pointer = 0;

    if(i > 8) pointer = i - 8;

    while(pointer < i){
        printf("%s %d %d\n", record[pointer], line[pointer], count[pointer]);
        pointer++;
    }
    
    return 0;
}