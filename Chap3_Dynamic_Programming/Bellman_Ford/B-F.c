#include <stdio.h>

#define VERTEX 7
#define NONE   100

int W[VERTEX][VERTEX] = { {NONE,6,5,5,NONE,NONE,NONE},
                          {NONE,NONE,NONE,NONE,-1,NONE,NONE},
                          {NONE,-2,NONE,NONE,1,NONE,NONE},
                          {NONE,NONE,NONE,NONE,NONE,-1,NONE},
                          {NONE,NONE,NONE,NONE,NONE,NONE,3},
                          {NONE,NONE,NONE,NONE,NONE,NONE,3},
                          {NONE,NONE,NONE,NONE,NONE,NONE,NONE} };
int dist[VERTEX];

void BellmanFord(int n, int v){

    // Initialize
    for(int i=0; i<n; i++)
        dist[i] = W[v][i];

    for(int k=2; k<n; k++){
        for(int u=0; u<n; u++){
            if( (u!=v) ){   // k마다 u를 어떻게 골라내지?????????????????
                for(int i=0; i<n; i++){
                    if( (dist[u] > dist[i] + W[i][u]) ){
                        printf("k = %d, u = %d, i = %d\n", k, u, i);
                        dist[u] = dist[i] + W[i][u];
                    }
                }
            }
        }
    for(int j=0; j<VERTEX; j++)
        printf("%4d", dist[j]);
    printf("\n");
    }
}

int main(){

    for(int i=0; i<VERTEX; i++){
        for(int j=0; j<VERTEX; j++)
            printf("%4d", W[i][j]);
        printf("\n");
    }
    printf("\n");

    BellmanFord(VERTEX, 0);

    for(int j=0; j<VERTEX; j++)
        printf("%4d", dist[j]);
    printf("\n");

    return 0;
}
