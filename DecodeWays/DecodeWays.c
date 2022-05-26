


int numDecodings(char * s){
   int len = strlen(s);
    if(s == NULL || len == 1 && s[0] != '0')
        return 1; 
    
 
    if(s[0] == '0') 
        return 0; 

    int dp[len]; 
    memset(&dp, 0, sizeof(int)*len);
    
    dp[0] = (s[0]>= '1' && s[0] <= '9')? 1:0;//length 1
    dp[1] = ((s[1]>= '1' && s[1] <= '9')? dp[0]:0) +
            ((s[0]== '1' && s[1] >='0' && s[1]<= '9') || (s[0]== '2' && s[1] >='0' && s[1]<= '6') ?1:0);
   
    for(int i =2; i < len; i++){
        
        if((s[i]>= '1' && s[i] <= '9'))
           dp[i] = dp[i-1];
        
        if((s[i-1]== '1' && s[i] >='0' && s[i]<= '9') || (s[i-1]== '2' && s[i] >='0' && s[i]<= '6'))
           dp[i] += dp[i-2];
                
    }
    
    return dp[len-1];
}


