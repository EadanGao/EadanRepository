#include <stdio.h>

void swap(int *a, int *b){
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
    return ;
}

int main() {
    int m, n;
    scanf("%d", &m);
    int num1[m];
    for(int i = 0; i < m; i++) scanf("%d", &num1[i]);
    scanf("%d", &n);
    int num[m + n];
    for(int i = 0; i < m; i++) num[i] = num1[i];
    for(int i = m; i < n + m; i++) scanf("%d", &num[i]);

    for(int i = 0; i < m + n - 1; i++){
        for(int j = 0; j < m + n - 1; j++){
            if(num[j] > num[j + 1]) swap(&num[j], &num[j + 1]);
        }
    }

    for(int i = 0; i < m + n - 1; i++){
        if(num[i] == num[i + 1]){
            for(int k = i + 1; k < m + n - 1; k++) num[k] = num[k + 1];
            n--;
            i--;
        }
    }
    for(int l = 0; l < m + n; l++) printf("%d", num[l]);

    
    return 0;
}