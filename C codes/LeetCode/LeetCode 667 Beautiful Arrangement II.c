#include <stdio.h>
#include <stdlib.h>

int* constructArray(int n, int k, int* returnSize){
    int * num = (int *) malloc(n * sizeof(int));
    
    (*returnSize) = 0;
    while((*returnSize) < n - k) num[(*returnSize)++] = (*returnSize);
    int i = *returnSize + 1, j = n;;
    while((*returnSize) < n){
        num[(*returnSize)++] = j--;
        if((*returnSize) < n) num[(*returnSize)++] = i++;
    }
    return num;
}


// int* constructArray(int n, int k, int* returnSize){
//     int * ans = (int *) malloc(n * sizeof(int));
//     int i = 1;
//     *returnSize = 0;
//     while(i < n - k) ans[(*returnSize)++] = i++;

//     for(int i = n - k, j = n; i <= j; i++, j--){
//         ans[(*returnSize)++] = i;
//         if(i != j) ans[(*returnSize)++] = j;
//     }
//     *returnSize = n;
//     return ans;

// }



int main(){
    int n, k, returnSize;
    int a = scanf("%d %d", &n, &k);
    int * num = NULL;
    num = constructArray(n, k, &returnSize);
    // for(int i = 0; i < returnSize; i++) printf("%d ", num[i]);
    // printf("\n");
    return 0;
}

