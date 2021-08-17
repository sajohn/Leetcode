


typedef struct Trie {
    char data;
    int isWordEnd; 
    struct Trie* children[26];
} Trie;

/** Initialize your data structure here. */

Trie* trieCreate() {
    
    
    Trie* obj = (Trie*)calloc(1, sizeof(Trie));
    if(obj == NULL)
        return NULL; 
    
    obj->data = '-';
    obj->isWordEnd = 0; 
return obj;
}

/** Inserts a word into the trie. */
void trieInsert(Trie* obj, char * word) {
    
    if(word == NULL || obj == NULL)
        return ; 
    int len = strlen(word);

             if(obj->children[word[0] - 'a'] == NULL) {
                 obj->children[word[0] - 'a'] = (Trie*)calloc(1, sizeof(Trie));
                if( obj->children[word[0] - 'a'] == NULL)
                    return; 
                             
               obj->children[word[0] - 'a']->data = word[0];
     
             }
    
            if(len == 1)
            {
                obj->children[word[0] - 'a']->isWordEnd = 1; 
                        return; 
            }
               
        trieInsert(obj->children[word[0]-'a'], word+1); 
            
    
}

/** Returns if the word is in the trie. */
bool trieSearch(Trie* obj, char * word) {
   if(word == NULL || obj == NULL)
        return false; 
    int len = strlen(word);
    
      if(obj->children[word[0] - 'a']  == NULL)
         return false; 
      else if(len ==1) 
          return (obj->children[word[0] - 'a']->isWordEnd == 1 ? true: false); 
      else if( len >1) 
              return trieSearch(obj->children[word[0]-'a'], word+1); 
    
    return false;
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool trieStartsWith(Trie* obj, char * word) {
  
      if(word == NULL || obj == NULL)
        return false; 
    int len = strlen(word);
    
     if(obj->children[word[0] - 'a']  == NULL)
         return false; 
    
      else if(len ==1) 
          return true; 
      else if(len >1) 
               return trieStartsWith(obj->children[word[0]-'a'], word+1); 
    
    return false;
}

void trieFree(Trie* obj) {
    if(obj){
        for(int i = 0; i < 26; i++){
            if(obj->children[i]) {
                trieFree(obj->children[i]); 
            }
        }
        
        free(obj);
    }
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);
 
 * bool param_2 = trieSearch(obj, word);
 
 * bool param_3 = trieStartsWith(obj, prefix);
 
 * trieFree(obj);
*/
