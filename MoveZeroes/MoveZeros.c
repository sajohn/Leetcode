

void swap(int* a, int* b)
{
    int tmp =0;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void moveZeroes(int* nums, int numsSize)
{
    if(nums == NULL || numsSize ==0)
        return ;
    
     if(nums[0]==0 && numsSize ==2)
     {
         swap(&nums[0], &nums[1]);
         return;
     }
    
  int count =0; 

     for (int i = 0; i < numsSize; i++) 
        if (nums[i]!= 0) 
            nums[count++] = nums[i]; 
    
     
    while (count < numsSize) 
        nums[count++] = 0; 
  
}
