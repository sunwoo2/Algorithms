#include <stdio.h>
#include <string.h>

void floyd(int n, int (*W)[5], int (*D)[5]){
	D = W;

	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++)
			printf("%3d ", D[i][j]);
		printf("\n");
	}
	printf("\n");

	for(int k=0; k<n; k++)
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if(D[i][j] > (D[i][k]+D[k][j])){
//					D[i][j] = D[i][k]+D[k][j];
//					(*(D+i))[j] = D[i][k]+D[k][j];
//					*(D[i]+j) = D[i][k]+D[k][j];
					*(*(D+i)+j) = D[i][k]+D[k][j];	// 아니 포인터인데 왜 값이 안넘어가는건데
					printf("k:%d (%d,%d) = %d\n", k,i,j, D[i][j]);
				}

	printf("\n");
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++)
			printf("%3d ", D[i][j]);
		printf("\n");
	}
	printf("\n");


}

int main(){
	int W[5][5] = {{0,1,100,1,5}, {9,0,3,2,100}, {100,100,0,4,100}, {100,100,2,0,3},
		{3,100,100,100,0}};
	int D[5][5];

	memset(&D, 0, sizeof(D));	
	floyd(5, W, D);

	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++)
			printf("%3d ", D[i][j]);
		printf("\n");
	}

	return 0;
}
