typedef struct {
    int* arr;
    int top;
    int size;
}KthLargest;

int leftChild(int i, int intervalSize)
{
    if(2*i+1>intervalSize)
        return -1;
    return (2*i+1);
}
int rightChild(int i, int intervalSize)
{ 
     if(2*i+2>intervalSize)
        return -1;
    return (2*i+2);
}
void Insert(int* arr,int index){
    int parent=(index-1)/2;
    
    if(parent>=0 && arr[index] < arr[parent]){
        int temp=arr[index];
        arr[index]=arr[parent];
        arr[parent]=temp;
        Insert(arr,parent);
    }
}

void Percolate(int* arr,int parent,int size){
    int left=leftChild(parent, size);
    int right=rightChild(parent, size);
    
    int min=parent;
    
    if(left<=size && left !=-1 && arr[left]<arr[min]){
        min=left;
    }
    if(right<=size && right !=-1&& arr[right]<arr[min]){
        min=right;
    }
    
    if(min!=parent){
        int temp=arr[min];
        arr[min]=arr[parent];
        arr[parent]=temp;
        Percolate(arr,min,size);
    }
}

KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest* obj=(KthLargest*)malloc(sizeof(KthLargest));
    obj->top=-1;
    obj->size=k;
    obj->arr=(int*)calloc(k,sizeof(int));

    for(int i=0;i<numsSize;i++){
        if(i<k)
        {
            obj->arr[++(obj->top)]=nums[i];
            Insert(obj->arr,obj->top);        
        } 
        else
        {
            //If new element (kth) comes which happens to be greater than nums[i] we can safely remove the smallest since we have to 
            //Get the maximum kth element. 
            if(obj->arr[0] < nums[i])
            {
                obj->arr[0]=nums[i];
                Percolate(obj->arr,0,obj->top);
            }       
        }
    }    
    return obj;
}

int kthLargestAdd(KthLargest* obj, int val) {
//if the heap is empty or not filled to its capacity, populate first with incoming elements
    if(obj->top < 0 || obj->top < (obj->size)-1)
    {
        obj->arr[++(obj->top)]=val;
        Insert(obj->arr,obj->top);
    } 
    else if(obj->arr[0] < val)
    {
        obj->arr[0]=val;
        Percolate(obj->arr,0,obj->top);
    }       
    return obj->arr[0];
}

void kthLargestFree(KthLargest* obj) {
    free(obj->arr);
    free(obj);
}
