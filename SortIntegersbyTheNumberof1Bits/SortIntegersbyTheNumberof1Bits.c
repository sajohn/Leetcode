

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int B[256] = {0};

int cmp(int*a, int*b)
{
    
    int x = countBits(*a, &B);
    int y = countBits(*b, &B);
    
    if(x==y) return (*(int*)a)- (*(int*)b);  //This is clever, when bits are equal function should compare value
    else if(x>y) return 1;
    else return -1;
}


int countBits(int x, int* B)
{
    return B[x&0xff]+B[(x>>8)&0xff]+B[(x>>16)&0xff]+B[(x>>24)&0xff];
}

int* sortByBits(int* arr, int arrSize, int* returnSize)
{
    *returnSize =0;
    
    if(arr == NULL || arrSize == 0 )
        return NULL;

    *returnSize = arrSize; 
  
    for (int i = 0; i < 256; i++)
        B[i] = (i & 1) + B[i / 2];
     
    qsort(arr, arrSize, sizeof(int), cmp); 
   return arr; 
}
