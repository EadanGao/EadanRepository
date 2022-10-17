

#include <stdio.h>

void swap(int * a, int * b){
    int temp = *b;
    *b = *a;
    *a = temp;
    return ;
}

int main() {
    int num;
    scanf("%d", &num);
    int random[num];
    for(int i = 0; i < num; i++) scanf("%d", &random[i]);

    int * start = random;
    int pointer = 0;

    //bubble sort
    for(int i = 0; i < num - 1; i++){
        for(int j = 0; j < num - 1; j++){
            if(start[j] == start[j + 1]){
                // remove repeatition
                for(int k = j; k > 0; k--) start[k] = start[k - 1];
                start++;
                i--;
                num--;
            }
            else if(start[j] > start[j + 1]) swap(&start[j], &start[j+1]);
        }
    }

    for(int i = 0; i < num; i++) printf("%d\n", start[i]);


    return 0;
}