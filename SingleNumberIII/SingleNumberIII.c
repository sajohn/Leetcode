

/**
 * Note: The returned array must be malloced, assume caller calls free().
 
  //The idea here is to have a xor
 */
int* singleNumber(int* nums, int numsSize, int* returnSize){
    
    if(!nums || numsSize == 0)
        return NULL;
    int* ret = (int*)calloc(2, sizeof(int));
    if(ret == NULL)
        return NULL;
    
    int xor = 0, right_most_bit =0;
    
    for(int i =0; i < numsSize; i++)
        xor^=nums[i];

    right_most_bit = xor & (-xor);

    
    //Numbers come in two buckets when we sort them according to right_most_bit 
    //
    
     for(int i =0; i < numsSize; i++)
         if( nums[i] &  right_most_bit )
            ret[0] ^=nums[i];


       ret[1] = ret[0]^xor;
        *returnSize = 2;
        return ret;

    
}
