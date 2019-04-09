#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VERTEX_NUM 4
#define SUBSET_EXCEPT_V1 8    // 2^(vertex-1)

int W[VERTEX_NUM][VERTEX_NUM] = { {-1,2,9,-1}, {1,-1,6,4}, {-1,7,-1,8}, {6,3,-1,-1} };
int D[VERTEX_NUM][SUBSET_EXCEPT_V1];

void tsp(int n){
    for(int i=1; i<n; i++)
        D[i][0] = W[i][0];

    for(int k=1; k<n-1; k++)
        for(    // Continue @@@@@@@@@
}

int main(){
    memset(D, -1, sizeof(D));

    tsp(VERTEX_NUM);

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++)
            printf("%3d", W[i][j]);
        printf("\n");
    }
    printf("\n");
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++)
            printf("%3d", D[i][j]);
        printf("\n");
    }

    exit(0);
}
