#include <stdio.h>
#include <stdlib.h>

int searchInsert(int* nums, int numsSize, int target){
    int i = 0;
    while(i < numsSize && nums[i] < target) i++;
    return i;
}

int main(){
    int nums[] = {1,3,5,6};
    int target = 7;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    // printf("numsSize = %d\n", numsSize);
    printf("%d\n", searchInsert(nums, numsSize, target));
    return 0;
}