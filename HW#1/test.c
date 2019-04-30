#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test(int A[], int i, int j, int k){

    for(int a=0; a<i; a++){
        for(int q=0; q<j; q++){
            for(int w=0; w<k; w++)
                printf("%d ", *(A+a*j*k+q*k+w));
            printf("\n");
        }
        printf("\n");
    }

}

int main(){

    int A[2][2][2] = { {{1,2}, {3,4}}, {{5,6}, {7,8}} };    
    int B[12] = {1,2,3,4,5,6,7,8,9,10,11,12}; // B[2][2][3]

    // real 3-D array
    for(int a=0; a<2; a++){
        for(int q=0; q<2; q++){
            for(int w=0; w<2; w++)
                printf("%d ", *(*(*(A+a)+q)+w));
            printf("\n");
        }
        printf("\n");
    }

    // representation 3-D array by 1-D array
    for(int a=0; a<2; a++){
        for(int q=0; q<2; q++){
            for(int w=0; w<2; w++)
                printf("%d ", *(B+a*4+q*2+w));
            printf("\n");
        }
        printf("\n");
    }

    // B[2][2][3]
    test(B,2,2,3);

    return 0;
}
