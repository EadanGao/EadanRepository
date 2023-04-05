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


/* C program to merge two sorted linked lists */
// #include<stdio.h>
// #include<stdlib.h>
// #include<assert.h>

// /* Link list node */
// struct Node
// {
// 	int data;
// 	struct Node* next;
// };

// void printList(struct Node *node)

// {
//     struct Node * temp = node;
// 	while (temp!=NULL)
// 	{
// 		printf("%d ", temp->data);
// 		temp = temp->next;
// 	}
// }


// /* pull off the front node of the source and put it in dest */
// void MoveNode(struct Node** destRef, struct Node** sourceRef);

// /* Takes two lists sorted in increasing order, and splices
// their nodes together to make one big sorted list which
// is returned. */
// struct Node* SortedMerge(struct Node* a, struct Node* b)
// {
// 	/* a dummy first node to hang the result on */
// 	struct Node dummy;

// 	/* tail points to the last result node */
// 	struct Node* tail = &dummy;

// 	/* so tail->next is the place to add new nodes
// 	to the result. */
// 	dummy.next = NULL;
// 	while (1)
// 	{
// 		if (a == NULL)
// 		{
// 			/* if either list runs out, use the
// 			other list */
// 			tail->next = b;
// 			break;
// 		}
// 		else if (b == NULL)
// 		{
// 			tail->next = a;
// 			break;
// 		}
// 		if (a->data <= b->data)
// 			MoveNode(&(tail->next), &a);
// 		else
// 			MoveNode(&(tail->next), &b);

// 		tail = tail->next;
// 	}
// 	return(dummy.next);
// }

// /* UTILITY FUNCTIONS */
// /* MoveNode() function takes the node from the front of the
// source, and move it to the front of the dest.
// It is an error to call this with the source list empty.

// Before calling MoveNode():
// source == {1, 2, 3}
// dest == {1, 2, 3}

// After calling MoveNode():
// source == {2, 3}
// dest == {1, 1, 2, 3} */
// void MoveNode(struct Node** destRef, struct Node** sourceRef)
// {
// 	/* the front source node */
// 	struct Node* newNode = *sourceRef;
// 	assert(newNode != NULL);

// 	/* Advance the source pointer */
// 	*sourceRef = newNode->next;

// 	/* Link the old dest off the new node */
// 	newNode->next = *destRef;

// 	/* Move dest to point to the new node */
// 	*destRef = newNode;
// }


// /* Function to insert a node at the beginning of the
// linked list */
// void push(struct Node** head_ref, int new_data)
// {
// 	/* allocate node */
// 	struct Node* new_node =
// 		(struct Node*) malloc(sizeof(struct Node));

// 	/* put in the data */
// 	new_node->data = new_data;

// 	/* link the old list off the new node */
// 	new_node->next = (*head_ref);

// 	/* move the head to point to the new node */
// 	(*head_ref) = new_node;
// }


// /* Driver program to test above functions*/
// int main()
// {
// 	/* Start with the empty list */
// 	struct Node* res = NULL;
// 	struct Node* a = NULL;
// 	struct Node* b = NULL;

// 	/* Let us create two sorted linked lists to test
// 	the functions
// 	Created lists, a: 5->10->15, b: 2->3->20 */
// 	push(&a, 15);
// 	push(&a, 10);
// 	push(&a, 5);

// 	push(&b, 20);
// 	push(&b, 3);
// 	push(&b, 2);

// 	/* Remove duplicates from linked list */
// 	res = SortedMerge(a, b);

// 	printf("Merged Linked List is: \n");
// 	printList(res);

// 	return 0;
// }
