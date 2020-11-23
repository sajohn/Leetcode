
int findValue(int **lp, int r, int c)
{
    if(lp == NULL || r< 0 || c< 0 )
        return 0;
    
    for(int i= 0; i<r; i++ )
    {
            *(*(lp+i)+0) = 1;
   
    }
     for(int j= 0; j<c; j++ )
    {
        *(*(lp+0)+j) = 1;
    }

    for(int i= 1; i<r; i++ )
    {
     for(int j= 1; j<c; j++ )
     {
         *(*(lp+i)+j) = *(*(lp+(i-1))+j) + *(*(lp+i)+(j-1));
     }
    }

    return lp[r-1][c-1];
}

int uniquePaths(int m, int n){
    
    if(m== 0 || n == 0)
        return 0;
    
    if(m ==1 || n ==1)
        return 1;
    
  int val = 0;
  int**lp = (int**)malloc(sizeof(int*)*m);
 
    if(!lp)
    {
      return 0;
    }
  
  for(int j =0; j<m; j++)
  {
      lp[j] = (int*)malloc(sizeof(int)*n);
      if(!lp[j])
       return 0;
  }
  
    val =  findValue(lp, m, n);
    
    for(int j =0; j<m; j++){   
     free(lp[j]);
        lp[j] = NULL;
    }
    
    if(lp) {
     free(lp);
     lp = NULL;
    }
  
    
return val;
}

