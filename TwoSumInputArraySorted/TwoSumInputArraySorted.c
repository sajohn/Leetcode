

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numbersSize, int target, int* returnSize){
    
    *returnSize = 0; 
    
    if(nums == NULL || numbersSize == 0 )
        return NULL; 
    int* ret = (int*)calloc(2, sizeof(int));

    if(ret == NULL)
        return NULL; 
    
    int start =0, mid =0, end = numbersSize-1; 

    
    while(start<end)
    {
       
        
        if(nums[start]+nums[end] == target )
        {
            ret[0] = start+1; 
            ret[1] = end+1; 
            *returnSize =2; 
            return ret; 
        }
        else if(nums[start]+nums[end] < target )
            start++; 
        else    if(nums[start]+nums[end] > target )
        end--; 
    }
    
    *returnSize = 0; 
    return ret; 
}
