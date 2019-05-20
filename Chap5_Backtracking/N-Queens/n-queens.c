#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define N 4 

int col[N];

bool promising(int i){
    int k=0;
    bool promising = true;

    while( k<i && promising ){
        if( (col[i]==col[k]) || (abs(col[i]-col[k])==abs(i-k)) ){
            promising = false;
        }
        k++;
    }

    return promising;
}

void queens(int i, int n){

    if(promising(i)){
        if(i==n){   // Finish locating N-Queens
            for(int k=0; k<=n; k++)
                printf("%d\n", col[k]);
            printf("\n");
            exit(0);   // Need to Exit
        }else{
            for(int j=0; j<=n; j++){
                col[i+1] = j+1;     // i : 0~N-1, j : 1~N
                queens(i+1, n);
            }
        }
    }

}

int main(){

    memset(col, '\0', sizeof(col));

    queens(-1,N-1);

    return 0;
}
