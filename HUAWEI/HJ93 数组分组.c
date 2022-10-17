#include <stdio.h>

int divide(int g1, int g2, int *num, int n, int i){
    if(i == n){
        if(g1 == g2) return 1;
        else return 0;
    }
    if(num[i] % 5 == 0) return divide(g1 - num[i], g2, num, n, i + 1);
    else if(num[i] % 3 == 0) return divide(g1, g2 - num[i], num, n, i + 1);
    else return divide(g1 - num[i], g2, num, n, i + 1) || divide(g1, g2 - num[i], num, n, i + 1);
}

int main() {
    int n;
    scanf("%d", &n);
    int num[n];

    for(int i = 0; i < n; i++)  scanf("%d", &num[i]);

    if(divide(0, 0, num, n, 0)) printf("true\n");
    else printf("false\n");

    return 0;
}