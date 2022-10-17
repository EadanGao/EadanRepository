#include <stdio.h>
#include <string.h>

void swap(int *a, int *b){
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
    return ;
}

int main() {
    int n;
    scanf("%d", &n);
    int letters[26] = {0};

    char str[10001];
    for(int i = 0; i < n; i++){
        scanf("%s", str);
        int len = strlen(str);
        memset(letters, 0, sizeof(letters));
        for(int i = 0; i < len; i++) letters[str[i] - 97]++;
        int cnt = 0;
        for(int i = 0; i < 25; i++){
            for(int j = 0; j < 25; j++){
                if(letters[j] < letters[j + 1]) swap(&letters[j], &letters[j + 1]);
            }
        }

        for(int i = 0; i < 26; i++) cnt += letters[i] * (26 - i);
        printf("%d\n", cnt);
        
    }

    return 0;
}