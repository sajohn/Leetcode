
int Findmin(int** dp, int row , int col, int matrixSize, int* matrixColSize)
{
   int minval = INT_MAX, prev = 0; 
   for(int i = 0; i < matrixColSize[row]; i++) {  
       if(i != col){
            if(dp[row][i] < minval) {
                minval = dp[row][i];  
            }
         }
   }
return minval;
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
    int minsum = INT_MAX; 
   
     for(int j =0; j< matrixColSize[matrixSize -1]; j++){
         dp[matrixSize -1][j] = matrix[matrixSize -1][j];
         if(matrixSize ==1)  //1X1
              if(dp[matrixSize -1][j] < minsum)
                  minsum = dp[matrixSize -1][j];
     }
    
    for(int i = matrixSize -2; i >=0; i--)
    {
       for(int j =0; j< matrixColSize[i] ; j++) {
           
         dp[i][j] = matrix[i][j] + Findmin(dp, i+1, j, matrixSize, matrixColSize);
         
            if(i == 0) {
                if(dp[i][j] < minsum)
                  minsum = dp[i][j];
           }
        }
        free(dp[i+1]);
    }

    free(dp[0]);
    free(dp);
    
return minsum; 
}

