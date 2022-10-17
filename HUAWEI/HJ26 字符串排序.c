#include <stdio.h>
#include <string.h>

void swap(char *a, char *b){
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
    return ;
}

int main() {
    char string[1001], letters[1001];
    scanf("%[^\n]%*c", string);

    int length = strlen(string);
    int pointer = 0;

    for(int i = 0; i < length; i++){
        if((string[i] > 64 && string[i] < 91) || (string[i] > 96 && (string[i] < 123))){
            letters[pointer++] = string[i];
            string[i] = -1;
        }
    }

    

    for(int i = 0; i < pointer - 1; i++){
        for(int j = 0; j < pointer - 1; j++){
            int temp = (letters[j] > 90) ? letters[j] - 32 : letters[j];
            int temp2 = (letters[j + 1] > 90) ? letters[j + 1] - 32 : letters[j + 1];
            if(temp > temp2) swap(&letters[j], &letters[j + 1]);
        }
    }

    
    int j = 0;
    for(int i = 0; i < length; i++){
        if(string[i] < 0) printf("%c", letters[j++]);
        else printf("%c", string[i]);
    }

    return 0;
}