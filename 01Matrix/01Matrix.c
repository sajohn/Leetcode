

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

bool   isValid(int r, int c, int row, int col)
{
    if((r>=0 & r< row ) && (c >=0 && c<col))
        return true; 
    
    return false; 
}
int Min(int a, int b)
{
    return (a< b? a:b);
}
int FindMinTopLeft(int** mat, int r, int c, int row, int col)
{
    
    if(isValid(r, c, row, col) && mat[r][c] == 0)
        return 0; 
    
    int top = INT_MAX-1, left = INT_MAX-1; 
    
      if(isValid(r-1, c, row, col)  )
          top =  mat[r-1][c];//, mat[r][c-1]//FindMinTopLeft(mat, r-1, c, row, col);
    
      if(isValid(r, c-1, row, col))
          left = mat[r][c-1];//FindMinTopLeft(mat, r, c-1, row, col);
          
          return (Min(top, left));
    
}

int FindMinBottomRight(int** mat, int r, int c, int row, int col)
{
   if( isValid(r, c, row, col) && mat[r][c] == 0)
        return 0; 
    
    int bottom = INT_MAX-1, right = INT_MAX-1; 
    
      if(isValid(r+1, c, row, col))
          bottom =  mat[r+1][c];//FindMinBottomRight(mat, r-1, c, row, col);
    
      if(isValid(r, c+1, row, col))
          right = mat[r][c+1];//FindMinBottomRight(mat, r, c+1, row, col);
          
          return (Min(bottom, right));
}

int** updateMatrix(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes){

    
    *returnSize =0; 
    if(mat == NULL || matColSize == NULL || matSize == 0)
        return 0; 
    
  
     *returnColumnSizes  = (int*)calloc(matSize, sizeof(int));
    
    if( (*returnColumnSizes)  == NULL)
        return NULL; 
 
    int** res = (int**)calloc(matSize, sizeof(int*));
    if(res == NULL)
        return NULL; 
    
    bool need = true; 

        for(int i=0; i < matSize; i++) {
            (*returnColumnSizes )[i] = *matColSize;
            res[i] = (int*)calloc(*matColSize, sizeof(int));
            if(res[i] == NULL)
                  return NULL; 
            
            for(int j=0; j < *matColSize; j++) {
                 if(mat[i][j]==0)
                    res[i][j] = 0; 
                else{
                res[i][j] = INT_MAX -1; 
                need = false; 
                }
            }
        }

    *returnSize = matSize; 
    if(need== true)
        return res; 
    
        for(int i=0; i < matSize; i++) {
            for(int j=0; j < *matColSize; j++) {
                if(mat[i][j]==0){
                    res[i][j] = 0; 
            } else {
                res[i][j] = Min(res[i][j],  FindMinTopLeft(res, i, j, matSize, *matColSize)+1);
                }
            }
        }

        for(int i=matSize-1; i >=0 ; i--) {
            for(int j=*matColSize -1; j >= 0; j--) {
                  res[i][j] =  Min(res[i][j],  FindMinBottomRight(res, i, j, matSize, *matColSize)+1);
            }
        }
          
    
   *returnSize = matSize; 
   return res;  
}
