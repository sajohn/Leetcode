
//Instead of all cased look around inflection point
//Cases around inflection point are easy to think than around L, M & R

/*
  Case 1:   mid > right 
  In this case the minimum is in mid+1 to right
          
          mid.   
           --------------
          /              \                     ---------
 low     /                \                   /
________/                  \        ---------/
                            \_____ /
                                  high 
  
  
  Case 2:   mid < right 
  In this case the minimum is in left to mid inclusive
  
  
             low
           --------------                        high
          /              \                      ---------
         /                \                    /
________/                  \         ---------/
                            \_____ /
                                  mid
  
  
  Case 3:    mid == high
  In this case the high is just moved one less since its equal
  
  low       mid                   mid.   high
  ___________________            _______________
                     \          /
                      \________/

*/
    

int findMin(int* nums, int numsSize){
      
    if(nums == NULL || numsSize == 0)
        return INT_MIN;
    
    int left =0, right = numsSize -1 , mid =0 ;
    
    while(left <= right)
    {
        mid = left + (right -left)/2;
        
        if(nums[mid] > nums[right])
            left = mid+1; 
        else if(nums[mid] < nums[right])
            right = mid; 
        else
            right = right -1;
      
    } 
    
return nums[left]; 
}
