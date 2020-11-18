


//Like java solution we need to define find 

struct hashNode {
    int key;
    int lastidx;
    UT_hash_handle hh;
};
int sortIdx( struct hashNode *a,  struct hashNode *b)
{
    return (a->lastidx - b->lastidx);
}

int lengthOfLongestSubstringKDistinct(char * s, int k){
    if(s == NULL )
        return -1;
    
    int len = strlen(s);
    if(len ==0 || k ==0)
        return 0;
    if(len < k)
        return len;
    
     int a_pointer =0, b_pointer =0,max =INT_MIN, count =0;

     struct hashNode *g_users = NULL, *element, *element1, *element2;

    while(b_pointer < len)
    {
        int pointer = s[b_pointer]-'a';
        HASH_FIND_INT(g_users, &pointer, element);
        
            if(element && count <=k)
            {
               element->lastidx = b_pointer++;
               max = ((b_pointer- a_pointer)>max)? (b_pointer - a_pointer):max;
            }
            else
            { 
                //Find both distinct chars and their index 
                if(count ==k)
                {
                    //Sort the HASHMAP for lowest index and check the contiguity till it becomes distinct
                    //Update tha a_pointer idx
                    //Add the newest element 
                    //Increment the b_pointer idx
                    HASH_SORT(g_users, sortIdx);
                    struct hashNode *current_user, *tmp;

                 HASH_ITER(hh, g_users, current_user, tmp) 
                 {
                    a_pointer = current_user->lastidx+1;
                     
                     HASH_DEL(g_users,current_user);  /* delete; users advances to next */

                    free(current_user);            /* optional- if you want to free  */
                     break;
                  }
        
                    count--;
                    //Add the new element
                        
                    element = (struct hashNode* )calloc(1, sizeof(*element));
                    element->key = s[b_pointer]-'a';
                    element->lastidx = b_pointer;
                    HASH_ADD_INT(g_users, key, element);
                    b_pointer++;
                    max = ((b_pointer- a_pointer)>max)? (b_pointer - a_pointer):max;
                    count++;
                   
                }
                
                else
                {
                    
                    element = (struct hashNode* )calloc(1, sizeof(*element));
                    element->key = s[b_pointer]-'a';
                    element->lastidx = b_pointer;
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



