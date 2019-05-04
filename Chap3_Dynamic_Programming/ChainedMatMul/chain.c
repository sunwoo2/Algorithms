#include <stdio.h>
#include <string.h>

#define N 6

int M[N][N];
int d[N+1] = {5,2,3,4,N,7,8};
int P[N][N];

void minmult(int n){
    int j;
    int min;
    memset(M, '\0', sizeof(M));
    memset(P, -1, sizeof(M));
    
    for(int diagonal=0; diagonal<=n-1; diagonal++){
        for(int i=0; i<n-diagonal; i++){
            j = i+diagonal;
            min = M[i][i]+M[i+1][j]+d[i]*d[i+1]*d[j+1];
            for(int k=i; k<=j-1; k++){
                if( min > M[i][k]+M[k+1][j]+d[i]*d[k+1]*d[j+1] ){
                    M[i][j] = M[i][k]+M[k+1][j]+d[i]*d[k+1]*d[j+1];
                    P[i][j] = k;
                }else{
                    M[i][j] = min;
                    P[i][j] = i;
                }
            }
        }
    }
}

void print_order(int i, int j){
    if(i==j)
        printf("%d",i+1);   // 1~N으로 표현하기위해 +1
    else{
        int k = P[i][j];
        printf("(");
        print_order(i,k);
        print_order(k+1,j);
        printf(")");
    }
}

int main(){

    minmult(N);

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++)
			printf("%4d ", M[i][j]);
		printf("\n");
	}
	printf("\n");
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++)
			printf("%4d ", P[i][j]);
		printf("\n");
	}
	printf("\n");

    print_order(0,N-1);
    printf("\n");

    return 0;
}
