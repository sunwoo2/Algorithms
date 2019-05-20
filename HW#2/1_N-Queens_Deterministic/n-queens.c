#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

bool promising(int col[], int i){
    int k=0;
    bool promising = true;

    while( k<i && promising ){
        if( (col[i]==col[k]) || (abs(col[i]-col[k])==abs(i-k)) ){
            promising = false;
        }
        k++;
    }

    return promising;
}

void queens(FILE *output, int col[], int i, int n){

    if(promising(col,i)){
        if(i==n){   // Finish locating N-Queens
            for(int k=0; k<=n; k++){
                printf("%d\n", col[k]);
                fprintf(output, "%d\n", col[k]);
            }
            printf("\n");
            exit(0);   // Need to Exit
        }else{
            for(int j=0; j<=n; j++){
                col[i+1] = j+1;     // i : 0~N-1, j : 1~N
                queens(output,col,i+1, n);
            }
        }
    }

}

int main(){

    char input_name[50];
    printf("input file name? ");
    if(!scanf("%s", input_name)){
        perror("Failed scanf!");
        exit(1);
    };

    FILE *input, *output;
    input = fopen(input_name, "r");
    output = fopen("output.txt", "w");

    // Read Data
    int N;
    if(!fscanf(input, "%d", &N)){
        perror("Failed fscanf!");
        exit(1);
    };

    // Initialize arrays
    int* col = (int*)calloc(N,sizeof(int)); 


    // Algorithm
    queens(output,col,-1,N-1);


    free(col);
    fclose(input);
    fclose(output);

    return 0;
}
