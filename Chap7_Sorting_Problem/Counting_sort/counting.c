#include <stdio.h>
#include <string.h>

#define N 10
#define K 10

void countsort(int A[], int B[], int C[], int k, int n){
    for(int i=0; i<n; i++)
        C[A[i]-1]++;
    for(int i=1; i<k; i++)
        C[i] += C[i-1];
    for(int i=n-1; i>=0; i--){
        B[(C[A[i]-1]--)-1] = A[i];  // C 배열이라 -1 해줌.
        //B[C[A[i]-1]-1] = A[i];    // same code
        //C[A[i]-1]--;
    }
}

int main(){

    int A[N] = {1,4,7,3,1,3,9,5,10,8};
    int B[N];
    int C[K];
    memset(B, 0, sizeof(B));
    memset(C, 0, sizeof(C));

    countsort(A,B,C,K,N);

    for(int i=0; i<N; i++)
        printf("% d", B[i]);
    printf("\n");

    return 0;
}
