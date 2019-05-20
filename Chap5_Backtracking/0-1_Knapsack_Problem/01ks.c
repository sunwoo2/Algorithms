#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define N 4
#define W 16

int p[N] = {40,30,50,10};
int w[N] = {2,5,10,5};
int include[N];
int bestset[N];
int maxprofit;

bool promising(int i, int profit, int weight){
    
    if(weight>=W)
        return false;
    else{
        int j = i+1;
        int bound = profit;
        int totalweight = weight;
        while( (j<N) && (totalweight+w[j]<=W) ){
            totalweight = totalweight + w[j];
            bound = bound + p[j];
            j++;
        }
        if(j==N)    // 마지막 물건을 넣을 수 있을때!!!
            j--;
        if(j<N){
            bound += (W-totalweight)*(p[j]/w[j]);   // Upper bound (solution of f.k.s)
            if(bound>maxprofit)
                return true;
        }
        return false;
    }

}

void knapsack(int i, int profit, int weight){

    if( weight<=W && profit>=maxprofit ){
        maxprofit = profit;
        for(int i=0; i<N; i++)
            bestset[i] = include[i];    // Copy by value! Not pointer!
    }

    if(promising(i,profit,weight)){
        include[i+1] = 1;
        knapsack(i+1, profit+p[i+1], weight+w[i+1]);
        include[i+1] = 0;
        knapsack(i+1, profit, weight);
    }

}

int main(){

    maxprofit = 0;
    knapsack(-1,0,0);   // Start -1
    printf("Maxprofit : %d\n", maxprofit);
    for(int i=0; i<N; i++)
        printf("%2d", bestset[i]);
    printf("\n");

    return 0;
}
