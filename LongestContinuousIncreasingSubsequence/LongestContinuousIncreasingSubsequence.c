

int findLengthOfLCIS(int* nums, int numsSize){

    if(nums == NULL || numsSize ==0)
        return 0; 
    
    
    int start =0, anchor =0, maxlen =1;
    
    for(int i =1; i <numsSize; i++)
    {
        if(nums[i-1] >= nums[i]) 
            anchor = i; 
     
            
        maxlen = maxlen>i-anchor+1? maxlen:i-anchor+1; 
        
    }
    
    return maxlen; 
}
