//Used Heap

struct Heap
{
    int capacity;
    int size;
    int type;
    int* arr;
};

struct Heap* CreateHeap( int intervalSize){
    if(intervalSize ==0)
        return NULL;
    
    struct Heap* heap = ( struct Heap* )calloc(1, sizeof( struct Heap ));
    if(heap == NULL)
        return NULL;
    
    heap->capacity = intervalSize;
    heap->size = 0;
    heap->arr = (int*)calloc(heap->capacity, sizeof(int));
    
    if(heap->arr == NULL)
        return NULL;
    
    return heap;
}

void DeleteHeap(struct Heap* h){
    if(h == NULL)
        return;
    if(h->arr)
        free(h->arr);
    free(h);
}
void  ResizeHeap(struct Heap* h, int intervalSize)
{
    if(h == NULL)
        return;
    h->capacity = intervalSize;
    h->arr = (int*)realloc(h->arr, h->capacity *sizeof(int));
    
}
void BuildHeap(struct Heap* h, int** intervals, int row , int col)
{
    if(h == NULL || intervals == NULL || row <0 || col < 0 )
        return;
    int intervalSize = row*col; 
    if(h->capacity < intervalSize)
        ResizeHeap(h, intervalSize);
    int k = 0; 
    for(int i=0; i < row; i++)
    for(int j = 0; j < col; j++)
        h->arr[k++] = intervals[i][j];
    
    h->size = intervalSize;
    for(int i= (intervalSize-1)/2;i>=0; i--)
        Percolate(h, i);
}
int leftChild(int i, int intervalSize)
{
      if((2*i+1) >=intervalSize)
        return -1;
    return (2*i+1);
}
int rightChild(int i, int intervalSize)
{ 
    if(2*i+2 >=intervalSize)
        return -1;
    return (2*i+2);
}
void Percolate(struct Heap* h, int i)
{
    if(h == NULL)    
        return;
    int left = leftChild(i, h->size);
    int right = rightChild(i, h->size);
    
    int min = 0;
    if(left !=-1 && h->arr[i] < h->arr[left])
        min = i;
    else 
        min = left;
    
     if(right !=-1 && h->arr[min] > h->arr[right])
        min = right;
    
    if(min !=i && min!=-1)
    {
     //Swap(&h->arr[min], &h->arr[i]);
        int tmp = h->arr[min];
        h->arr[min] = h->arr[i];
        h->arr[i] = tmp; 
        Percolate(h, min);
    }
}

void Insert(struct Heap* h, int index)
{
    int parent=(index-1)/2;
    
    if(parent>=0 && h->arr[index] < h->arr[parent]){
        int temp=h->arr[index];
        h->arr[index]=h->arr[parent];
        h->arr[parent]=temp;
        Insert(h,parent);
    }
}

int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k){
    
    
    if(matrix == NULL || matrixSize == 0 || matrixColSize == NULL)
        return INT_MIN; 
        
    if(k > (matrixSize* (* matrixColSize)  ) || k< 0 )
        return INT_MIN; 
    
    int numsSize = matrixSize* (*matrixColSize);
    
   struct Heap* h = CreateHeap( numsSize);
    
   BuildHeap(h, matrix,matrixSize, (* matrixColSize));
   //Deleting  numsSize-k will give first element which is kth largest in sorted list. 
   //After percolating 
    int tmp = 0;
    for(int i=0; i <k; i++)
    {
        tmp = h->arr[0];
        h->arr[0] = h->arr[h->size -1];
        h->size--;
        Percolate(h, 0);
    }
       

    DeleteHeap(h);
    
    
return tmp; 
}

