struct hashTable
{
    int idx; 
    char key;
    UT_hash_handle hh;
};

bool isAlienSorted(char ** words, int wordsSize, char * order){
    
    if(words == NULL || wordsSize == 0 || order == NULL)
        return false;

    struct hashTable* g_users = NULL,*element, *element1, *element2;
    
    int len = strlen(order);
    
   for(int i =0; i < len; i++)
   {
     element =   (struct hashTable* )calloc(1, sizeof(*element));
       if(element == NULL)
           return false;
       
       element->idx = i;
       element->key = order[i]-'a';
       HASH_ADD_INT(g_users, key, element );
   }
    int j =0, k=0; 
    
    for(int i =0; i < wordsSize-1; i++)
    {
        
        int len1 = strlen(words[i]);
        int len2 = strlen(words[i+1]);
        
        while(j<len1 && k< len2)
        {
            int key1 = words[i][j++]-'a';
            int key2 = words[i+1][k++]-'a';
            
            HASH_FIND_INT(g_users, &key1, element1);
            HASH_FIND_INT(g_users, &key2, element2);
            if(element1->idx <element2->idx )
                break;
            else if(element1->idx == element2->idx)
                 continue;
            else  
                return false;
        }
        if(j== len1 && (i+1 != wordsSize-1) )
            continue;
        else if((i+1 == wordsSize-1) && element1->idx > element2->idx)
            return false;
         else if((i+1 == wordsSize-1) && ((j== len1) || element1->idx < element2->idx))
                 return true;
        else
            return false;
    }
    return true;

}
