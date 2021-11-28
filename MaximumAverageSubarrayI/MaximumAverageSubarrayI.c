

double findMaxAverage(int* nums, int numsSize, int k){
    
    if(nums == NULL || numsSize == 0 || k ==0)
        return 0.0; 
    double sum = 0.0, avg = 0.0, maxavg = 0.0; 
    
    
    for(int i =0; i< k; i++)
       sum+=nums[i];
    
     avg = sum/k; maxavg = avg; 
    
    for(int i = 0; i< numsSize-k; i++)
    {
        sum = sum + nums[i+k] - nums[i]; 
        avg = sum/k; 
        
            if(avg>maxavg)
                maxavg = avg; 
        
    }
    return maxavg; 
}
