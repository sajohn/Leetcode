

int FindIndex(char* token, int* val)
{
    if(token == NULL)
        return -1; 
  
    int len = strlen(token);
    if(len == 0)
        return -1; 
    
    int i =0; 
    for( i = len-1; i>=0; i--){ 
        if(!isdigit(token[i]))
            break; 
    }
    
    *val = i+1; 
    return atoi(&token[i+1]);
    
}


char * sortSentence(char * s){
    
    if(s == NULL)
        return NULL; 
    int len = strlen(s);
    if(len == 0)
        return NULL; 

    char* result = (char*)calloc(len+1 , sizeof(char));
    if(result == NULL)
        return NULL; 
    int maxidx = 0; 
    char delim[] = {" "};
 
    char* token = NULL; 
    
    token = strtok(s, delim);
    char* ptr[200] = {0};


    while(token != NULL){
        int len = 0; 
        int idx = FindIndex(token, &len);
        
   
        char* str = (char*)calloc(len+1, sizeof(char));
        strncpy(str, token, len );
      
        if(idx > maxidx)
            maxidx = idx; 
        
        ptr[idx-1] = str; 
        
        token = strtok(NULL, delim);
    }

    
    for(int i =0; i< maxidx; i++)
    {
         strcat(result, ptr[i]);
         if(i != maxidx -1)
             strcat(result, " ");
        free(ptr[i]);
    }
    
    return result; 
}
