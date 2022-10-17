#include <stdio.h>
#include <string.h>

int fraction[100] = {0};
int fraction_pointer = 0;

int gcf(int a, int b)
{
    if (b != 0) return gcf(b, a%b);
    else  return a;
}

void EgyptianFraction(int a, int b){
    if(a == 1){
        fraction[fraction_pointer++] = a;
        fraction[fraction_pointer++] = b;
        return;
    }
    else{
        int p = b / a;
        int r = b - a * p;
        EgyptianFraction(1, p + 1);
        EgyptianFraction(a - r, b * (p + 1));
    }
    // printf("Error: a = %d b = %d\n", a, b);
    // printf("Error:\n");
    return ;
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
        EgyptianFraction(a,b);
        for(int i = 0; i < fraction_pointer; i++){
            printf("%d/", fraction[i]);
            fraction[i++] = 0;

            printf("%d", fraction[i]);
            fraction[i] = 0;
            if(i != fraction_pointer - 1) printf("+");
        }
        printf("\n");
        fraction_pointer = 0;
        
        
    }
    

    return 0;
}

int main() {
    int a = 0, b = 0;
    while(~scanf("%d/%d", &a, &b)){
        
        for(int i=0; i<a-1; i++){
            printf("1/%d+", b);
        }
        printf("1/%d\n", b);
        
        
    }
    

    return 0;
}