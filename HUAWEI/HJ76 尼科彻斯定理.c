#include <stdio.h>

int main(){
    int m;
    scanf("%d", &m);

    int head = m * m - m + 1;
    printf("%d", head);
    for(int i = 0; i < m - 1; i++){
        head += 2;
        printf("+%d", head);
    }
    return 0;
}