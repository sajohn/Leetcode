
//Find the pivot
//Then either search left or right the target

//bool search(int* nums, int numsSize, int target)


bool search(int* nums, int numsSize, int target)
{

    if(nums== NULL || numsSize ==0)
        return false;
    
    if(numsSize ==1 && target != nums[0])
        return false;
    
    
    int left=0, right =0, mid =0, pivot = 0;
     right = numsSize -1;
    
   
    while( left<=right)
    {
       while(left <right && nums[left] == nums[left+1] )
           ++left;
         while( 0 <right && nums[right] == nums[right-1] )
           --right;
        
        mid = left + (right -left)/2;
        
        
        if(nums[mid] == target)
            return true;
        else if(nums[left] <= nums[mid])
        {
            //Target is in here
            if(nums[left]<= target && target < nums[mid] )
                right = mid-1;
                
            //Target is not here
            else
                left = mid+1;
        }
        else  if(nums[mid] <= nums[right])
        {
            //Target is in here
             if(nums[mid]< target && target <= nums[right] )
                left = mid+1;
            //Target is not here
            else
                right = mid-1;
        }

            
    }
        
   return false;
}
