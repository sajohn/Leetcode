

bool checkString(char * s){
    
    if(s == NULL)
        return false; 
    
    char* token = strstr(s, "ba");
    if(token == NULL)
        return true; 
    
return false; 
}
