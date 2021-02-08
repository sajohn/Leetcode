
int minMoves(int* nums, int numsSize)
{
    if(nums == NULL || numsSize == 0)
        return 0; 
    
  long min = INT_MAX, sum =0;
    
  for(int i =0; i < numsSize; i++)
  {
      if(nums[i]<min)
          min = nums[i];
      sum+= nums[i];
  }
    
    return (sum - numsSize*min); 
} 
