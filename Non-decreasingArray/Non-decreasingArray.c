



bool checkPossibility(int* nums, int numsSize){
    
    if(nums == NULL || numsSize == 0)
        return true; 
    
    if(numsSize <= 2)
        return true; 
    
    int inflection = 0, valley = 0; 
    
    for(int i =1; i < numsSize; i++)
    {
        
        
        if(nums[i-1] > nums[i])
        {
            if(inflection >0){
                return false; 
            } 
            
                inflection++; 
                
                if(i < 2 ||  nums[i-2] <= nums[i]) //Should happen earlier
                {
                    nums[i-1] = nums[i]; //Make it increasing sequence by pulling down middle element
                } else {
                    
                  nums[i] = nums[i-1]; //Lift it up (i.e. pull up the last element which is violating )
                }
            }
        
    }
        
        

 
    
    return true; 

}
