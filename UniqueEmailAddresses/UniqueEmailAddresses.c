typedef struct HashSet{
  
    char* string; 
    UT_hash_handle hh; 
}HashSet;



int numUniqueEmails(char ** emails, int emailsSize){
    
    if(emails == NULL || emailsSize == 0)
        return 0; 
    
    char delim[2] = "@";
    char* token, *tokenLast; 
    int count = 0, k = 0; 
    
    char* buff = (char*)calloc(100, sizeof(char));
        if(buff == NULL)
            return -1; 
    
    HashSet *guser = NULL, *element; 
    
    for(int i = 0; i < emailsSize; i++) {
        k =0; 
        token = strtok(emails[i], delim);
        if(token == NULL)
          continue; 
        
        tokenLast = strtok(NULL, delim);
        if(tokenLast == NULL)
            continue; 
        int j =0;
        for( j = 0; j< strlen(token); j++)
        {
            if(token[j] != '+')
            {
                if(token[j] != '.')
                  buff[k++] = token[j];
            }
            else
                break;
          
        }
       if(j!=0){
            strcat(buff, "@");
            strcat(buff, tokenLast);
       }
    
        HASH_FIND_STR(guser, buff, element);
       
    if(element == NULL){
        element = (HashSet*)calloc(1, sizeof(HashSet));
        if(element == NULL)
            return -1; 
        element->string = (char*)calloc(strlen(buff)+1,sizeof(char) );
        strcpy(element->string , buff);

        HASH_ADD_KEYPTR(hh, guser, element->string, strlen(element->string), element);
      }
     
       memset(buff, 0, 100);
    }

        
    free(buff);
    return HASH_COUNT(guser); 
}
