


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
//C library has its own quicksort but in case not included the quick sort below works as well
/*
**/
int cmpfunc(void* a, void* b)
{
    int aa = (*(int*)a);    
     int bb = (*(int*)b);  
    
    return (aa - bb);
}


int threeSumClosest(int* nums, int numsSize, int target){

    
    if(!nums || numsSize <3)
    {  
        return INT_MIN;
    }
      
 
    int low = 0, high = numsSize -1, mid =0;
     
    qsort(nums, numsSize, sizeof(int), cmpfunc);   
    
     int sum =0, diff = INT_MAX;

    
  for(int i = 0; i <numsSize && diff !=0;i++)
  {
      mid = i+1;
      high = numsSize-1;
 
      while(mid < high)
      {
         sum = nums[i]+nums[mid]+nums[high];
        if( abs(target-sum) < abs(diff) )
        {            
                diff = target -sum;             
        }   
        if (sum < target)
        {
          mid++;
        }
        else 
        {        
           high--;     
            
        }
      }
  }
          
 return target -diff;    
    
    
}
