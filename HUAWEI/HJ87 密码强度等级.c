#include <stdio.h>
#include <string.h>


int main() {
    char pw[301];
    scanf("%s", pw);
    int score = 0;
    int length = strlen(pw);

    if(length <= 4) score += 5;
    else if(length <= 7 && length >= 5) score += 10;
    else score += 25;

    int cap = 0, lower = 0, num = 0, symbol = 0;
    for(int i = 0; i < length; i++){
        if(pw[i] >= 'A' && pw[i] <= 'Z') cap = 1;
        else if(pw[i] >= 'a' && pw[i] <= 'z') lower = 1;
        else if(pw[i] >= '0' && pw[i] <= '9') num++;
        else symbol++;
    }

    if(cap + lower == 0) score += 0;
    else if(cap == 1 && lower == 1) score += 20;
    else score += 10;

    if(num == 0) score += 0;
    else if(num == 1) score += 10;
    else score += 20;

    if(symbol == 0) score += 0;
    else if(symbol == 1) score += 10;
    else score += 25;

    if(num > 0 && cap + lower > 0){
        if(symbol > 0){
            if(cap > 0 && lower > 0) score += 5;
            else score += 3;
        }
        else score += 2;
    }

    if(score >= 90) printf("VERY_SECURE\n");
    else if(score >=80) printf("SECURE\n");
    else if(score >=70) printf("VERY_STRONG\n");
    else if(score >=60) printf("STRONG\n");
    else if(score >=50) printf("AVERAGE\n");
    else if(score >=25) printf("WEAK\n");
    else printf("VERY_WEAK\n");

    return 0;
}