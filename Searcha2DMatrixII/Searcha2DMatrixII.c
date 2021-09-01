

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    
    
    
    if(matrix == NULL || matrixSize == 0 || matrixColSize == NULL)
        return false; 
    
  for(int i = 0; i < matrixSize; i++ ) {
      
      if(matrix[i][matrixColSize[0] -1] < target || matrix[i][0] > target)
      {
         continue; 
      }

  int mid = 0, left = 0,  right = matrixColSize[0] -1, row = i;       
  while(left <= right){
      
      mid = left + (right -left)/2;
      
      if(matrix[row][mid] > target)
      { right = mid -1; }
      else if(matrix[row][mid] <target) {
          left = mid+1; }
      else if(matrix[row][mid] == target)
          return true; 
  }
   
   
}
    
    return false; 
}



// bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    
    
    
//     if(matrix == NULL || matrixSize == 0 || matrixColSize == NULL)
//         return false; 

//     int col =0, row = matrixSize -1;
//     while(row>=0 && col < *matrixColSize ){
        
//         if(matrix[row][col] <target)
//             col++;
//         else if(matrix[row][col] > target)
//             row--;
//         else
//             return true;
//     }
// return false; 
// }
