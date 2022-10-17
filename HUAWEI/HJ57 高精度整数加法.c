#include <stdio.h>
#include <string.h>

int main() {
    char stra[10001], strb[10001];
    scanf("%s", stra);
    scanf("%s", strb);
    
    int lengtha = strlen(stra), lengthb = strlen(strb);
    int i = lengtha, j = lengthb;

    int carry = 0;

    while(i > 0 && j > 0){
        i--;
        j--;
        int temp = (int) ((stra[i] - '0') + (strb[j] - '0')) + carry;
        
        if(temp < 10){
            stra[i] = (char) (temp + '0');
            carry = 0;
        }
        else{
            carry = 1;
            temp %= 10;
            stra[i] = (char) (temp + 48);

        }
    }

    int pointer = j;

    while(carry && i > 0){
        i--;
        int temp = (int) (stra[i] - '0') + carry;
        if(temp < 10){
            stra[i] = (char) (temp + '0');
            carry = 0;
        }
        else{
            carry = 1;
            temp %= 10;
            stra[i] = (char) (temp + 48);

        }
    }

    while(carry && j > 0){
        j--;
        int temp = (int) (strb[j] - '0') + carry;
        if(temp < 10){
            strb[j] = (char) (temp + '0');
            carry = 0;
        }
        else{
            carry = 1;
            temp %= 10;
            strb[j] = (char) (temp + 48);

        }
    }


    if(carry == 1 && (i <= 0 && j <= 0)) printf("1");

    if(lengtha >= lengthb){
        printf("%s\n", stra);
        return 0;
    }
    else{
        for(int k = 0; k < pointer; k++) printf("%c", strb[k]);
        printf("%s\n", stra);
    }



    return 0;
}