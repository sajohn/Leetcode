
int findmin(int a, int b , int c){
    
    return (a>b?(b>c? c: b):(a>c? c:a));
}

int countSquares(int** matrix, int matrixSize, int* matrixColSize){

    if(matrix == NULL || matrixSize == 0 || *matrixColSize ==0 )
        return INT_MIN;
    
    int sum = 0;
    
    int** tmp = (int**)calloc(matrixSize, sizeof(int*));
    if(tmp == NULL)
        return INT_MIN; 
    
    for(int i=0; i < matrixSize; i++){
        tmp[i] = calloc(*matrixColSize, sizeof(int));
            if(tmp[i] == NULL)
                return INT_MIN;
    }
    
     for(int i=1; i < *matrixColSize; i++){
         if(matrix[0][i] == 1){
             tmp[0][i] = 1;
             sum+= 1;
         }
    }

     for(int i=0; i < matrixSize; i++){
         if(matrix[i][0] == 1){
             tmp[i][0] = 1;
             sum+= 1;
         }
     }
     for(int i=1; i < matrixSize; i++){
       for(int j=1; j < *matrixColSize ; j++){
           if(matrix[i][j] == 1) {
              tmp[i][j] = findmin(tmp[i-1][j], tmp[i-1][j-1], tmp[i][j-1])+ matrix[i][j];
              sum +=tmp[i][j];
           }
       }
     }
   for(int i=0; i < matrixSize; i++)
        free(tmp[i]);
       
    free(tmp);
    return sum; 
}
