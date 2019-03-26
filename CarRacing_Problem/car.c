#include <stdio.h>

#define PossibleMaxDistance 140

int min_time(int n, int node_time[], int last, int node_distance[]){
	if(n==1)
		return 5;

	int min = min_time(n-1, node_time, last-1, node_distance) + node_time[last-1];
	int distance = node_distance[last-1];
	int current = 0;

	for(int i=2; i<=n ; i++){
		distance += node_distance[last-i];	
		if(distance >= PossibleMaxDistance){
			return min;
		}
		else{
			current = min_time(n-i, node_time, last-i, node_distance) + node_time[last-i];
			if(current < min)
				min = current;
		}
	}

	return min;
};

void test(int a[]){
	for(int i=0; i<3; i++)
		printf("%d\n", a[2+i]);
}

int main(){
	int node_time[7] = {0,5,10,4,11,7,0};
	int node_distance[6] = {100,30,100,40,50,60};
	int MinTime = 0;

	MinTime = min_time(2, node_time, 2, node_distance);

	printf("최소 총 정비시간: %d\n", MinTime);

//	test(node_time);	

	return 0;
}
