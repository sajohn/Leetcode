
int peakIndexInMountainArray(int* nums, int numsSize)
{
    if(nums == NULL || numsSize == 0)
        return -1;
        if(numsSize==1)
            return 0;
    if(numsSize<3 )
        return (nums[0]>nums[1]? 0:1);
    
    int low =0, mid =0, high = numsSize -1;
    
    while(low <=high)
    {
        mid = low+ (high-low)/2;
        
        if( mid == 0 || mid == numsSize-1)
            return mid;
       
        if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1])
            return mid;
        else
        {
           if(nums[mid]>nums[mid+1])
              high = mid;
            else if(nums[mid]<nums[mid+1])
              low = mid+1;
            else  if(nums[mid]<nums[mid-1])
                high = mid-1;
            else  if(nums[mid]>nums[mid-1])
                low = mid;
            
        }
        
    }
    return -1;
}

