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



int maxDepth(struct TreeNode* root){
    if(root == NULL) return 0;
    int left = maxDepth(root -> left);
    int right = maxDepth(root -> right);
    if(left > right) return left + 1;
    else return right + 1;

}

int main(){
    struct TreeNode * bTree = creatNode(1);
    bTree -> left = creatNode(2);
    bTree -> right = creatNode(2);
    bTree -> left -> left = creatNode(4);
    bTree -> left -> right = creatNode(5);
    bTree -> right -> left = creatNode(5);
    bTree -> right -> right = creatNode(4);

    printf("%d\n", maxDepth(bTree));

    // printf("%d\n", isSymmetric(bTree));


    return 0;
}