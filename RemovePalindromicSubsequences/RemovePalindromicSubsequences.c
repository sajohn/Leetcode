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
int removePalindromeSub(char * s)
{
     int len = strlen(s);
    if(s == NULL || len == 0)
        return 0;
    if(len <=1)
        return 1;
    
    int count = 0, min= INT_MAX;
    
    if(IsPalindrome(s, len))
        return 1;
    
 return 2;
}
