

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct hashNode {
    int sum;
    int count;
    char** key;
    UT_hash_handle hh;
   
};

struct hashNode *findUser(struct hashNode **g_users, int sum) {
    struct hashNode *s;
    HASH_FIND_INT(*g_users, &sum, s);
    return s;
}

int sumSort(struct hashNode* a, struct hashNode* b){
    return (a->sum - b->sum);
}

void AddUser(struct hashNode **g_users, char* key, int sum) {
    struct hashNode *s;
    HASH_FIND_INT(*g_users, &sum, s);
    if (s == NULL) {
        struct hashNode *s = (struct hashNode *)calloc(1, sizeof(struct hashNode));
        s->key = (char**)calloc(s->count+1, sizeof(char*));
        s->key[s->count] = (char*)calloc(strlen(key)+1,sizeof(char) );
        strncpy(s->key[s->count++], key, strlen(key));
        s->sum = sum; 
        HASH_ADD_INT(*g_users,sum,s);
    } 
    else { 
        s->key = (char**) realloc(s->key, (s->count+1)*sizeof(char*));
        s->key[s->count] = (char*)calloc(strlen(key)+1,sizeof(char) );
        strncpy(s->key[s->count++], key, strlen(key));
    }
}

char ** findRestaurant(char ** list1, int list1Size, char ** list2, int list2Size, int* returnSize){
  
    struct hashNode *g_users = NULL, *element;
    
    *returnSize = 0;   
    char** ret = (char**)calloc(list1Size, sizeof(char*));
        
    if(list1 == NULL || list2 == NULL || list1Size == 0 || list2Size == 0 || ret == NULL)
        return 0;
    

    for (int i = 0; i < list1Size; i++) {
        for (int j = 0; j < list2Size; j++) {            
            if(strcmp(list1[i], list2[j]) ==0) {
                AddUser(&g_users, list1[i], i+j);
            }
        }
    }

    HASH_SORT(g_users, sumSort);
   
    int count = g_users->count;
    
     while( (*returnSize) < count){
             ret[(*returnSize)] = (char*)calloc(strlen(g_users->key[*returnSize])+1, sizeof(char));
             strncpy( ret[(*returnSize)] ,  g_users->key[*returnSize],  strlen(g_users->key[*returnSize]));
             (*returnSize)++;
         }
    
     struct hashNode *current_user, *tmp;
     HASH_ITER(hh, g_users, current_user, tmp) {
         while(current_user->count){
            
             free(current_user->key[--current_user->count]);
         }
      HASH_DEL(g_users, current_user);  /* delete it (users advances to next) */
      free(current_user);             /* free it */
    }
    
    
    return ret;
}


