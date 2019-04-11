#include <stdio.h>

#define VERTEX 5

int W[VERTEX][VERTEX] = { {100,1,3,100,100}, {1,100,3,6,100}, {3,3,100,4,2}, 
                             {100,6,4,100,5}, {100,100,2,5,100} };
int nearest[VERTEX];
int distance[VERTEX];

void prim(int n){
    int min;
    int near;

    // Initialize
    for(int i=1; i<n; i++){
        nearest[i]  = 0;
        distance[i] = W[0][i];
    }

    for(int k=0; k<n-2; k++){

        // Choose min
        min = 100;
        for(int i=1; i<n; i++)
            if( 0<distance[i] && distance[i]<min ){
                min  = distance[i];
                near = i;
            }

        // Compare and Update
        distance[near] = -1;
        for(int i=1; i<n; i++)
            if( W[i][near] < distance[i] ){
                distance[i] = W[i][near];
                nearest[i]  = near;
            }
    }
}

int main(){

    prim(VERTEX);

    printf("Vertex   :");
    for(int i=0; i<VERTEX; i++)
        printf("%4d", i+1);
    printf("\n");
    printf("Connected:");
    for(int i=0; i<VERTEX; i++)
        printf("%4d", nearest[i]+1);
    printf("\n");

    return 0;
}
