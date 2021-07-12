

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

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
void BuildHeap(struct Heap* h, int* intervals, int intervalSize)
{
    if(h == NULL || intervals == NULL || intervalSize <0 )
        return;

    if(h->capacity < intervalSize)
        ResizeHeap(h, intervalSize);
    int k = 0; 
    for(int i=0; i < intervalSize; i++)
        h->arr[k++] = intervals[i];
    
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

// int** kSmallestPairs(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize, int** returnColumnSizes){
//            if(nums1 == NULL || nums1 == NULL || nums1Size == 0 || nums2Size == 0 || k< 0)
//                return NULL;
//     *returnSize =0; 

    
//     struct Heap* h1 = CreateHeap( nums1Size);
//     struct Heap* h2 = CreateHeap( nums2Size);
//     BuildHeap(h1, nums1, nums1Size);
//     BuildHeap(h2, nums2, nums2Size);
    
//     int tmp = 0;
  
//     //First element from heap1 and all element from heap 2(put them in array)
//     //First element * heap2 element ---> insert in hash map
//     //if HASH_COUNT >= k, return K numbers...
    
    
//     int** ret = (int**)calloc(k, sizeof(int*));
//     if(ret == NULL)
//         return NULL; 
        
//     (*returnColumnSizes) = calloc(k,sizeof(int) );
//     if((*returnColumnSizes) == NULL)
//         return NULL; 
    
//     int min = INT_MAX, m=0; 
  
    
//     while(m<k &&  h1->size>0){
//         tmp = h1->arr[0];
//         for(int i =0; i < h2->size &&  m < k; i++)
//         {
//                   ret[m] = (int*)calloc(2, sizeof(int));
//                  if(ret[m] == NULL)
//                     return NULL; 
                
//                 ret[m][0] = tmp; 
//                 ret[m][1] = h2->arr[i]; 
                

//              (*returnColumnSizes)[m++] = 2;  
            
            
//         }
       
//         h1->arr[0] = h1->arr[h1->size -1];
//         h1->size--;
//         Percolate(h1, 0);
//     }
    
//         DeleteHeap(h1);
//         DeleteHeap(h2);
//     *returnSize = m; 
//     return ret; 
// }

typedef struct Pair{
    int i; 
    int j; 
    int sum; 
    UT_hash_handle hh; 
}Pair; 

int cmp(Pair*a, Pair* b){
    
    return (a->sum - b->sum);
}


int** kSmallestPairs(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize, int** returnColumnSizes){
           if(nums1 == NULL || nums1 == NULL || nums1Size == 0 || nums2Size == 0 || k< 0)
               return NULL;
    *returnSize =0; 

    
    Pair *guser = NULL, *element, *tmp; 
    
    for(int i =0; i< nums1Size; i++)
    {
        for(int j =0; j < nums2Size; j++)
        {
            int sumnum = (nums1[i]+nums2[j]); 
            HASH_FIND_INT(guser, &sumnum, element);
            
            if(element)
            {
                if(element->i != i || element->j != j && element->sum == sumnum)
                {
                    element = calloc(1, sizeof(Pair));
                    if(element == NULL)
                        return NULL; 
                    element->i = i; 
                    element->j = j; 
                    element->sum = sumnum;
                    
                    HASH_ADD_INT(guser, sum, element);
                    
                }
                
            }else{
                
                  element = calloc(1, sizeof(Pair));
                    if(element == NULL)
                        return NULL; 
                    element->i = i; 
                    element->j = j; 
                    element->sum = sumnum;
                    
                    HASH_ADD_INT(guser, sum, element);
                    
            }
            
            
        }
    }
    
    
    
    
    HASH_SORT(guser, cmp);
    
    int** ret = (int**)calloc(k, sizeof(int*));
    if(ret == NULL)
        return NULL; 
        
    (*returnColumnSizes) = calloc(k,sizeof(int) );
    if((*returnColumnSizes) == NULL)
        return NULL; 
    int m =0; 
      
    HASH_ITER(hh, guser, element, tmp) {

       if(m<k ){ 
            ret[m] = (int*)calloc(2, sizeof(int));
             if(ret[m] == NULL)
                return NULL; 

            ret[m][0] = nums1[element->i]; 
            ret[m][1] = nums2[element->j];


            (*returnColumnSizes)[m++] = 2;  
          HASH_DEL(guser, element);
          free(element);
       }
        
       
    }
    *returnSize = m; 
    return ret; 
    

}
