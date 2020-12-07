int cmpFunc(const void* a, const void* b)
    {
        int n1 = * (int *) a, n2 = * (int *) b;
        return (n1 > n2)? 1: n1 == n2 ? 0 : -1 ; 
    }

int singleNumber(int* nums, int numsSize)
{
    if(nums == NULL || numsSize <=3)
       return nums[0];
    
    qsort(nums, numsSize, sizeof(int), cmpFunc);
     
    int count =1;
    for(int i =1; i < numsSize; i++ )
    {
        if(nums[i]== nums[i-1])
          count++;
       else if(count == 3 && nums[i]!= nums[i-1] && i!=numsSize-1)
           count = 1;
       else if( nums[i]!= nums[i-1]  )
       {
          if(i==numsSize-1)
            return nums[i];
          else
             return nums[i-1];
       }
    }
    
    return -1;
}
