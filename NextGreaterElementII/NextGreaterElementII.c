

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


int* nextGreaterElements(int* nums, int numsSize, int* returnSize){
       
      if(nums == NULL ||  numsSize == 0 )
          return NULL; 
    
    int* ret = (int*)calloc(numsSize, sizeof(int));
   
    *returnSize = 0; 
    if(ret == NULL)
        return NULL;
    
    int j = 0, val =0; 
    
    for(int i = 0; i< numsSize; i++) {  
           j = (i+1) %numsSize; 
                  while( nums[j] <= nums[i] && j !=i ){
                      j = (j+1)%numsSize;
                  } 
                 
                 if(j  == i) {
                     val = -1; 
                      
                 } else {
                         val = nums[j];
                 }
        
                ret[i] = val;
               (*returnSize)++; 
        }

    
  return ret; 
}
