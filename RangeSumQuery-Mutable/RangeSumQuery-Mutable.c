


typedef struct {
    int numsSize;
    int* nums;
    int* sum;
    
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    
 NumArray* obj = (NumArray*)malloc(sizeof(NumArray));
    if(!obj)
        return NULL;
  if(!nums || numsSize ==0 )
    return NULL;
    
    obj->numsSize = numsSize;
    obj->nums = nums;
    obj->sum =  (int*)calloc(numsSize+1, sizeof(int));
    
    if(obj->sum == NULL)
        return NULL;
    
     for(int i= 0; i<numsSize; i++)
              obj->sum[i+1] = obj->sum[i]+obj->nums[i];
   
   return obj;
}

void numArrayUpdate(NumArray* obj, int i, int val) {
  if(obj == NULL || i > obj->numsSize || i< 0)
      return;
    
    obj->nums[i] = val;
    for(int idx =i; idx<obj->numsSize; idx++)
        obj->sum[idx+1] = obj->sum[idx]+ obj->nums[idx];
    
}

int numArraySumRange(NumArray* obj, int i, int j) {
  
       if(obj == NULL || i <0 || j< 0 || i> obj->numsSize || j > obj->numsSize)
        return -1;
    
         int sum =0; 
         sum = obj->sum[j+1] - obj->sum[i]; //Why I because i t= j inclusive should exclude i sum. And since we have idx+1
    return sum;
}

void numArrayFree(NumArray* obj) {
    
    if(obj)
        free(obj->sum);
        
    free(obj);
    
}


