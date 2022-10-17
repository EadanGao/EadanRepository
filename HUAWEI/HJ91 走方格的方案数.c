#include <stdio.h>
int cnt = 0;

int trace(int i, int j, int m, int n){
    if(m == i || n == j) return 1;
    return trace(i, j + 1, m, n) + trace(i + 1, j, m, n);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int cnt = trace(0, 0, m, n);
    printf("%d\n", cnt);
    return 0;
}