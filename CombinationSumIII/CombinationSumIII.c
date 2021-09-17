
void Dfs(int* candidates, int candidatesSize, int k, int target, int* returnSize, int** returnColumnSizes, int** ret, int* cur, int idx, int curidx) {
    
    if(candidates == NULL || candidatesSize == 0 || returnSize == NULL || returnColumnSizes == NULL)
        return ; 
    
    if(target <= 0 ){ 
    
        if(target == 0 && curidx == k)
        {
          
           ret[*returnSize] = (int*)calloc(curidx, sizeof(int));
           memcpy(ret[*returnSize], cur, sizeof(int)*(curidx));
           (*returnColumnSizes)[(*returnSize)++] = curidx;  
             return; 
        }
    }
 


    for(int i =idx; i < candidatesSize; i++)
    {
        if(target -candidates[i]<0)
            continue; 
        cur[curidx++] = candidates[i];    
        Dfs(candidates, candidatesSize, k, target- candidates[i], returnSize, returnColumnSizes, ret, cur, i+1, curidx);
        cur[--curidx] = 0;//clean/backtrack
    }
       

  
}

#define MAX 150


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes){
    *returnSize = 0; 
    int* candidates = (int*)calloc(9, sizeof(int));
    
    if(candidates == NULL|| returnSize == NULL || returnColumnSizes == NULL)
        return NULL; 
    
    int** ret = (int**) calloc(MAX, sizeof(int*));
    if(ret == NULL)
        return NULL; 
    *returnColumnSizes = (int*) calloc(MAX, sizeof(int));
    if(returnColumnSizes == NULL)
        return NULL; 

    int* cur = (int*)calloc(9, sizeof(int)); 
    
    for(int i=0; i <9; i++ )
        candidates[i] = i+1; 
    
    Dfs(candidates, 9, k, n, returnSize, returnColumnSizes, ret, cur, 0, 0);
   
   free(cur); 
    return ret; 
}

