

int findClosestNumber(int* nums, int numsSize){
    
    if(nums == NULL || numsSize == 0)
        return 0; 
    int min = INT_MAX, val = 0, idx =0; 
    
    
    for(int i =0; i < numsSize; i++)
    {
         
        if(abs(nums[i]) <= min){
                
             if(min == abs(nums[i]))
             {
                 if(nums[i] > nums[idx]){
                    val = nums[i];
                    idx = i; 
                 }
             }
            else{
                
                    val = nums[i];
                    idx = i; 
                min = abs(nums[i]) < min? abs(nums[i]): min; 
            }

              
        }
        
    }

    return val; 
}
