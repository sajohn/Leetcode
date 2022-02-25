

bool backspaceCompare(char * s, char * t){
    
    if(s == NULL && t == NULL)
        return true;
    if(s== NULL && t  || s && t == NULL)
        return false; 
    int len1 = strlen(s);
    int len2 = strlen(t);
    
    char stack[len1>len2? len1:len2];
    
    int k = -1;
    for(int i =0; i < len1; i++)
    {
        if(s[i] != '#')
            stack[++k ] = s[i];
        else{
            if(k>=0)
               stack[k--] ='\0';
        }
            
    }
    char* tmp1 = NULL; 
    if(k>=0) {
        tmp1 = calloc(k+2, sizeof(char));
        strncpy(tmp1, stack, k+1);
         tmp1[k+1] = '\0';
    }
    
     k = -1;
    for(int i =0; i < len2; i++)
    {
        if(t[i] != '#')
            stack[++k ] = t[i];
        else{
            if(k>=0)
               stack[k--] ='\0';
        }
            
    }
     char* tmp2 = NULL; 
    if(k>=0) {
       tmp2 = calloc(k+2, sizeof(char));
        strncpy(tmp2, stack, k+1);
          tmp2[k+1] = '\0';
    }
  
      
    if((tmp1== NULL && tmp2 == NULL))
        return true; 
      if((tmp1== NULL || tmp2 == NULL))
        return false; 
    return (strcmp(tmp1, tmp2) == 0);

}
