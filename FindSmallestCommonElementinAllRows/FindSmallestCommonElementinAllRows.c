
//Like java solution we need to define find 

struct hashNode {
    int key;
    int val;
    UT_hash_handle hh;
};

int cmpfunc(struct hashNode* a, struct hashNode* b)
{
    return (a->val - b->val);
}

int smallestCommonElement(int** mat, int matSize, int* matColSize){
    
    if(mat == NULL || matSize == 0 || matColSize ==NULL)
        return -1;
    
     struct hashNode *g_users = NULL, *s;
    
    int sum = 0, cnt = 0;
 
    for(int i = 0; i < matSize; i++)
    {
        for(int j =0; j<*matColSize; j++)
        {
            
            HASH_FIND_INT(g_users, &mat[i][j], s);
            if (s == NULL) {
                s = (struct hashNode *)calloc(1, sizeof(*s));
                s->key = mat[i][j];
                s->val = 1;
                HASH_ADD_INT(g_users, key, s);
            } else {
                s->val++;
            }    
        } 
        
    }
    
    HASH_SORT(g_users, cmpfunc);
    int element =INT_MAX;
   
   //Delete HASH 
     struct hashNode *current_user, *tmp;
     HASH_ITER(hh, g_users, current_user, tmp) 
     {
        if(current_user->val >=matSize )
            if(current_user->key < element )
                element = current_user->key;

        HASH_DEL(g_users, current_user);  /* delete it (users advances to next) */
        free(current_user);
     }
return (element == INT_MAX? -1:element);
}

