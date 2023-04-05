#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode * creatNode(int val){
    struct TreeNode * node = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    node -> val = val;
    node -> left = NULL;
    node -> right = NULL;
    return node;
}

void inorderSearch(struct TreeNode * root, int * returnSize, int * inorderNodes){
    if(root == NULL) return ;
    inorderSearch(root -> left, returnSize, inorderNodes);
    inorderNodes[(*returnSize)++] = root -> val;
    inorderSearch(root -> right, returnSize, inorderNodes);
    return ;
}


int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int * inorderNodes = (int *) malloc(100 * sizeof(int));
    *returnSize = 0;
    inorderSearch(root, returnSize, inorderNodes);
    return inorderNodes;
}

int main(){
    struct TreeNode * bTree = creatNode(1);
    bTree -> right = creatNode(2);
    bTree -> right -> left = creatNode(3);
    int returnSize = 0;
    int * order;

    order = inorderTraversal(bTree, &returnSize);
    for(int i = 0; i < returnSize; i++) printf("%d ", order[i]);
    printf("\n");
    return 0;
}