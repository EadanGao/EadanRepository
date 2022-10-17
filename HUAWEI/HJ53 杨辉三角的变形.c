#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    if(n <= 2){
        printf("-1\n");
        return 0;
    } 
    switch(n % 4){
        case 0: printf("3\n"); break;
        case 1: printf("2\n"); break;
        case 2: printf("4\n"); break;
        case 3: printf("2\n"); break;
    }
    return 0;
}