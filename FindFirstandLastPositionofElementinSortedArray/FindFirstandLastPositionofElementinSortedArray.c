

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/*
If found the element get left and right index
*/
/*
           if(mid > ret[1]) {
                ret[1]  = mid;
                left = mid+1; 
            }
            else if(mid < ret[0]) {
                ret[0] = mid;
                right = mid-1; 
            }  

          [5,7,7,8,8,8,8,8,8,10], target = 8
    
*/

void FindLeftIdx(int* nums, int numsSize, int target, int* ret){
  
    if(nums == NULL || numsSize == 0)
        return NULL; 

    int left =0, right = numsSize -1, mid = 0; 
    while(left <= right)
    {
        mid = left + (right -left)/2;  
        if(nums[mid] == target) {
           right = mid-1; ///Trying to go to left index; 
            ret[0] = mid;  ///Keep updating the left
        } else if(nums[mid] < target) {
            left = mid+1; 
        } else if(nums[mid] > target) {
            right = mid-1; 
        }
    }

}

void FindRightIdx(int* nums, int numsSize, int target, int* ret){
  
    if(nums == NULL || numsSize == 0)
        return NULL; 

    int left =0, right = numsSize -1, mid = 0; 
    while(left <= right)
    {
        mid = left + (right -left)/2;  
        if(nums[mid] == target) {
          left = mid+1;
          ret[1] = mid; 
        } else if(nums[mid] < target) {
            left = mid+1; 
        } else if(nums[mid] > target) {
            right = mid-1; 
        }
    }
    
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize){

      *returnSize = 0; 
    int* ret = (int*)calloc(2, sizeof(int));
    if(ret == NULL)
        return NULL; 
    
    ret[0] = ret[1] = -1; 
    *returnSize = 2; 
    if(nums == NULL || numsSize == 0 || returnSize == NULL)
        return ret; 
    

        FindLeftIdx(nums, numsSize, target, ret); //For left
        FindRightIdx(nums, numsSize, target, ret); //For right

    
    return ret; 
}
