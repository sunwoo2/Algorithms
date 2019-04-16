#include <stdio.h>

#define VERTEX 7
#define NONE 100

int W[VERTEX][VERTEX] = { {200,5,10,200,200,200,200}, 
                          {200,200,10,4,200,200,200}, 
                          {200,200,200,4,11,200,200},
                          {200,200,200,200,11,7,200},
                          {200,200,200,200,200,7,7}, 
                          {200,200,200,200,200,200,0},
                          {200,200,200,200,200,200,200} };
int touch[VERTEX];
int length[VERTEX];

void dijkstra(int n){
    int min = 0;
    int near = 0;

    // Initialize touch and length
    for(int i=1; i<n; i++){
        touch[i] = 0;
        length[i] = NONE;
    }
    touch[0] = -2;
    length[0] = -2;
    length[1] = 5;
    length[2] = 10;

    // Repeat VERTEX-1 times
    for(int k=0; k<1; k++){

        // Choose locally optimal choice
        min = NONE;
        for(int i=1; i<n; i++)
            if( 0<=length[i] && length[i]<min ){
                min = length[i];
                near = i;
            }
//        printf("Choose locally optimal choice: %d\n", near);
//    for(int j=0; j<VERTEX; j++)
//        printf("%4d", length[j]);
//        printf("\n");

//        printf("length[1]: %d\n", length[1]);   // 아니 여기서는 5 맞는데
        // Compare & Update
        for(int i=1; i<3; i++){
            if( (length[near]+W[near][i]) < length[i] ){
//        printf("length[1]: %d\n", length[1]);   // if문 안에 저거 하고나면 왜 -1이 되냐고!!?
//                printf("%d + %d < %d\n", length[near],W[near][i],length[i]);
                length[i] = length[near] + W[near][i];
                touch[i] = near;
//    for(int j=0; j<VERTEX; j++)
//        printf("%4d", length[j]);
//        printf("\n");

//                printf("length[%d]: %d\n", i, length[i]);
//                printf("touch[%d]: %d\n", i, touch[i]);

            }
            length[near] = -1;
        }
//    for(int j=0; j<VERTEX; j++)
//        printf("%4d", length[j]);
//        printf("\n");
    }
}

int main(){

    for(int i=0; i<VERTEX; i++){
        for(int j=0; j<VERTEX; j++)
            printf("%4d", W[i][j]);
        printf("\n");
    }


    dijkstra(VERTEX);

    for(int j=0; j<VERTEX; j++)
        printf("%2d", touch[j]); 
    printf("\n");
    for(int j=0; j<VERTEX; j++)
        printf("%2d", length[j]);
    printf("\n");

    return 0;
}
