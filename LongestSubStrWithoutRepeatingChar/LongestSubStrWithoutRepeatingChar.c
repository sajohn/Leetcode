struct hashNode {
    int key;
    UT_hash_handle hh;
};


int lengthOfLongestSubstring(char * s){
    if(s == NULL )
        return -1;
    
    int len = strlen(s);
    if(len ==0)
        return 0;
    
     int a_pointer =0, b_pointer =0,max =INT_MIN;
     struct hashNode *g_users = NULL, *element;

    while(b_pointer < len)
    {
        int pointer = s[b_pointer]-'a';
        HASH_FIND_INT(g_users, &pointer, element);
            if(element)
            {
                int pointer = s[a_pointer]-'a';
                HASH_FIND_INT(g_users, &pointer, element);
                HASH_DEL(g_users, element);
                a_pointer++;
            }
            else
            {
                element = (struct hashNode* )calloc(1, sizeof(*element));
                element->key = s[b_pointer]-'a';
                HASH_ADD_INT(g_users, key, element);
                b_pointer++;
                max = ((b_pointer- a_pointer)>max)? (b_pointer - a_pointer):max;
            }
    }
     struct hashNode *current_user, *tmp;
     HASH_ITER(hh, g_users, current_user, tmp) {
    HASH_DEL(g_users, current_user);  /* delete it (users advances to next) */
    free(current_user);             /* free it */
  }
return max;
}


