#include <stdio.h>

int main() {
    int n;
    while(scanf("%d", &n) != EOF){
        //b = 25 - 7a/4
        for(int i = 0; i < 4; i++){
            printf("%d %d %d\n", 4 * i, 25 - 7 * i, 75 + 3 * i);
        }
    }
    return 0;
}