#include <stdio.h>

void NaiveMatMul(int (*A)[5], int (*B)[5], int (*C)[5]){	// O(n^3)
	for(int i=0; i<5; i++)
		for(int j=0; j<5; j++){
			C[i][j] = 0;
			for(int k=0; k<5; k++)
				C[i][j] += A[i][k] * B[k][j];
		}
};

void StrassenMatMul(int (*A)[5], int (*B)[5], int (*C)[5]){		// O(n^2.81)!!
// How can i implement Staressen algorithm...?
}

int main(){
	int A[5][5] = {{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};
	int B[5][5] = {{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};
	int C[5][5];

	NaiveMatMul(A,B,C);

	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++)
			printf("%d ", C[i][j]);
		printf("\n");
	}

	return 0;
}
