//Used Heap
// Used Sorting


// int cmpfunc(void* a, void* b)
// {
//     return (*(int*)a) - (*(int*)b);
// }

// int findKthLargest(int* nums, int numsSize, int k)
// {
  
//     if(nums == NULL || numsSize ==0 || numsSize <k)
//         return -1;
    
    
//     qsort(nums, numsSize, sizeof(int), cmpfunc);
    
//     return nums[numsSize-k];
// }


struct Heap
{
    int capacity;
    int size;
    int type;
    int* arr;
};

struct Heap* CreateHeap( int type, int intervalSize){
    if(intervalSize ==0)
        return NULL;
    
    struct Heap* heap = ( struct Heap* )calloc(1, sizeof( struct Heap ));
    if(heap == NULL)
        return NULL;
    
    heap->capacity = intervalSize;
    heap->type = type;
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
void BuildHeap(struct Heap* h, int* intervals, int intervalSize)
{
    if(h == NULL || intervals == NULL || intervalSize ==0 )
        return;
    if(h->capacity < intervalSize)
        ResizeHeap(h, intervalSize);
    
    for(int i=0; i < intervalSize; i++)
        h->arr[i] = intervals[i];
    
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

int findKthLargest(int* nums, int numsSize, int k)
{
     if(nums == NULL || numsSize ==0 || numsSize <k)
        return -1;

   struct Heap* h = CreateHeap(0, numsSize);
    
   BuildHeap(h, nums,numsSize);
    
    for(int i=0; i < numsSize-k; i++)
    {
        int tmp = h->arr[0];
        h->arr[0] = h->arr[h->size -1];
        h->size--;
        Percolate(h, 0);
    }
       
  int ret = h->arr[0];
    DeleteHeap(h);
return ret;
}
