#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

void addNodeFront(struct ListNode ** list, int value){
    struct ListNode * temp  = (struct ListNode *) malloc(sizeof(struct ListNode));
    temp -> val = value;
    temp -> next  = (* list);
    (* list) = temp;
    return ;
}

void printlist(struct ListNode *list){
    struct ListNode * temp = list;
    while(temp != NULL){
        printf("%d ", temp -> val);
        temp = temp -> next;
    }
    printf("\n");
    return ;
}

struct ListNode * addNode(int value){
    struct ListNode * temp  = (struct ListNode *) malloc(sizeof(struct ListNode));
    temp -> val = value;
    temp -> next  = NULL;

    return temp;
}


struct ListNode* deleteDuplicates(struct ListNode* head){
    if(head == NULL || head -> next == NULL) return head;
    struct ListNode * newlist = (struct ListNode *) malloc(sizeof(struct ListNode));
    newlist -> next = NULL;
    struct ListNode * pointer = newlist;
    pointer -> next = addNode(head -> val);
    pointer = pointer -> next;
    while(head -> next != NULL){
        // printlist(head);
        if(head -> val != head -> next -> val) {
            pointer -> next = addNode(head -> next -> val);
            pointer = pointer -> next;
        }
        head = head -> next;
    }
    newlist = newlist -> next;
    return newlist;

}

int main(){
    struct ListNode * list = NULL;
    addNodeFront(&list, 4);
    addNodeFront(&list, 3);
    addNodeFront(&list, 3);
    addNodeFront(&list, 2);
    addNodeFront(&list, 1);
    addNodeFront(&list, 1);
    // printlist(list);

    struct ListNode * newList = deleteDuplicates(list);
    printlist(newList);
    return 0;
}