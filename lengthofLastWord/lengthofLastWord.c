

int lengthOfLastWord(char * s){
    
    if(s== NULL )
        return 0; 
    
    int len = strlen(s);
    if(len == 0 || (len == 1 && s[len-1] != ' ')) 
        return len; 
    
    if(len ==1 && s[len-1] == ' ')
        return 0; 
    
    
    int count = 0; 
    
     while(len >0 && s[len-1]== ' ')
     {
         len--; 
     }
    
    while(len >0 && s[len-1]!= ' ')
    {
        count++; 
        len--;
    }

    return count; 
}
