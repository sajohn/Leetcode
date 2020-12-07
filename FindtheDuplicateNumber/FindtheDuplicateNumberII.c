

int findDuplicate(int* nums, int numsSize)
{
   if(nums == NULL || numsSize <=0)
       return -1;
 
    for(int i=0; i<numsSize; i++)
    {
        if(nums[abs(nums[i])] >0)
            nums[abs(nums[i])] = -nums[abs(nums[i])];
        else

            return abs(nums[i]);
    }
    
return 0;
}

