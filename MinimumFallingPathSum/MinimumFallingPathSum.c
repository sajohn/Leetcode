int min(int a, int b, int c)
{
    return ((a>b)?(b>c?c:b):(a>c? c:a) );
}

int minFallingPathSum(int** matrix, int matrixSize, int* matrixColSize){

    if( matrix == NULL ||   matrixSize==0 ||  matrixColSize == NULL)
        return INT_MIN;
      
    int** dp = (int**)calloc(matrixSize, sizeof(int*));
    
    if(dp == NULL)
        return INT_MIN;
    
    for(int i=0; i < matrixSize; i++){
        dp[i] = calloc(*matrixColSize, sizeof(int));
                if(dp[i] == NULL)
                    return INT_MIN;
    }
    int minsum =INT_MAX; 
    
     for(int j =0; j< matrixColSize[matrixSize -1]; j++){
         dp[matrixSize -1][j] = matrix[matrixSize -1][j];
         if(matrixSize ==1)
              if(dp[matrixSize -1][j] < minsum)
                  minsum = dp[matrixSize -1][j];
     }
    
    for(int i = matrixSize -2; i >=0; i--)
    {
       for(int j =0; j< matrixColSize[i]; j++) {
           
         dp[i][j] = matrix[i][j] + min(dp[i+1][j], dp[i+1][((j-1)<0?0: (j-1))], dp[i+1][(j+1 >= matrixColSize[i] )? j:j+1] );
         
            if(i == 0) {
                if(dp[i][j] < minsum)
                  minsum = dp[i][j];
           }
        }
    }
    
return minsum; 
}
