#include <stdio.h>

int main() {
    int m, n;
    while(~scanf("%d %d", &m, &n)){
        if(m > 9 || n > 9) printf("-1\n");
        else printf("0\n");
        
        int r = m < 9 ? m : 9;
        int c = n < 9 ? n : 9;
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        if((x1 < 0 || x1 > r - 1) || (y1 < 0 || y1 > c - 1) || (x2 < 0 || x2 > r - 1) || (y2 < 0 || y2 > c - 1)) printf("-1\n");
        else printf("0\n");

        int x, y;
        scanf("%d", &x);
        if(r + 1 > 9 || x >= r) printf("-1\n");
        else printf("0\n");

        scanf("%d", &y);
        if(c + 1 > 9 || y >= c) printf("-1\n");
        else printf("0\n");

        scanf("%d %d", &x, &y);

        if((x < 0 || x > r - 1) || (y < 0 || y > c - 1)) printf("-1\n");
        else printf("0\n");

    }
    return 0;
}