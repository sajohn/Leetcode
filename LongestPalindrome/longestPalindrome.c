
//This seems to be only asking about even char's which can be used to make palindrome by reshuffling
//If count is coming out to be even and leng it > count then there is a space for one more letter which was missed due to condition count >1


int longestPalindrome(char * s)
{
   if(s == NULL )
       return 0;
    
    int len = strlen(s);
    if(len == 1)
        return 1;
    
    int countU[26] = {0}, countL[26] = {0}, ret =0; 
    for(int i =0; i < len; i++)
    {
        if(islower(s[i]))
          countL[s[i] -'a']++;
        if(!islower(s[i]))
          countU[s[i] -'A']++;
    }
    
    for(int i =0; i < 26; i++)
    {
        if(countU[i]>1)
            ret +=countU[i]/2*2;
        if(countL[i]>1)
            ret +=countL[i]/2*2;
    }
         
                   
    return ((len > ret && ret%2 == 0) ?   ret+1: ret);     
}
