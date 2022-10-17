#include <stdio.h>
#include <math.h>

void DectoBin(char * bin, int dec, int bits){
    while(dec > 0){
        bin[--bits] = dec % 2;
        dec /= 2;
    }
    return ;
}

int BintoDec(char * bin, int bits){
    int dec = 0;
    for(int i = 0; i < bits; i++){
        dec += bin[i] * pow(2, bits - 1 - i);
    }

    return dec;
}

int illegal_ip(int * ip){
    for(int i = 0; i < 4; i++){
        if(ip[i] > 255 || ip[i] < 0) return 1;
    }
    return 0;
}

int illegal_mask(char * mask){
    int hasZero = 0;
    for(int i = 0; i < 32; i++){
        if(!hasZero && !mask[i]){
            hasZero = 1;
            continue;
        }
        if(hasZero && mask[i]){
            return 1;
        } 

    }
    return 0;
}

int main(){
    int Mask[4], IP1[4], IP2[4];

    while(scanf("%d.%d.%d.%d", &Mask[0], &Mask[1], &Mask[2], &Mask[3]) != EOF){
        scanf("%d.%d.%d.%d", &IP1[0], &IP1[1], &IP1[2], &IP1[3]);
        scanf("%d.%d.%d.%d", &IP2[0], &IP2[1], &IP2[2], &IP2[3]);

        char mask[32] = {0}, ip1[32] = {0}, ip2[32] = {0};
        
        int legal = 0;
        legal += illegal_ip(IP1);
        legal += illegal_ip(IP2);
        legal += illegal_ip(Mask);

        for(int i = 0; i < 4; i++) DectoBin(mask + i * 8, Mask[i], 8);

        legal += illegal_mask(mask);
        if(legal){
            printf("1\n");
            continue;
        }

        for(int i = 0; i < 4; i++) DectoBin(ip1 + i * 8, IP1[i], 8);
        for(int i = 0; i < 4; i++) DectoBin(ip2 + i * 8, IP2[i], 8);

        for(int i = 0; i < 32; i++) ip1[i] = ip1[i] & mask[i];
        for(int i = 0; i < 32; i++) ip2[i] = ip2[i] & mask[i];

        for(int i = 0; i < 4; i++) IP1[i] = BintoDec(ip1 + i * 8, 8);
        for(int i = 0; i < 4; i++) IP2[i] = BintoDec(ip2 + i * 8, 8);

        if(IP1[0] == IP2[0] && IP1[1] == IP2[1] && IP1[2] == IP2[2] && IP1[3] == IP2[3]) printf("0\n");
        else printf("2\n");
        
    }
    
    return 0;
}