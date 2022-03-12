

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void AllocAddBuffer(char** ret, int* returnSize, int lower, int upper)
{
    
     ret[(*returnSize)] = calloc(50, sizeof(char));
                     if(  ret[(*returnSize)]  == NULL)
                         return NULL; 
    
       if(lower == upper)
            sprintf(ret[(*returnSize)], "%d", lower);
       else 
          sprintf(ret[(*returnSize)], "%d->%d", lower, upper);
          
        (*returnSize)++;
}

char ** findMissingRanges(int* nums, int numsSize, int lower, int upper, int* returnSize){
    
    *returnSize = 0; 
        
      char** ret = (char**)calloc(numsSize+1, sizeof(char*));
        if(ret == NULL)
            return NULL; 
    
       if(numsSize == 0) {
            AllocAddBuffer(ret, returnSize, lower, upper);
            return ret; 
       }
    
    if(lower < nums[0])
        AllocAddBuffer(ret, returnSize, lower, nums[0]-1);
    
    
    for(int i =1; i < numsSize; i++)
        if(nums[i] - nums[i-1] >1)
             AllocAddBuffer(ret, returnSize, nums[i-1]+1, nums[i]-1);
      

    if(nums[numsSize -1] < upper)
        AllocAddBuffer(ret, returnSize, nums[numsSize -1]+1, upper);
    
    return ret; 
    

}
  
