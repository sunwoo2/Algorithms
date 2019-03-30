// extra space is n
// Stable Sorting
// Time Complexity is T(nlgn)

#include <stdio.h>
#include <string.h>

void merge(int a[], int low, int mid, int high){	// Input Size : n
	int i = low;
	int j = mid+1;
	int k = low;
	int U[high];

	while(i<=mid && j<=high)
		if(a[i]<=a[j])		// Basic Opertion : Key Comparison
			U[k++] = a[i++];
		else
			U[k++] = a[j++]; 

	if(i>mid)
		while(j<=high)
			U[k++] = a[j++];
	else
		while(i<=mid)
			U[k++] = a[i++];

	for(int i=low; i<=high; i++)
		a[i] = U[i];
}

void mergesort(int a[], int low, int high){		// Input Size : n

	if(low<high){	// Termination Condition (T.C)
		int mid = (low+high)/2;
		mergesort(a, low, mid);
		mergesort(a, mid+1, high);
		merge(a, low, mid, high);
	}

}

int main(){
	int a[12] = {38, 24, 10, 12, 20, 27,2, 13, 15, 22, 25, 9};

	mergesort(a, 0, 11);

	for(int i=0; i<12; i++)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}
