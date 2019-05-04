#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

enum direction {U,D,L,R};

void maze(int W[], int l[], int l1[], int t[], int N){
    int min;
    int near1=0;
    int near2=0;
    
    // Initialize
    l[0] = 0;
    l1[0] = 0;

    // L.O.C
    for(int k=0; k<N*N-1; k++){
        min = INFINITY;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(0<=l[i*N+j] && l[i*N+j]<min){
                    min = l[i*N+j]; 
                    near1 = i;
                    near2 = j;
                }
            }
        }

        // Down -> Up
        if( l[near1*N+near2]+W[(near1-1)*N+near2] < l[(near1-1)*N+near2] &&
                (near1-1) >= 0 ){
            l[(near1-1)*N+near2] = l[near1*N+near2]+W[(near1-1)*N+near2]; 
            l1[(near1-1)*N+near2] = l[near1*N+near2]+W[(near1-1)*N+near2]; 
            t[(near1-1)*N+near2] = D;
        }
        // Up -> Down
        if( l[near1*N+near2]+W[(near1+1)*N+near2] < l[(near1+1)*N+near2] &&
                (near1+1) < N ){
            l[(near1+1)*N+near2] = l[near1*N+near2]+W[(near1+1)*N+near2]; 
            l1[(near1+1)*N+near2] = l[near1*N+near2]+W[(near1+1)*N+near2]; 
            t[(near1+1)*N+near2] = U;
        }
        // Right -> Left
        if( l[near1*N+near2]+W[near1*N+(near2-1)] < l[near1*N+(near2-1)] &&
                (near2-1) >= 0 ){
            l[near1*N+(near2-1)] = l[near1*N+near2]+W[near1*N+(near2-1)]; 
            l1[near1*N+(near2-1)] = l[near1*N+near2]+W[near1*N+(near2-1)]; 
            t[near1*N+(near2-1)] = R;
        }
        // Left -> Right
        if( l[near1*N+near2]+W[near1*N+(near2+1)] < l[near1*N+(near2+1)] &&
                (near2+1) < N ){
            l[near1*N+(near2+1)] = l[near1*N+near2]+W[near1*N+(near2+1)]; 
            l1[near1*N+(near2+1)] = l[near1*N+near2]+W[near1*N+(near2+1)]; 
            t[near1*N+(near2+1)] = L;
        }

        l[near1*N+near2] = -1;
    } //for k to N^2-1

} // maze

void print_path(FILE *output, int t[], int N, int i, int j){
    if(i>=0 && j>=0){
        int parent = t[i*N+j];
        switch(parent){
            case U:
                print_path(output,t,N,i-1,j);
                break;
            case D:
                print_path(output,t,N,i+1,j);
                break;
            case L:
                print_path(output,t,N,i,j-1);
                break;
            case R:
                print_path(output,t,N,i,j+1);
                break;
        }
        printf("%d %d\n", i+1, j+1);    // 1~N으로 표현하기위해 +1
        fprintf(output, "%d %d\n", i+1, j+1);
    }
}


int main(){

    char input[50];
    printf("input file name? ");
    scanf("%s", input);

    FILE *fd, *output;
    fd = fopen(input, "r");
    output = fopen("output.txt", "a");

    // Read Data
    int N;
    fscanf(fd, "%d", &N);
    int W[N*N];
    char ch;
    int k=0;
    while( !feof(fd) ){
        ch = fgetc(fd);
        if( isdigit(ch) )
            W[k++] = (ch=='1') ? 0 : 1;     // Algorithm을 위해 흰방=0, 검은방=1 로 설정 
    }

    // Initialize arrays
    int l[N*N];
    int l1[N*N];   // 바꾸어야할 방의개수 저장 Array
    int t[N*N];
    memset(t, -1, sizeof(t));
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            l[i*N+j] = INFINITY;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            l1[i*N+j] = INFINITY;


    // Algorithm
    maze(W,l,l1,t,N);
    printf("%d\n", l1[N*N-1]);
    fprintf(output, "%d\n", l1[N*N-1]);
    print_path(output,t,N,N-1,N-1);


    fclose(fd);
    fclose(output);

    return 0;
}
