//Two smallest can make product big and then their product with third could be > positive 
//Two max can make product big and then their product with third could bring product > max_so_far
//max1>max2>max3
//min1<min2<min3

int maximumProduct(int* nums, int numsSize)
{
  if(nums == NULL || numsSize < 3)
      return 0;
    
   int max1 =INT_MIN, max2 =INT_MIN, max3 =INT_MIN; 
     
   int min1 = INT_MAX, min2=INT_MAX; 
   
    
    for(int i =0; i < numsSize; i++)
    {
         if(nums[i]<min1)
            {
                min2 = min1;
                min1 = nums[i];
            }
            else if(nums[i]<min2)
                min2 = nums[i];
             
            if(nums[i]>max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            }
            else if(nums[i]>max2)
            {
                max3 = max2;
                max2 = nums[i];
            }
            else if(nums[i]>max3)
                max3 = nums[i];
        
      }
    
       int max = (long)max1*max2*max3;
       int min = (long)min1*min2*max1;
    
        return (max > min? max: min);

}


