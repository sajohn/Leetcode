int max(int a, int b)
{
   return (a>b? a:b);
}

int rob(int* nums, int numsSize)
{
    if(nums == NULL || numsSize == 0)
        return 0;  
    
    if(numsSize ==1)
        return nums[0];
    
    if(numsSize ==2)
            return max(nums[0], nums[1]);
    
    int f1[numsSize], f2[numsSize];
    
    f1[0] = nums[0];
    f1[1] = max(nums[0], nums[1]);
    
   
    f2[0] = nums[1];
    f2[1] = max(nums[1], nums[2]);
    
     
    for(int i =2; i < numsSize-2; i++)
    {
        f1[i] = max(f1[i-2]+nums[i], f1[i-1]);
   
        f2[i] = max(f2[i-2]+nums[i+1], f2[i-1]);
    }
    
    
    return max(f1[numsSize-2], f2[numsSize-2]);
}

