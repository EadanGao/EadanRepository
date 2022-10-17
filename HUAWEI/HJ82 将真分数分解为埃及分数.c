#include <stdio.h>
#include <string.h>

int fraction[100] = {0};
int fraction_pointer = 0;

int gcf(int a, int b)
{
    if (b != 0) return gcf(b, a%b);
    else  return a;
}

int main() {
    int a = 0, b = 0;
    while(~scanf("%d/%d", &a, &b)){
        
        int factor = gcf(a, b);
        while(factor != 1){
            a /= factor;
            b /= factor;
            factor = gcf(a, b);
        }
        for(int i=0; i<a-1; i++) printf("1/%d+", b);
        printf("1/%d\n", b);        
    }
    
    return 0;
}