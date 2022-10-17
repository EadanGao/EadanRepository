#include <stdio.h>

int distribute(int m, int n){
    if(n == 1 || m == 0) return 1;
    if(n > m) return distribute(m, m);
    return distribute(m, n - 1) + distribute(m - n, n);

}

int main() {
    int m, n;
    scanf("%d%d", &m, &n);
    int rst = distribute(m, n);
    printf("%d\n", rst);
    return 0;
}