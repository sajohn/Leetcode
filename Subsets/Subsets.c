

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */


int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){ 

    
     *returnSize = 0;
    
    if( !nums || numsSize == 0)
        return NULL;
      
    int val = (1<<numsSize);  //Total size of set would be 2^N
    
	int** ret = (int**)calloc(val, sizeof(int*));
	*returnColumnSizes = (int*)calloc(val, sizeof(int));
       
    if(returnColumnSizes == NULL || ret == NULL)
        return NULL;
    
    ret[0] = NULL;
    (*returnColumnSizes)[ (*returnSize)++] = 0;
   
    for(int i =1; i <val; i ++)
    {
        int count =0;
        for(int j = 0; j < numsSize && ( (1<<j)<=i); j++)
        {
            if(i & (1<<j) && ( (1<<j)<=i))
            {
               count++; 
               ret[(*returnSize)]  = realloc(ret[(*returnSize)], count*sizeof(int));
               int y = numsSize -1-log2(1<<j);
               ret[(*returnSize)][count -1] = nums[y]; 
            }
        }
        (*returnColumnSizes)[ (*returnSize)++] = count;
    }
 
    return ret;
}
