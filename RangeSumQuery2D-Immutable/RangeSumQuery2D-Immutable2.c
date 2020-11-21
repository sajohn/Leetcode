



typedef struct {
    int row;
    int col;
    int **sum;
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
    obj->sum =  (int**)calloc(matrixSize, sizeof(int*));
    
    if(obj->sum == NULL)
        return NULL;
    
     for(int i= 0; i<matrixSize; i++)
     { 
         obj->sum[i] = (int*)calloc(*matrixColSize+1, sizeof(int));
        if(obj->sum[i] == NULL)
             return NULL;
        for(int j = 0; j<*matrixColSize; j++)
              obj->sum[i][j+1] = obj->sum[i][j]+matrix[i][j];

     }
   return obj;
}

int numMatrixSumRegion(NumMatrix* obj, int row1, int col1, int row2, int col2) {
    
    if(obj == NULL || row1 > row2 || col1> col2)
        return 0;
    
  int sum =0; 
    
           for(int i= row1; i<=row2; i++)
                   sum += (obj->sum[i][col2+1] - obj->sum[i][col1]) ;

    return sum;
}

void numMatrixFree(NumMatrix* obj) {
    if(obj)
    {
        int count =0;
        while(count <obj->row)
            free(obj->sum[count++]);
        
        free(obj->sum);
    }
    obj = NULL;
}

/**
 * Your NumMatrix struct will be instantiated and called as such:
 * NumMatrix* obj = numMatrixCreate(matrix, matrixSize, matrixColSize);
 * int param_1 = numMatrixSumRegion(obj, row1, col1, row2, col2);
 
 * numMatrixFree(obj);
*/
