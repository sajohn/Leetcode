

int numDecodings(char * s){
   int len = strlen(s);
    if(s == NULL )
        return 1; 
    
 
    if(s[0] == '0') 
        return 0; 

    long dp[len+1]; //Because 0 length is also considered. which eats up final resulta at len-1 hence return from len
    memset(&dp, 0, sizeof(int)*len);
    int M = 1000000007;
         
    dp[0] = 1; //one way to decode null/empty string
    
    dp[1] = (s[0]>= '1' && s[0] <= '9' ? 1: s[0] == '*' ? 9: 0);//length 1
    
    
    for(int i =1; i < len; i++)
    {
        if (s[i] == '*') {
            dp[i + 1] = 9 * dp[i] % M;
            if (s[i - 1] == '1')
                dp[i + 1] = (dp[i + 1] + 9 * dp[i - 1]) % M;
            else if (s[i - 1] == '2')
                dp[i + 1] = (dp[i + 1] + 6 * dp[i - 1]) % M;
            else if (s[i - 1] == '*')
                dp[i + 1] = (dp[i + 1] + 15 * dp[i - 1]) % M;
        } else {
            dp[i + 1] = s[i] != '0' ? dp[i] : 0;
            if (s[i - 1] == '1')
                dp[i + 1] = (dp[i + 1] + dp[i - 1]) % M;
            else if (s[i - 1] == '2' && s[i] <= '6')
                dp[i + 1] = (dp[i + 1] + dp[i - 1]) % M;
            else if (s[i - 1] == '*')
                dp[i + 1] = (dp[i + 1] + (s[i] <= '6' ? 2 : 1) * dp[i - 1]) % M;
        }
    }
    return dp[len];
}


