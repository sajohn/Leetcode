

int minAddToMakeValid(char * s){
    
    if(s == NULL )
        return 0; 
    int len = strlen(s);
    if(len == 0)
        return 0; 
    int open = 0, close = 0; 
    

    for(int i =0; i < len; i++){
        if(s[i] == '(')
            open++; 
        else
            if(open > 0)
                open--; 
            else
                close++; 
}
        
    return (open + close);

}
