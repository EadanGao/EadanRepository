#include <stdio.h>
#include <stdlib.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i = m - 1, j = n - 1;
    while(i > -1 && j > -1){
        if(nums1[i] > nums2[j]) nums1[--nums1Size] = nums1[i--];
        else nums1[--nums1Size] = nums2[j--];
    }
    
    while(j > -1) nums1[--nums1Size] = nums2[j--];
    while(i > -1) nums1[--nums1Size] = nums1[i--];

    return ;
}

int main(){
    int nums1[] = {1, 2, 3, 4, 0, 0, 0};
    int nums2[] = {2, 5, 6};
    int m = 4, n = 3;
    int nums1Size = m + n;
    int nums2Size = n;
    
    merge(nums1, nums1Size, m, nums2, nums2Size, n);
    for(int i = 0; i < nums1Size; i++) printf("%d ", nums1[i]);
    printf("\n");
    return 0;
}