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


bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if(p == NULL && q == NULL) return true;
    if(p == NULL || q == NULL || p -> val != q -> val) return false;

    return isSameTree(p -> left, q -> left) && isSameTree(p -> right, q -> right);

}

int main(){
    struct TreeNode * p = creatNode(1);
    p -> right = creatNode(2);
    struct TreeNode * q = creatNode(1);
    q -> right = creatNode(2);
    printf("%d\n", isSameTree(p, q));
    return 0;
}