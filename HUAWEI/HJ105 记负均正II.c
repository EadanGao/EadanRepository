#include <stdio.h>

int main() {
    int n;
    int neg = 0, sum = 0, pos = 0;
    while(~scanf("%d", &n)){
        if(n < 0) neg++;
        else{
            sum += n;
            pos++;
        }
    }
    if(pos == 0){
        printf("%d\n0.0\n", neg);
        return 0;

    }
    printf("%d\n%.1f\n", neg, (sum + 0.0) / pos);
    return 0;
}