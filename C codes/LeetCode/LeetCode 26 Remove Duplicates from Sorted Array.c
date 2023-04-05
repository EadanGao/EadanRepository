#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int* nums, int numsSize){
    if(numsSize == 1) return numsSize;

    int newSize = 0, temp = nums[0], i = 0;

    while(i < numsSize - 1){
        while(i < numsSize - 1 && temp == nums[i]) i++;

        nums[newSize] = temp;
        temp = nums[i];
        newSize++;   
    }

    if(temp != nums[newSize - 1]){
        nums[newSize] = nums[i];
        newSize++;  
    }
    
    return newSize;
}

int main(){
    int nums[] = {1,1,1, 1, 2, 2,2 ,2 ,2, 3,3 ,3 ,3 ,4,4 ,4 ,4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int k = removeDuplicates(nums, numsSize);
    printf("new Size: %d\n", k);
    for(int i = 0; i < k; i++) printf("%d ", nums[i]);
    printf("\n");
    return 0;
}