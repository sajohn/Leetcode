

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int cmp(void* a, void* b)
{
   return ( *(int*)a - *(int*)b); 
}


void FindIndex(int* nums, int numsSize, int target, int* ret, int dir){
  
    if(nums == NULL || numsSize == 0)
        return NULL; 

    int left =0, right = numsSize -1, mid = 0; 
    while(left <= right)
    {
        mid = left + (right -left)/2;  
        if(nums[mid] == target) {
            
        if(dir == 0){
            right = mid-1; ///Trying to go to left index; 
            ret[0] = mid;  ///Keep updating the left
        }else{
                  left = mid+1;
                  ret[0] = mid; 
            }
        } else if(nums[mid] < target) {
            left = mid+1; 
        } else if(nums[mid] > target) {
            right = mid-1; 
        }
    }
}

int* targetIndices(int* nums, int numsSize, int target, int* returnSize){

    *returnSize = 0; 
    if(nums == NULL || numsSize == 0 )
        return NULL; 
    
    qsort(nums, numsSize, sizeof(int), cmp);
    int ret = -1; 
    FindIndex(nums, numsSize, target, &ret, 0);
    int left = ret; 
    FindIndex(nums, numsSize, target, &ret, 1);
    int right = ret; 
  
    if(left == right && left == -1)
    {
        return NULL; 
    }
        
    int *result = calloc(right-left+1, sizeof(int));
    if(result == NULL)
        return NULL; 
    
        
    for(int i = left; i<= right; i++)
        result[(*returnSize)++] = i; 
    
    return result;
}
