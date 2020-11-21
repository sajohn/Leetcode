
typedef struct {
    int row;
    int col;
    int **matrix;
} NumMatrix;

bool isValid(int row1, int col1, int row2, int col2, NumMatrix* obj)
{
    if(!obj || row1 >=0 && row1<obj->row && 
               row2 >=0 && row2<obj->row && 
               col1 >=0 && col1<obj->col && 
               col2 >=0 && col2<obj->col &&
               row1<= row2 && col1 <= col2)
            {
               return true;
            }
return false;
}

NumMatrix* numMatrixCreate(int** matrix, int matrixSize, int* matrixColSize) {
    
  if(!matrix || matrixSize ==0 || !matrixColSize)
    return NULL;
    
   NumMatrix* obj = (NumMatrix*)malloc(sizeof(NumMatrix));
    if(!obj)
        return NULL;
    
    obj->row = matrixSize;
    obj->col = *matrixColSize;
    obj->matrix = matrix;
    
   return obj;
}

int numMatrixSumRegion(NumMatrix* obj, int row1, int col1, int row2, int col2) {
    
    if(obj == NULL || row1 > row2 || col1> col2)
    {
        return 0;
    }
  int sum =0; 
    //if(isValid(row1, col1, row2, col2, obj))
    {
           for(int i= row1; i<=row2; i++)
               for(int j = col1; j<=col2; j++)
               {
                   //printf("% d ",obj->matrix[i][j]);
                   sum += obj->matrix[i][j];
               }
               
    }
    return sum;
}

void numMatrixFree(NumMatrix* obj) {
    if(obj)
        free(obj);
    obj = NULL;
}

/**
 * Your NumMatrix struct will be instantiated and called as such:
 * NumMatrix* obj = numMatrixCreate(matrix, matrixSize, matrixColSize);
 * int param_1 = numMatrixSumRegion(obj, row1, col1, row2, col2);
 
 * numMatrixFree(obj);
*/
