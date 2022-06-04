


typedef struct Trie {
    char data;
    int isWordEnd; 
    struct Trie* children[26];
} Trie;

/** Initialize your data structure here. */
Trie* trieCreate();
void trieInsert(Trie* obj, char * word);
bool trieSearch(Trie* obj, char * word);
bool trieStartsWith(Trie* obj, char * word);
void trieFree(Trie* obj);

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
               
        trieInsert(obj->children[word[0]-'a'], word+1); //This is inserting next char from word ....recursively
            
    
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


/*
1. Put everything in trie
2. Check currnt word against trie entry 
3. If for current word trie finds every substring of word[i] 
    - Update the lenght of the result with current word[i]
4. Compare with next word[i]
*/
int cmpfunc(const void *a, const void *b) 
{ 
    const char **ia = (const char **)a;
    const char **ib = (const char **)b;
    return strcmp(*ia, *ib);
}

char* substring(char *destination, const char *source, int n)
{
    while (n > 0)
    {
        *destination = *(source);
 
        destination++;
        source++;
        n--;
    }
 
    *destination = '\0';
 
    return destination;
}

char * longestWord(char ** words, int wordsSize){
    
    if(words == NULL || wordsSize == 0)
        return NULL; 
    char* result = NULL; 
    bool found = false; 
    int len = 0, maxlen = 0; 
    Trie* obj =  trieCreate();
    if(obj == NULL)
        return NULL; 
    
   qsort(words, wordsSize, sizeof(words[0]), cmpfunc);
    
    for(int i = 0; i < wordsSize; i++)
        trieInsert(obj, words[i]);
    

      for(int i = 0; i < wordsSize; i++){
          
          len = strlen(words[i]);
          
          char* substr = (char*)calloc(len+1, sizeof(char));
          if(substr == NULL)
              return NULL; 
          
          if(len > 1){
              
              for(int j = 1; j <= len-1; j++){
                
         
                 strncpy(substr, words[i], j);
                  substr[j] = '\0';
    
                found = trieSearch(obj,  substr );
                  
                  if(found == false){
                     break;
                  }
                      
              }
              
          }
          else if(len == 1)
          {
              found = true; 
          }
          
          if(len > maxlen && found){
              
              result = realloc(result, (len+1)*sizeof(char));
              if(result == NULL)
                  return NULL; 
              strncpy(result, words[i], len+1);
              maxlen = len; 
              
          }
          
          free(substr);
          
      }
    
    
    trieFree(obj);
    
    return (result ? result: ""); 
}
