

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int max (int a , int b)
{
    return (a>b? a: b);
    
}

int* findBuildings(int* heights, int heightsSize, int* returnSize){
    
    *returnSize = 0; 
    if(heights == NULL || heightsSize == 0)
        return NULL; 
    
    int maxsofar = -1, stack[heightsSize], idx = -1;
    int* ret = (int*)calloc(heightsSize, sizeof(int));
    
    for(int i = heightsSize-1; i>=0; i--)
    {   
        if(heights[i]>maxsofar){
            ret[heightsSize  - 1- (*returnSize)] = i;
            (*returnSize)++;
        
         maxsofar = max(heights[i], maxsofar);
        }
        
    }
  if((*returnSize) < heightsSize)
      memmove(ret, &ret[heightsSize - (*returnSize)], sizeof(int)*(*returnSize));
  
    return ret; 

}
