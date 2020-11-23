int min(int a , int b)
{
    return (a<b? a:b);
}

int findMinValue(int** grid, int **lp, int r, int c)
{
    if(lp == NULL || r< 0 || c< 0 )
        return 0;

       *(*(lp+0)+0) = grid[0][0];
            
    for(int i= 1; i<r; i++ )
            *(*(lp+i)+0) =    *(*(lp+(i-1))+0) + grid[i][0];

     for(int j= 1; j<c; j++ )
        *(*(lp+0)+j) =  *(*(lp+0)+(j-1))+ grid[0][j];
    

    for(int i= 1; i<r; i++ )
    {
     for(int j= 1; j<c; j++ )
     {
         *(*(lp+i)+j) = min( *(*(lp+(i-1))+j) , *(*(lp+i)+(j-1))) + grid[i][j];
     }
    }

    return lp[r-1][c-1];
}


int minPathSum(int** grid, int m, int* n){
    
      if(m== 0 || n == NULL ||*n ==0)
        return 0;


  int val = 0, min =0;
  int**lp = (int**)calloc(m, sizeof(int*));
    if(!lp)
      return 0;
    

  for(int j =0; j<m; j++){
      lp[j] = (int*)calloc(*n, sizeof(int));
      if(!lp[j])
         return 0;
  }

    val =  findMinValue(grid, lp, m, *n);

    for(int j =0; j<m; j++){
     free(lp[j]);
        lp[j] = NULL;
    }
    free(lp);

   return val; 
    
}
