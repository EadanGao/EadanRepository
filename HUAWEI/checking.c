#include <stdio.h>
#include <stdlib.h>

int main(){
    int n; // intput
    scanf("%d", &n);
    int length = 10;

    int *num = (int *) malloc(length * sizeof(int));
    for(int i = 0; i < length; i++) num[i] = i + 2;

    int min = 0, max = length - 1, mid = (min + max) / 2;
    while(min < max){
        if(num[mid] == n){
            printf("%d %d\n", n, mid);
            return 0;
        }
        else if(mid > n){
            max = mid - 1;
            mid = (min + max) / 2;
            continue;
        }
        else{
            min = mid + 1;
            mid = (min + max) / 2;
            continue;
        }
    }
    free(num);
    printf("%d %d\n", n, mid);

    return 0;
}