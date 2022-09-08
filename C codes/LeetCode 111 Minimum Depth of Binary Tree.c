#include <stdio.h>
#include <stdlib.h>
// #include <stdbool.h>

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

int minDepth(struct TreeNode * root){
    if(root == NULL) return 0;
    int left = minDepth(root -> left);
    int right = minDepth(root -> right);
    if(left == 0 || right == 0) return (left | right) + 1;
    if(left > right) return right + 1;
    else return left + 1;
}


int main(){
    struct TreeNode * bTree = creatNode(2);
    bTree -> right = creatNode(3);
    bTree -> right -> right = creatNode(4);
    bTree -> right -> right -> right = creatNode(5);
    bTree -> right -> right -> right -> right = creatNode(6);

    // struct TreeNode * bTree = creatNode(1);
    // bTree -> right = creatNode(2);
    printf("%d\n", minDepth(bTree));

    return 0;
}