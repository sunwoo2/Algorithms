#include <stdio.h>
#include <stdbool.h>

#define N 8

int W[N][N] = { {0,1,0,0,1,0,0,0},
                {1,0,1,0,1,1,0,0},
                {1,1,0,1,0,0,1,0},
                {0,0,1,0,0,0,0,1},
                {1,1,0,0,0,1,0,0},
                {0,1,0,0,1,0,1,0},
                {0,0,1,0,0,1,0,1},
                {0,0,0,1,0,0,1,0} };
int Vindex[N];

bool promising(int i){

    if( (i==N-1) && (W[Vindex[N-1]][Vindex[0]] == 0) )
        return false;
    else if(i>0 && (W[Vindex[i-1]][Vindex[i]] == 0))
        return false;
    else{
        int j=1;
        while(j<i){
            if(Vindex[i]==Vindex[j])
                return false;
            j++;
        }
        return true;
    }
        
}

void hamilton(int i){

    if(promising(i)){
        if(i==N-1){
            for(int k=0; k<N; k++)
                printf("%2d", Vindex[k]+1);     // +1 For representation 1~N
            printf("\n");
        }else{
            for(int j=1; j<N; j++){
                Vindex[i+1] = j;
                hamilton(i+1);
            }
        }
    }

}

int main(){

    Vindex[0] = 0;
    hamilton(0);

    return 0;
}
