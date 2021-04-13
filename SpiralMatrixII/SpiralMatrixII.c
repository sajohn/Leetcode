

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
    
    *returnSize = 0; 
    if(n == 0)
        return NULL; 
   
     
    int** matrix = (int**)calloc(n, sizeof(int*));
    if(matrix == NULL )
        return NULL; 
    
     (*returnColumnSizes) = (int*)calloc(n, sizeof(int));
    
    for(int i =0; i < n; i++) {
        matrix[i] = (int*)calloc(n, sizeof(int));
        
        (*returnColumnSizes)[i] = n;
          if(matrix[i] == NULL )
            return NULL; 
    }
  
  *returnSize = n;    
  spiralOrder(matrix, n);
   return matrix; 
}


/**
 * Note: The returned array must be malloced, assume caller calls free().

 */
void spiralOrder(int** matrix, int n){
      

    int startRowidx=0, endRowidx = n-1, startColidx=0, endColidx =n-1, val =1; 
    
    while(startRowidx <= endRowidx && startColidx <= endColidx)
    {
        
        for(int i = startColidx; i <= endColidx; i++)
            matrix[startRowidx][i] = val++; 
            
        for(int j = startRowidx+1; j <=endRowidx; j++)
            matrix[j][endColidx] = val++;
        
        if(startRowidx < endRowidx && startColidx < endColidx)
        {
            for(int i = endColidx-1; i >startColidx; i--)
              matrix[endRowidx][i] = val++;
            
           for(int j = endRowidx; j >startRowidx; j--)
             matrix[j][startColidx] = val++;
        
        }
        startRowidx++;
        startColidx++;
        endRowidx--;
        endColidx--;
            
    }
        
    
}
