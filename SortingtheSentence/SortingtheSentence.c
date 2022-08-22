typedef struct Hash{
   char* str; 
   int idx; 
   UT_hash_handle hh;  
    
}Hash;

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

int cmp(Hash* el1, Hash* el2){

    return (el1->idx - el2->idx);
    
}

char * sortSentence(char * s){
    
    if(s == NULL)
        return NULL; 
    int len = strlen(s);
    if(len == 0)
        return NULL; 
    
    Hash* guser= NULL, *element = NULL; 
    
    char* result = (char*)calloc(len+1 , sizeof(char));
    if(result == NULL)
        return NULL; 
    
    char delim[] = {" "};
 
    char* token = NULL; 
    
    token = strtok(s, delim);
    
    while(token != NULL){
        int len = 0; 
        int idx = FindIndex(token, &len);
        
        element = (Hash*)calloc(1, sizeof(Hash));
        if(!element)
            return NULL; 
        element->idx = idx; 
        element->str = (char*)calloc(len+1, sizeof(char));
        strncpy(element->str, token, len );
        HASH_ADD_INT(guser, idx, element);
        
        token = strtok(NULL, delim);
    }
    
     HASH_SORT(guser, cmp);
    
     Hash *current_user;
     Hash *tmp;

    HASH_ITER(hh, guser, current_user, tmp) {
        
        strcat(result, current_user->str);
        if(tmp)
         strcat(result, " ");
        HASH_DEL(guser, current_user);  /* delete it (users advances to next) */
        free(current_user);             /* free it */
    }
    
    return result; 
}
