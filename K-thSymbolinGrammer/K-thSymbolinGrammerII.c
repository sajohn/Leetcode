void helper(int** arr, int idx, int size)
{
   if(idx < size) { 
    
       int val = (1<< idx);
       *arr = realloc(*arr, sizeof(int)* val);
    
    if(arr == NULL)
        return ;  
       
    for(int i = 0; i <val/2; i++)
    {
        if(arr[0][i] == 0) {
            arr[0][i+val/2] = 1;
        }
        else if(arr[0][i] == 1) {
            arr[0][i+val/2] = 0;
        }
        
    }
      helper(arr, idx+1, size);
   }   
}

int kthGrammar(int N, int K){
    
    
  if(N == 0 || K == 0)
      return -1;
    
  if(K == 0 && N >0)
      return 0; å
    int** row = (int**)calloc(1, sizeof(int*));
    if(row == NULL)
        return -1; 
       
    
    (*row) = (int*)calloc(1, sizeof(int));
    if(*row == NULL)
        return -1; 
    
    (*row)[0] = 0; 
    
    helper(row, 1, N);
        
    
   // for(int i =0; i < 16; i++)
   // {
   //     printf("%d", row[i]);
   // }
    
   return (*row)[K-1]; 
}


