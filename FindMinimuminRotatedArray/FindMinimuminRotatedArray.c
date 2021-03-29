

int findMin(int* nums, int numsSize){
      
    if(nums == NULL || numsSize == 0)
        return INT_MIN;
    
    int left, right , mid ;
    left = 0; 
    
    right = numsSize -1; 
    
   int min = INT_MAX; 
    
    while(left <= right)
    {
        mid = left + (right -left)/2;
    
        if(nums[mid]< min)
            min = nums[mid];
        
        if(nums[mid]<=nums[right]){
            right = mid -1; 
            
        }
        else   if(nums[mid]>=nums[right]){
            left = mid +1;
        }
        
    } 
    
return min; 
}
