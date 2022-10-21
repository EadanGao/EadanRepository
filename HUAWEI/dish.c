#include <stdio.h>
int price[5] = {1, 3, 7, 11, 13};
int num[5] = {1, 2, 3, 4, 5};
int cush = 3;
int mindish = 100000, balance2 = 100000;

void  dinner(int balance, int cnt, int pointer){
    if (pointer == -1 || balance == 0 || (pointer == 0 && num[0] == 0)) {

        if (balance == 0) {
            mindish = cnt < mindish ? cnt : mindish;
            balance2 = 0;
        }
        else {
            mindish = balance < balance2 ? cnt : mindish;
            balance2 = balance < balance2 ? balance : balance2;

        }
        return;
    }
    for(int i = 4; i > -1 && balance > 0; i--){
        if (balance >= price[i] && num[i] > 0){
            num[i]--;
            dinner(balance - price[i], cnt + 1, i);
            num[i]++;
        }
    }
    return ;
}



int main(){
    // for(int i = 0; i < 5; i++) scanf("%d", &num[i]);
    // for(int i = 0; i < 5; i++) printf("%d ", num[i]);
    // printf("\n");
    // scanf("%d", &cush);
    if(cush == 0){
        printf("0\n");
        return 0;
    }
    dinner(cush, 0, 4);
    printf("%d\n", mindish);

    return 0;
}