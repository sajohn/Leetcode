
int max(int num, int max_so_far, int min_so_far)
{
   int min=0, max =0, tmp =0;
    
    min = min_so_far*num;
    max = max_so_far*num;
    
    tmp = (min>max)? min:max;
  
    
    if(tmp>num)
        return tmp;
    return num;
    
    
}
int min(int num, int max_so_far, int min_so_far)
{
    int min=0, max =0, tmp =0;
    
    min = min_so_far*num;
    max = max_so_far*num;
    
    tmp = (min<max)? min:max;
  
    
    if(tmp<num)
        return tmp;
    return num;
}


int maxProduct(int* nums, int numsSize)
{
  if(nums == NULL || numsSize == 0)
        return 0;
    
    if(numsSize == 1)
        return nums[0];
    
    int max_so_far =nums[0], min_so_far = nums[0], result=nums[0];
     
    for(int i = 1; i < numsSize; i++)
    {
        int max_i = max_so_far;
        int min_i = min_so_far;
        
       max_so_far = max(nums[i], max_i, min_i);
       min_so_far = min (nums[i], max_i, min_i);
       
        result = (result> max_so_far?result: max_so_far);
        
    }
    
    return result;
}


