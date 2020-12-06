
//Like java solution we need to define find 

struct hashNode {
    int key;
    int val;
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
    return s->val;
}
void AddUser(struct hashNode **g_users, int key) {
    struct hashNode *s;
    HASH_FIND_INT(*g_users, &key, s);
    if (s == NULL) {
        struct hashNode *s = (struct hashNode *)malloc(sizeof(struct hashNode));
        s->key = key;
        s->val = 1;
        HASH_ADD_INT(*g_users, key, s);
    } else {
        s->val++;
    }    
}

int subarraysDivByK(int* nums, int numsSize, int k){

    struct hashNode *g_users = NULL;

    int sum = 0, cnt = 0, remainder =0;
    g_users = NULL;
    //The first 0 is added to cover the case of remainder comes to be zero. Freq 1 doesn't contribute anyways
    AddUser(&g_users,0);
    
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        remainder = sum%k;
        if(remainder<0)
            remainder = remainder+k;
        
        if (findUser(&g_users, remainder)) 
          cnt += GetUserVal(&g_users, remainder);
        
        AddUser(&g_users, remainder);
    }
    
     struct hashNode *current_user, *tmp;
     HASH_ITER(hh, g_users, current_user, tmp) {
    HASH_DEL(g_users, current_user);  /* delete it (users advances to next) */
    free(current_user);             /* free it */
  }
   
    return cnt;
}
:x
