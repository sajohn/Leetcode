bool isValid(int r, int c, int row, int col)
{
    
    if((r>=0 && r<row) && (c >=0 && c<col))
        return true; 
    return false; 
}
bool DFS(char** board, int boardSize, int* boardColSize, char * word, int row, int col, int wordidx, int wordlen){
    
    
  if(board == NULL || boardColSize == NULL || word == NULL  )
        return false; 
    int len = strlen(word);
    if (wordidx<0 || wordidx>len)
        return false; 

            if(isValid(row, col, boardSize, *boardColSize) && word[wordidx] == board[row][col] && board[row][col]>0 ){
              
                board[row][col] =- board[row][col]; 
                if(wordidx+1 == len)
                    return true; 
                
                if(DFS(board, boardSize, boardColSize, word, row+1, col, wordidx+1, len))
                      return true; 
                if(DFS(board, boardSize, boardColSize, word, row-1, col, wordidx+1, len))
                    return true; 
                if(DFS(board, boardSize, boardColSize, word, row, col+1, wordidx+1, len))
                    return true; 
                if(DFS(board, boardSize, boardColSize, word, row, col-1, wordidx+1, len))
                    return true; 
                board[row][col] =- board[row][col]; 
             }
            else
              return false; 
    
return false; 
}


bool exist(char** board, int boardSize, int* boardColSize, char * word){

    if(board == NULL || boardColSize == NULL || word == NULL)
        return false; 
    
    int len = strlen(word);
   
    
    int wordidx = 0; 
    for(int i =0; i < boardSize; i++){
        for(int j =0; j < *boardColSize; j++){
            if(word[wordidx] == board[i][j] &&  board[i][j] > 0 ){
              
                if(DFS(board, boardSize, boardColSize, word, i, j, wordidx, len) == true){
                    return true;
                }
            }
        }
    }
    
    return false; 
    
}
