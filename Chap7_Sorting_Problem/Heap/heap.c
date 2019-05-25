#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Min Heap

typedef struct{
   int* array;      // Heap array 인덱스는 1부터!!!(0은 걍 비워두자)
   int heapsize;
   int max_size;
} HEAP;

HEAP* create_heap(int max);
void siftdown(HEAP* H, int i);        // O(logn)
void makeheap(HEAP* H, int n);        // O(nlogn). theta(n)
int root(HEAP* H);                    // delete root(min). O(logn)
void removekeys(HEAP* H, int n);      // Sorting. O(nlogn). In-place
void heapsort(HEAP* H, int n);        // O(nlogn). In-place
void insert(HEAP* H, int data);

int main(){
    //srand((time)NULL);
    //int random = rand()%20+1;   //1~20
    int size = 10;
    int S[10] = {4,9,1,2,7,8,3,10,18,6};

    HEAP* h1 = create_heap(size);

    for(int i=1; i<=size; i++)
        h1->array[i] = S[i-1];
    h1->heapsize = 10;
    for(int i=0; i<=h1->heapsize; i++)
        printf("%d ", h1->array[i]);
    printf("\n");

    //makeheap(h1, 10);
    heapsort(h1, 10);
    for(int i=1; i<=size; i++)
        printf("%d ", h1->array[i]);
    printf("\n");

    return 0;
}

HEAP* create_heap(int max){
    HEAP* H = (HEAP*)malloc(sizeof(HEAP));
    if(!H){
        perror("Failed to create HEAP!"); 
        exit(1);
    }
    H->array = (int*)calloc((max+1), sizeof(int));  // 0은 안쓰고 1~N이기 때문에 max+1 !!!
    if(!(H->array)){
        perror("Failed to calloc to H->array!"); 
        exit(1);
    }
    H->heapsize = 0;
    H->max_size = max;
    return H;
}

void siftdown(HEAP* H, int i){
    int siftkey = H->array[i];
    //printf("siftkey = %d\n", siftkey);
    int parent = i;
    int smallerchild;
    bool found = false;

    while( (2*parent <= H->heapsize) && (!found) ){
        if( (2*parent < H->heapsize) && (H->array[2*parent+1] < H->array[2*parent]) )
            smallerchild = 2*parent+1;
        else
            smallerchild = 2*parent;
        //printf("smallerchild=%d, array[smallerchild]=%d\n", smallerchild, H->array[smallerchild]);

        if(siftkey > H->array[smallerchild]){
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

int root(HEAP* H){
    int keyout = H->array[1];   // root
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

void insert(HEAP* H, int data){
    if(H->heapsize == H->max_size){
        H->array = (int*)realloc(H->array, 2*(H->max_size)*sizeof(int));  // 배열 2배로 늘려줌
        if(!(H->array)){
            perror("Failed to realloc!"); 
            exit(1);
        }
        H->max_size = 2*(H->max_size);
    }

    H->heapsize++;
    int parent = (H->heapsize)/2;
    int i = H->heapsize;
    int key = data;
    while( (parent>0) && (H->array[parent] > key) ){
        H->array[i] = H->array[parent]; 
        i = parent;
        parent = i/2;
    }
    H->array[i] = key;
}
