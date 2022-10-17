#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int num;
    int neg = 0, pos = 0, sum = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &num);
        if(num < 0) neg++;
        if(num > 0) pos++, sum += num;
    } 
    if(pos == 0){
        printf("%d 0.0\n", neg);
        return 0;
    } 
    printf("%d %.1f\n", neg, (sum + 0.0) / pos);

    return 0;
}