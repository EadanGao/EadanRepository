#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int m_nKey;
    struct ListNode * m_pNext;
};

struct ListNode * createNode(int val){
    struct ListNode * newNode = (struct ListNode *) malloc(sizeof(struct ListNode));
    newNode -> m_nKey = val;
    newNode -> m_pNext = NULL;
    return newNode;
}

int main() {
    int n;
    while(scanf("%d", &n) != EOF){
        struct ListNode * head = createNode(0);
        struct ListNode * pointer = head;

        for(int i = 0; i < n; i++){
            int val; 
            scanf("%d", &val);
            pointer -> m_pNext = createNode(val);
            pointer = pointer -> m_pNext;
        }
        int k;
        scanf("%d", &k);


        struct ListNode * fast = head -> m_pNext;
        struct ListNode * slow = head -> m_pNext;



        for(int i = 0; i < k - 1; i++){
            
            if(fast -> m_pNext != NULL) fast = fast -> m_pNext;
            else{
                printf("0\n");
                return 0;
            }
        }

        while(fast -> m_pNext != NULL){
            fast = fast -> m_pNext;
            slow = slow -> m_pNext;
        }
        
        printf("%d\n", slow -> m_nKey);
    }

    return 0;
}