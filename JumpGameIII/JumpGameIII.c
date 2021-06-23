int helper(int *arr , int n, int sindex, int* visited){
    int left = 0, right =0;
    if( sindex > n-1 || sindex < 0  )
        return 0;
    
    if(arr[sindex] == 0){
        return 1;
    visited[sindex] == 1; 
    }
  else{
    
    if( (sindex + arr[sindex] <= n-1) && (sindex + arr[sindex] >= 0) ) {

               if(visited[sindex + arr[sindex]] == 1){
                   right = 0; 
                
            }else{
                 visited[sindex + arr[sindex]] = 1;    
                right = helper(arr , n, sindex + arr[sindex], visited);
               
                
                }
                  
    }

    if( (sindex - arr[sindex] >= 0) && (sindex - arr[sindex] <= n-1)) {
             if(visited[sindex - arr[sindex]] == 1){
                   left = 0; 
         }
             else{
                    visited[sindex - arr[sindex]] = 1; 
            left = helper(arr , n, sindex - arr[sindex], visited);
          
             }
    }
    if(left == 1 || right == 1)
            return 1;
  
  }
    
    return 0;
}


bool canReach(int* arr, int arrSize, int start){
    
    if(arr == NULL || arrSize == 0)
        return 0;
int* visited = (int*)calloc(arrSize, sizeof(int));
    if(visited == NULL)
        return false; 
    
    return  helper( arr, arrSize, start, visited); 
}


