#include <stdio.h>
#include <string.h>

int ip_legal(int ip[]){
    for(int i = 0; i < 4; i++){
        if(ip[i] < 0 || ip[i] > 255) return 0;
    }
    return 1;
}

int dns_legal(int dns[]){
    
    for(int i = 0; i < 4; i++){
        if(dns[i] < 0 || dns[i] > 255) return 0;
    }

    int hasZero = 0;
    for(int i = 0; i < 4; i++){
        int bin[8] = {0}, k = 8 - 1;
        while(dns[i] > 0){
            bin[k--] = dns[i] % 2;
            dns[i] /= 2;
        }

        for(k = 0; k < 8; k++){
            if(!hasZero && bin[k] == 0){
                hasZero = 1;
                continue;
            } 
            if(hasZero && bin[k]) return 0; 
        }

        if(!hasZero && bin[7] == 1 && i == 3) return 0;
    }
    return 1;
}

int main() {
    char str[50];
    int A = 0, B = 0, C = 0, D = 0, E = 0, Err = 0, Private = 0;

    while(scanf("%s", str) != EOF){
        int IP[4] = {-1}, dns[4] = {-1};
        memset(IP, -1, 4 * sizeof(int));
        memset(dns, -1, 4 * sizeof(int));
        sscanf(str,"%d.%d.%d.%d~%d.%d.%d.%d", &IP[0], &IP[1], &IP[2], &IP[3], &dns[0], &dns[1], &dns[2], &dns[3]);

        if(IP[0] == 0 || IP[0] == 127) continue;
        if(!ip_legal(IP) || !dns_legal(dns)){
            Err++;
            continue;
        }

        if(IP[0] <= 126){
            A++;
            if(IP[0] == 10) Private++;
        }
        else if(IP[0] <= 191){
            B++;
            if(IP[0] == 172 && (IP[1] >= 16 && IP[1] <= 31)) Private++;
        }
        else if(IP[0] <= 223){
            C++;
            if(IP[0] == 192 && IP[1] == 168) Private++;
        }
        else if(IP[0] <= 239) D++;
        else E++;

    }
    printf("%d %d %d %d %d %d %d\n", A, B, C, D, E, Err, Private);

    
    return 0;
}