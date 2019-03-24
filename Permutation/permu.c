#include <stdio.h>
#include "sort.h"

void perm(int* s, int k, int n){
	int i;
	int tmp;
	if(k>=n){		// Termination Condition
		for(int i=0; i<n; i++)
			printf("%d ", s[i]);
		printf("\n");
		return ;		// T.C !!!
	}

	quick_sort(s,k,n-1);
	perm(s, k+1, n); quick_sort(s, k+1, n-1);
	for(i=k ; i<n; i++)
		if(s[k]<s[i]){
			tmp = s[k];
			s[k] = s[i];
			s[i] = tmp;
			perm(s, k+1, n); quick_sort(s, k+1, n-1);
		}

};

int main(){
	int s[7] = {1,1,2,2,2,3,3};

//	quick_sort(s,0,7);
//	for(int i=0; i<7; i++)
//		printf("%d ", s[i]);
//	printf("\n");
	perm(s, 0, 7);

	return 0;
};
