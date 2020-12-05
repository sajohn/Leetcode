/*
At ith index if sum is X Total Sum (prefix ) is Y and nums[i]
then
      Sum= Y;
      Y - nums[i] - X = X
      
      i.e. 2X + num[i] = Y
      X is rolling from i to end......
*/
int pivotIndex(int* nums, int numsSize){
  
     if(nums == NULL || numsSize <=1)
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
  
