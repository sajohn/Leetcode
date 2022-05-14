

int findValue(int **lp, int r, int c, int** grid)
{
    if(lp == NULL || r< 0 || c< 0 )
        return 0;
    
    for(int i= 1; i<r; i++ ) {
        if(grid[i][0]!= 1  && (i>0 && lp[i-1][0]!= 0))
           lp[i][0]= 1;
        else
          lp[i][0]= 0;
    }
     for(int j= 1; j<c; j++ ) {
        if(grid[0][j]!= 1 && (j>0 && lp[0][j-1]!= 0))
           lp[0][j]= 1;
        else
         lp[0][j] = 0; 
    }

    for(int i= 1; i<r; i++ ) {
     for(int j= 1; j<c; j++ ) {
         //Because the are asking for total path........
         lp[i][j] = grid[i][j]== 1? 0: lp[i-1][j] + lp[i][j-1];
     }
    }
 // printf("%d ", lp[r-1][c-1]);
    return lp[r-1][c-1];
}



int uniquePathsWithObstacles(int** grid, int m, int* n) {
    
    if(m== 0 || *n == 0)
        return 0;
    
  if(grid[0][0] == 1)
        return 0; 
 
  int val = 0;
  int**lp = (int**)malloc(sizeof(int*)*m);
  if(!lp) {
      return 0;
    }
  
  for(int j =0; j<m; j++){
      lp[j] = (int*)malloc(sizeof(int)*(*n));
      if(!lp[j])
       return 0;
  }
     
  
    lp[0][0] = 1; //There is a one way to be at start. if its not 1.
    val =  findValue(lp, m, *n, grid);
    
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
