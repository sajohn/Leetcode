int max(int a , int b){
    
    return (a>b? a:b);
}

int numWays(int n, int k){
    
    if(n == 0 || k < 0)
        return 0; 
    
     if(n == 1 && k >=1)
        return k; 
    
    int dp[n];
    bzero(dp, n*sizeof(int));
/*
    //I know first two states i.e first post has k ways.. second has k*k ways
    //Third depends on previous two posts
    
    if(I pick same color as previous post)
     Make sure previous to previous is not same color 
     dp[i-1]*1 == way of picking same color * dp[i-2] ways to pick color 
     
     After removing same color (k-1) is representing the color of previous post 
 
 
    if(I don't pick same color as previous post)
    k ways to fill 
*/
    
    dp[0] = k; 
    dp[1] = k*k; 

    
    for(int i=2; i<n; i++){
        
        //Paint with previous color
         dp[i] = (k-1)*dp[i-2]*1;
        
        //Paint without previous color
         dp[i] += dp[i-1] * (k-1); 
    }

    
  return dp[n-1];
}
