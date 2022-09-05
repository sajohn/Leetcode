
bool areOccurrencesEqual(char * s){
    
    if(s == NULL)
        return false; 
    
    
    char freq[26] = {0};
    int len = strlen(s);

    
    for(int i =0; i < len; i++)
        freq[s[i] -'a']++;
                  
        
       for(int i =1; i < len; i++)
        if(freq[s[i-1]-'a'] != freq[s[i]-'a'] )
            return false; 
    
    return true; 
}
