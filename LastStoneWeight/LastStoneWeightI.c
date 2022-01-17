
int cmpfunc(void* a, void* b)
{
    return (*(int*)a) - (*(int*)b);
}



int findKthLargest(int* nums, int numsSize, int k)
{
  
    if(nums == NULL || numsSize ==0 || numsSize <k)
        return -1;
    
    
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    
    return nums[numsSize-k];
}

int lastStoneWeight(int* stones, int stonesSize){

    
    if(stones == NULL || stonesSize == 0)
        return 0; 
    
    
   
    int i = stonesSize -1;
    while(i > 0)
    {
        qsort(stones, i+1, sizeof(int), cmpfunc);
        
        if(stones[i] == stones[i-1]){
            i = i-2;//Both destroyed
        }else
        {
             if(stones[i] != stones[i-1]){
                  if(stones[i] > stones[i-1])
                      stones[i-1] = stones[i]- stones[i-1];
                      i = i-1;
             }
        }
         //qsort(stones+i, stonesSize, sizeof(int), cmpfunc);
    }
    
    return (i>=0 ? stones[i]: 0);
}
