#include <stdio.h>
#include <string.h>

int EE[6][6][2];    
int PP[6][6][2];    // streetlamp : 1~6
int W[6] = {2,10,18,19,15,19};
int D[6] = {3,11,12,13,15,17};

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
            PP[i][j][0] = j+1; 
            return E12;
        }else if(EE[i+1][j][1] == -1){
            PP[i][j][0] = i+1+1; 
            return E11;
        }else
            if(E11<E12){
                PP[i][j][0] = i+1+1; 
                return E11;
            }else{
                PP[i][j][0] = j+1; 
                return E12;
            }
    }else{
        for(int k=i; k<j; k++)
            W_off += W[k];
        E21 = EE[i][j-1][0] + (D[j]-D[i])*(WT-W_off);
        E22 = EE[i][j-1][1] + (D[j]-D[j-1])*(WT-W_off);
        if(EE[i][j-1][0] == -1){
            PP[i][j][1] = j-1+1; 
            return E22;
        }else if(EE[i][j-1][1] == -1){
            PP[i][j][1] = i+1; 
            return E21;
        }else
            if(E21<E22){
                PP[i][j][1] = i+1; 
                return E21;
            }else{
                PP[i][j][1] = j-1+1; 
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

void print_path(int i, int j){
    int pre_lamp;
    if(EE[i][j][0] < EE[i][j][1])
        pre_lamp = PP[i][j][0];
    else
        pre_lamp = PP[i][j][1];
    
    if(pre_lamp > 0){
        printf("%d ", pre_lamp);
        //print_path  ////////////////
    }
}

int main(){
    memset(EE, '\0', sizeof(EE));
    memset(PP, '\0', sizeof(PP));

    streetlamp(6,5);

    for(int i=0; i<6; i++){
        for(int j=0; j<6; j++)
            printf("%5d", EE[i][j][0]);
        printf("\n");
    }
    printf("\n");
    for(int i=0; i<6; i++){
        for(int j=0; j<6; j++)
            printf("%5d", EE[i][j][1]);
        printf("\n");
    }
    printf("\n");

    for(int i=0; i<6; i++){
        for(int j=0; j<6; j++)
            printf("%4d", PP[i][j][0]);
        printf("\n");
    }
    printf("\n");
    for(int i=0; i<6; i++){
        for(int j=0; j<6; j++)
            printf("%4d", PP[i][j][1]);
        printf("\n");
    }
    printf("\n");

    return 0;
}
