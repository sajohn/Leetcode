
/* 
  If you mark valule negative i.e. nums[i] = -nums[i]  case with 0 fails so 
  only use some other value like INT_MAX or INT_MIN 
*/
//Seems like in Array there is no repetition of element
//All elements are in range 0 - n-1


int arrayNesting(int* nums, int numsSize){
    
    
    if(nums == NULL || numsSize == 0)
        return 0; 
    
    
    int max = 1; 
    
      for(int i=0; i < numsSize; i++)
    {
        if(nums[i] == INT_MIN)
            continue; 
        int count = 0, start = 0, tmp = 0; 
        
      start = nums[i];  // 5 
       while(nums[start] != INT_MIN){
            count++;
            tmp = start; 
           start = nums[start];  // 1
         
            nums[tmp] = INT_MIN; //1 = -1 
    
       }
      
        max = count > max? count: max;   
    }
    
    
    return max; 

}


////


/*


//Seems like in Array there is no repetition of element
//All elements are in range 0 - n-1


void HelperNest(int* nums, int numsSize, int* max){
    
       
    if(nums == NULL || numsSize == 0)
        return ; 
    
    for(int i=0; i < numsSize; i++)
    {
        int count = 1; 
        
        int si =nums[i];
        int tmp = si; 
       while(si != nums[tmp]){
           count++;
           
           *max = count > *max? count: *max; 
           tmp = nums[tmp];
       }
    }
    
}

int arrayNesting(int* nums, int numsSize){
    
    
    if(nums == NULL || numsSize == 0)
        return 0; 
    
    
    int max = 1; 
    
    HelperNest(nums, numsSize, &max);
    
    return max; 

}
*/

