#include <stdio.h>
#include <stdlib.h>

static char less_twenty[][10] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
static char tens[][10] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
static char more_hundred[][11] = {"thousand", "million", "bilion"};

void print3bits(int bits[]);


int main() {
    int n;
    scanf("%d", &n);
    int bits[3] = {0};
    int temp = n, cnt = 0;
    while(temp / 1000 > 0) temp /= 1000, cnt++;
    
    for(int i = cnt; i > -1; i--){

        bits[2] = temp % 10;
        bits[1] = temp / 10; bits[1] %= 10; 
        bits[0] = temp / 100; bits[1] %= 10; 

        print3bits(bits);
        if(cnt == 0) continue;
        printf("%s ", more_hundred[i -  1]);
        
        temp = n;
        for(int j = 0; j < i - 1; j++) temp /= 1000;
        temp %= 1000;
        bits[2] = 0, bits[1] = 0; bits[0] = 0;
        
    }

    return 0;
}

void print3bits(int bits[]){
    if(bits[0] > 0){
        printf("%s hundred ", less_twenty[bits[0] - 1]);
        if(bits[1] > 0 || bits[2] > 0) printf("and ");
    }

    if(bits[1] ==  0 && bits[2] == 0) return ;


    if(bits[1] >= 2){
        printf("%s ", tens[bits[1] - 2]);
        if(bits[2] > 0) printf("%s ", less_twenty[bits[2] - 1]);
        return ;
    }

    else {
        int temp = bits[2] + 10 * bits[1];
        printf("%s ", less_twenty[temp - 1]);
    }
    return ;
}