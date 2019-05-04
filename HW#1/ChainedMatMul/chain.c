#include <stdio.h>
#include <string.h>

void minmult(int M[], int P[], int d[], int N){
    int j;
    int min;
    
    for(int diagonal=0; diagonal<=N-1; diagonal++){
        for(int i=0; i<N-diagonal; i++){
            j = i+diagonal;
            min = M[i*N+i]+M[(i+1)*N+j]+d[i]*d[i+1]*d[j+1];
            for(int k=i; k<=j-1; k++){
                if( min > M[i*N+k]+M[(k+1)*N+j]+d[i]*d[k+1]*d[j+1] ){
                    M[i*N+j] = M[i*N+k]+M[(k+1)*N+j]+d[i]*d[k+1]*d[j+1]; 
                    P[i*N+j] = k;
                }else{
                    M[i*N+j] = min;
                    P[i*N+j] = i;
                }
            }
        }
    }
}

void print_order(FILE *output, int P[], int N, int i, int j){
    if(i==j){
        printf("%d",i+1);   // 1~N으로 표현하기위해 +1
        fprintf(output, "%d",i+1);
    }
    else{
        int k = P[i*N+j];
        printf("(");
        fprintf(output, "(");
        print_order(output,P,N,i,k);
        print_order(output,P,N,k+1,j);
        printf(")");
        fprintf(output, ")");
    }
}

int main(){

    char input[50];
    printf("input file name? ");
    scanf("%s", input);

    FILE *fd, *output;
    fd = fopen(input, "r");
    output = fopen("output.txt", "w");

    // Read Data
    int D,N;
    fscanf(fd, "%d", &D);
    N = D-1;
    int d[D];
    for(int i=0; i<D; i++)
        fscanf(fd, "%d", &d[i]);

    // Initialize arrays
    int M[N*N];
    int P[N*N];
    memset(M, '\0', sizeof(M));
    memset(P, -1, sizeof(P));


    minmult(M,P,d,N);
    print_order(output,P,N,0,N-1);
    printf("\n");


    fclose(fd);
    fclose(output);

    return 0;
}
