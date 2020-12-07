

int singleNumber(int* nums, int numsSize)
{
   if(nums == NULL || numsSize == 0)
       return -1;

    for(int i =1; i<numsSize; i++)
       nums[0] ^=nums[i];
    
    return nums[0];

}
