

bool checkValid(int** matrix, int matrixSize, int* matrixColSize){

    if(matrix == NULL || matrixSize == 0 || matrixColSize == NULL)
        return false; 
    
    
    for(int i =0; i < matrixSize; i++)
        for(int j =0; j < *matrixColSize; j++){
             if(matrix[i][abs(matrix[i][j])-1] <0)
                 return false; 
                matrix[i][abs(matrix[i][j])-1] = -matrix[i][abs(matrix[i][j])-1];
        }

        for(int j =0; j < *matrixColSize; j++)
        {
            for(int i =0; i < matrixSize; i++)
             {
                if(matrix[abs(matrix[i][j])-1][j] > 0 )
                     return false; 
                
                     matrix[abs(matrix[i][j])-1][j] = -matrix[abs(matrix[i][j])-1][j];
        }
       }
                

    return true; 
}
 
