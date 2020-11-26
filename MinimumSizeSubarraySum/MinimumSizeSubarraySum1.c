//Here left boundary is discarded is not needed in further check (sliding is sufficient condition to get the next mininum)
int minSubArrayLen(int s, int* nums, int numsSize){
    
    int sum =0, left =0, min = INT_MAX; 
    
    if(nums == NULL || numsSize == 0 )
        return 0;
    
    for(int i=0; i < numsSize; i++)
    {
        sum +=nums[i];
  
        while(sum >=s)
        {
           min = abs(i +1- left) < min? abs(i+1 - left):min;
            sum -=nums[left++];
        }
 
    }
    
   return (min!=INT_MAX? min:0);
}
