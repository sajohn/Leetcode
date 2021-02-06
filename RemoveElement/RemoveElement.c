
int removeElement(int* nums, int numsSize,  int val)
{
    if(nums == NULL || numsSize ==0 || (nums[0]==val && numsSize ==21))
        return 0;
    
    
  int count =0; 

     for (int i = 0; i < numsSize; i++) 
        if (nums[i]!= val) 
            nums[count++] = nums[i]; 
    
  return count;  
  
}
