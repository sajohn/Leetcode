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
    int f[numsSize];
    
    f[0] = nums[0];
    f[1] = max(nums[0], nums[1]);
    
    
    for(int i =2; i < numsSize; i++)
        f[i] = max(f[i-2]+nums[i], f[i-1]);
    
    return f[numsSize-1];
}
