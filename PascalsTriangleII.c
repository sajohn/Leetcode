

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* generate(int numRows, int* returnSize){
    
    *returnSize =0; 
    if(numRows == 0)
      return NULL;
    int** ret = (int**)calloc(numRows, sizeof(int*));
    if(ret == NULL)
        return NULL;

    for(int i=0; i < numRows; i++) {
        ret[i] = (int*)calloc(i+1, sizeof(int));
        
        ret[i][0] = ret[i][i] = 1;
    }
    
    for(int i=2; i<numRows; i++){
      int j =1;
        while(j< i){
            ret[i][j] = ret[i-1][j-1] + ret[i-1][j]; 
            j++;
        }
    }
    *returnSize = numRows; 
    return ret[numRows-1];  
}

int* getRow(int rowIndex, int* returnSize){

    if(rowIndex <0)
        return NULL;
    
    return generate(rowIndex+1, returnSize);
}
