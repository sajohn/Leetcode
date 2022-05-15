bool isvalid(int row, int col,int grow, int gcol)
{
  if(col>=0 && col<gcol && row >=0 && row < grow)
      return true; 
    
    return false; 
}
            
void Helper(int** grid, int grow, int gcol, int row, int col, int* totalpath, int nonobstacles){
    
    
   if(!isvalid(row, col, grow, gcol) )
      return; 
    
      if(grid[row][col] == 2 && nonobstacles == 1){
         *totalpath += 1;
          return; 
      }
      
      /* Mark cell
         Travese
         Unmark cell
      
      */

     int rowoffset[4] = {0, 0, 1, -1};
     int coloffset[4] = {1, -1, 0, 0};
    

      int tmp = grid[row][col];
      grid[row][col] = -4; 
      nonobstacles--;
      for(int i =0; i < 4; i++){
          if(!isvalid(row+rowoffset[i], col+coloffset[i], grow, gcol))
              continue; 
          if(grid[row+rowoffset[i]][col+coloffset[i]] <0)
              continue; 
           
          Helper(grid, grow, gcol, row+rowoffset[i], col+coloffset[i], totalpath, nonobstacles);

      }
          
     grid[row][col] = tmp; 
}

int uniquePathsIII(int** grid, int gridSize, int* gridColSize){
    /*
    //The idea is that you need to check if you have covered the entire area...
    //That is done by counting all nonobstacles have been visited from start position 
    // 0 1 adn 2 are non obstacles. obstacles + nonobstacles = n
    // 
       You have to start from starting position and the move in all four directions....
       
       
       condition that counts path is 
       if(grid[i][j] == 2 and nonobstacles ==1)
         totalpath += 1;
         
    Before all this find the start position 
         
  */
    
    if(grid == NULL || gridSize == 0)
        return 0; 
    int nonobstacles = 0, startrow =0, startcol =0, totalpath =0; 
    
    for(int i =0; i < gridSize; i++){
        for(int j =0; j< *gridColSize; j++){
            
            if(grid[i][j] != -1){
                nonobstacles++;  //Counting 1 and 2 as well hence when we reach destination the nonobstacles should exactly be one  as it included start 
                if(grid[i][j]  == 1){
                    startrow = i; 
                    startcol = j; 
                }
                
            }
        }
    }
    
    
    //--nonobstacles because starrow and startcol accounted 1
    
    Helper(grid, gridSize, *gridColSize, startrow, startcol,&totalpath, nonobstacles);
    
    
    return totalpath; 
    
    
}
