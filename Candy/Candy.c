

int candy(int* ratings, int ratingsSize){

    if(ratings == NULL || ratingsSize == 0)
        return NULL; 
    
    int* res = (int*)calloc(ratingsSize, sizeof(int));
    if(res == NULL)
        return NULL; 
     int sum = 0; 
     for(int i = 0; i < ratingsSize; i++)
         res[i] = 1;
   
    for(int i = 1; i < ratingsSize; i++)
    {
        if(ratings[i-1] < ratings[i])
            res[i] = res[i-1]+ 1; 
  
    }
    
    for(int i = ratingsSize-2; i >=0; i--)
    {
        if(ratings[i] > ratings[i+1])
            res[i] = (res[i] > res[i+1]+1? res[i]: res[i+1]+1);
        
      sum+= res[i];
    }

    sum +=res[ratingsSize-1];
    return sum; 
}
