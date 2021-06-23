int cmp(void* a, void* b)
{
    return (*(int*)a - *(int*)b);
}

int twoSumLessThanK(int* nums, int numsSize, int k){

    if(nums == NULL || numsSize == 0)
        return -1; 
    
    
    qsort(nums, numsSize, sizeof(int), cmp);

    
    int start = 0, end = numsSize -1, tmp = -1; 
    
    while(start < end)
    {
       
        if(nums[start]+nums[end] == k){
            end--; 
        }
        else if(nums[start]+nums[end] < k)
        {
            if(tmp < nums[start]+nums[end])
                tmp = nums[start]+nums[end];
            start++;
        }
        else if(nums[start]+nums[end] > k)
        {
            end--; 
        }
    }
    
    
    return tmp;
}
