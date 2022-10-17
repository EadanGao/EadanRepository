#include <stdio.h>

int divisorSum(int n){
    int rst = 0;
    for(int i = 1; i < n; i++){
        if(n % i == 0) rst += i;
    }
    return rst;
}

int main() {
    int n;
    scanf("%d", &n);
    int cnt = 0;

    for(int i = 1; i < n; i++){
        int temp = divisorSum(i);
        if(temp == i) cnt++;
    }
    printf("%d\n", cnt);

    return 0;
}