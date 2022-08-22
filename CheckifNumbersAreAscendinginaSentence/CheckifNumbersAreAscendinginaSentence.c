

bool areNumbersAscending(char * s){

    if(s == NULL )
        return true; 
    
    
    int len = strlen(s);
    if(len <=0)
        return false; 

    char* token = NULL; 
    char delim[] = {" "};
    int max = INT_MIN, val = 0; 
    
    token = strtok(s, delim);
    
    while(token != NULL)
    {
        if(!isalpha(token[0]))
        
        {
            val = atoi(token);
            
            if(val <= max)
                return false; 
            max = val; 
            
        }
        
         token = strtok( NULL, delim);
        
    }
    
    return true; 
}
