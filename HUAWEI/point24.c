#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n[4];
int ConverttoNumber(char a);
void swap(int *a, int *b);
void perm(int offset, int n, int *num);
int point24(char *operator, int operator_pointer);
void printCard(int n);

int main() {
    char a[4][6];
    scanf("%s%s%s%s", a[0], a[1], a[2], a[3]);
    for(int i = 0; i < 4; i++){
        if(a[i][1] == 'o' || a[i][1] == 'O'){
            printf("ERROR\n");
            return 0;
        }
    }

    
    for(int i = 0; i < 4; i++) n[i] = ConverttoNumber(a[i][0]);

    perm(0, 4, n);

    // char operator[4];
    // int rst = 0;

    // point24(operator, 0);
    // if(!rst) printf("NONE\n");
    printf("NONE\n");

    return 0;
}


int ConverttoNumber(char a){
    switch(a){
        case 'A': return 1;
        case 'J': return 11;
        case 'Q': return 12;
        case 'K': return 13;
        case '1': return 10;
        default: return a - '0';
    }
    return 0;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return ;
}

void perm(int offset, int n, int *num){
    if(offset == n -1){
        // for(int i = 0; i < n; i++) printf("%d ", num[i]);
        // printf("\n");
        char operator[4];
        int rst = point24(operator, 0);
        // if(rst > 0) exit(0);

        return;
    }
    else{
        for(int i = offset; i < n; i++){
            swap(&num[i], &num[offset]);
            perm(offset + 1, n, num);
            swap(&num[i], &num[offset]);
        }
    }
}

void printCard(int n){
    switch(n){
        case 1: printf("A"); return ;
        case 11: printf("J"); return ;
        case 12: printf("Q"); return ;
        case 13: printf("K"); return ;
        default: printf("%d", n); return;
    }
    return ;
}

int point24(char *operator, int operator_pointer){
    if(operator_pointer == 3){
        int temp[4];
        for(int i = 0; i < 4; i++) temp[i] = n[i];
        for(int i = 0; i < 3; i++){
            if(operator[i] == '-'){
                temp[i + 1] = 0 - temp[i + 1];
                continue;
            }
            else if(operator[i] == '*'){
                temp[i + 1] = temp[i] * temp[i + 1];
                temp[i] = 0;
                continue;
            }
            else if(operator[i] == '/'){
                temp[i + 1] = temp[i] / temp[i + 1];
                temp[i] = 0;
                continue;
            }
        }
        int cnt = 0;
        for(int i = 0; i < 4; i++) cnt += temp[i];
        printf("%d%c%d%c%d%c%d = %d\n", n[0], operator[0], n[1], operator[1], n[2], operator[2], n[3], cnt);
        if(cnt == 24){
            // printf("%d%c%d%c%d%c%d = %d\n", n[0], operator[0], n[1], operator[1], n[2], operator[2], n[3], cnt);
            for(int k = 0; k < 3; k++){
                printCard(n[k]);
                printf("%c", operator[k]);
            }
            printCard(n[3]);
            // printf("%d%c%d%c%d%c%d\n", n[0], operator[0], n[1], operator[1], n[2], operator[2], n[3]);
            return 1;
        }
        else return 0;
    }
    operator[operator_pointer] = '+';
    if(point24(operator, operator_pointer + 1)) return 1;
    operator[operator_pointer] = '-';
    if(point24(operator, operator_pointer + 1)) return 1;
    operator[operator_pointer] = '*';
    if(point24(operator, operator_pointer + 1)) return 1;
    operator[operator_pointer] = '/';
    if(point24(operator, operator_pointer + 1)) return 1;
    return 0;

}
