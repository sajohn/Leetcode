

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize){
    *returnSize =0;
    
    if(mat == NULL || matSize== 0 || matColSize == NULL)
        return NULL; 
    
    int* ret = (int*)calloc(matSize*(*matColSize) , sizeof(int));
    int stack[matSize>(*matColSize)?matSize:(*matColSize)];
    if(ret == NULL)
        return NULL; 
    int sum = (matSize -1)+ (*matColSize -1), l = -1, up =0, i =0, j =0, k =0;
    
   while (i<= sum){
        j = (i>matSize-1? matSize-1: i);
        k = (i>matSize-1? i-j: 0);
       
        while((j>=0 && j< matSize) && (k>=0 && k < (*matColSize)) ){
            if(up ==0){
               ret[(*returnSize)++] = mat[j][k];
            }
            else{
                stack[++l] = mat[j][k];
            }
            j--; k++; 
        }
        if(up)
        {
            up = 0; 
            while(l >=0){
             ret[(*returnSize)++] = stack[l--];
            }
        }else 
        up =1;
        
        i++;
    }
    *returnSize = (*matColSize)*(matSize);
    return ret; 
}
