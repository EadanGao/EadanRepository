#include <stdio.h>
#include <stdlib.h>

// int countMethods(int n, int * method){
//     if(n == 0 || n == 1 || n == 2) return n;
//     return method[n] = countMethods(n - 2, method) + countMethods(n - 1, method);
// }

// int climbStairs(int n){
//     int method[46] = {0};
//     return countMethods(n, method);

// }

int climbStairs(int n){
    if(n == 0 || n == 1 || n == 2) return n;
    int method[46] = {0};
    method[0] = 0, method[1] = 1, method[2] = 2;
    int i = 3;
    while(i <= n) method[i++] = method[i - 1] + method[i - 2];
    return method[n];

}

int main(){
    int n = 3;
    printf("%d\n", climbStairs(n));
    return 0;
}