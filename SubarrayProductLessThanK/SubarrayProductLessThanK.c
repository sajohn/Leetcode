//Since the integers are positive meaning we can use log
//Inequality is 
// log(a*b*c) = loga +logb+logc = logk
//Like java solution we need to define find 


int numSubarrayProductLessThanK(int* nums, int numsSize, int k)
{
   if(nums == NULL || numsSize ==0 || k<=1)
       return 0;
    
  int start =0,  end = 0, product = 1, res =0;
    
    
    for(int end = 0; end < numsSize;  end++)
    {
        product *=nums[end];
        while(product >=k)
        {
            //Trying to shrink to come upto new start point
          product /=nums[start++];
              
        }
        
       res += end -start +1; 
    }
    
    return res;
}
