

int minimumDeletions(int* nums, int numsSize){
    
    if(nums == NULL )
        return 0; 
    
    int max = 0, maxidx, min = 0, minidx =0, countfront = 0, countback =0, countmix =0; 
    max = INT_MIN, min = INT_MAX;
    minidx = maxidx = 0; 
    for(int i =0; i < numsSize; i++){
        
        if(max < nums[i])
        {
            max = nums[i];
            maxidx = i; 
        }
        if(min > nums[i])
        {
            min = nums[i];
            minidx = i; 
        }   
        
    }

    //removing from front
    
    countfront = (minidx>maxidx? minidx+1:maxidx+1);
    
    //removing from back...
    countback = (numsSize -maxidx > numsSize -minidx? numsSize -maxidx :numsSize -minidx);
    
    
     countmix = (minidx +1 < (numsSize - minidx)?minidx +1: (numsSize - minidx)) + 
               (maxidx +1 < (numsSize - maxidx)?maxidx +1: (numsSize - maxidx));
    
     
   if(countfront < countback)
        min = countfront; 
    else
        min = countback; 
    
    if(countmix < min)
        min = countmix; 
    
    return min;
}
