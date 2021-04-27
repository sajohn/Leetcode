

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParityII(int* nums, int numsSize, int* returnSize){
    *returnSize= 0; 
if(nums == NULL || numsSize == 0 )
    return NULL; 
    
   int idx =0; 
    int* ret = (int*)calloc(numsSize, sizeof(int));
    if(ret == NULL)
        return NULL; 
    
    int even = 0, odd =1;
    for(int i =0; i < numsSize; i++) {
        if(nums[i]%2 == 0){
            ret[even] = nums[i];
         even+=2;
        }
        if(nums[i]%2 != 0){
            ret[odd] = nums[i];
         odd+=2;
        }
    }
  
    *returnSize = numsSize; 
    return ret; 
}
