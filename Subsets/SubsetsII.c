
void CreateSubset(int* nums, int numsSize, int* returnSize, int** returnColumnSizes, int** ret, int idx, int** subset){ 
    
    //Add to result 
    if(*returnSize == 0)
    {
        ret[*returnSize] = NULL;
        (*returnColumnSizes)[ (*returnSize)++] = 0;
    }else
    {
        ret[*returnSize] = (int*) calloc(idx,sizeof(int));
        if(! ret[*returnSize])
            return ;
        int count =0; 
        for(int i =0; i<idx; i++)
            if( (*subset)[i] != 0xFFFFFFF8)
                ret[*returnSize][ count++] = (*subset)[i];
    
        //ret[*returnSize] = (int*)realloc( ret[*returnSize], (count)*sizeof(int));
        (*returnColumnSizes)[ (*returnSize)++] = count;
    }
    
    for(int i = idx; i< numsSize; i++)
    {
        *subset = (int*)realloc(*subset, (i+1 )*sizeof(int));
      
        (*subset)[idx]  = nums[i];
       
        CreateSubset(nums, numsSize, returnSize, returnColumnSizes, ret, i+1, subset);
        (*subset)[idx] = 0xFFFFFFF8;
        //*subset = (int*)realloc(*subset, (i)*sizeof(int));
    }
    
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){ 
    
     *returnSize = 0;
    
    if( !nums || numsSize == 0)
        return NULL;
      
    int val = (1<<numsSize);  //Total size of set would be 2^N
    
	int** ret = (int**)calloc(val, sizeof(int*));
	*returnColumnSizes = (int*)calloc(val, sizeof(int));
       
    if(returnColumnSizes == NULL || ret == NULL)
        return NULL;
 
    int* subset = NULL;
       
    CreateSubset(nums, numsSize, returnSize, returnColumnSizes, ret, 0, &subset);
  
    return ret;
}
    
    
