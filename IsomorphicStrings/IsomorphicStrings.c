typedef struct hashset{
    int val; //Key
    int map; //Value
    UT_hash_handle hh; 
}hashset;

bool isIsomorphic(char * s, char * t){

    if(s == NULL && t == NULL)
        return true; 
    if(s== NULL)
        return false; 
    if(t == NULL)
        return false; 
    
    
    hashset *guser1=NULL, *guser2=NULL, *element1 = NULL , *element2=NULL, *curuser = NULL; 
    
    
    int lens =strlen(s);
    int lenb = strlen(t);
    
    if(lens != lenb)
        return false; 
    
    for(int i =0; i < lens; i++)
    {
        int x = s[i]-'a';
        int y = t[i]-'a';
        HASH_FIND_INT(guser1, &x , element1);
        HASH_FIND_INT(guser2, &y , element2);
        if(element1 == NULL && element2 == NULL){
            element1 = (hashset*)calloc(1, sizeof(hashset));
            if(element1 == NULL)
                return false; 
            element1->val = x;
            element1->map = y;
           element2 = (hashset*)calloc(1, sizeof(hashset));
            if(element2 == NULL)
                return false; 
            element2->val = y;
            element2->map = x;
            
            HASH_ADD_INT(guser1, val, element1);
            HASH_ADD_INT(guser2, val, element2);
        }
        else{
            
           if(element1){
               if( element1->val ==x && element1->map != y)
                   return false; 
           }
            if(element2){
               if( element2->val ==y && element2->map != x)
                   return false; 
           }
            
        }
    }

    HASH_ITER(hh, guser1, curuser, element1) {
    HASH_DEL(guser1, curuser);  /* delete it (users advances to next) */
    free(curuser);             /* free it */
  }

        HASH_ITER(hh, guser2, curuser, element2) {
    HASH_DEL(guser2, curuser);  /* delete it (users advances to next) */
    free(curuser);             /* free it */
  }

   
    
    return true; 
    
}
