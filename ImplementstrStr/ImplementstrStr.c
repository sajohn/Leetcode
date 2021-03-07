

int strStr(char * haystack, char * needle)
{
   if(haystack == NULL || needle == NULL)
       return -1; 
       
    if(strcmp(haystack, needle) == 0)
        return 0;
    
    int hlen = strlen(haystack);
    int nlen = strlen(needle);
    
    if(nlen > hlen || ((hlen == 0 || nlen ==0) && strcmp(haystack, needle) == 0))
        return -1; 
    
    
    
    int idx = hlen -nlen;

    for(int i =0; i <= idx; i++)
    {
        if(strncmp(&haystack[i], needle, nlen) == 0)
            return i; 
    }
    return -1; 
}
