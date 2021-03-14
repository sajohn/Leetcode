//Idea was to go from 1,1 cordinate and look in all four directions to find out if any of the '0' is connected to corner '0'
//If so
void mark(char** board, int i, int j, int boardSize, int boardColSize)
{
 
       if( (i< 0 && i > boardSize-1) || ( j< 0 && j > boardColSize-1) || board == NULL)
          return ;

    if( board[i][j] == 'X')
        return; 
    
    board[i][j] = 'X'; 
                 
    mark(board, i-1, j, boardSize, boardColSize);  
    mark(board, i+1, j, boardSize, boardColSize); 
    mark(board, i, j-1, boardSize, boardColSize); 
    mark(board, i, j+1, boardSize, boardColSize); 
    
}

void dfs(char** board, int i , int j, int boardSize, int boardColSize, int** visited, int* seen)
{
      if( (i< 0 && i > boardSize-1) || 
          ( j< 0 && j > boardColSize-1) || 
          board == NULL || 
          visited == NULL || 
          seen == NULL) {
          return ;
      }
       if(board[i][j] == 'X' || visited[i][j] == 1){ 
        return ;
      }
    //This condition tells if current element is '0' at border and is connected to called '0'
    //Since we are calling from (1,1) or non border element it tells that we travelled here from inside
    //This means we have found connected '0' to inner '0'
      if(i<=0 || i >=boardSize -1 || j <=0 || j>=boardColSize-1){ 
          *seen = true; 
          return ;
      }
    
     visited[i][j] = 1; 
                 
    dfs(board, i-1, j, boardSize, boardColSize, visited, seen);  
    dfs(board, i+1, j, boardSize, boardColSize, visited, seen); 
    dfs(board, i, j-1, boardSize, boardColSize, visited, seen); 
    dfs(board, i, j+1, boardSize, boardColSize, visited, seen); 
    
}

void solve(char** board, int boardSize, int* boardColSize)
{
   //First mark all the Boundry '0' to '1' and check if they connect to any other '0' within but this approach  does't work since you need boundary to remain zero else inner connection won't work.
    
    if(board == NULL || boardSize <= 0 || boardColSize <= NULL)
        return; 
    
    
    int** visited = (int**)calloc(boardSize, sizeof(int*));
    if(visited == NULL)
        return;
    
   for(int i =0; i< boardSize; i++){
       visited[i]  = calloc(*boardColSize, sizeof(int));
       if(visited[i]  == NULL)
           return; 
   }
     //Each DFS put this as false untill corner connected '0' is not see.
      int seen = false;  
   
      for(int i =1; i< boardSize; i++){
         for(int j =1; j< *boardColSize; j++){
               if(board[i][j] == 'O' && visited[i][j] == 0){
                   seen = false; 
                   dfs(board, i, j, boardSize, *boardColSize, visited, &seen);
                   if(seen == false)
                       mark(board,i, j, boardSize, *boardColSize );
                   
                   seen = true; 
               }
         }
     }   
    
     for(int i =1; i< boardSize; i++)
       free(visited[i]);
         
    free(visited);
   
}
