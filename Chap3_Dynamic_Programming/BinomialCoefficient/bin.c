#include <stdio.h>

// Recursion
int bin(int n, int k){
	if(k==0 || k==n)
		return 1;
	return bin(n-1,k-1) + bin(n-1,k);
}

int main(){
	printf("%d\n", bin(35,20));

	return 0;
}
