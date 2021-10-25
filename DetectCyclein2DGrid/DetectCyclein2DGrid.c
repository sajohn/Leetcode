bool isValid (int i , int j, int gridSize, int gridColSize){
     if((i< 0 || i>=gridSize ) || (j <0 || j>=gridColSize))
         return false; 
    return true; 
    
}


bool DFS(char** grid, int i , int j, int gridSize, int gridColSize, char c, int prev_i, int prev_j){
    
    if(grid == NULL || gridSize== 0 || gridColSize == 0  || !isValid(i, j, gridSize, gridColSize)  || (grid[i][j] == '#'))
          return false; 
    
    
     if(grid[i][j] == '$' ) return true; 
     if(grid[i][j] != c ) return false; 

    
     grid[i][j] = '$';  //Processing
   
    bool res = false; 

        if( i != prev_i || j+1 != prev_j)
            res |= DFS(grid, i, j+1, gridSize, gridColSize, c, i, j);
        
           if( i != prev_i || j-1 != prev_j)
            res |=DFS(grid, i, j-1, gridSize, gridColSize, c, i, j);
           
     
        if( i-1!= prev_i || j != prev_j)
            res |= DFS(grid, i-1, j, gridSize, gridColSize, c, i, j);
        
     

       if( i+1 != prev_i || j != prev_j)
            res |= DFS(grid, i+1, j, gridSize, gridColSize, c, i, j);
    
     grid[i][j] = '#';  //Processed this node and nothing can be done....
    
     return res; 
}

bool containsCycle(char** grid, int gridSize, int* gridColSize){

    if(grid == NULL || gridSize== 0 || gridColSize == NULL)
        return false; 

    for(int i = 0; i < gridSize; i++){
        for(int j = 0; j < *gridColSize; j++)
        {
            
            if( DFS(grid, i, j, gridSize, *gridColSize, grid[i][j] , -1, -1))
                     return true; 
              
        }
    
    }
  return false;   
}
