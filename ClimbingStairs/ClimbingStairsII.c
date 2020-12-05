int findstep(int n, int step)
{
    int result[n];
    memset(result, 0, sizeof(int)*n);
    
    result[0] =1;
    result[1] =1;
    
    for(int i = 2; i< n; i++)
    {
        result[i]  = 0;
      for(int j = 1; j<=step ; j++)
      {
          result[i] = result[i]+result[i -j];
      }
    }
    
    return result[n-1];
}
int climbStairs(int n)
{
    if(n <= 1)
       return 1;       
    
    return findstep(n+1, 2);   
}
   

