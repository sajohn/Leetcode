

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
 
 *returnSize = 0;
    
 int left =0, right = ASize -1, tmp =0;
 int* result = (int*)calloc(ASize, sizeof(int));
    if(result == NULL)
        return NULL; 
    
    
 for(int i =ASize-1; i >=0; i--)
 {
     tmp=0;
     
    if(abs(A[left]) < abs(A[right]) ) {
        tmp = A[right];
        right--;
    }
    else {
        
          tmp = A[left];
        left++;
        
    }
     result[i] = tmp*tmp;
 }
    *returnSize = ASize;
    return result;
  
}
