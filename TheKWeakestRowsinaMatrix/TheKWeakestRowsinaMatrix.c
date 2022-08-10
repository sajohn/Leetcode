

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct Pair{

    int value;
    int index;
} Pair; 

typedef struct Heap
{
    int capacity;
    int size;
    int index;
    struct Pair* arr;
}Heap;

 Heap* CreateHeap( int intervalSize){
    if(intervalSize ==0)
        return NULL;
    
 Heap* heap = ( Heap* )calloc(1, sizeof( Heap ));
    if(heap == NULL)
        return NULL;
    
    heap->capacity = intervalSize;
    heap->size = 0;
    heap->arr = (Pair*)calloc(heap->capacity, sizeof(Pair));
    
    if(heap->arr == NULL)
        return NULL;
    
    return heap;
}

void DeleteHeap(Heap* h){
    if(h == NULL)
        return;
    if(h->arr)
        free(h->arr);
    free(h);
}
void  ResizeHeap(Heap* h, int intervalSize)
{
    if(h == NULL)
        return;
    h->capacity = intervalSize;
    h->arr = (Pair*)realloc(h->arr, h->capacity *sizeof(Pair));
    
}
void BuildHeap( Heap* h, Pair* intervals, int intervalSize)
{
    if(h == NULL || intervals == NULL || intervalSize ==0 )
        return;
    if(h->capacity < intervalSize)
        ResizeHeap(h, intervalSize);
    
    for(int i=0; i < intervalSize; i++){
        h->arr[i].value = intervals[i].value;
        h->arr[i].index = intervals[i].index; 
    }
    
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


void Percolate( Heap* h, int i)
{
    if(h == NULL)    
        return;
    int left = leftChild(i, h->size);
    int right = rightChild(i, h->size);
    
    int min = -1;
    if(left !=-1 && left!= i && ((h->arr[i].value < h->arr[left].value  )  || 
                    (h->arr[i].value == h->arr[left].value  && h->arr[i].index < h->arr[left].index )))
        min = i;
    else 
        min = left;
    
     if(right !=-1 && min!= right &&  (( h->arr[right].value < h->arr[min].value  )  || 
                    (h->arr[min].value == h->arr[right].value  && h->arr[right].index < h->arr[min].index )))
        min = right;
    
    if(min !=i && min!=-1)
    {
     //Swap(&h->arr[min], &h->arr[i]);
        int tmp = h->arr[min].value;
        int idx =  h->arr[min].index;
        h->arr[min].value = h->arr[i].value;
        h->arr[min].index = h->arr[i].index; 
        h->arr[i].value = tmp; 
        h->arr[i].index = idx; 
        Percolate(h, min);
    }
}

void Insert(Heap* h, int index)
{
    int parent=(index-1)/2;
    
    if(parent>=0 && h->arr[index].value < h->arr[parent].value){
        int temp = h->arr[index].value;
        int idx =  h->arr[index].index;
        h->arr[index].value=h->arr[parent].value;
        h->arr[index].index=h->arr[parent].index;
        h->arr[parent].value=temp;
        h->arr[parent].index=idx;
        Insert(h,parent);
    }
}



int searchInRow(int* mat, int size){
    if(mat == NULL)
        return 0; 
    
    int start = 0, end = size, mid =0;
    
    while(start < end){
        mid = start + (end - start)/2; 
        
        if(mat[mid] == 1)
            start = mid+1;
        else if(mat[mid] == 0)
            end = mid; 
    
    }
    return end; 
}
int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize){
    
    if(mat == NULL || matSize == 0 || matColSize == NULL){
        *returnSize = 0; 
        return NULL;
    }
  
  int* ret =  (int*)calloc(k, sizeof(int));
        if(ret == NULL)
        return NULL; 
   
  Pair tmp[matSize];
  bzero(tmp, sizeof(tmp));
    
    for(int i =0; i < matSize; i++){
       tmp[i].value =  searchInRow(mat[i], *matColSize);
       tmp[i].index =  i;
    }
    
   Heap* h = CreateHeap(matSize);
    
   BuildHeap(h, &tmp,matSize);
   
    for(int i=0; i <k; i++)
    {
        ret[i] =  h->arr[0].index;
        h->arr[0].value = h->arr[h->size -1].value;
        h->arr[0].index = h->arr[h->size -1].index;
        h->size--;
        Percolate(h, 0);
    }
       
    DeleteHeap(h);
    *returnSize = k; 
    return ret;

    
}
