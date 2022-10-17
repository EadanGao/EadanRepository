#include <stdio.h>
#include <string.h>
#define min(a, b) (a < b) ? a : b

void swapword(char *a, char *b){
    char temp[11];
    memcpy(temp, a, strlen(a) + 1);
    memcpy(a, b, strlen(b) + 1);
    memcpy(b, temp, strlen(temp) + 1);
    return ;
}


int isBrother(char a[], char b[]){
    int length = strlen(a);
    if(length != strlen(b)) return 0;

    int same = 0;
    for(int i = 0; i < length; i++){
        if(a[i] != b[i]) same++;
    }
    if(!same) return 0;

    char bcpy[11];
    memcpy(bcpy, b, length + 1);
    for(int i = 0; i < length; i++){
        int j = 0;
        while(j < length){
            if(a[i] == bcpy[j]){
                bcpy[j] = 0;
                break;
            }
            else j++;
        }
    }

    for(int i = 0; i < length; i++){
        if(bcpy[i]) return 0;
    }
    return 1;
}

int main() {
    int n, k;
    scanf("%d", &n);
    char words[n][11];
    for(int i = 0; i < n; i++) scanf("%s", words[i]);
    char target[11];
    scanf("%s", target);
    scanf("%d", &k);

    char list[n][11];
    int pointer = 0;


    for(int i = 0; i < n; i++){
        if(isBrother(target, words[i])){
            memcpy(list[pointer++], words[i], strlen(words[i]) + 1);
        }
    }

    // sort as dictionary
    for(int i = 0; i < pointer - 1; i++){
        for(int j = 0; j < pointer - 1; j++){
            int length = min(strlen(list[j]), strlen(list[j + 1]));
            int k = 0;
            while(k < length){
                if(list[j][k] < list[j + 1][k]) break;
                else if(list[j][k] > list[j + 1][k]){
                    swapword(list[j], list[j + 1]);
                    break;
                }
                else k++;
            }

            if(k == length && strlen(list[j]) > strlen(list[j + 1])){
                swapword(list[j], list[j + 1]);
            }
        }
    }

    if(!pointer) printf("0\n");
    else printf("%d\n%s", pointer, list[k - 1]);
    
    return 0;
}