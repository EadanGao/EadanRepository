#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAXN 100

int map[MAXN][MAXN]; //[odd][even]
bool vis[MAXN];
int even_partner[MAXN];
int even_n;
int odd_n;

int isPrime(int n){
    for(int i = 2; i * i <= n; i++){
        if( n % i == 0) return 0;
    }
    return 1;       
}

void arePrimePartner(int * even, int * odd){
    for(int i = 0; i < odd_n; i++){
        for(int j = 0; j < even_n; j++) map[i][j] = isPrime(even[j] + odd[i]);
    }
    return ;
}

int match(int i){// input odds, check even
    for(int j = 0; j < even_n; j++){
        if(map[i][j] && !vis[j]){
            vis[j] = true;
            if(even_partner[j] == -1 || match(even_partner[j])){
                even_partner[j] = i;
                return 1;
            }
        }
    }
    return 0;
}

int Hungarian(){
    int cnt = 0;
    for(int i = 0; i < odd_n; i++){
        memset(vis, 0, sizeof(vis));
        if(match(i)) cnt++;
    }
    return cnt;
}


int main(){
    int n;
    scanf("%d", &n);
    int * nums = (int *) malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) scanf("%d", &nums[i]);

    int * odds = (int *) malloc(n * sizeof(int));
    int * evens = (int *) malloc(n * sizeof(int));

    memset(even_partner, -1, sizeof(even_partner));


    for(int i = 0; i < n; i++){
        if(nums[i] % 2 == 0) evens[even_n++] = nums[i];
        else odds[odd_n++] = nums[i];
    }

    arePrimePartner(evens, odds);
    int cnt = Hungarian();

    printf("%d\n", cnt);

    free(nums);
    free(odds);
    free(evens);
    return 0;
}