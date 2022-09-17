

int countHillValley(int* nums, int numsSize){
    
    if(nums == NULL || numsSize == 0)
        return 0; 
    
    
    int k =0, count = 0; 
    int left[numsSize], right[numsSize];
    memset(&left, 0, sizeof(int)*numsSize);
    memset(&right, 0, sizeof(int)*numsSize);
    right[numsSize-1]= -1; 
    left[0]= -1; 
    
    for(int i =numsSize -2;i>=0; i--){
        k = i+1; 
        while(k < numsSize && nums[k] == nums[i] ){
            k++; 
        }
        right[i] = (k < numsSize)? nums[k]: -1;
     
    }
     k =0; 
    for(int i =1;i<numsSize; i++){
        k = i-1; 
        while( k >=0 && nums[k] == nums[i]  ){
            k--; 
        }
        left[i] = (k>=0)? nums[k]: -1;
     
    }
    
         for(int i =1;i<numsSize; i++){
             if(left[i] !=-1 && right[i]!=-1)
             {
                 if((nums[i]>right[i] && nums[i] > left[i]) || 
                    (nums[i]<right[i] && nums[i] < left[i]) )
                     
                     if(left[i-1] != left[i] && right[i-1] != right[i])
                       count++; 
             }
         }         
              
    return count;

}

    
