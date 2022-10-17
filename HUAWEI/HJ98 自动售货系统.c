#include <stdio.h>
#include <string.h>

int cush[4];

struct product{
    char name[10];
    int price;
    int cnt;
};

struct product commodity[6];
int balance = 0;

void check();
void command_r();
void command_p();
void command_b();
void command_c();
void command_q();

int main(){
    char command;
    commodity[0].price = 2;
    commodity[1].price = 3;
    commodity[2].price = 4;
    commodity[3].price = 5;
    commodity[4].price = 8;
    commodity[5].price = 6;
    
    strcpy(commodity[0].name, "A1");
    strcpy(commodity[1].name, "A2");
    strcpy(commodity[2].name, "A3");
    strcpy(commodity[3].name, "A4");
    strcpy(commodity[4].name, "A5");
    strcpy(commodity[5].name, "A6");

    while(~scanf("%c", &command)){
        switch(command){
            case 'r': command_r(); break;
            case 'p': command_p(); break;
            case 'b': command_b(); break;
            case 'c': command_c(); break;
            case 'q': command_q(); break;
        }
        // check();
    }

    return 0;
}

void command_r(){
    scanf("%d-%d-%d-%d-%d-%d", &commodity[0].cnt, &commodity[1].cnt, &commodity[2].cnt, &commodity[3].cnt, &commodity[4].cnt, &commodity[5].cnt);
    scanf("%d-%d-%d-%d", &cush[0], &cush[1], &cush[2], &cush[3]);
    printf("S001:Initialization is successful\n");
    return ;
}

void command_p(){
    int temp;
    scanf("%d", &temp);
    if(temp != 1 && temp != 2 && temp != 5 && temp != 10){
        printf("E002:Denomination error\n");
        return ;
    }
    if(temp == 5){
        if(cush[0] + 2 * cush[1] < 5) printf("E003:Change is not enough, pay fail\n");
        else{
            balance += 5;
            cush[2]++;
            int cnt  = 0;
            for(int i = 0; i < 6; i++) cnt += commodity[i].cnt;

            if(cnt == 0){
                printf("E005:All the goods sold out\n");
                return ;
            }
            printf("S002:Pay success,balance=%d\n", balance);
        }
        return;
    }
    if(temp == 10){
        if(cush[0] + 2 * cush[1] < 10) printf("E003:Change is not enough, pay fail\n");
        else{
            balance += 10;
            cush[3]++;
            int cnt  = 0;
            for(int i = 0; i < 6; i++) cnt += commodity[i].cnt;

            if(cnt == 0){
                printf("E005:All the goods sold out\n");
                return ;
            }
            printf("S002:Pay success,balance=%d\n", balance);

        }
        return;
    }
    
    balance += temp;
    cush[temp - 1]++;

    int cnt  = 0;
    for(int i = 0; i < 6; i++) cnt += commodity[i].cnt;

    if(cnt == 0){
        printf("E005:All the goods sold out\n");
        return ;
    }
    printf("S002:Pay success,balance=%d\n", balance);
    return ;
}

void command_b(){
    char name[3];
    scanf(" %c%c%c", &name[0], &name[1], &name[2]);
    if(name[0] != 'A'){
        printf("E006:Goods does not exist\n");
        return;
    }
    if(name[2] != ';'){
        printf("E006:Goods does not exist\n");
        return;
    }

    int product = name[1] - '0';
    if(product < 1 || product > 6){
        printf("E006:Goods does not exist\n");
        return;
    }

    if(commodity[product - 1].cnt == 0){
        printf("E007:The goods sold out\n");
        return;
    }
    if(balance < commodity[product - 1].price){
        printf("E008:Lack of balance\n");
        return ;
    }
    commodity[product - 1].cnt--;
    balance -= commodity[product - 1].price;
    printf("S003:Buy success,balance=%d\n", balance);
    return ;
}

void command_c(){
    if(balance == 0){
        printf("E009:Work failure\n");
        return ;
    }
    int cnt[4] = {0};
    while(balance >= 10 && cush[3] > 0){
        balance -= 10;
        cush[3]--;
        cnt[3]++;
    }

    while(balance >= 5 && cush[2] > 0){
        balance -= 5;
        cush[2]--;
        cnt[2]++;
    }

    while(balance >= 2 && cush[1] > 0){
        balance -= 2;
        cush[1]--;
        cnt[1]++;
    }

    while(cush[0] > 0 && balance > 0){
        balance -= 1;
        cush[0]--;
        cnt[0]++;
    }
    printf("1 yuan coin number=%d\n", cnt[0]);
    printf("2 yuan coin number=%d\n", cnt[1]);
    printf("5 yuan coin number=%d\n", cnt[2]);
    printf("10 yuan coin number=%d\n", cnt[3]);
    balance = 0;

    return ;
}

void command_q(){
    int command;
    scanf("%d", &command);
    if(command != 0 || command != 1){
        printf("E010:Parameter error\n");
        return ;
    }
    if(command == 1){
        printf("1 yuan coin number=%d\n", cush[0]);
        printf("2 yuan coin number=%d\n", cush[1]);
        printf("5 yuan coin number=%d\n", cush[2]);
        printf("10 yuan coin number=%d\n", cush[3]);
        return ;
    }
    int check[6] = {0, 1, 2, 3, 4, 5};
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(commodity[j].cnt < commodity[j + 1].cnt) swap(&check[j], &check[j + 1]);
        }
    }

    for(int i = 0; i < 6; i++){
        printf("%s %d %d\n", commodity[check[i]].name, commodity[check[i]].price, commodity[check[i]].cnt);
    }
    return ;
}

void check(){
    printf("product cnt ");
    for(int i = 0; i < 6; i++) printf("%d ", commodity[i].cnt);
    printf(" | cush ");
    for(int i = 0; i < 4; i++) printf("%d ", cush[i]);
    printf("\n");
    return ;
}