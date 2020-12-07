//How do you convert negative modulo to positive
/*
     if modulo = a%p <0
     modulo = a%p + p
     

//Here the condition is [1,n] inclusive range i.e. size of array is bounded so we can use modulo
operation to set index 

*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){

    
   if(nums== NULL || numsSize ==0)
   {
       *returnSize =0;
        return NULL;
   }
    int j =0;
    
    *returnSize =0;
    
    int* ret = (int*)malloc(sizeof(int)*numsSize);
    if(!ret)
    {
       *returnSize =0;
        return NULL;
    }
        
    memset(ret, 0, sizeof(int)*numsSize);
    for(int i =0; i < numsSize; i++)
         nums[i] = nums[i]-1;
    
    for(int i =0; i < numsSize; i++)
      nums[nums[i]%numsSize] = nums[nums[i]%numsSize]+numsSize;
    
    for(int i =0; i < numsSize; i++)
     if(nums[i]/numsSize == 0) {
       ret[j++] = i+1;
        *returnSize = *returnSize+1;
     }
    ret[j] = '\0';
    return ret;
}


