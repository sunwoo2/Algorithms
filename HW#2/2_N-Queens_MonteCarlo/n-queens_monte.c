#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// For VS
#pragma warning(disable: 4996)  // scanf, fsacnf
#pragma warning(disable: 4819)  // 한글주석 

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

int estimate_n_queens(int col[], int n){   // 여기서 n은 N 
    srand(time(NULL));
    int m = 1;
    int i = 0;
    int k = 0;
    int mprod = 1;
    long  numnodes = 1;
    int promising_children[n];

    while((m!=0) && (i!=n)){
        mprod = mprod*m;
        numnodes = numnodes + mprod*n;
        m=0;
        k=0;
        memset(promising_children, 0, sizeof(int)*n);

        for(int j=1; j<=n; j++){  // j : queen의 위치
            col[i] = j;
            if(promising(col, i)){
                m++;
                promising_children[k++] = j;
            }
        }

        if(m!=0)
            col[i++] = promising_children[rand()%k];   // 난수 : 0~k-1 (마지막에 ++ 됐기 때문에 딱 맞음)
        else   // promising 한게 없으면 위에서 j대입한거 다시 0으로 만들어 줘야지!!
            col[i] = 0;
    }

    return i;  
}

void queens(FILE *output, int col[], int i, int n){     // 여기서 n은 N-1로 배열 인덱스 기준

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
                col[i+1] = j+1;     // i(배열 인덱스) : 0~N-1, j(queen의 위치) : 1~N
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
    int monte_index = estimate_n_queens(col, N);
    printf("monte calro로 채운 index = %d\n", monte_index-1);
    int back_num = monte_index-9;   // 10개 Back tracking
    // Ready to Back tracking
    for(int i=back_num; i<monte_index; i++)    
        col[i] = 0;
    // Strat Back tracking
    for(int j=0; j<N; j++){
        col[back_num] = j+1;    // 배열 인덱스 : 0~N-1, queen의 위치 : 1~N
        queens(output,col,back_num, N-1);
    }


    free(col);
    fclose(input);
    fclose(output);


    return 0;
}
