

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

long factorial(long n )
{
    if(n == 0 || n ==1)
        return 1; 
    return n*factorial(n-1);
}
long permutation(long n, long r)
{
    return factorial(n) / factorial(n-r);
}

long combination(long n, long r)
{

    return permutation(n, r) / factorial(r);
}

void combineHelper(int* cur, int idx, int val, int count, int k, int n, int* returnSize, int** ret, int** returnColumnSizes)
{
    if(cur == NULL || returnSize == NULL || ret == NULL || returnColumnSizes == NULL || count>k || idx > k)
        return; 
    
    if(count== k){
        
        ret[*returnSize]  = calloc(k, sizeof(int));
        if(ret[*returnSize] == NULL)
            return; 
        
        memcpy(ret[*returnSize], cur, sizeof(int)*k);
        (*returnColumnSizes)[(*returnSize)++]= k;
        
        return; 
    }
    
    
     for(int i =val; i <=n; i++)
    {
        cur[idx] = i; 
            
        combineHelper(cur, idx+1, i+1, count+1, k, n, returnSize, ret, returnColumnSizes);
        cur[idx] = 0;
        
    }
    
    
    
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes){
    
      *returnSize = 0; 
       if(n == 0 || k == 0 || k>n)
           return NULL; 
    
    //Total combinations == nCk
    
    long size = combination(n, k);
    
    
    int**ret = (int**)calloc(size, sizeof(int*));
     *returnColumnSizes = (int*)calloc(size, sizeof(int));
    if(ret == NULL || *returnColumnSizes == NULL)
        return NULL; 
    int* tmp = (int*)calloc(k, sizeof(int));
    if(tmp == NULL)
        return NULL; 
    int idx = 0; // 1. 2 3 4
    for(int i =1; i <=n-k+1; i++)
    {
        tmp[idx] = i; 
            
        combineHelper(tmp, idx+1, i+1,  1, k, n, returnSize, ret, returnColumnSizes);
        tmp[idx] = 0;
        
    }
    

    return ret; 
}
