

int specialArray(int* nums, int numsSize){

    if(nums == NULL || numsSize == 0)
        return -1; 
    
    
    int ret[1001] = {0};
    
    for(int i =0; i < numsSize; i++){
        ret[nums[i]]++; 
    }
  
      for(int i =999; i >=0; i--){
          
          ret[i] = ret[i+1]+ ret[i];
          
          if(ret[i]!= 0 && i == ret[i])
           return i; 
           
      }
      
    return -1; 
}
