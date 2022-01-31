
bool canThreePartsEqualSum(int* nums, int numsSize){

     if(nums == NULL || numsSize <=0)
        return false;
    
    int sum = 0, tmp = 0, count =0; 
    
    for(int i = 0; i < numsSize; i++)
       sum +=nums[i];
    
    if(sum%3)
        return false; 
    
    for(int i = 0; i < numsSize; i++){
        tmp +=nums[i];
        
        if(tmp == sum/3)
        {
            tmp = 0; 
            count++; 
        }
        
    }   
    return count >=3; //count == 3 is going to fail for all 0 array
}

