

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

//Column size is actually the size of row for which you are calculating col size... so its row[0] column size 
//which is same as size of mat2 column...
int** multiply(int** mat1, int mat1Size, int* mat1ColSize, int** mat2, int mat2Size, int* mat2ColSize, int* returnSize, int** returnColumnSizes){
    
    *returnSize = 0; 
    if(mat1 == NULL || mat2 == NULL || mat1Size == 0 || mat2Size == 0 || mat1ColSize ==NULL || mat2ColSize == NULL)
        return NULL; 
    
    
    int** ret = (int**)calloc(mat1Size, sizeof(int*));
     (*returnColumnSizes) = (int*)calloc(mat1Size, sizeof(int));
    if(ret == NULL || (*returnColumnSizes) == NULL )
        return NULL; 
    
    for(int i =0; i < mat1Size; i++){
        ret[i] = (int*)calloc((*mat2ColSize), sizeof(int));
        
        if(ret[i] == NULL)
            return NULL; 
        (*returnColumnSizes)[i] = (*mat2ColSize);
    }
    
    
    for(int i =0; i < mat1Size; i++){
         for(int j =0; j < (*mat2ColSize); j++){
             
             for(int k = 0; k< (*mat1ColSize); k++){
                 if(mat1[i][k] == 0 ||  mat2[k][j] == 0)
                     continue; 
               ret[i][j] += (mat1[i][k] * mat2[k][j]);
             }
         
         }
         (*returnSize)++;

    }
  
    return ret; 
}


