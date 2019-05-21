#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool promising(int p[], int w[], int* maxprofit, int N, int W, int i, int profit, int weight){
    
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
            if(bound>(*maxprofit))
                return true;
        }
        return false;
    }

}

void knapsack(int p[],int w[], int include[], int bestset[], int* maxprofit, int N, int W,
        int i, int profit, int weight){

        //printf("i=%d\n",i);
    if( weight<=W && profit>=(*maxprofit) ){
        *maxprofit = profit;
        for(int i=0; i<N; i++)
            bestset[i] = include[i];    // Copy by value! Not pointer!
    }

    if(promising(p,w,maxprofit,N,W,i,profit,weight)){
        include[i+1] = 1;
        knapsack(p,w,include,bestset,maxprofit,N,W,i+1,profit+p[i+1],weight+w[i+1]);
        include[i+1] = 0;
        knapsack(p,w,include,bestset,maxprofit,N,W,i+1,profit,weight);
    }

}

int main(){

    char input_name[50];
    printf("input file name? ");
    scanf("%s", input_name);

    FILE *input, *output;
    input = fopen(input_name, "r");
    output = fopen("output.txt", "w");

    // Read Data
    int N,W;
    fscanf(input, "%d", &N);
    fscanf(input, "%d", &W);

    // Initialize arrays
    int* p = (int*)calloc(N,sizeof(int)); 
    int* w = (int*)calloc(N,sizeof(int)); 
    for(int i=0; i<N; i++){
        fscanf(input, "%d", &p[i]);
        fscanf(input, "%d", &w[i]);
    }
    int* include = (int*)calloc(N,sizeof(int)); 
    int* bestset = (int*)calloc(N,sizeof(int)); 
    int maxprofit=0;


    // Algorithm
    knapsack(p,w,include,bestset,&maxprofit,N,W,-1,0,0);   // Start -1

    // Print
    printf("%d\n", maxprofit);
    fprintf(output,"%d\n", maxprofit);
    for(int i=0; i<N; i++){
        printf("%d\n", bestset[i]);
        fprintf(output,"%d\n", bestset[i]);
    }


    //free(p);      // input2.txt run할때 "free(): invalid pointer" error뜸. 다른 input.txt에서는 error 발생 안함 
    //free(w);
    //free(include);
    //free(bestset);
    fclose(input);
    fclose(output);

    return 0;
}
