

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

//Create min heap and put the distance on the heap 
//Pop K elements from heap

//Here minimum of end (min_heap) is needed
 struct Points 
 {
     double dist;
     int idx;
 };
struct Heap
{
    int capacity;
    int size;
    int type;
    struct Points* arr;
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
    heap->arr = (struct Points*)calloc(heap->capacity, sizeof( struct Points));
    
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
    h->arr = (struct Points*)realloc(h->arr, h->capacity*sizeof(struct Points));
    
}
void BuildHeap(struct Heap* h, int** points, int intervalSize)
{
    if(h == NULL || points == NULL || intervalSize ==0 )
        return;
    if(h->capacity < intervalSize)
        ResizeHeap(h, intervalSize);
    
    for(int i=0; i < intervalSize; i++){
        h->arr[i].dist = sqrt((double) (points[i][0]*points[i][0] + points[i][1]*points[i][1]));
        h->arr[i].idx = i;}
    
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
    if(left !=-1 && h->arr[i].dist < h->arr[left].dist)
        min = i;
    else 
        min = left;
    
     if(right !=-1 && h->arr[min].dist > h->arr[right].dist)
        min = right;
    
    if(min !=i && min!=-1)
    {
     //Swap(&h->arr[min], &h->arr[i]);
        struct Points tmp = {0};
        memcpy(&tmp, &(h->arr[min]), sizeof(struct Points));
        memcpy( &(h->arr[min]), &(h->arr[i]), sizeof(struct Points));
        memcpy( &(h->arr[i]), &tmp, sizeof(struct Points));
     
        Percolate(h, min);
    }
}
void InsertHeap(struct Heap* h, double data, int idx)
{
    if(h == NULL)
        return;
    if(h->size == h->capacity)
        ResizeHeap(h, h->capacity*2);
    
    int i = h->size++;
    while(i>0 && data < h->arr[(i-1)/2].dist)
    {
        memcpy(&(h->arr[i]), &(h->arr[(i-1)/2]), sizeof(struct Points));
          i = (i-1)/2;
    }
    
    h->arr[i].dist = data;
    h->arr[i].idx = idx;
}

int GetMinHeap(struct Heap* h)
{
    if(h!= NULL)
        return h->arr[0].dist;    
   return -1;
}

struct Points* DeleteMinHeap(struct Heap* h)
{
     if(h== NULL)
         return NULL;
     struct Points* tmp = calloc(1,  sizeof( struct Points));
    if(tmp == NULL)
        return NULL;
    
     memcpy(tmp, &(h->arr[0]), sizeof( struct Points));
     memcpy(&(h->arr[0]) , &(h->arr[h->size-1]), sizeof( struct Points));
    
    h->size--;
    Percolate(h, 0);
    return tmp;
}



int** kClosest(int** points, int pointsSize, int* pointsColSize, int K, int* returnSize, int** returnColumnSizes){

    if(points== NULL || pointsSize== 0|| pointsColSize== NULL || K==0 )
    {
        *returnSize=0;
        return NULL;
    }
     *returnSize=0;
    
    struct Heap* h = CreateHeap(0, pointsSize);
    if(h == NULL)
        return NULL;
 
    for(int i =0; i < pointsSize; i++)
        InsertHeap(h,  sqrt((double) (points[i][0]*points[i][0] + points[i][1]*points[i][1])), i);

     *returnColumnSizes  = (int*)calloc(K, sizeof(int));
     int** ret = (int**)calloc(K, sizeof(int*));
     if(ret== NULL||returnColumnSizes == NULL)
        return NULL;
    
        for(int i =0; i < K; i++)
        {
              struct Points* tmp = DeleteMinHeap(h);
              ret[i] = (int*)calloc(2, sizeof(int));
              if(ret[i] == NULL)
                  return NULL;
            
            ret[i][0] = points[tmp->idx][0];
            ret[i][1] = points[tmp->idx][1];
             (*returnColumnSizes)[i] = 2;
        }    
    
    DeleteHeap(h);
    *returnSize =K;
     return ret;
   
}
