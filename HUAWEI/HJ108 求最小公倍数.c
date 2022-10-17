#include <stdio.h>

int gcf(int a, int b){
    if(!b) return a;
    return gcf(b, a % b);
}

int main() {
    int a, b;
    while (scanf("%d %d", &a, &b) != EOF) {
        int num = gcf(a, b);
        printf("%d\n", a * b / num);
    }
    return 0;
}