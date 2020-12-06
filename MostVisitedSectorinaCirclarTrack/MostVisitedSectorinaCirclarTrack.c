

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct Count
{
    int count; 
    int sector;
};

int cmpfunc(void* a, void* b)
{
    struct Count* x = (struct Count*)a;
    struct Count* y = (struct Count*)b;
    
    return (y->count - x->count);
}
int cmpfuncInt(int* a, int* b)
{
    return (*a - *b);
}
int* mostVisited(int n, int* rounds, int roundsSize, int* returnSize)
{
    *returnSize =0;
    if(round == NULL || roundsSize ==0)
        return NULL;
    struct Count count[n]; 
    
    int max = INT_MIN, tmp1= 0, tmp2 =0;
    
    memset(count, 0, sizeof(struct Count)*n);
    
    int* ret = (int*)calloc(n, sizeof(int));
    if(ret == NULL)
        return NULL;
    
    for(int i = 0; i < roundsSize-1; i++)
    {
        tmp1 = rounds[i];
        tmp2 = rounds[i+1];
        while(tmp1%n !=tmp2%n )
        {
            count[tmp1%n].count++;
            count[tmp1%n].sector = (tmp1%n == 0? n:tmp1%n);
            tmp1++;
        }
        
    }
    //Last one
    count[tmp2%n].count++;
    count[tmp2%n].sector = tmp2%n;
    
      qsort(&count, n, sizeof(struct Count), cmpfunc);
       max = count[0].count;
    int k =0;
    bool fix = false;
    for(int i = 0; i < n; i++)
    {
        if(count[i].count >=max)
        {
            if(count[i].sector == 0)
            {
             fix = true;
             continue;
            }
            else
            {
                ret[k++] = count[i].sector;
                 (*returnSize)++;
            }
           
        }
        
    }
    if(fix)
    {
        ret[k] = n;
           (*returnSize)++;
    }
    
    qsort(ret, (*returnSize), sizeof(int), cmpfuncInt );
    return ret;
}

