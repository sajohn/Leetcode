

bool increasingTriplet(int* nums, int numsSize){

    if(nums == NULL || numsSize < 3)
        return false; 
  
    
    int size = 0, idx = 0; 
    int arr[3] = {0};
    
    arr[0] = nums[0];
    idx = 0; 
    
    for(int i = 1; i< numsSize; i++)
    {
        if(nums[i] > arr[idx])
        {
            arr[++idx] = nums[i]; 
           if(idx == 2)
               return true; 
        }
        else
        {
            int j = 0; 
            while (arr[j]< nums[i] && j <= idx && j < 3){
                    j++;
            }
      
            arr[j] = nums[i];
           if(j > 2 )
               return true; 
            
        }
    }

   
    return false; 
 
}
