

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(int* a , int* b){
    
     return (*a - *b);    
}

int* rearrangeArray(int* nums, int numsSize, int* returnSize){

    *returnSize = 0; 
    if(nums == NULL || numsSize == 0)
        return NULL; 
    
    int* tmp = (int*)calloc(numsSize, sizeof(int));
    if(tmp == NULL)
        return NULL; 
    memcpy(tmp, nums, sizeof(int)*numsSize);
    
    qsort(tmp, numsSize, sizeof(int), cmp);

    for(int i =1; i < numsSize; i+=2)
    {
        int var = tmp[i];
        tmp[i] = tmp[i-1];
        tmp[i-1] = var; 
    }
    
//    int smallidx = 0, start = 1; 
    
//   while(smallidx >= 0 && smallidx < numsSize && start <= numsSize -1)
//   {
//       tmp[start] = nums[smallidx];
//       start +=2; smallidx++; 
//   }
//   start = 0; 
//      while(smallidx >= 0 && start <= numsSize -1)
//   {
//       tmp[start] = nums[smallidx];
//       start +=2; smallidx++; 
//   }

    *returnSize = numsSize; 
    return tmp; 
}
