#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//O(n)
// int mySqrt(int x){
//     if(!x) return 0;
//     long int root = 0;
//     while(root * root <= x) root++;
//     return root - 1;
// }

//O(log(n))

int mySqrt(int x){
    if(!x) return 0;
    // long int root = 0;
    int start = 0, end = x / 2 + 1;
    long int mid = (start + end) / 2;
    
    
    while(start <= end){
        // printf("start = %d, end = %d, mid = %d\n", start, end, mid);
        
        if(mid * mid == x) return mid;
        else if(mid * mid < x) start = mid + 1;
        else  end = mid - 1;
        mid = (start + end) / 2;
        // printf("start = %d, end = %d, mid = %d\n\n", start, end, mid);
    }
    return start - 1;
}

int main(){
    int a = 8192;
    printf("%d %f\n", mySqrt(a), sqrt(a));
    return 0;
}