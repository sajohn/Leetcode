
int cmpfunc(void* a, void* b)
{
    return (*(int*)a) - (*(int*)b);
}

int findKthLargest(int* nums, int numsSize, int k)
{
  
    if(nums == NULL || numsSize ==0 || numsSize <k)
        return -1;
    
    
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    
    return nums[numsSize-k];
}

