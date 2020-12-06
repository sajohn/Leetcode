int singleNonDuplicate(int* nums, int numsSize)
{
    if(nums == NULL || numsSize == 0)
        return -INT_MAX;
 
    int ret = 0;
    
    for(int i = 0; i < numsSize; i++)
       ret ^=nums[i];

    
    return ret;
}
