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

int countDepth(struct TreeNode * root){
    if(root == NULL) return 0;
    int left = countDepth(root -> left);
    int right = countDepth(root -> right);
    if(left > right) return left + 1;
    else return right + 1;
}

bool isBalanced(struct TreeNode* root){
    if(root == NULL) return true;
    int left = countDepth(root -> left);
    int right = countDepth(root -> right);
    return abs(left - right) < 2 && isBalanced (root -> right) && isBalanced (root -> left);

}

int main(){
    struct TreeNode * bTree = creatNode(1);
    bTree -> right = creatNode(2);
    bTree -> right -> left = creatNode(3);
    isBalanced(bTree);

    return 0;
}