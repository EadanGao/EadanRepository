#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int num[10] = {0};
    while(n > 0){
        int i = n % 10;
        if(!num[i]){
            num[i]++;
            printf("%d", i);
        }
        n /= 10;
    }
    return 0;
}