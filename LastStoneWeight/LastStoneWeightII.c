//Used Heap
// Used Sorting




typedef struct Heap
{
    int capacity;
    int size;
    int type;
    int* arr;
}Heap;

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
    
    int max = 0;
    if(left !=-1 && h->arr[i] > h->arr[left])
        max = i;
    else 
        max = left;
    
     if(right !=-1 && h->arr[max] < h->arr[right])
        max = right;
    
    if(max !=i && max!=-1)
    {
     //Swap(&h->arr[min], &h->arr[i]);
        int tmp = h->arr[max];
        h->arr[max] = h->arr[i];
        h->arr[i] = tmp; 
        Percolate(h, max);
    }
}

void Insert(struct Heap* h, int index)
{
    int parent=(index-1)/2;
    
    if(parent>=0 && h->arr[index] > h->arr[parent]){
        int temp=h->arr[index];
        h->arr[index]=h->arr[parent];
        h->arr[parent]=temp;
        Insert(h,parent);
    }
}



int lastStoneWeight(int* stones, int stonesSize){

    
    if(stones == NULL || stonesSize == 0)
        return 0; 
    
   Heap* h =  CreateHeap( 0, stonesSize);
    
   BuildHeap(h, stones, stonesSize);

    int first = 0, second = 0; 
    
 while(h->size > 0){
 
       first = h->arr[0];
       h->arr[0] = h->arr[h->size -1];
       h->size--;
       Percolate(h, 0);
     
     if(h->size > 0)
      second = h->arr[0];
     else
         break;
     
      if(first == second){
            h->arr[0] = h->arr[h->size -1];
       h->size--;
       Percolate(h, 0); 
          
          first = 0; 
          second = 0;
        } else {
           h->arr[0] = h->arr[h->size -1];
           h->size--;
           Percolate(h, 0); 

              h->arr[h->size] = first - second; 
              h->size++; 
              Insert(h,h->size-1);
              first = 0; 
              second = 0;
            
        }
    }
    
    
   return first;  

}

