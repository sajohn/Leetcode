
typedef struct hashset{
    int val; //Key
    char* map; //Value
    UT_hash_handle hh; 
}hashset;

bool wordPattern(char * s, char * t){

    if(s == NULL && t == NULL)
        return true; 
    if(s== NULL)
        return false; 
    if(t == NULL)
        return false; 
    
    
    hashset *guser1=NULL, *guser2=NULL, *element1 = NULL , *element2=NULL, *curuser = NULL; 
    
    
     int lens =strlen(s);
//     int lenb = strlen(t);
    
//     if(lens != lenb)
//         return false; 
   
   char* token = strtok(t, " ");
    int i =0; 
    for( i =0; i < lens && token != NULL; i++)
    {
        int x = s[i]-'a';
      
        // HASH_FIND_STR(users, "betty", s);
        // HASH_ADD_KEYPTR(hh, users, s->name, strlen(s->name), s)
        HASH_FIND_INT(guser1, &x , element1);
        HASH_FIND_STR(guser2, token , element2);
        if(element1 == NULL && element2 == NULL){
            element1 = (hashset*)calloc(1, sizeof(hashset));
            if(element1 == NULL)
                return false; 
            element1->val = x;
            element1->map = calloc(strlen(token)+1, sizeof(char));
            if(element1->map == NULL)
                return false; 
            strncpy(element1->map, token, strlen(token));
            
           element2 = (hashset*)calloc(1, sizeof(hashset));
            if(element2 == NULL)
                return false; 
            element2->val = x;
            element2->map =  calloc(strlen(token)+1, sizeof(char));
            if(element2->map == NULL)
                return false; 
             strncpy(element2->map, token, strlen(token));
            
            HASH_ADD_INT(guser1, val, element1);
            
            HASH_ADD_KEYPTR(hh, guser2, element2->map, strlen(token) , element2);
        }
        else{
            
           if(element1){
               if( element1->val != x || strcmp(element1->map, token)!=0)
                   return false; 
           }
            if(element2){
               if( element2->val != x || strcmp(element2->map, token)!=0 )
                   return false; 
           }
            
        }
        token = strtok(NULL, " ");
    }

    
    HASH_ITER(hh, guser1, curuser, element1) {
    free(curuser->map);
    HASH_DEL(guser1, curuser);  /* delete it (users advances to next) */
    free(curuser);             /* free it */
  }

    HASH_ITER(hh, guser2, curuser, element2) {
             free(curuser->map);
    HASH_DEL(guser2, curuser);  /* delete it (users advances to next) */
    free(curuser);             /* free it */
  }

    if((i == lens && token != NULL) || (token == NULL && i<lens))
        return false;
   
    
    return true; 
    
}

