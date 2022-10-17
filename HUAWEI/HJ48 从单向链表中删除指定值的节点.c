#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node * next;
};

struct node * createNode(int val){
    struct node * newNode = (struct node *) malloc(sizeof(struct node));
    newNode -> val = val;
    newNode -> next = NULL;
    return newNode;

}

struct node * findNode(int val, struct node * head){
    struct node * temp = head;
    while(temp != NULL){
        if(temp -> val == val) return temp;
        temp = temp -> next;
    }
    return head;
}

void deleteNode(int val, struct node ** head){
    if((*head) -> val == val){
        *head = (*head) -> next;
        return ;
    }
    else{
        struct node * temp = *head;
        while(temp -> next != NULL){
            if(temp -> next -> val == val){
                temp -> next = temp -> next -> next;
                return ;
            }
            temp = temp -> next;
        }
    }
    return ;
}

void printList(struct node * head){
    struct node * temp = head;
    while(temp != NULL){
        printf("%d ", temp -> val);
        temp = temp -> next;
    }
    printf("\n");
}

int main() {
    int num, val1;
    scanf("%d %d", &num, &val1);
    struct node * head = createNode(val1);

    for(int i = 1; i < num; i++){
        int dst, val;
        scanf("%d %d", &val, &dst);
        struct node * temp = findNode(dst, head);
        struct node * temp2 = temp -> next;
        temp -> next = createNode(val);
        temp -> next -> next = temp2;
    }

    int del;
    scanf("%d", &del);
    deleteNode(del, &head);
    printList(head);

    return 0;
}