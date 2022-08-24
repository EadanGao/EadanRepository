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
        printf("%d\n", temp -> val);
        temp = temp -> next;
    }
    return ;
}

struct ListNode * addNode(int value){
    struct ListNode * temp  = (struct ListNode *) malloc(sizeof(struct ListNode));
    temp -> val = value;
    temp -> next  = NULL;

    return temp;
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    struct ListNode * newlist = (struct ListNode *) malloc(sizeof(struct ListNode));
    newlist -> next = NULL;
    struct ListNode * pointer = NULL;
    pointer = newlist;

    while(list1 != NULL && list2 != NULL){
        if(list1 -> val < list2 -> val){
            pointer -> next = addNode(list1 -> val);
            list1 = list1 -> next;
        }
        else{
            pointer -> next = addNode(list2 -> val);
            list2 = list2 -> next;
        }
        pointer = pointer -> next;
    }

    if(list1 == NULL) pointer -> next = list2;
    if(list2 == NULL) pointer -> next = list1;

    newlist = newlist -> next;
    return newlist;
}




int main(){
    struct ListNode * list1 = NULL;
    struct ListNode * list2 = NULL;
    struct ListNode * newlist = NULL;

    addNodeFront(&list1, 4);
    addNodeFront(&list1, 2);
    addNodeFront(&list1, 1);

    addNodeFront(&list2, 4);
    addNodeFront(&list2, 3);
    addNodeFront(&list2, 1);

    newlist = mergeTwoLists(list1, list2);  

    printlist(newlist);

    return 0;
}

// struct ListNode* smallernodes(struct ListNode* list1, struct ListNode* list2){
//     if(list1 -> val < list2 -> val) return list1;
//     else return list2;
// }


// void printlist(struct ListNode *list){
//     while(list != NULL){
//         printf("%d\n", list -> val);
//         list = list -> next;
//     }
//     return ;
// }