int cmpfunc(int* a , int* b)
{
    return (*a -*b);    
}

int findDuplicate(int* nums, int numsSize)
{
   if(nums == NULL || numsSize <=0)
       return -1;
    
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    
    for(int i=0; i<numsSize-1; i++)
       if(nums[i] == nums[i+1])
           return nums[i];
    
    
    
return -1;
}
