#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int maxcnt = 0, cnt = 0;
    while(n > 0){
        if(n % 2) cnt++;
        else{
            maxcnt = maxcnt < cnt ? cnt : maxcnt;
            cnt = 0;
        }
        n /= 2;
    }
    maxcnt = maxcnt < cnt ? cnt : maxcnt;
    printf("%d\n", maxcnt);
    return 0;
}