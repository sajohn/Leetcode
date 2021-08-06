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

bool findRotation(int** mat, int matSize, int* matColSize, int** target, int targetSize, int* targetColSize){

      if(mat == NULL || matSize == 0 || matColSize == NULL || target == NULL || targetSize == 0 || targetColSize == 0)
        return false;
     
    int count = 0; 
    
     for(int ii =0; ii< 4; ii++) {
        for(int k = 0; k< matSize; k++) {
            
           if(memcmp(mat[k], target[k], (matSize)*sizeof(int)) == 0)
               count++;
            else
                break; 
            
            if(count == matSize)
                return true;
          } 
          rotate(mat, matSize, matColSize);
     }
        
    return false; 
}
