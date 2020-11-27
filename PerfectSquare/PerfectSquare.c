int min(int a, int b)
{
    return (a<b?a:b);
}

int FindSquares(int n, int* dpsqr, int* dpidx)
{
    if(dpsqr == NULL || dpidx == NULL)
        return INT_MIN;
     int idx =sqrt(n)+1;
    for(int i = 1; i<= n; i++)
    {
        for(int j = 1; j<idx; ++j )
        {
            if(i< dpsqr[j])
                break;
            dpidx[i] = min(dpidx[i], dpidx[i-dpsqr[j]]+1);
          
        }
     }   
    return dpidx[n];
}


int numSquares(int n)
{
    int* dpsqr = (int*)calloc(sqrt(n)+1, sizeof(int));
    int* dpidx = (int*)calloc(n+1, sizeof(int));
    
    if(dpsqr ==NULL || dpidx == NULL )
        return -1;
    dpidx[0] = 0;
    int idx =sqrt(n)+1;
    for(int i = 1; i<idx; ++i)
         dpsqr[i] = i*i;
     for(int i = 1; i<n+1; ++i)
         dpidx[i] = INT_MAX;
   return FindSquares(n, dpsqr, dpidx);
}
