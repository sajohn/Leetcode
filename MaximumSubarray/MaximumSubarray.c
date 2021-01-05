//Kadane's Algorithm

int maxSubArray(int* nums, int numsSize)
{
    
   int max_sum =INT_MIN, cur_sum =0, sum =0; 
    
    if(numsSize ==1)
      return nums[0];
    
    for(int i = 0; i < numsSize; i++)
    {
        cur_sum += nums[i];
   
            if(cur_sum>max_sum)
                max_sum = cur_sum;
        
        if(cur_sum <0)
            cur_sum =0; 
    
    }
    
    return max_sum;
}
