

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int cmp(int* a, int* b)
{
    return ( (*(int*)a) - (*(int*)b)  );
}

int* sortedSquares(int* A, int ASize, int* returnSize)
{
    if(A== NULL || ASize ==0)
        return NULL;
    
   
    
    for(int i =0; i < ASize; i++)
        A[i] *=A[i];
        
        
          qsort(A, ASize, sizeof(int), cmp);
    
    *returnSize = ASize;
    
    return A;
  
}
