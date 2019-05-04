#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 8
#define INF 99999

enum direction {U,D,L,R};

// 흰방 - 0, 검은방 - 1
int W[N][N] = { {0,0,0,1,1,0,0,1},
                {0,0,1,0,1,1,0,1},
                {0,1,1,0,0,1,0,1},
                {0,0,0,1,0,0,1,1},
                {1,0,1,1,1,0,0,0},
                {1,1,0,0,1,1,1,0},
                {0,0,1,0,0,1,1,1},
                {0,0,1,1,1,0,0,0} };

int l[N][N];
int l1[N][N];
int t[N][N];

void maze(){
    int min;
    int near1=0;
    int near2=0;
    
    // Initialize
    l[0][0] = 0;
    l1[0][0] = 0;

    // L.O.C
    for(int k=0; k<N*N-1; k++){
        min = INF;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(0<=l[i][j] && l[i][j]<min){
                    min = l[i][j]; 
                    near1 = i;
                    near2 = j;
                }
            }
        }

        // Down -> Up
        if( l[near1][near2]+W[near1-1][near2] < l[near1-1][near2] &&
                (near1-1) >= 0 ){
            l[near1-1][near2] = l[near1][near2]+W[near1-1][near2]; 
            l1[near1-1][near2] = l[near1][near2]+W[near1-1][near2]; 
            t[near1-1][near2] = D;
        }
        // Up -> Down
        if( l[near1][near2]+W[near1+1][near2] < l[near1+1][near2] &&
                (near1+1) < N ){
            l[near1+1][near2] = l[near1][near2]+W[near1+1][near2]; 
            l1[near1+1][near2] = l[near1][near2]+W[near1+1][near2]; 
            t[near1+1][near2] = U;
        }
        // Right -> Left
        if( l[near1][near2]+W[near1][near2-1] < l[near1][near2-1] &&
                (near2-1) >= 0 ){
            l[near1][near2-1] = l[near1][near2]+W[near1][near2-1]; 
            l1[near1][near2-1] = l[near1][near2]+W[near1][near2-1]; 
            t[near1][near2-1] = R;
        }
        // Left -> Right
        if( l[near1][near2]+W[near1][near2+1] < l[near1][near2+1] &&
                (near2+1) < N ){
            l[near1][near2+1] = l[near1][near2]+W[near1][near2+1]; 
            l1[near1][near2+1] = l[near1][near2]+W[near1][near2+1]; 
            t[near1][near2+1] = L;
        }

        l[near1][near2] = -1;
    }

}

void print_path(int i, int j){
    if(i>=0 && j>=0){
        int parent = t[i][j];
        switch(parent){
            case U:
                print_path(i-1,j);
                break;
            case D:
                print_path(i+1,j);
                break;
            case L:
                print_path(i,j-1);
                break;
            case R:
                print_path(i,j+1);
                break;
        }
        printf("%d %d\n", i+1, j+1);    // 1~N으로 표현하기위해 +1
    }
}

int main(){

    memset(t, -1, sizeof(t));
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            l[i][j] = INF;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            l1[i][j] = INF;

    maze();

    printf("\n");
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            printf("%3d", l1[i][j]);
        printf("\n");
    }
    printf("\n");
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            printf("%3d", t[i][j]);
        printf("\n");
    }
    printf("\n");

    print_path(N-1,N-1);

    return 0;
}
