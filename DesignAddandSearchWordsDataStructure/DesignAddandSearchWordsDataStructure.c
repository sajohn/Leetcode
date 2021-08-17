
typedef struct WordDictionary{
    char data;
    int isWordEnd; 
    struct WordDictionary* children[26];
} WordDictionary;

/** Initialize your data structure here. */

WordDictionary* wordDictionaryCreate() {
        WordDictionary* obj = (WordDictionary*)calloc(1, sizeof(WordDictionary));
    if(obj == NULL)
        return NULL; 
    
    obj->data = '-';
    obj->isWordEnd = 0; 
return obj;
}

void wordDictionaryAddWord(WordDictionary* obj, char * word) {
    if(word == NULL || obj == NULL)
        return ; 
    int len = strlen(word);

             if(obj->children[word[0] - 'a'] == NULL) {
                 obj->children[word[0] - 'a'] = (WordDictionary*)calloc(1, sizeof(WordDictionary));
                if( obj->children[word[0] - 'a'] == NULL)
                    return; 
                             
               obj->children[word[0] - 'a']->data = word[0];
     
             }
    
            if(len == 1)
            {
                obj->children[word[0] - 'a']->isWordEnd = 1; 
                        return; 
            }
               
        wordDictionaryAddWord(obj->children[word[0]-'a'], word+1); 
            
}

bool wordDictionarySearch(WordDictionary* obj, char * word) {
       if(word == NULL || obj == NULL)
        return false; 
    int len = strlen(word);
       if(word[0] == '.' && len ==1 ){
           for(int i =0; i < 26 ; i++){
               if(obj->children[i] && obj->children[i]->isWordEnd ==1)
                   return true; 
           }
           return false; 
       }
       else if(word[0] == '.' && len >1){
            bool x = false;
           for(int i =0; i < 26 ; i++){
             x |=  wordDictionarySearch(obj->children[i], word+1); 
           }
           return x; 
       }
      else if(obj->children[word[0] - 'a']  == NULL)
         return false; 
      else if(len ==1) 
          return (obj->children[word[0] - 'a']->isWordEnd == 1 ? true: false); 
      else if( len >1) 
              return wordDictionarySearch(obj->children[word[0]-'a'], word+1); 
    
    return false;
  
}

void wordDictionaryFree(WordDictionary* obj) {
     if(obj){
        for(int i = 0; i < 26; i++){
            if(obj->children[i]) {
                wordDictionaryFree(obj->children[i]); 
            }
        }
        
        free(obj);
    }
}

/**
 * Your WordDictionary struct will be instantiated and called as such:
 * WordDictionary* obj = wordDictionaryCreate();
 * wordDictionaryAddWord(obj, word);
 
 * bool param_2 = wordDictionarySearch(obj, word);
 
 * wordDictionaryFree(obj);
*/
