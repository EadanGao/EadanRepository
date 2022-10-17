#include <stdio.h>
#include <string.h>

void swapint(int *a, int *b){
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
    return ;
}

void swapstring(char *a, char *b){
    char temp[20];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
    return ;
}

int main() {
    int n, sequence;
    scanf("%d%d", &n, &sequence);
    char name[n][20];
    int score[n];
    for(int i = 0; i < n; i++){
        scanf("%s", name[i]);
        scanf("%d", &score[i]);
    }

    if(!sequence){
        for(int i = 0; i < n - 1; i++){
            for(int j = 0; j < n - 1; j++){
                if(score[j] < score[j + 1]){
                    swapint(&score[j], &score[j + 1]);
                    swapstring(name[j], name[j + 1]);

                }
            }
        }
    }
    else{
        for(int i = 0; i < n - 1; i++){
            for(int j = 0; j < n - 1; j++){
                if(score[j] > score[j + 1]){
                    swapint(&score[j], &score[j + 1]);
                    swapstring(name[j], name[j + 1]);

                }
            }
        }
    }

    for(int i = 0; i < n; i++) printf("%s %d\n", name[i], score[i]);

    return 0;
}