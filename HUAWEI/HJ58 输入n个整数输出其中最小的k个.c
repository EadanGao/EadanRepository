#include <stdio.h>

void swap(int *a, int *b){
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
    return ;
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int num[n];
    for(int i = 0; i < n; i++)scanf("%d", &num[i]);
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1; j++){
            if(num[j] > num[j + 1]) swap(&num[j], &num[j + 1]);
        }
    }
    for(int i = 0; i < k; i++) printf("%d ", num[i]);
    return 0;
}