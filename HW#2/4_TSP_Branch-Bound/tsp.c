#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// For VS
#pragma warning(disable: 4996)  // scanf, fsacnf
#pragma warning(disable: 4819)  // 한글주석 

#define Inf 9000

typedef struct{
    int level;
    int* path;
    int index;  // 비어있는 최소 인덱스
    int bound;
}NODE;

typedef struct{
    NODE* array;      // 1부터(0은 걍 비워두자), 단지 NODE가 값인 배열일 뿐!
    int heapsize;
    int max_size;
}HEAP;     // Min heap

HEAP* create_heap(int max);
void siftdown(HEAP* H, int i);        // O(logn)
void makeheap(HEAP* H, int n);        // O(nlogn). theta(n)
NODE root(HEAP* H);                    // delete root(min). O(logn)
void removekeys(HEAP* H, int n);      // Sorting. O(nlogn). In-place
void heapsort(HEAP* H, int n);        // O(nlogn). In-place
void insert(HEAP* H, NODE node); // data = node.bound

int length(int W[], int n, NODE node){
    int length = 0;
    int i;
    int j;
    for(int k=0; k<(node.index-1); k++){
        i = node.path[k];
        j = node.path[k+1];
        length += W[i*n+j];
    }
    return length;
}

int bound(int W[], NODE node){
// bound function 짜기!!! 연습장에 한개씩 적어보면서 규칙 찾고 알고리즘 짜고 그다음 코딩하자!
}

void travel2(int W[], int n, int opttour[], int* minlength){
    int tmp=0;
    int leaves = 1;
    for(int i=1; i<n; i++)  // (n-1)! leaves
            leaves *= i;
    HEAP* heap = create_heap(leaves);
    NODE u,v;
    v.level = 0;
    v.path = (int*)calloc(n, sizeof(int));
    v.path[0] = 1;
    v.index = 1;
    v.bound = bound(W,v);
    u.path = (int*)calloc(n, sizeof(int));
    insert(heap, v);

    while(heap->heapsize > 0){
        v = root(heap);
        if(v.bound < minlength){
            u.level = v.level+1;
            memcpy(u.path, v.path, sizeof(int)*n);    // copy 
            u.index = v.index;
            if(u.level==n-2){
                for(int i=0; i<n-2; i++)        // add last one node
                    tmp += u.path[i];
                u.path[n-2] = tmp;
                tmp = 0;
                for(int i=1; i<=n; i++)
                    tmp += i;
                u.path[n-2] -= tmp;
                tmp = length(W,n,u);
                if(tmp < minlength){
                    minlength = tmp;
                    memcpy(opttour, u.path, sizeof(int)*n);
                }
            }else{
                for(int i=2; i<=n; i++){
                    int k=0;
                    while( (i!=v.path[k]) && (k<u.index) )
                        k++;
                    if(k==u.index){
                        u.path[u.index++] = i;    
                        u.bound = bound(W,u);
                        if(u.bound < minlength)
                            insert(heap, u);
                    }
                }
            }
        }
    }

    free(heap);
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
    fscanf(input, "%d", &N);

    // Initialize arrays
    int* W = (int*)malloc(N*N*sizeof(int)); 
    for(int i=0; i<N*N; i++)
        fscanf(input, "%d", &W[i]);
    int* opttour = (int*)malloc(N*sizeof(int));
    int minlength = Inf;
    /*
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            printf("%3d", W[i*N+j]);
        printf("\n");
    }
    */


    // Algorithm
    //travel2(W,N,opttour,&minlength);




    /* test for NODE&HEAP
    NODE n1,n2,n3,n4;
    n1.bound = 10; n1.level=1; 
    n1.path = (int*)calloc(4, sizeof(int));
    n1.path[0] = 1;
    n2.bound = 9; n2.level=2;
    n2.path = (int*)calloc(4, sizeof(int));
    n2.path[1] = 2;
    n3.bound = 8; n3.level=3;
    n3.path = (int*)calloc(4, sizeof(int));
    n3.path[2] = 3;
    n4.bound = 4; n4.level=4;
    n4.path = (int*)calloc(4, sizeof(int));
    n4.path[3] = 4;
    HEAP* h1 = create_heap(4);
    insert(h1, n1);
    insert(h1, n2);
    insert(h1, n3);
    insert(h1, n4);
    NODE tmp;
    memcpy(n1.path,n2.path,sizeof(int)*4);    // copy 
    for(int i=0; i<4; i++){
        tmp = root(h1);
        printf("tmp.bound = %d, tmp.level = %d\n", tmp.bound, tmp.level);
        for(int j=0; j<4; j++)
            printf("%d ", tmp.path[j]);
        printf("\n");
    }
    */ 
     
    free(W);
    fclose(input);
    fclose(output);

    return 0;
}

HEAP* create_heap(int max){
    HEAP* H = (HEAP*)malloc(sizeof(HEAP));
    if(!H){
        perror("Failed to create HEAP!"); 
        exit(1);
    }
    H->array = (NODE*)calloc((max+1), sizeof(NODE));  // 0은 안쓰고 1~N이기 때문에 max+1 !!!
    if(!(H->array)){
        perror("Failed to calloc to H->array!"); 
        exit(1);
    }
    H->heapsize = 0;
    H->max_size = max;
    return H;
}

void siftdown(HEAP* H, int i){
    NODE siftkey = (H->array[i]);
    int parent = i;
    int smallerchild;
    bool found = false;

    while( (2*parent <= H->heapsize) && (!found) ){
        if( (2*parent < H->heapsize) && (H->array[2*parent+1].bound < H->array[2*parent].bound) )
            smallerchild = 2*parent+1;
        else
            smallerchild = 2*parent;

        if(siftkey.bound > H->array[smallerchild].bound){
            H->array[parent] = H->array[smallerchild]; 
            parent = smallerchild;
        }else
            found = true;
    }
    H->array[parent] = siftkey;
}

void makeheap(HEAP* H, int n){
    H->heapsize = n;
    for(int i=n/2; i>=1; i--)   // Bottom->Up
        siftdown(H, i);
}

NODE root(HEAP* H){
    NODE keyout = H->array[1];   // root
    H->array[1] = H->array[H->heapsize];
    H->heapsize--; 
    siftdown(H, 1);
    return keyout;
}

void removekeys(HEAP* H, int n){    
    //root함수 때문에 heapsize = 0됌. 근데 지금은 In-place 로 짜놓은거라 H->array에 값 들어 있음!
    // Min heap 이라 역sorting 되어 있음!
    for(int i=n; i>0; i--)
        H->array[i] = root(H);
}

void heapsort(HEAP* H, int n){
    makeheap(H, n);
    removekeys(H, n);
}

void insert(HEAP* H, NODE node){
    /*
    if(H->heapsize == H->max_size){
        H->array = (int*)realloc(H->array, 2*(H->max_size)*sizeof(int));  // 배열 2배로 늘려줌
        if(!(H->array)){
            perror("Failed to realloc!"); 
            exit(1);
        }
        H->max_size = 2*(H->max_size);
    }
    */

    H->heapsize++;
    int parent = (H->heapsize)/2;
    int i = H->heapsize;
    NODE key = node;
    while( (parent>0) && (H->array[parent].bound > key.bound) ){
        H->array[i] = H->array[parent]; 
        i = parent;
        parent = i/2;
    }
    H->array[i] = key;
}
