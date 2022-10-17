#include <stdio.h>
#include <string.h>

void swap(int *a, int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return ;
}

int main() {
    int n;
    scanf("%d", &n);
    int num[n], index[n];
    for(int i = 0; i < n; i++) scanf("%d %d", &index[i], &num[i]);

    //ascnding 
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1; j++){
            if(index[j] > index[j + 1]){
                swap(&index[j], &index[j + 1]);
                swap(&num[j], &num[j + 1]);
            }
        }
    }

    int length = 0; 
    int result[n][2];
    result[length][0] = index[0], result[length][1] = num[0];

    for(int i = 1; i < n; i++){
        if(result[length][0] != index[i]){
            length++;
            result[length][0] = index[i];
            result[length][1] = num[i];
        }
        else{
            result[length][1] += num[i];
        }
    }

    for(int i = 0; i <= length; i++){
        printf("%d %d\n", result[i][0], result[i][1]);
    }

    return 0;
}