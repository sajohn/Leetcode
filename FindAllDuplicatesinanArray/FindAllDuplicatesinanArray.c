

/**
 * Note: The returned array must be malloced, assume caller calls free().
 
Since condition is 1 ≤ a[i] ≤ n (n = size of array), we can transform it to index -1 to 
negate elements
 
 */
int* findDuplicates(int* nums, int numsSize, int* returnSize)
{
    
    if(nums == NULL || numsSize == 0)   {
       *returnSize = 0;   
        return NULL;
    }
    
    
    int* ret = (int*)calloc(numsSize, sizeof(int));
    
    if(!ret)
    {
       *returnSize = 0;   
        return NULL;
    }
    
   int j =0, idx =0;
   for(int i =0; i < numsSize; i++)
   {
      idx = abs(nums[i])-1;
      
       if( nums[idx]  < 0)
          ret[j++] = abs(idx+1);
       
           nums[idx] = -nums[idx];
        
   }

 
      *returnSize = j; 
    
    return ret;
}
