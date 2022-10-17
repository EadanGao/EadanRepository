#include <stdio.h>
int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main() {
    int y, m, d;
    scanf("%d %d %d", &y, &m, &d);
    if(y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) month[2] +=1;
    int cnt  = 0;
    for(int i = 0; i < m; i++){
        cnt += month[i];
    }
    cnt += d;
    printf("%d\n", cnt);

    return 0;
}