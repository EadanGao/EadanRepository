/*************************************************************************
	> File Name: 13_max_int.c
	> Author: 
	> Mail: 
	> Created Time: Mon 18 Jan 2021 04:05:17 AM CST
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#include<stdarg.h>

int max_int(int n, ...){
    int ans = INT32_MIN;
    va_list arg;
    va_start(arg, n);
    while(n --){
        int temp = va_arg(arg, int);
        if(temp > ans) ans = temp;
    }
    va_end(arg);
    return ans;
}
int main(){
    printf("%d\n", max_int(3, 4, 10, 1, 5, 3));
    return 0;
}
