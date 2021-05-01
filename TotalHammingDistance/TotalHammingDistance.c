

int totalHammingDistance(int* nums, int numsSize){
    
    if(nums == NULL || numsSize == 0)
        return 0; 
    
    int setbits[32] = {0}, res =0;
    
    for(int i= 0 ; i < numsSize; i++) {
        
        for(int j = 0; j< 32; j++) {
            setbits[j] += (nums[i] & (1U<<j)) ? 1: 0;
        }
    }

       for(int j = 0; j< 32; j++){
           res += ( setbits[j] * (numsSize - setbits[j] )); 
       }
    
    return res; 
}
