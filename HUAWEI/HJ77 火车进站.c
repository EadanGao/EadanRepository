#include <stdio.h>
#include <string.h>

int station_in[10] = {0};
int table[6000][10] = {0};
int N;
int table_pointer;

void swap(int *a, int *b){
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
    return ;
}

void schedule(int i, int *Station, int *Station_out, int Out_pointer, int Station_pointer){
    int station[10];
    int station_out[10];
    int out_pointer = Out_pointer;
    int station_pointer = Station_pointer;
    for(int k = 0; k < N; k++) station[k] = Station[k];
    for(int k = 0; k < N; k++) station_out[k] = Station_out[k];

    if(i == N - 1) station_out[out_pointer++] = station_in[i];

    if(out_pointer + station_pointer == N){        
        while(station_pointer > 0) station_out[out_pointer++] = station[--station_pointer];
        for(int k = 0; k < N; k++) table[table_pointer][k] = station_out[k];
        table_pointer++;
        out_pointer = 0;
        return ;
    }
    else{
        // in station
        station[station_pointer++] = station_in[i];
        schedule(i + 1, station, station_out, out_pointer, station_pointer);
        //out 
        station[--station_pointer] = 0;
        station_out[out_pointer++] = station_in[i];
        schedule(i + 1, station, station_out, out_pointer, station_pointer);

        while(station_pointer > 0){
            station_out[out_pointer++] = station[--station_pointer];
            station[station_pointer] = 0;
            schedule(i + 1, station, station_out, out_pointer, station_pointer);

        }
    }
    
    return ; 
}

int main() {
    
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%d", &station_in[i]);

    int station[10] = {0};
    int station_out[10] = {0};
    int out_pointer = 0;
    int station_pointer = 0;

    schedule(0, station, station_out, out_pointer, station_pointer);

    for(int i = 0; i < table_pointer - 1; i++){
        for(int j = 0; j < table_pointer - 1; j++){
            for(int k = 0; k < N; k++){
                if(table[j][k] < table[j + 1][k]) break;
                if(table[j][k] > table[j + 1][k]){
                    for(int l = 0; l < N; l++) swap(&table[j][l], &table[j + 1][l]);
                    break;
                }
            }
        }
    }

    for(int i = 0; i < table_pointer; i++){
        for(int j = 0; j < N; j++) printf("%d ", table[i][j]);
        printf("\n");

    }

    return 0;
}