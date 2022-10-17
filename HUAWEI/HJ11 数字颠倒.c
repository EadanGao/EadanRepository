#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    if(!n) {
        printf("%d", n);
        return 0;
    }
    while(n > 0){
        printf("%d", n % 10);
        n /= 10;
    }
    return 0;
}