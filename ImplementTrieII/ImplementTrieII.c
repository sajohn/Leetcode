
typedef struct Trie {
    char data;
    int dataCount; 
    int isWordEnd; 
    int wordCount;
    struct Trie* children[26];
    
} Trie;


Trie* trieCreate() {
    
    Trie* obj = (Trie*)calloc(1, sizeof(Trie));
    if(obj == NULL)
        return NULL; 
    
    obj->data = '-';
    obj->dataCount = 0; 
    obj->isWordEnd = 0; 
    obj->wordCount = 0;
    
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
               obj->children[word[0] - 'a']->dataCount = 1;
             }
            else{
                 obj->children[word[0] - 'a']->dataCount += 1;
            }
    
            if(len == 1)
            {
                obj->children[word[0] - 'a']->wordCount += 1; 
                obj->children[word[0] - 'a']->isWordEnd += 1; 
                 return; 
            }
               
        trieInsert(obj->children[word[0]-'a'], word+1); //This is inserting next char from word ....recursively     
    
}



int trieCountWordsEqualTo(Trie* obj, char * word) {
     if(word == NULL || obj == NULL)
        return 0; 
     int len = strlen(word);
    
             if(obj->children[word[0] - 'a'] == NULL) 
                 return 0; 
    
            if(len == 1)
            {
                if(obj->children[word[0] - 'a']->isWordEnd >0)
                    return obj->children[word[0] - 'a']->wordCount; 
                else
                    return 0; 
            }
               
        return trieCountWordsEqualTo(obj->children[word[0]-'a'], word+1); //This is searching next char from word ....recursively
        
}

/** Returns if there is any word in the trie that starts with the given prefix. */
int trieCountWordsStartingWith(Trie* obj, char * prefix) {
  
      if(prefix == NULL || obj == NULL)
        return 0; 
    int len = strlen(prefix);
    
     if(obj->children[prefix[0] - 'a']  == NULL)
         return 0; 
    
      else if(len ==1) 
          return obj->children[prefix[0]-'a']->dataCount; 
      else if(len >1) 
               return trieCountWordsStartingWith(obj->children[prefix[0]-'a'], prefix+1); 
    
    return false;
}

void trieErase(Trie* obj, char * word) {
    if(word == NULL || obj == NULL)
        return ; 
     int len = strlen(word);

             if(obj->children[word[0] - 'a'] == NULL) 
                 return; 
             else
               obj->children[word[0] - 'a']->dataCount -= 1;

    
            if(len == 1)
            {
                obj->children[word[0] - 'a']->wordCount -= 1; 
                obj->children[word[0] - 'a']->isWordEnd -= 1; 
                
                return; 
            }
               
        trieErase(obj->children[word[0]-'a'], word+1); //This is deleting next char from word ....recursively
            
    
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
 
 * int param_2 = trieCountWordsEqualTo(obj, word);
 
 * int param_3 = trieCountWordsStartingWith(obj, prefix);
 
 * trieErase(obj, word);
 
 * trieFree(obj);
*/


