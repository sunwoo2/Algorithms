#include <stdio.h>
#include <string.h>

int D[5][5] = {{0,1,100,1,5}, {9,0,3,2,100}, {100,100,0,4,100}, {100,100,2,0,3},
    {3,100,100,100,0}};
int P[5][5];

void floyd(int n){

    // Array : 0,1,2,3,4    
	for(int k=0; k<n; k++)
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if(D[i][j] > (D[i][k]+D[k][j])){
                    P[i][j] = k+1;      // save vertex
					D[i][j] = D[i][k]+D[k][j];
                }

}

void print_path(int i, int j){  // vertex : 1,2,3,4,5
    i--;
    j--;
    if(P[i][j] != 0){
        print_path(i+1, P[i][j]);
        printf("%d ", P[i][j]);
        print_path(P[i][j], j+1);
    }
}

int main(){
    memset(P, '\0', sizeof(P));

	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++)
			printf("%3d ", D[i][j]);
		printf("\n");
	}
	printf("\n");

	floyd(5);

	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++)
			printf("%3d ", D[i][j]);
		printf("\n");
	}
	printf("\n");

	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++)
			printf("%3d ", P[i][j]);
		printf("\n");
	}
	printf("\n");

    print_path(3,2);    // S.P of vertex3 -> vertex2
	printf("\n");

	return 0;
}
