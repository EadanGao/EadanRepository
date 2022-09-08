#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void inorderPrint(struct TreeNode * root){
    if(root == NULL) return ;
    inorderPrint(root -> left);
    printf("%d ", root -> val);
    inorderPrint(root -> right);
    return ;
}

struct TreeNode * creatNode(int val){
    struct TreeNode * node = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    node -> val = val;
    node -> left = NULL;
    node -> right = NULL;
    return node;
}

// Recursion 1
// struct TreeNode * buildTree(int * nums, int start, int end){
//     if(start > end) return NULL;
//     int mid = (start + end) / 2;
//     struct TreeNode * node = creatNode(nums[mid]); 
//     node -> left = buildTree(nums, start, mid - 1);
//     node -> right = buildTree(nums, mid + 1, end);
//     return node;
// }

// struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
//     if(numsSize == 0) return NULL;
//     return buildTree(nums, 0, numsSize - 1);
// }

// Recursion 2
struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    if(numsSize == 0) return NULL;
    int mid = numsSize / 2;
    struct TreeNode * root = creatNode(nums[mid]);
    root -> left = sortedArrayToBST(nums, mid);
    root -> right = sortedArrayToBST((nums + mid + 1), (numsSize - mid - 1));
    return root;
}


int main(){
    int nums[] = {-10, -3, 0, 5, 9};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    // for(int i = 0; i < numsSize; i++) printf("%d ", nums[i]);
    // printf("\n"); printf("size = %d\n", numsSize);
    struct TreeNode * root = sortedArrayToBST(nums, numsSize); 

    inorderPrint(root); printf("\n");

    return 0;
}


