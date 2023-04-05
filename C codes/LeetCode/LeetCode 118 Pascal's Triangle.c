#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    * returnColumnSizes =  (int *) malloc(numRows * sizeof(int));
    int ** triangle = malloc(numRows * sizeof(int*));
    *returnSize = numRows;
    int i = 0;
    while(i < numRows){
        triangle[i] = (int *) malloc((i + 1) * sizeof(int));
        (*returnColumnSizes)[i] = i + 1;
        int j = 0;
        triangle[i][j++] = 1, triangle[i][i] = 1; 
        while(j < i){
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            j++;
        }
        i++;
    }
    return triangle;
}



int main(){
    int numRows = 5, returnSize;
    // scanf("%d", &numRows);
    int * returnColumnSize = NULL;
    int ** triangle = NULL;
    triangle = generate(numRows, &returnSize, &returnColumnSize);
    for(int i = 0; i < numRows; i++){
        printf("i = %d: ", i);
        for(int j = 0; j < returnColumnSize[i]; j++){
            printf("%d ", triangle[i][j]);
        }
        printf("\n");
    }
    return 0;
}

// int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    
//     * returnColumnSizes =  (int *) malloc(numRows * sizeof(int));
//     int ** triangle = malloc(numRows * sizeof(int*));
//     *returnSize = numRows;
//     int i = 0;
//     while(i < numRows){
//         triangle[i] = (int *) malloc((i + 1) * sizeof(int));
//         (*returnColumnSizes)[i] = 0;
//         // printf("i + 1 = %d, numRows = %d\n", i + 1, numRows);
//         // int j = 0;
//         triangle[i][(*returnColumnSizes)[i]++] = 1, triangle[i][i] = 1; 
//         // printf("triangle[%d][%d] = %d, triangle[%d][%d] = %d\n", i, (*returnColumnSizes)[i] - 1, triangle[i][(*returnColumnSizes)[i] - 1], i, i, triangle[i][i]);
//         while((*returnColumnSizes)[i] < i){
//             triangle[i][(*returnColumnSizes)[i]] = triangle[i - 1][(*returnColumnSizes)[i] - 1] + triangle[i - 1][(*returnColumnSizes)[i]];
//             (*returnColumnSizes)[i]++;
//         }
//         // printf("i = %d, (*returnColumnSizes)[i] = %d\n", i, (*returnColumnSizes)[i]);
//         (*returnColumnSizes)[i] = i + 1;
//         i++;
//     }
//     return triangle;
// }
