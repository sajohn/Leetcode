
int firstUniqChar(char * s)
{
if(s == NULL )
    return -1;
    
    int n = strlen(s);
    if(n == 0)
        return -1;
    
    int count[26] = {0};
    
    for(int i =0; i < n; i++)
     count[(s[i] -'a')] +=1;
    
     
    
    for(int i =0; i < n; i++)
        if(count[s[i]-'a'] ==1)
            return i;
    
        
        
   
    return -1;
}
