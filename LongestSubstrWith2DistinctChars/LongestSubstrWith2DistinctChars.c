


//Like java solution we need to define find 

struct hashNode {
    int key;
    int idx;
    UT_hash_handle hh;
};


int lengthOfLongestSubstringTwoDistinct(char * s){
    if(s == NULL )
        return -1;
    
    int len = strlen(s);
    if(len ==0)
        return 0;
    
     int a_pointer =0, b_pointer =0,max =INT_MIN, count =0;
     int char1 =0, char2 =0;
     struct hashNode *g_users = NULL, *element, *element1, *element2;

    while(b_pointer < len)
    {
        int pointer = s[b_pointer]-'a';
        HASH_FIND_INT(g_users, &pointer, element);
        
            if(element && count <3)
            {
               element->idx = b_pointer++;
               max = ((b_pointer- a_pointer)>max)? (b_pointer - a_pointer):max;
            }
            else
            { 
                //Find both distinct chars and their index 
                if(count ==2)
                {
                    HASH_FIND_INT(g_users, &char1, element1);
                    HASH_FIND_INT(g_users, &char2, element2);
                
                    if(element1 && element2)
                    {
                        if(element1->idx<element2->idx)
                        {
                           a_pointer = element1->idx+1;
                           HASH_DEL(g_users, element1);
                           char1 = element2->key;
                        }
                        else
                        {
                           a_pointer = element2->idx+1;
                           HASH_DEL(g_users, element2);
                          char1 = element1->key;
                        }

                          count--;
                        
                      //Add the new element
                        
                    element = (struct hashNode* )calloc(1, sizeof(*element));
                    element->key = s[b_pointer]-'a';
                    element->idx = b_pointer;
                    HASH_ADD_INT(g_users, key, element);
                    char2= s[b_pointer]-'a';
                    b_pointer++;
                    max = ((b_pointer- a_pointer)>max)? (b_pointer - a_pointer):max;
                    count++;
                   
                    }
                }
                else
                {
                    if(count == 0)
                        char1 = s[b_pointer]-'a';
                    if(count == 1)
                        char2 = s[b_pointer]-'a';
                    
                    element = (struct hashNode* )calloc(1, sizeof(*element));
                    element->key = s[b_pointer]-'a';
                    element->idx = b_pointer;
                    HASH_ADD_INT(g_users, key, element);
                    b_pointer++;
                    max = ((b_pointer- a_pointer)>max)? (b_pointer - a_pointer):max;
                    count++;
                }
                
            }
        
    }
     struct hashNode *current_user, *tmp;
     HASH_ITER(hh, g_users, current_user, tmp) {
     HASH_DEL(g_users, current_user);  /* delete it (users advances to next) */
    free(current_user);             /* free it */
  }
return max;
}

