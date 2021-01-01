int thirdMax(int* nums, int numsSize)
{
  if(nums == NULL || numsSize ==0)
      return 0;

 long num1 = LONG_MIN, num2=LONG_MIN, num3=LONG_MIN;
 for(int i =0; i < numsSize; i++)
 {
     if(nums[i]>num1)
     {
         num3 = num2;
         num2 = num1;
         num1=nums[i];
     }
     else if(nums[i] < num1 && nums[i]>num2)
     {
         num3 = num2;
         num2 = nums[i];
     }
     else if(nums[i]<num1 && nums[i] < num2 && nums[i]>num3)
     {
         num3 = nums[i];
     }
 }
        

    if(num3 != LONG_MIN)
    return (int)num3;
    
    if((long)num1 != LONG_MIN)
      return (int)num1;  
    if(num2 != LONG_MIN)
        return (int) num2;

    return INT_MIN;
}

int thirdMax(int* nums, int numsSize)
{
long first = LONG_MIN;
    long second = LONG_MIN;
    long third = LONG_MIN;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] >= first)
        {
           if (nums[i] != first)
            {
                third = second;
                second = first;
                first = nums[i];
            }
        }
        else if (nums[i] >= second)
        {
            if (nums[i] != second)
            {
                third = second;
                second = nums[i];
                //printf("second: %d\n", first);
            }
        }
        else if (nums[i] >= third)
        {
            if (nums[i] != third)
            {
                third = nums[i]; 
            }
        }
    }
    return third > LONG_MIN ? third : first;
}

