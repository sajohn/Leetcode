

int searchInsert(int* nums, int numsSize, int target){
    
    if(nums == NULL || numsSize == 0)
        return 0; 
    
     int left =0, right = numsSize -1, mid =0; 
    
    while(left <=right){
        
        mid = left + (right -left)/2;
        
        if(nums[mid] == target)
        {
           return mid; 
            
        }else if (nums[mid] < target) {
            left = mid+1; 
            
        } else if (nums[mid] > target)
        {
            right = mid-1;
        }
        
    }

/*On paper when I tried the only condition when you don't find the target in general search 
 left becomes larger than right 
 
     left>right 
     Three cases r <0 l > numsSize -1 && (r>-0 && r=numsSize -1)
     In all cases above left is the desired position. 
 */  
    return left; 
}
