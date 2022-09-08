#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* constructArray(int n, int k, int* returnSize){
    int * ans = (int *) malloc(n * sizeof(int));
    int i = 1;
    *returnSize = 0;
    while(i < n - k) ans[(*returnSize)++] = i++;

    for(int i = n - k, j = n; i <= j; i++, j--){
        ans[(*returnSize)++] = i;
        if(i != j) ans[(*returnSize)++] = j;
    }
    *returnSize = n;
    return ans;

}


int main(){
    return 0;
}