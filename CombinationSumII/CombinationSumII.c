

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */



/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void Dfs(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes, int** ret, int* cur, int idx, int curidx) {
    
    if(candidates == NULL || candidatesSize == 0 || returnSize == NULL || returnColumnSizes == NULL)
        return ; 
    
    if(target <= 0 ){ 
    
        if(target == 0)
        {
           ret[*returnSize] = (int*)calloc(curidx, sizeof(int));
         
           memcpy(ret[*returnSize], cur, sizeof(int)*(curidx));
           (*returnColumnSizes)[(*returnSize)++] = curidx;  
             return; 
        }
    }
 
    for(int i =idx; i < candidatesSize; i++)
    {
 
        if(target -candidates[i]<0 || (i !=idx && candidates[i] == candidates[i-1]))
            continue; 
        
        cur[curidx++] = candidates[i]; 

        
        Dfs(candidates, candidatesSize, target- candidates[i], returnSize, returnColumnSizes, ret, cur, i+1, curidx);
        cur[--curidx] = 0;//clean/backtrack
       
    }
       

  
}
int cmp(void* val1, void* val2){

    return ( (*((int*)val1)) - (*((int*)val2)) );
}

#define MAX 150
int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    *returnSize = 0; 
    if(candidates == NULL || candidatesSize == 0 || returnSize == NULL || returnColumnSizes == NULL)
        return NULL; 
    
    int** ret = (int**) calloc(MAX, sizeof(int*));
    if(ret == NULL)
        return NULL; 
    *returnColumnSizes = (int*) calloc(MAX, sizeof(int));
    if(returnColumnSizes == NULL)
        return NULL; 

    int* cur = (int*)calloc(MAX, sizeof(int));
    
    qsort(candidates, candidatesSize, sizeof(int), cmp);

    Dfs(candidates, candidatesSize, target, returnSize, returnColumnSizes, ret, cur, 0, 0);
   
   free(cur); 
    return ret; 
}


