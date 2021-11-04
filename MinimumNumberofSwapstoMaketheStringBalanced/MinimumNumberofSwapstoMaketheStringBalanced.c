

int minSwaps(char * s){
    
    
    if(s == NULL )
        return 0; 
    
    int len = strlen(s);
    if(len%2)
        return 0; 
    int open=0, close=0, lastopen = 0, idx = -1;
   
    int farthest[len];
   
    while(lastopen < len)
    {
        if(s[lastopen] == '[')
            farthest[++idx] = lastopen; 
        lastopen++;
        
    }
    
    lastopen =0; 
    for(int i =0; i < len; i++){
        
        
        if(s[i] == '[')
            open++; 
        else
            close++;
        
        if(close > open)
        {
           
            s[i] = '[';
            s[farthest[idx]] = ']';
            idx--;
            open++;
            close--; 
            lastopen++; 
        }
    }
    
return lastopen; 
}
