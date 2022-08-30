#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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



int main(){
    struct TreeNode * bTree = creatNode(1);
    bTree -> left = creatNode(2);
    bTree -> right = creatNode(2);
    bTree -> left -> left = creatNode(4);
    bTree -> left -> right = creatNode(5);
    bTree -> right -> left = creatNode(5);
    bTree -> right -> right = creatNode(4);

    printf("%d\n", isSymmetric(bTree));


    return 0;
}

// void inorderTraversal(struct TreeNode * root, int * returnSize, int * inorderNodes){
//     if(root == NULL) return ;
//     inorderTraversal(root -> left, returnSize, inorderNodes);
//     inorderNodes[(*returnSize)++] = root -> val;
//     inorderTraversal(root -> right, returnSize, inorderNodes);
//     return ;
// }
