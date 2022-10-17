#include <stdio.h>

int prime(int n){
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);
    int rst[2];
    for(int i = 1; i < n / 2 + 1; i++){
        if(prime(i) && prime(n - i)){
            rst[0] = i;
            rst[1] = n - i;
        }
    }
    printf("%d\n%d\n", rst[0], rst[1]);

    return 0;
}