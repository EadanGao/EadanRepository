#include <stdio.h>
int num[4] = {1, 2, 3, 4};

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return ;
}

void perm(int offset, int n){
    if(offset == n -1){
        for(int i = 0; i < n; i++) printf("%d ", num[i]);
        printf("\n");
        return;
    }
    else{
        for(int i = offset; i < n; i++){
            swap(&num[i], &num[offset]);
            perm(offset + 1, n);
            swap(&num[i], &num[offset]);
        }
    }
}

int main(){
    int n = 4;
    // for(int i = 0; i < n; i++) printf("%d ", num[i]);
    //     printf("\n");
    perm(0, n);
    
    return 0;
}