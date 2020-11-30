//If mid finds its previous index even and equal to him then 
//Unique element is not on left side
//If mid finds its previous index odd and equal to him then 
//Unique element is not on right side

int singleNonDuplicate(int* nums, int numsSize)
{
    if(nums == NULL || numsSize == 0)
        return -INT_MAX;
    if(numsSize ==1)
        return nums[0];
    
    int low=0,mid=0, high =numsSize -1;
    
    if(nums[low] !=nums[low+1])
        return nums[low];
    
    if(nums[high-1] !=nums[high])
        return nums[high];
    
    
    while(low <=high)
    {
        mid = low+ (high -low)/2;
        
        if(nums[mid]>nums[mid-1] && nums[mid]<nums[mid+1])
            return nums[mid];
        else if( nums[mid-1] == nums[mid] )
        {
            if((mid-1)%2)
                high = mid-1;
            else if((mid-1)%2 ==0)
                low = mid+1;
        }  
        else if(mid%2 )
             high = mid-1;
        else
              low = mid+1; 
        
    }
return INT_MIN;
}
