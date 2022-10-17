#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swap(int * a, int *b){
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
    return ;
}

int containR(int R, int I){
    char i_str[10], r_str[10];
    sprintf(r_str, "%d", R);
    sprintf(i_str, "%d", I);
    if(strstr(i_str, r_str)) return 1;
    return 0;
}



int main() {
    int n_i, n_r;
    scanf("%d", &n_i);
    int * I = (int *) malloc(n_i * sizeof(int));
    for(int i = 0; i < n_i; i++) scanf("%d", &I[i]);
    scanf("%d", &n_r);
    int * R = (int *) malloc(n_r * sizeof(int));
    for(int i = 0; i < n_r; i++) scanf("%d", &R[i]);


    for(int i = 0; i < n_r - 1; i++){
        for(int j = 0; j < n_r - 1; j++){
            if(R[j] > R[j + 1]) swap(&R[j], &R[j + 1]);
            if(R[j] == R[j + 1]){
                for(int k = j; k > 0; k--) R[k] = R[k - 1];
                R++;
                n_r--;
            }
        }
        
    }
    
    int ** hashTable = (int **) malloc(n_r * sizeof(int *));
    for(int i = 0; i < n_r; i++) hashTable[i] = (int *) calloc((n_i + 1), sizeof(int));

    for(int i = 0; i < n_r; i++){
        for(int j = 0; j < n_i; j++){
            if(containR(R[i], I[j])){
                hashTable[i][0]++;
                hashTable[i][hashTable[i][0]] = j;
            }
            
        }
    }

    int n = 0;
    for(int i = 0; i < n_r; i++){
        if(hashTable[i][0]){
            n += 2;
            n += (hashTable[i][0] * 2);
        }
    }
    printf("%d", n);
    for(int i = 0; i < n_r; i++){
        if(hashTable[i][0]){
            printf(" %d", R[i]);
            printf(" %d", hashTable[i][0]);
            for(int j = 1; j < hashTable[i][0] + 1; j++){
                printf(" %d %d", hashTable[i][j], I[hashTable[i][j]]);
            }
        }
    }

    return 0;
}