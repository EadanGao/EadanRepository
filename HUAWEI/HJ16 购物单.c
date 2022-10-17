#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) a > b ? a : b

int main() {
    int N, m;
    scanf("%d %d",&N, &m);
    int v[m + 1], p[m + 1], q[m + 1];
    int weight[m + 1][4], price[m + 1][4];
    memset(weight, 0, 4 * (m + 1) * sizeof(int));
    memset(price, 0, 4 * (m + 1) * sizeof(int));
    N /= 10;

    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &v[i], &p[i], &q[i]);
        if(q[i] == 0){
            for(int j = 0; j < 4; j++){
                price[i][j] += v[i];
                weight[i][j] += v[i] * p[i];
            }
        }
        else if(price[q[i] - 1][0] == price[q[i] - 1][1]){
            price[q[i] - 1][1] += v[i];
            weight[q[i] - 1][1] += v[i] * p[i];
            price[q[i] - 1][3] += v[i];
            weight[q[i] - 1][3] += v[i] * p[i];
        }
        else if(price[q[i] - 1][1] == price[q[i] - 1][3]){
            for(int j = 2; j < 4; j++){
                price[q[i] - 1][j] += v[i];
                weight[q[i] - 1][j] += v[i] * p[i];
            }
        }
        
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < 4; j++) price[i][j] /= 10;
    }


    int dp[m + 1][N + 1];
    memset(dp, 0, sizeof(dp));
    for(int i = 1 ; i < m + 1 ; i++)
    {
        for(int j = 1 ; j < N + 1 ; j++)
        {
            dp[i][j] = dp[i-1][j];
            for(int k = 0 ; k < 4 ; k++)
            {
                if(j >= price[i - 1][k]) //j >= price[i][k]
                {
 
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - price[i - 1][k]] + weight[i - 1][k]);
                }
            }
            dp[i][j] = dp[i][j]; //printf("dp[%d][%d]  = %d\n", i, j, dp[i][j] );
        }
   }

    printf("%d\n", dp[m][N]);    
    
    return 0;
}