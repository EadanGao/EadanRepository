#include <stdio.h>

int main() {
    int n;
    while(scanf("%d", &n) != EOF){
        if(n / 2) printf("%d\n", n / 2);
    }
    return 0;
}