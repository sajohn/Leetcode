

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


struct wordSet
{
  char* keyWord;
  int freq; 
  UT_hash_handle hh;
    
};
int cmpfunc(struct wordSet* aa, struct wordSet* bb)
{
    
    struct wordSet* a = (struct wordSet*)aa;
    struct wordSet* b = (struct wordSet*)bb;
    if (a->freq == b->freq)
    {
        int i = 0;
        while (a->keyWord[i] && b->keyWord[i] && a->keyWord[i]== b->keyWord[i]) i++;
        return (a->keyWord[i] - b->keyWord[i]);
    }
   return (((struct wordSet*)b)->freq - ((struct wordSet*)a)->freq);
    
}

char ** topKFrequent(char ** words, int wordsSize, int k, int* returnSize)
{

    if(!words || wordsSize <1 || k<1 || wordsSize <k)
        return NULL;
    
    if(wordsSize ==1 && k==1)
    {
        *returnSize =k;
        return words;
    }
     
  char** ret = (char**)calloc(k, sizeof(char*));
    if(ret== NULL)
        return NULL;
 
 struct wordSet* set = NULL, *element;
   
    for(int i =0; i < wordsSize; i++)
    {
        HASH_FIND_STR(set, words[i], element);
        if(element)
            element->freq++;
       else{
        element = (struct wordSet*)calloc(1, sizeof(*element));
            if(element == NULL)
              return NULL;
            //int len = strlen(words[i]);
            element->keyWord = words[i];
            if(element == NULL)
               return NULL;
            
            element->freq = 1;
            
            HASH_ADD_KEYPTR(hh, set, element->keyWord, strlen(element->keyWord), element);
       }
    }
       
     
    *returnSize =k;  
     /* Destroy the hashset */
  struct wordSet* curr;
    
  HASH_SORT(set, cmpfunc);  
    
int i =0;
  HASH_ITER(hh, set, curr, element) {
      if(i<k)
          ret[i++] = curr->keyWord;
      
    HASH_DEL(set, curr);
    free(curr);
  }
    
return ret;
        
    
}
