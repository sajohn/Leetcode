
/*
    if any cell was supposed to die make it -1 but for next cell count -1 as a contributor as well. 
    
*/


bool isValid(int i, int j, int boardSize, int boardColSize)
{
    if((i>=0 && i<boardSize) && (j>=0 && j < boardColSize))
        return true; 
    
    return false;
}


void ShouldDie(int** board,  int boardSize, int boardColSize, int i , int j){
    
    if(board == NULL ||  boardSize==0 || boardColSize ==0)
        return false; 
    int count = 0;
 
        
        if(isValid(i, j+1, boardSize, boardColSize)){
            if(board[i][j+1] == 1 || board[i][j+1] == -1)
                count++;
        }
        if(isValid(i, j-1, boardSize, boardColSize)){
             if(board[i][j-1] == 1 || board[i][j-1] == -1)
                count++;
        }
        if(isValid(i-1, j+1, boardSize, boardColSize)){
            if(board[i-1][j+1] == 1  || board[i-1][j+1] == -1)
                count++;
        }
        
        if(isValid(i-1, j-1, boardSize, boardColSize)){
            if(board[i-1][j-1] == 1 || board[i-1][j-1] == -1)
                count++;
        }
        
        if(isValid(i-1, j, boardSize, boardColSize)){
             if(board[i-1][j] == 1 || board[i-1][j] == -1)
                count++;
        }
        
        if(isValid(i+1, j+1, boardSize, boardColSize)){
              if(board[i+1][j+1] == 1 || board[i+1][j+1] == -1)
                count++;
        }
        if(isValid(i+1, j-1, boardSize, boardColSize)){
              if(board[i+1][j-1] == 1 || board[i+1][j-1] == -1)
                count++;
        }
        if(isValid(i+1, j, boardSize, boardColSize)){
             if(board[i+1][j] == 1 || board[i+1][j] == -1)
                count++;
        }
        
       if(board[i][j] == 1 && (count <2 || count>3)){
           board[i][j] = -1;
       }

        if(board[i][j] == 0 && count == 3){
           board[i][j] = 2;
       }
}

void gameOfLife(int** board, int boardSize, int* boardColSize){

     if(board == NULL ||  boardSize==0 || boardColSize ==NULL)
        return ; 
    
    for(int i =0; i < boardSize; i++)
    {
        for(int j =0; j < *boardColSize; j++){
            if(board[i][j] !=2 || board[i][j]!= -1) 
              ShouldDie(board, boardSize, *boardColSize, i, j);
        }
    }
    for(int i =0; i < boardSize; i++)
    {
        for(int j =0; j < *boardColSize; j++){
            if(board[i][j] == -1 )
                board[i][j] = 0; 
            if(board[i][j] == 2 )
                board[i][j] = 1; 
        }
    }
    
}
