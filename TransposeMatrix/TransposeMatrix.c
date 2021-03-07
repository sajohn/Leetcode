

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */


void Transpose(int** matrix, int matrixSize, int* matrixColSize, int** ret)
{ 
    int tmp =0;
    for(int i =0; i <  matrixSize ; i++)
    {
         for(int j =0; j < *matrixColSize; j++)
         {
             ret[j][i] =  matrix[i][j];
         }
    }

}

int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes)
{
    *returnSize = 0; 
    
    if(matrix == NULL || matrixColSize == NULL)
        return NULL; 
    
    int** ret = (int**)calloc((*matrixColSize),sizeof(int*));
    if(ret == NULL)
        return NULL;
    
    (*returnColumnSizes) = (int*)calloc((*matrixColSize), sizeof(int));
    
    if( (*returnColumnSizes) == NULL)
        return NULL; 
    
    for(int i =0; i < (*matrixColSize); i++) {
        (*returnColumnSizes)[i] = matrixSize;
        ret[i] = (int*)calloc((matrixSize), sizeof(int));
     }
    
  *returnSize = *matrixColSize;
  Transpose(matrix, matrixSize, matrixColSize, ret);
  
    
    
    
    
    return ret;
    
}
