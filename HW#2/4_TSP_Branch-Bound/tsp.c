#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// For VS
#pragma warning(disable: 4996)  // scanf, fsacnf
#pragma warning(disable: 4819)  // 한글주석 

#define Inf 9000
// input_*.txt test할려면 90000000으로 바꾸고 돌리자

typedef struct{     // VS에서 변수 순서와 밑에 띄어쓰기 저렇게 안해주면 error뜸.
	int bound;
    int level;
    int* path;  // 1~N
    int index;  // 비어있는 최소 인덱스
	
}NODE;

typedef struct{
    NODE* array;      // 1부터(0은 걍 비워두자), 단지 NODE가 값인 배열일 뿐!
    int heapsize;
    int max_size;
}HEAP;     // Min heap

NODE* create_node(int n);
HEAP* create_heap(int max);
void siftdown(HEAP* H, int i);        // O(logn)
void makeheap(HEAP* H, int n);        // O(nlogn). theta(n)
NODE root(HEAP* H);                    // delete root(min). O(logn)
void removekeys(HEAP* H, int n);      // Sorting. O(nlogn). In-place
void heapsort(HEAP* H, int n);        // O(nlogn). In-place
void insert(HEAP* H, int n, NODE* node); // data = node.bound

int length(int W[], int n, NODE* node1){    
    // 모든경로 찾았을때 니깐 마지막에 1로 가는 엣지 까지 더해준다!
    NODE node = *node1;   
    int length = 0;
    int i;
    int j;
    for(int k=0; k<(node.index-1); k++){
        i = node.path[k]-1;
        j = node.path[k+1]-1;
        length += W[i*n+j];
    }
    length += W[(node.path[n-1]-1)*n+0];
    return length;
}

int bound(int W[], int n, NODE* node1){
    NODE node = *node1;     // node.path 값 읽기 위해(node1을 포인터로 받음)
    int* w = (int*)malloc(n*n*sizeof(int));     // 배열값 copy 하기 위해
    if(!w){
        perror("bound function에서 w복사 malloc 실패!");
        exit(1);
    }
    memcpy(w, W, sizeof(int)*n*n);
    int bound=0;
    int min;
    int i,j;
    
    // Set Matrix by path and bound
    for(int k=0; k<(node.index-1); k++){
        i = node.path[k]-1;     // 배열 인덱스 때문에 -1
        j = node.path[k+1]-1;
        bound += w[i*n+j];
        for(int m=0; m<n; m++)
            w[i*n+m] = 0;
        for(int m=0; m<n; m++)
            w[m*n+j] = 0;
        w[j*n+0] = 0;
    }

    // Choose min at each row  
    for(int k=0; k<n; k++){
        min=Inf;
        for(int m=0; m<n; m++)
            if( (min > w[k*n+m]) && (w[k*n+m] > 0) )
                min = w[k*n+m];
        if(min!=Inf)
            bound += min;
    }

    free(w);
    return bound;
}

void travel2(int W[], int n, int opttour[], int* minlength){
    // Set heap-maxsize = n^5, after try to realloc
    int leaves = 1;
    for(int i=0; i<5; i++)  
            leaves *= n;
    HEAP* heap = create_heap(leaves);
    if(!heap){
        perror("Creating heap Fail!");
        exit(1);
    }
    NODE* u = create_node(n);
    if(!u){
        perror("Creating node u Fail!");
        exit(1);
    }
    NODE* v = create_node(n);
    if(!v){
        perror("Creating node v Fail!");
        exit(1);
    }
    v->level = 0;
    v->path[0] = 1;
    v->index = 1;
    v->bound = bound(W,n,v);
    insert(heap, n, v);

    while(heap->heapsize > 0){
        *v = root(heap);
        if(v->bound < *minlength){
            if(v->level==n-2){
                int tmp=0;
                for(int i=1; i<=n; i++)     // add last one node
                    tmp += i;
                v->path[n-1] = tmp;
                tmp = 0;
                for(int i=0; i<n-1; i++)        
                    tmp += v->path[i];
                v->path[n-1] -= tmp;
                v->index++;
                tmp = length(W,n,v);
                if(tmp < *minlength){
                    *minlength = tmp;
                    memcpy(opttour, v->path, sizeof(int)*n);
                }
            }else{
                for(int i=2; i<=n; i++){
                    int exist = 0;
                    for(int k=1; k<v->index; k++)
                        if(i==v->path[k])
                            exist = 1;
                    if(!exist){
                        NODE* temp = create_node(n);
                        if(!temp){
                            perror("Creating node temp Fail!");
                            exit(1);
                        }
                        temp->index = v->index;
                        temp->level = v->level+1;
                        memcpy(temp->path, v->path, sizeof(int)*n);   
                        temp->path[temp->index++] = i;    
                        temp->bound = bound(W,n,temp);
                        if(temp->bound < *minlength)
                            insert(heap, n, temp);
                        free(temp);
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


    // Algorithm
    travel2(W,N,opttour,&minlength);
    printf("opttour : ");
    for(int j=0; j<N; j++)
        printf("%d ", opttour[j]);
    printf("\n");
    printf("minlength = %d\n", minlength);
    for(int i=0; i<N; i++)
        fprintf(output, "%d\n", opttour[i]);
    fprintf(output, "%d", 1);

     
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

    if(H->heapsize == 0){
        perror("Failed to remove heap-root because heapsize is zero!");
        exit(1);
    }

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

void insert(HEAP* H, int n, NODE* data){
    if(H->heapsize == H->max_size){     // stack 메모리 꽉 차면 다시 n^5만큼 더 늘려주기
        H->array = (NODE*)realloc(H->array, sizeof(NODE)*(H->max_size+n*n*n*n*n));  
        if(!(H->array)){
            perror("Failed to calloc to H->array!"); 
            exit(1);
        }
        H->max_size += n*n*n*n*n;
    }
    if(H->heapsize == H->max_size){
        perror("heapsize realloc 했는데?!");
        exit(1);
    }

    H->heapsize++;
    int parent = (H->heapsize)/2;
    int i = H->heapsize;
    NODE* new = create_node(n);
    memcpy(new, data, sizeof(NODE));

    while( (parent>0) && (H->array[parent].bound > new->bound) ){
        H->array[i] = H->array[parent]; 
        i = parent;
        parent = i/2;
    }
    H->array[i] = *new;     // H->array[] 는 NODE임. pointer 아님!
}

NODE* create_node(int n){
    NODE* new = (NODE*)malloc(sizeof(NODE));
    if(!new){
        perror("Failed to create NODE!");
        exit(1);
    }
    new->path = (int*)calloc(n, sizeof(int));
    new->level = 0;
    new->bound = 0;
    new->index = 0;

    return new;
}
