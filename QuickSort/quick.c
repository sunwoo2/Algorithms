// Unstable Sorting
// In-Place Sorting
// Time Complexity is O(n^2) ... A(nlgn), W(n^2);

#include <stdio.h>

void swap(int* a, int* b){
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void partition(int a[], int low, int high, int* pivotpoint){
	int pivotitem = a[low];
	int j = low;

	for(int i=low+1; i<=high; i++)
		if(a[i]<pivotitem)
			swap(&a[i], &a[++j]);

	*pivotpoint = j;
	swap(&a[low], &a[*pivotpoint]);
}

int partition1(int a[], int low, int high){
	int pivotitem = a[low];
	int j = low;

	for(int i=low+1; i<=high; i++)
		if(a[i]<pivotitem)
			swap(&a[i], &a[++j]);

	swap(&a[low], &a[j]);
	return j;
}

// Which one is better?
void quicksort(int a[], int low, int high){
	if(low<high){	// T.C
		int pivotpoint = low;
		partition(a, low, high, &pivotpoint);
		quicksort(a, low, pivotpoint-1);
		quicksort(a, pivotpoint+1, high);
	}
}

void quicksort1(int a[], int low, int high){
	if(low<high){	// T.C
		int pivotpoint = partition1(a, low, high);
		quicksort(a, low, pivotpoint-1);
		quicksort(a, pivotpoint+1, high);
	}
}
//

// Protect Stack Overflow (Reduce Stack Depth)
void quicksort2(int a[], int low, int high){
	int l=low;
	int h=high;
	while(l<h){		// T.C
		int pivotpoint = l;
		partition(a, l, h, &pivotpoint);
		if(pivotpoint-l <= h-pivotpoint){
			quicksort1(a, l, pivotpoint-1);
			l = pivotpoint+1;
		}else{
			quicksort1(a, pivotpoint+1, h);
			h = pivotpoint-1;
		}
	}
}

int main(){
	int a[8] = {15,22,13,27,12,10,20,25};

//	quicksort(a, 0, 7);
	quicksort1(a, 0, 7);
//	quicksort2(a, 0, 7);

	for(int i=0; i<8; i++)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}
