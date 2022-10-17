#include <stdio.h>
#include <string.h>
// int m = 3, n = 4;
int m, n;
int scnt = 0, value = 0, cnt = 0;
int garden[100], plant[100] = {0};

int planting(int gardenpointer){
    if(gardenpointer == m){
        if(cnt > value){
            value = cnt;
            scnt = 1;
        }
        else if(cnt == value) scnt++;
        return 1;
    }

    for(int j = gardenpointer; j < m; j++){
        for(int i = 0; i < n; i++){
            if(!plant[i] && i % m != j){
                plant[i] = 1;
                cnt++;
                garden[j] = i;
                planting(j + 1);
                plant[i] = 0;
                garden[j] = -1;
                cnt--;
            }

        }
    }
}


int main(){
    scanf("%d%d", &m, &n);
    for(int i = 0; i < m; i++) garden[i] = -1;
    planting(0);
    printf("%d\n", scnt);

        // scanf("%d%d", &m, &n);
        // int garden[m], plant[n];

        return 0;
}

