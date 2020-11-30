bool IsPalindrome(char* s, int len )
{
    if(s == NULL )
        return false;
    
    for(int i =0; i < len/2; i++)
    {
        if(s[i] != s[len-1-i])
            return false;
    }
  
    return true;
}

bool validPalindrome(char * s)
{
     if(s == NULL)
         return false;
    int len = strlen(s);
    
    if(len == 0 || len==1)
        return true;
    
   // int l = 0  r =len -1; 
    for(int i = 0; i< len; i ++)
    {
        if(s[i] != s[len-1 -i])
            return (IsPalindrome(s+i, len-1-(2*i)) || IsPalindrome(s+i+1, len-1-(2*i)));
    }    
    
    return true;
}
