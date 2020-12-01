

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct number_set {
  int value;
  int freq; 
  UT_hash_handle hh;
};

int cmpFunc(struct number_set *a, struct number_set *b)
{
    return (b->freq -a->freq);
}

char * frequencySort(char * s)
{
   if(s == NULL)
       return NULL;
    
    int len = strlen(s);
    if(len <=1)
        return s;
    
     struct number_set* set = NULL;
     struct number_set* element;

    
     for (int i = 0; i < len; ++i) 
     {
        int y = (s[i]-'a');
        HASH_FIND_INT(set, &y, element);
        if (element) {
            element->freq++;
        }
       else{
        element = (struct number_set *) malloc(sizeof(*element));
        element->value = s[i]-'a';
        element->freq = 1;
        HASH_ADD_INT(set, value, element);
       }
  }
 
   HASH_SORT(set, cmpFunc);
           
  /* Destroy the hashset */
  struct number_set* curr;
     
  char* ret = (char*)calloc(len+1, sizeof(char));
    if(ret == NULL)
        return NULL;
  int i =0;
  HASH_ITER(hh, set, curr, element) {
         while(curr->freq){
         ret[i++] = curr->value+'a';
          curr->freq--;
    }
    HASH_DEL(set, curr);
    free(curr);
  }
  ret[i] = '\0';
  return ret; 
}
