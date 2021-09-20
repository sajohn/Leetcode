

char * replaceDigits(char * s){

    if(s == NULL)
        return NULL; 
    
    int len= strlen(s);
    
    for(int i =0; i < len-1; i+=2)
    {
        s[i+1] = s[i] + s[i+1] -'0';
        
    }
    
    return s; 
}
