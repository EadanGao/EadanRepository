#include <stdio.h>
#include <stdlib.h>

int *twoSum(int *nums, int numsSize, int target, int *returnSize);

int main()
{
    int numsSize; // default = 0
    scanf("%d", &numsSize);
    int nums[numsSize], target; //, returnSize[numsSize];
    int* returnSize = (int *) malloc(2 * sizeof(int));
    if (returnSize == NULL) exit(1);

    for (int i = 0; i < numsSize; i++) scanf("%d", &nums[i]);
    scanf("%d", &target);

    twoSum(nums, numsSize, target, returnSize);
    // printf("[%d %d]\n", returnSize[0], returnSize[1]);
    free(returnSize);

    return 0;
}

// Hash Table
int *twoSum(int *nums, int numsSize, int target, int *returnSize){
    int max = nums[0], min = nums[0];

    for(int i = 1; i < numsSize; i++){
        max = max > nums[i] ? max : nums[i];
        min = min < nums[i] ? min : nums[i];
    }

    int arrsize = max - min + 1;
    int *HT = calloc(arrsize--, sizeof(int));
    HT[nums[0] - min] = -1;
    for(int i = 1; i < numsSize; i++) HT[nums[i] - min] = i;

    // printf("arrsize = %d\n", arrsize);
    // for(int i = 0; i < arrsize; i++) printf("HT[%d] = %d\n", i, HT[i]);

    *returnSize = 2;
    int *output = (int*) malloc (2 * sizeof(int));
    int diff;
    for(int i = 0; i < numsSize; i++){
        diff = target - nums[i] - min;
        if(diff < 0 || diff > arrsize) continue;
        if(HT[diff]){
            output[0] = i;
            output[1] = HT[diff];
            if(HT[diff] < 0) output[1] = 0;
            if(output[0] == output[1]) continue;
            printf("[%d %d]\n", output[0], output[1]);
            free(HT);
            return output;
        }
    }
    return 0;
}


// O(n^2)
// int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
//     // printf("numsSize: %d\ntarget: %d\n", numsSize, target);
//     // for (int i = 0; i < numsSize; i++) printf("nums[%d] = %d\n", i, *(nums + i));
//     int i = 0;
//     while (i < numsSize)
//     {
//         int j = i + 1;
//         while (j < numsSize)
//         {
//             if (*(nums + i) + *(nums + j) == target)
//             {
//                 *(returnSize + 0) = i;
//                 *(returnSize + 1) = j;
//                 // printf("returnSize + 0 = %d\nreturnSize + 1 = %d\n", *(returnSize + 0), *(returnSize + 1));
//                 return returnSize;
//             }
//             else
//                 j++;
//         }
//         i++;
//     }
//     return 0;
// }