

int longestOnes(int* A, int ASize, int K){

   if(A == NULL|| ASize ==0 )
       return 0;
    int start = 0, end = 0; 
  while(end < ASize ){
      
      if(A[end] == 0) K--; 
      
      //Slide window untill K becomes 0 (i.e. )
      if(K<0)
      {
          if(A[start] == 0)
              K++; 
          
          start++; 
      }
    
      end++; 
      
  }
    
    
    return end-start;
}
