#include <stdio.h>
#include <string.h>

int main() {
    int n, m;
    scanf("%d", &n); 
    char name[n][50];
    int vote[n + 1];
    char allVote[101];

    for(int i = 0; i < n; i++) scanf("%s", name[i]);
    for(int i = 0; i < n + 1; i++) vote[i] = 0;

    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%s", allVote);
        int j = -1;
        while(++j < n){
            if(strcmp(allVote, name[j]) == 0) break;
        }
        vote[j]++;
    }

    for(int i = 0; i < n; i++) printf("%s : %d\n", name[i], vote[i]);
    printf("Invalid : %d\n",  vote[n]);
    return 0;
}