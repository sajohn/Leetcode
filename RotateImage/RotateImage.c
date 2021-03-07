void Transpose(int** matrix, int matrixSize, int* matrixColSize)
{
    int tmp =0; 
    for(int i =0; i <  matrixSize ; i++)
    {
         for(int j =i; j < *matrixColSize; j++)
         {
             tmp =  matrix[j][i];
             matrix[j][i] =  matrix[i][j];
             matrix[i][j] = tmp;  
         }
    }

}
    
void Reflect(int** matrix, int matrixSize, int* matrixColSize)
{
    int tmp =0; 
     for(int i =0; i < matrixSize; i++)
    {
         for(int j =0; j < (*matrixColSize)/2; j++)
         {
            tmp = matrix[i][j];
             matrix[i][j] =  matrix[i][*matrixColSize-j-1];
             matrix[i][*matrixColSize-j-1] = tmp;
         }
    }
    
}


void rotate(int** matrix, int matrixSize, int* matrixColSize){
    
    if(matrix == NULL || matrixSize == 0 || matrixColSize == NULL)
        return ;
    
    Transpose(matrix, matrixSize,matrixColSize);
    Reflect(matrix, matrixSize,matrixColSize);
}
