struct BoardHash
{
    int val; 
    int* row; 
    int* col; 
    int count;
    UT_hash_handle hh;
};

void deleteHash(struct BoardHash **g_user)
{
     struct BoardHash *element= NULL, *s;
     HASH_ITER(hh, *g_user, element, s) {
     HASH_DEL(*g_user, element);  /* delete it (users advances to next) */
    free(element);             /* free it */
  }
}
bool isValidSudoku(char** board, int boardSize, int* boardColSize){

    if(board== NULL || boardSize == 0 || boardColSize == NULL)
        return false; 
    
    
    struct BoardHash *g_user = NULL, *element= NULL, *s;
    
    
    for(int i= 0; i< boardSize; i++)
    {
        for(int j =0; j< *boardColSize; j++)
        {
            
            if(board[i][j]!= '.' && (board[i][j]-'0'> 0 && board[i][j]-'0'<=9) )
            {
                int x = board[i][j]-'0';
                 HASH_FIND_INT(g_user, &x, element);
                
                   if(element)
                   {
                       for(int k = 0; k < element->count; k++)
                       {
                        if((element->row[k] == i || element->col[k] == j) ||
                           ((i/3)*3+ (j/3) ) == ((element->row[k]/3)*3+(element->col[k]/3)))
                        {
                            deleteHash(&g_user);
                            return false;
                        }
                            
                       }
                       element->count++;
                       element->row = (int*)realloc(element->row, element->count*sizeof(int));
                       element->col = (int*)realloc(element->col, element->count*sizeof(int));
                       element->row[element->count-1] = i; 
                       element->col[element->count-1] = j; 
                    }
                   else
                   {
                    element = (struct BoardHash*)calloc(1, sizeof(*element));
                    if(element == NULL)
                        return false; 
                    
                    element->val = board[i][j]-'0';
                    element->count++;
                    element->row = (int*)calloc(element->count, sizeof(int));
                    element->col = (int*)calloc(element->count, sizeof(int));
                       
                    element->row[element->count-1] = i; 
                    element->col[element->count-1] = j; 
                 
                    HASH_ADD_INT(g_user,val, element);
                 }
            }
        }
        
    }
     deleteHash(&g_user);
    return true;
    
}
