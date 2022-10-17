#include <stdio.h>

int checkSeven(int n){
    if(n % 7 == 0) return 1;
    while(n > 0){
        if(n % 10 == 7) return 1;
        n /= 10;
    }
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);
    int cnt = 0;
    for(int i = 1; i <=n; i++) cnt += checkSeven(i);
    printf("%d\n", cnt);
    
    return 0;
}