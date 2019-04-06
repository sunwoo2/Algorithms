#include <stdio.h>
#include <string.h>

#define N 5
#define Final_value 8
//#define N 12
//#define Final_value 22

int A[N][N][31];
int P[N][N][31];

void sequence(int n){
    int j;

    for(int m=1; m<n; m++)
        for(int i=0; i<n-m; i++){
            j = i+m;
            for(int v=0; v<31; v++)
                for(int k=i; k<j; k++)
                    for(int u=0; u<31-v; u++){
                        if( ((A[i][k][u] != -1) && (A[k+1][j][u+v] != -1)) ||  \
                            ((A[i][k][u+v] != -1) && (A[k+1][j][u] != -1))){
                            if(A[i][j][v] == -1){   // 이미 값이 존재하면 덮어쓰기 금지(1210나옴)
                                A[i][j][v] = u;
                                P[i][j][v] = k;
                                //printf("%d~%d에서 최종값 %d를 얻기 위해 %d에서 끊는다.(%d)\n" \ 
                                //        ,i ,j            ,v             ,k             ,u);
                            }
                        }
                }
        }
}

void print_value(int i, int j, int v, int x){
    if(i<j){    
        int u = A[i][j][v];
        int k = P[i][j][v];

        if( (A[i][k][u]!=-1) && (A[k+1][j][u+v]!=-1) ){
            print_value(i,k,u,x);
            print_value(k+1,j,u+v,x+1);
            printf("%3d", x);
        }else{
            print_value(i,k,u+v,x);
            print_value(k+1,j,u,x+1);
            printf("%3d", x);
        }

    }
}

int main(){
    int S[N] = {12,10,4,3,5};
    //int S[N] = {12,10,4,3,5,31,37,22,18,4,5,9};

    // Initialize
    memset(A, -1, sizeof(A));
    for(int i=0; i<N; i++){
        A[i][i][S[i]] = S[i];
        P[i][i][S[i]] = i;
    }

    sequence(N);

    // A
    printf("\n");
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            printf("%3d", A[i][j][Final_value]);
        printf("\n");
    }
    printf("\n");
    // P
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            printf("%3d", P[i][j][Final_value]);
        printf("\n");
    }
    printf("\n");

    // Print
    if(A[0][N-1][Final_value] == -1)
        printf("최종값 존재 하지 않음\n");
    else{
        print_value(0,N-1,Final_value,0);
        printf("\n");
    }
    
    return 0;
}
