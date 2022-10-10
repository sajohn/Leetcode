


typedef struct {
    int idx;
    int nextidx; 
    int curcount; 
    int tmpcount; 
    char* str; 
    int len; 
    
} StringIterator;


StringIterator* stringIteratorCreate(char * compressedString) {
    StringIterator* obj = (StringIterator*)calloc(1, sizeof(StringIterator));
    
    if(obj == NULL)
        return NULL; 
    if(compressedString == NULL)
        return NULL; 
    
    int len = strlen(compressedString);
    obj->idx = 0; 
    obj->nextidx = 0; 
    obj->tmpcount = 0; 
    obj->curcount = 0; 
    obj->str = compressedString;
    obj->len = len; 
    
    return obj; 
}

int calculateRepeatCount(StringIterator* obj) {
    
    if(obj == NULL) 
        return 0; 
    
     int tmp = 0, idx = obj->idx+1; 
    
   if(obj->str == NULL)
      return -1; 
    
    if(idx >= obj->len){
         obj->nextidx  = -1; 
        return -1; 
    
    }
            while(isdigit(obj->str[idx] ))
            {
                
                tmp = tmp*10 + (obj->str[idx] - '0'); 
                idx++; 
                 
            }
        obj->nextidx = idx; 
         
    return tmp; 
}
char stringIteratorNext(StringIterator* obj) {
    
    
    if(obj != NULL) {
       //printf("Calling %d \n", obj->idx);
        char c; 
        if(obj->curcount == 0){
            
              if(obj->str == NULL)
                    return ' ';
    
        c = (char)obj->str[obj->idx]; 
       if(!isalpha(c))
           return ' '; 
        
        //calculate curcount if not calculated (i.e. idx points to new character )
        
            obj->curcount = calculateRepeatCount(obj); 
            if( obj->curcount == -1)
                return ' '; 
            
            obj->tmpcount = 0;
        
        }
       else {
            
           //change the obj->idx; 
           if (obj->tmpcount == obj->curcount){
                obj->idx = obj->nextidx; 
                obj->tmpcount = 0;
                obj->curcount = calculateRepeatCount(obj); 
               
                if( obj->curcount == -1)
                {
                    obj->idx = obj->nextidx; 
                    return ' '; 
                }
           }
        }
                 
     
     if(obj->tmpcount <obj->curcount){   
            obj->tmpcount++; 
            return obj->str[obj->idx]; 
        }
    
    }
  
    return ' '; 
    
}

bool stringIteratorHasNext(StringIterator* obj) {
    
    if(obj != NULL){
        
        if((obj->curcount != -1 && obj->tmpcount < obj->curcount && obj->idx < obj->len ) || 
           (obj->curcount != -1 && obj->tmpcount == obj->curcount && obj->idx < obj->len && obj->nextidx< obj->len )   
          )
            return true; 
    }
  
    return false; 
}

void stringIteratorFree(StringIterator* obj) {
    
    if(obj)
    {
        if(obj->str)
          free(obj->str);
        obj->str = NULL;
        free(obj);
        obj = NULL; 
    }
    
    return; 
}

/**
 * Your StringIterator struct will be instantiated and called as such:
 * StringIterator* obj = stringIteratorCreate(compressedString);
 * char param_1 = stringIteratorNext(obj);
 
 * bool param_2 = stringIteratorHasNext(obj);
 
 * stringIteratorFree(obj);
*/
