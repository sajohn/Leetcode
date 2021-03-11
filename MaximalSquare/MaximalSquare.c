int min(int a , int b, int c)
{
   return ((a< b? a:b) <c? (a< b? a:b): c );
}



int maximalSquare(char** matrix, int matrixSize, int* matrixColSize){

    if(matrix == NULL || matrixSize == 0 || matrixColSize == NULL)
        return 0; 
    int *arr[matrixSize]; 
    for (int i=0; i<matrixSize; i++) 
         arr[i] = (int *)calloc((*matrixColSize ), sizeof(int)); 
    
    int maxsqsize = 0; 
    for(int i = 0; i< matrixSize; i++){
         for(int j = 0; j< (*matrixColSize ); j++){
            if((i == 0 || j ==0) && matrix[i][j] == '1'){
               arr[i][j] =  1;
                maxsqsize =1;
            }
        }
    }
  
    
     for(int i = 1; i< matrixSize; i++){
        for(int j = 1; j< (*matrixColSize ); j++) {
           if(matrix[i][j] == '0')
           {
               arr[i][j] = 0;
           }
            else
            {
                 arr[i][j] = 1+ min((((i-1)>=0)? arr[i-1][j]: 0), 
                               (((j-1)>=0)? arr[i][j-1]: 0), 
                               (((i-1)>=0 && (j-1)>=0)? arr[i-1][j-1]: 0));
                if(maxsqsize < arr[i][j])
                    maxsqsize = arr[i][j];
            }
        }
     }
    
    for (int i=0; i<matrixSize; i++) 
         free(arr[i]);
    
    return maxsqsize*maxsqsize;
}
