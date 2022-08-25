#include <stdio.h>
#include <stdlib.h>

int removeElement(int* nums, int numsSize, int val){
    int temp = nums[0], i = 0, newSize = 0;
    while(i < numsSize){
        if(nums[i] != val){
            nums[newSize] = nums[i];
            newSize++;
        }
        i++;
    }
    return newSize;

}

int main(){
    int nums[] = {3,2,2,2,4,5,3,1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int val = 3;
    int k = removeElement(nums, numsSize, val);
    for(int i = 0; i < k; i++)  printf("%d ", nums[i]);
    printf("\n");

    return 0;
}
