// 输入整型数组和排序标识，对其元素按照升序或降序进行排序
#include <stdio.h>
void swap(int *a, int *b){
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
    return ;
}

int main() {
    int n;
    scanf("%d", &n);
    int num[n];
    for(int i = 0; i < n; i++) scanf("%d", &num[i]);
    int order;
    scanf("%d", &order);
    if(order){
        for(int i = 0; i < n -1; i++){
            for(int j = 0; j < n - 1; j++){
                if(num[j] < num[j + 1]) swap(&num[j], &num[j + 1]);
            }
        }
    }
    else{
        for(int i = 0; i < n -1; i++){
            for(int j = 0; j < n - 1; j++){
                if(num[j] > num[j + 1]) swap(&num[j], &num[j + 1]);
            }
        }
    }
    for(int i = 0; i < n; i++) printf("%d ", num[i]);
    printf("\n");

    return 0;
}