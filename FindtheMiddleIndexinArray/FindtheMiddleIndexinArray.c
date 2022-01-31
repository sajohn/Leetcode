

int findMiddleIndex(int* nums, int numsSize){

     if(nums == NULL || numsSize <=0)
        return -1;
    
    int sum=0, tmp =0; 
    
    for(int i = 0; i < numsSize; i++)
       sum +=nums[i];
    
    for(int i= 0; i<numsSize; i++)
    {
        if(tmp == sum - tmp - nums[i])
            return i;
           tmp += nums[i];
    }
                
    return -1;
}
  
