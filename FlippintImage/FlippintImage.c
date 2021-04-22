

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** flipAndInvertImage(int** image, int imageSize, int* imageColSize, int* returnSize, int** returnColumnSizes){

    
    *returnSize = 0; 
    if(image == NULL || imageSize== 0 || imageColSize == NULL){
        return NULL; 
    }
    
    int start =0, end = (*imageColSize)-1, i=0, col =0;
    
     *returnColumnSizes = calloc(*imageColSize, sizeof(int));
    
    while(start <= end)
    {
       for(i = 0; i < imageSize; i++)
       {  
           int tmp = image[i][start];
         
           image[i][start] = image[i][end] ^1;
            
           image[i][end] = tmp^1;
           if( (*returnColumnSizes)[i] ==0)
            (*returnColumnSizes)[i] = *imageColSize;   
       }
       
        start++; 
        end--;
    }
   
  
    *returnSize = imageSize;
    return image; 
}
