#include <stdio.h>
#include <string.h>

int M[6][6];
int d[7] = {5,2,3,4,6,7,8};
int P[5][6];

void minmult(int n){
    int j;
    int tmp;
    memset(M, '\0', sizeof(M));
    memset(P, '\0', sizeof(M));
    
    for(int diagonal=0; diagonal<n-1; diagonal++){
        for(int i=0; i<n-diagonal; i++){
            j = i+diagonal;
            for(int k=i; k<=j-1; k++){
                /*
                if(k==i)
                    M[i][j] = M[i][k]+M[k+1][j]+d[i-1]*d[k]*d[j];
                if(M[i][k]+M[k+1][j]+d[i-1]*d[k]*d[j] < M[i][j]){
                    M[i][j] = M[i][k]+M[k+1][j]+d[i-1]*d[k]*d[j];
                    printf("%d\n", M[i][j]);
                }
                */
            }
        }
    }
}

int main(){

    minmult(6);

	for(int i=0; i<6; i++){
		for(int j=0; j<6; j++)
			printf("%4d ", M[i][j]);
		printf("\n");
	}
	printf("\n");

    return 0;
}
