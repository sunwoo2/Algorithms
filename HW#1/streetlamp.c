#include <stdio.h>
#include <string.h>

int min(int EE[], int PP[], int W[], int D[], int n, int i, int j, int f){
    int W_off = 0;
    int WT = 0;
    int E11, E12, E21, E22;
    for(int k=0; k<n; k++)
        WT += W[k];

    if(f==0){
        for(int k=i+1; k<=j; k++)
            W_off += W[k];
        E11 = EE[0*n*n+(i+1)*n+j] + (D[i+1]-D[i])*(WT-W_off); 
        E12 = EE[1*n*n+(i+1)*n+j] + (D[j]-D[i])*(WT-W_off); 
        if(EE[0*n*n+(i+1)*n+j] == -1){
            PP[0*n*n+i*n+j] = j;
            return E12;
        }else if(EE[1*n*n+(i+1)*n+j] == -1){
            PP[0*n*n+i*n+j] = i+1;
            return E11;
        }else
            if(E11<E12){
                PP[0*n*n+i*n+j] = i+1;
                return E11;
            }else{
                PP[0*n*n+i*n+j] = j;
                return E12;
            }
    }else{
        for(int k=i; k<j; k++)
            W_off += W[k];
        E21 = EE[0*n*n+i*n+(j-1)] + (D[j]-D[i])*(WT-W_off); 
        E22 = EE[1*n*n+i*n+(j-1)] + (D[j]-D[j-1])*(WT-W_off); 
        if(EE[0*n*n+i*n+(j-1)] == -1){
            PP[1*n*n+i*n+j] = j-1;
            return E22;
        }else if(EE[1*n*n+i*n+(j-1)] == -1){
            PP[1*n*n+i*n+j] = i;
            return E21;
        }else
            if(E21<E22){
                PP[1*n*n+i*n+j] = i;
                return E21;
            }else{
                PP[1*n*n+i*n+j] = j-1;
                return E22;
            }
    }
}

void streetlamp(int EE[], int PP[], int W[], int D[], int n, int m){
    int i_start;
    int i_last;
    int j;
    int M = m-1;

    for(int i=0; i<n; i++){
        EE[M*n+i] = -1;
        EE[1*n*n+i*n+M] = -1;
    }
    EE[0*n*n+M*n+M] = 0;
    EE[1*n*n+M*n+M] = 0;

    for(int diagonal=1; diagonal<n; diagonal++){
        i_start = M-diagonal > 0 ? M-diagonal : 0;
        i_last = n-1-diagonal < M ? n-1-diagonal : M;
        for(int i=i_start; i<=i_last; i++){
            j = i+diagonal;
            if(j==M){
                EE[0*n*n+i*n+j] = min(EE,PP,W,D,n,i,j,0);
            }else if(i==M){
                EE[1*n*n+i*n+j] = min(EE,PP,W,D,n,i,j,1);
            }else{
                EE[0*n*n+i*n+j] = min(EE,PP,W,D,n,i,j,0);
                EE[1*n*n+i*n+j] = min(EE,PP,W,D,n,i,j,1);
            }
        }
    }
}

void print_path(int PP[], int n, int i, int j, int f){
    // 가로등을 1~N으로 표현하기위해 출력할때 +1
    int pre_lamp = PP[f*n*n+i*n+j];
    if(pre_lamp != -1){
        if(f==0){
            if(pre_lamp == i+1){
                print_path(PP,n,i+1, j, 0);
                printf("%d\n", pre_lamp+1);
            }else{
                print_path(PP,n,i+1, j, 1);
                printf("%d\n", pre_lamp+1);
            }
        }else{
            if(pre_lamp == i){
                print_path(PP,n,i, j-1, 0);
                printf("%d\n", pre_lamp+1);
            }else{
                print_path(PP,n,i, j-1, 1);
                printf("%d\n", pre_lamp+1);
            }
        }
    }
}

void print_result(int EE[], int PP[], int N){

    if(EE[0*N*N+0*N+(N-1)] < EE[1*N*N+0*N+(N-1)]){
        printf("%d\n", EE[0*N*N+0*N+(N-1)]);
        print_path(PP,N,0,N-1,0);
        printf("%d\n", 1);
    }else{
        printf("%d\n", EE[1*N*N+0*N+(N-1)]);
        print_path(PP,N,0,N-1,1);
        printf("%d\n", N);
    }

}

int main(){

    char input[50];
    printf("input file name? ");
    scanf("%s", input);

    FILE *fd;
    fd = fopen(input, "r");

    // Read Data
    int N;
    fscanf(fd, "%d", &N);
    int location;
    fscanf(fd, "%d", &location);
    int W[N]; 
    int D[N];
    for(int i=0; i<N; i++){
        fscanf(fd, "%d", &D[i]);
        fscanf(fd, "%d", &W[i]);
    }

    // Initialize arrays
    int EE[2*N*N];
    int PP[2*N*N];
    memset(EE, '\0', sizeof(EE));
    memset(PP, -1, sizeof(PP));


    streetlamp(EE,PP,W,D,N,5);

    print_result(EE,PP,N);


    fclose(fd);

    return 0;
}
