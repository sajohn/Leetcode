
int subarraySum(int* nums, int numsSize, int k)
{

    if(!nums || numsSize ==0)
        return 0;
    
    
int sum =0, count =0;
    
      for(int i =0; i< numsSize; i++)
      {
          sum = 0;
        for(int j =i; j< numsSize; j++)
        {
         sum +=nums[j];
            if(sum == k)
                count++;
        }
      }
    
    return count;
}
