#include <stdio.h>

int main() {
    double num;
    scanf("%lf", &num);

    double i = 0;
    if(num > 0){
        while(i * i * i < num) i += 0.01;
    }
    else{
        while(i * i * i > num) i -= 0.01;
    }
    printf("%.1f\n", i);

    return 0;
}