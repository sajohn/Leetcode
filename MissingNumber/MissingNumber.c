

int missingNumber(int* nums, int numsSize)
{
   if(!nums || numsSize ==0)
       return 0;
    
    
    unsigned long sum =0, expectedSum =0;
    for(int i =0; i< numsSize; i++)
        sum += nums[i];
    
    for(int i =0; i<=numsSize; i++)
    expectedSum += i;
    
   return expectedSum -sum;
}
