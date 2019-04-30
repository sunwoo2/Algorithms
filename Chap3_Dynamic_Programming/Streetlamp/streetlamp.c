#include <stdio.h>
#include <string.h>

#define N 6

int EE[N][N][2];    
int PP[N][N][2];    
int W[N] = {2,10,18,19,15,19};
//int W[N] = {52,10,18,99,15,9};    // TEST
int D[N] = {3,11,12,13,15,17};

int min(int n, int i, int j, int f){
    int W_off = 0;
    int WT = 0;
    int E11, E12, E21, E22;
    for(int k=0; k<n; k++)
        WT += W[k];

    if(f==0){
        for(int k=i+1; k<=j; k++)
            W_off += W[k];
        E11 = EE[i+1][j][0] + (D[i+1]-D[i])*(WT-W_off); 
        E12 = EE[i+1][j][1] + (D[j]-D[i])*(WT-W_off); 
        if(EE[i+1][j][0] == -1){
            PP[i][j][0] = j; 
            return E12;
        }else if(EE[i+1][j][1] == -1){
            PP[i][j][0] = i+1; 
            return E11;
        }else
            if(E11<E12){
                PP[i][j][0] = i+1; 
                return E11;
            }else{
                PP[i][j][0] = j; 
                return E12;
            }
    }else{
        for(int k=i; k<j; k++)
            W_off += W[k];
        E21 = EE[i][j-1][0] + (D[j]-D[i])*(WT-W_off);
        E22 = EE[i][j-1][1] + (D[j]-D[j-1])*(WT-W_off);
        if(EE[i][j-1][0] == -1){
            PP[i][j][1] = j-1; 
            return E22;
        }else if(EE[i][j-1][1] == -1){
            PP[i][j][1] = i; 
            return E21;
        }else
            if(E21<E22){
                PP[i][j][1] = i; 
                return E21;
            }else{
                PP[i][j][1] = j-1; 
                return E22;
            }
    }
}

void streetlamp(int n, int m){
    int i_start;
    int i_last;
    int j;
    int M = m-1;

    for(int i=0; i<n; i++){
        EE[M][i][0] = -1;
        EE[i][M][1] = -1;
    }
    EE[M][M][0] = 0;
    EE[M][M][1] = 0;

    for(int diagonal=1; diagonal<n; diagonal++){
        i_start = M-diagonal > 0 ? M-diagonal : 0;
        i_last = n-1-diagonal < M ? n-1-diagonal : M;
        for(int i=i_start; i<=i_last; i++){
            j = i+diagonal;
            if(j==M){
                EE[i][j][0] = min(n,i,j,0);
            }else if(i==M){
                EE[i][j][1] = min(n,i,j,1);
            }else{
                EE[i][j][0] = min(n,i,j,0);
                EE[i][j][1] = min(n,i,j,1);
            }
        }
    }
}

void print_path(int i, int j, int f){
    // 가로등 1~N으로 나타내기위해 출력할때 +1  
    int pre_lamp = PP[i][j][f];
    if(pre_lamp != -1){
        if(f==0){
            if(pre_lamp == i+1){
                print_path(i+1, j, 0);
                printf("%2d", pre_lamp+1);
            }else{
                print_path(i+1, j, 1);
                printf("%2d", pre_lamp+1);
            }
        }else{
            if(pre_lamp == i){
                print_path(i, j-1, 0);
                printf("%2d", pre_lamp+1);
            }else{
                print_path(i, j-1, 1);
                printf("%2d", pre_lamp+1);
            }
        }
    }
}

int main(){
    memset(EE, '\0', sizeof(EE));
    memset(PP, -1, sizeof(PP));

    streetlamp(N,5);

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            printf("%4d", EE[i][j][0]);
        printf("\n");
    }
    printf("\n");
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            printf("%4d", EE[i][j][1]);
        printf("\n");
    }
    printf("\n");

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            printf("%4d", PP[i][j][0]);
        printf("\n");
    }
    printf("\n");
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            printf("%4d", PP[i][j][1]);
        printf("\n");
    }
    printf("\n");

    if(EE[0][N-1][0] < EE[0][N-1][1]){
        print_path(0,N-1,0);
        printf("%2d\n", 1);
    }else{
        print_path(0,N-1,1);
        printf("%2d\n", N);
    }

    return 0;
}
