#include <stdio.h>

#define VERTEX 5
#define NONE 100
  
int W[VERTEX][VERTEX] = { {NONE,7,4,6,1}, 
                          {NONE,NONE,NONE,NONE,NONE}, 
                          {NONE,2,NONE,5,NONE},
                          {NONE,3,NONE,NONE,NONE},
                          {NONE,NONE,NONE,1,NONE} };
int touch[VERTEX];
int length[VERTEX];

void dijkstra(int n){
    int min = 0;
    int near = 0;

    // Initialize touch and length
    for(int i=1; i<n; i++){
        touch[i] = 0;
        length[i] = W[0][i];
    }
    touch[0] = -2;
    length[0] = -2;

    // Repeat VERTEX-1 times
    for(int k=0; k<n-1; k++){

        // Choose locally optimal choice
        min = NONE;
        for(int i=1; i<n; i++)
            if( 0<=length[i] && length[i]<min ){
                min = length[i];
                near = i;
            }

        // Compare & Update
        for(int i=1; i<n; i++){
            if( length[near]+W[near][i] < length[i] ){
                length[i] = length[near] + W[near][i];
                touch[i] = near;
            }
            length[near] = -1;
        }
    }
}

int main(){
/*
    for(int i=0; i<VERTEX; i++){
        for(int j=0; j<VERTEX; j++)
            printf("%4d", W[i][j]);
        printf("\n");
    }
*/

    dijkstra(VERTEX);

    for(int j=0; j<VERTEX; j++)
        printf("%2d", touch[j]+1);  // For represent as 1~n
    printf("\n");
    for(int j=0; j<VERTEX; j++)
        printf("%2d", length[j]+1);
    printf("\n");

    return 0;
}
