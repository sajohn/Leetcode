

/**
 * Note: The returned array must be malloced, assume caller calls free().

 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
      
    *returnSize = 0;   
    if(matrix == NULL || matrixColSize == NULL )
        return NULL; 

    int* ret = (int*)calloc(matrixSize*(*matrixColSize), sizeof(int));
    if(ret == NULL)
        return NULL; 
    
    
    int startRowidx=0, endRowidx = matrixSize-1, startColidx=0, endColidx =*matrixColSize-1, val =0; 

    
    while(startRowidx <= endRowidx && startColidx <= endColidx)
    {
        
        for(int i = startColidx; i <= endColidx; i++)
            ret[val++] = matrix[startRowidx][i];
            
        for(int j = startRowidx+1; j <=endRowidx; j++)
            ret[val++] = matrix[j][endColidx];
        
        if(startRowidx < endRowidx && startColidx < endColidx)
        {
            for(int i = endColidx-1; i >startColidx; i--)
              ret[val++] = matrix[endRowidx][i];
            
           for(int j = endRowidx; j >startRowidx; j--)
             ret[val++] = matrix[j][startColidx];
        
        }
        startRowidx++;
        startColidx++;
        endRowidx--;
        endColidx--;
            
    }
        
    *returnSize = (matrixSize*(*matrixColSize));
    return ret; 
}
