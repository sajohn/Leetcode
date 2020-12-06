
struct hashNode {
    int key;
    UT_hash_handle hh;
};

struct hashNode *findUser(struct hashNode **g_users, int key) {
    struct hashNode *s;
    HASH_FIND_INT(*g_users, &key, s);
    return s;
}

int GetUserVal( struct hashNode **g_users, int key) {
    struct hashNode *s;
    HASH_FIND_INT(*g_users, &key, s);
    return s->key;
}

void AddUser(struct hashNode **g_users, int key) {
    struct hashNode *s;
    HASH_FIND_INT(*g_users, &key, s);
    if(s == NULL) {
        struct hashNode *s = (struct hashNode *)malloc(sizeof(struct hashNode));
        s->key = key;
        HASH_ADD_INT(*g_users, key, s);
      } 
}

int singleNonDuplicate(int* nums, int numsSize)
{
    if(nums == NULL || numsSize == 0)
        return -INT_MAX;
    
    struct hashNode * g_users = NULL, *element;
    
    for(int i =0; i < numsSize; i++)
    {
        if(element = findUser(&g_users, nums[i]))
        {
              //Element exists this is a second count so can safely delete it
            HASH_DEL(g_users, element);  /* user: pointer to deletee */
             free(element);      
        }
        else
        {
            AddUser(&g_users, nums[i]);
        }
    }
    
       
   struct hashNode *s;

    for(s=g_users; s != NULL; s=s->hh.next) {
       return s->key;
    }
   
    return -1;
}
