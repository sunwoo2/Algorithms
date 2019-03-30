#include <stdio.h>
  
#define PossibleMaxDistance 140

void min_time(int Max, int n, int d[], int t[], int T[], int P[]){
	int min;
	int distance;
	int previous_shop;

	for(int current_shop=1; current_shop<=n+1; current_shop++){
		// set initial value in this loop
		previous_shop = current_shop-1;
		min = T[previous_shop]+t[current_shop];
		P[current_shop] = previous_shop;

		// Checcurrent_shop other cases
		distance = d[current_shop] + d[previous_shop];
		for(int i=1; distance<=Max && (previous_shop-i)>=0; i++){
			if( (T[previous_shop-i]+t[current_shop]) < min ){
				min = T[previous_shop-i]+t[current_shop];
				P[current_shop] = previous_shop-i;
			}
			distance += d[previous_shop-i];
		}

		T[current_shop] = min;	
	}

};

int main(){								// Initial Condition
	int t[7] = {0,5,10,4,11,7,0};		// t[0]=t[n+1]=0
	int d[7] = {0,100,30,100,40,50,60};	// d[0]=0
	int T[7] = {0,0,0,0,0,0,0}; 		// T[0]=0
	int P[7] = {-1,0,0,0,0,0,0};		// P[0]=-1

	min_time(140, 6, d, t, T, P);

	printf("%2d %2d %2d %2d %2d %2d %2d\n", 0,1,2,3,4,5,6);
	for(int i=0; i<7; i++)
		printf("%2d ", T[i]);
	printf("\n");
	for(int i=0; i<7; i++)
		printf("%2d ", P[i]);
	printf("\n");

//	test(node_time);	

	return 0;
}
