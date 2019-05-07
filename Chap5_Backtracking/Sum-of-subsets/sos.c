#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define N 4

int w[N] = {3,4,5,6};
int W = 13;
int include[N];

bool promising(int i, int weight, int total){

                printf("w[%d]=%d, weight=%d, total=%d\n", i,w[i],weight,total);
    if( (weight+total)>=W &&
        ( (weight==W) || ((weight+w[i+1])<=W) ) ){
                printf("promising : w[%d]=%d, weight=%d, total=%d\n", i,w[i],weight,total);
        return true;
    }

    return false;
}

void sum_of_subsets(int i, int weight, int total){

    if(promising(i,weight,total)){
        if(weight==W){   // Find Solution
            for(int k=0; k<=i; k++)
                printf("w%d - %d\n", k+1, include[k]);
        }else{
            include[i+1] = 1;
            sum_of_subsets(i+1, weight+w[i+1], total-w[i+1]);
            include[i+1] = 0;
            sum_of_subsets(i+1, weight, total-w[i+1]);
        }
    }

}

int main(){

    sum_of_subsets(-1, 0, W);

    return 0;
}
