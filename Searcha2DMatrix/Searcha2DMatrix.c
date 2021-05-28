

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    
    
    
    if(matrix == NULL || matrixSize == 0 || matrixColSize == NULL)
        return false; 
    
  int left = 0,  right = matrixColSize[0] -1, row = 0; 
    
  for(int i = 0; i < matrixSize; i++) {
      
      if(matrix[i][matrixColSize[0] -1] >= target)
      {
          row = i; 
          break; 
      }
  }  
 int mid = 0; 

  while(left <= right){
      
      mid = left + (right -left)/2;
      
      if(matrix[row][mid] > target)
      { right = mid -1; }
      else if(matrix[row][mid] <target) {
          left = mid+1; }
      else if(matrix[row][mid] == target)
          return true; 
  }
    
    return false; 
}
